// Samuel J Grenon
// 3/27/2019
// randacc.cpp
// CS321 Assignment 4 B
// Turning in early, but going to fix it. Readfile will read however,
// write dosen't currently work.





#include <iostream>
#include <cstddef>
using std::size_t;
#include <string>
#include <sstream>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/types.h>
#include<sys/stat.h> 


//checkInput
//Pre: None
//Post: Checks to see if the input is a valid input

int checkInput(){
    std::string input;
    int n;
    while(true){
     getline(std::cin, input);
     std::istringstream iss(input);
     iss >> n;
     if(!iss){
         std::cout << "Please enter an int (0 - 99)" <<std::endl;
         continue;
     }
     if( n < 0 || n > 99){
         std::cout << "Not a valid input Please try again" << std::endl;
         continue;
     }
     break;
    }

    return n;
}

void wait_exit(int code)
{
    std::cout << "Press ENTER to quit ";
    while (std::cin.get() != '\n') ;
    _exit(code);
}

//closeit
//Pre:none
//Post:Closes a file discriptor.
void closeit(int fd) {
    int close_failure = close(fd);
    if (close_failure) {
        std::cout << "Close Failed" << std::endl;
        wait_exit(1);
    }

}

//getFileSize
//Pre::none
//Post::Returns the filesize of the passed filename.
off_t getFileSize(const std::string & fileName){
    struct stat st;
    
    if (stat(fileName.c_str(), &st) == 0){
        return st.st_size;
    }

    return -1;

}

//readFile
//Pre::none
//Post::Reads the input given at a specific
//record number
void readFile(std::string & filePath) {
    int fd = open(
        filePath.c_str(),
        O_CREAT|O_RDONLY,
        0644);
        if (fd == -1) {
            std::cout << "Could not open file" << std::endl;
            _exit(1);
        }

        std::cout << "Enter a record (0 - 99)" << std::endl;
        int num = checkInput();
        void *addr = mmap(
            nullptr,
            getFileSize(filePath),
            PROT_READ,MAP_SHARED,
            fd,
            0);
        if(addr == MAP_FAILED){
		std::cout << "There is nothing There" << std::endl;
		closeit(fd);
		wait_exit(1);
        }

        int *value = (int*)addr;
        std::cout << "The value at " << num << " is " << value[num] << std::endl;
      

        int munmap_failure = munmap(
            addr, getFileSize(filePath));

        if (munmap_failure) {
            std::cout << "Failed to deallocate" << std::endl;
            closeit(fd);
            wait_exit(1);
        }

        closeit(fd);
}

void writeFile(const std::string & fileName) {
    //Open the file
    int fd = open(
        fileName.c_str(),        
        O_RDWR | O_CREAT | O_APPEND,
        0644);

    if (fd == -1){
        std::cout << "Could not open File" << std::endl;
        wait_exit(1);
    }
    
    // Memory map the file
    void * addr = mmap(
        nullptr,                 // Requested address (no request)
        getFileSize(fileName),   // How much memory
        PROT_READ | PROT_WRITE,  // Access flags
        MAP_SHARED,              // File & sharing flags
        fd,                      // File descriptor
        0);                      // Byte offset in file
    
    if (addr == MAP_FAILED){
        std::cout << "- mmap FAILED" << std::endl;
        closeit(fd);
        wait_exit(1);
    }


    std::cout << "Enter a Record (0 - 99)" << std::endl;
    int num = checkInput();
    std::cout << "Enter a positive int (0 - 99)" << std::endl;
    int newnum = checkInput();
  

    // Write the memory
    int * value = (int *)addr;
    value[num] = newnum;

  
    int munmap_failure = munmap(
        addr,    
        getFileSize(fileName));     

  
    if (munmap_failure){
        std::cout << "- munmap FAILED" << std::endl;
        closeit(fd);
        wait_exit(1);
    }

 
    closeit(fd);
   
}




void startFile (const std::string & fileName){
    int fd = open(
        fileName.c_str(),       
        O_RDWR,
        0644);

    if (fd == -1){
        fd = open(
        fileName.c_str(),        
        O_RDWR | O_CREAT | O_TRUNC,
        0644);

        ssize_t dummy;
        for (size_t i = 0; i < 100; ++i){
            dummy = write(fd, 0 , 1);
        }
        dummy = write(fd, "\n", 1);
    }
    
    closeit(fd);
}

int main()
{

    std::string fileName = "testing.txt";
    startFile(fileName);
    int n;
    std::string input;

    while (true)
    {

        std::string filePath = "testing.txt";
        std::cout << "Choose one of the following" << std::endl;
        std::cout << "1: Read a record " << std::endl;
        std::cout << "2: Write a record" << std::endl;
        std::cout << "3: Quit" << std::endl;

        getline(std::cin, input);
        std::istringstream iss(input);
        if(!std::cin){
            std::cout << "Error with cin" << std::endl;
            return 1;
        }
      
        iss >> n;


        switch (n)
        {
        case 1:
            readFile(fileName);
            break;
        case 2:
            writeFile(fileName);
            break;
        case 3:
            wait_exit(1);
            break;
        default:
            std::cout << "You didn't choose an input" << std::endl;
            break;
        }
    }
}