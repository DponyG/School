/*
Samuel Grenon
2/12/2018
delegate.cpp
*/

#include "sa2a.h"
#include <thread>
#include <vector>
#include <mutex>
using std::lock_guard;
using std::mutex;
using std::thread;
using std::vector;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::getline;
using std::string;
#include <sstream>
using std::istringstream;

int totalIteration = 0;
vector<int> userInput;
vector<int> result;
vector<int> id;
mutex shared;
bool print;

void run()
{

    while (!totalIteration)
    {
        continue;
    }

    while (true)
    {
        shared.lock();
        if (userInput.size() == 0)
        {
            shared.unlock();
            return;
        }
    

        int temp = userInput[userInput.size() - 1];
        userInput.pop_back();
        shared.unlock();

        int hash = sa2a(temp);
        shared.lock();
        id.push_back(temp);
        result.push_back(hash);
        shared.unlock();
    }
}


int main()
{

    string inputString;
    int inputNum;
    vector<thread> workers(6);

    for (int i = 0; i < 6; i++)
    {
        workers[i] = thread(run);
    }

    // while(true){
    //     cout << "Enter a positive integer(or 0 to end input)" << endl;
    //     getline(cin, inputString);
    //     istringstream iss(inputString);
    //     if(!cin){
    //         break;
    //     }

    //     if(iss >> inputNum){
    //         iss >> inputNum;

    //         if(inputNum > 0) {
    //              userInput.push_back(inputNum);
    //         }

    //         if(inputNum == 0){
    //             break;
    //         }

    //     }

    //     else{

    //         cout<< "Please enter an integer"<< endl;
    //         continue;
    //     }

    //    for (int i = 0; i < userInput.size(); i++){
    //        cout<<userInput[i]<<endl;
    //    }

    // }

    do
    {
        std::cout << "Enter a positive number to continue, 0 to end" << std::endl;
        string s;
        std::getline(cin, s);
        if (s.length() > 0)
            userInput.push_back(std::stoi(s));
    } while (userInput.back() > 0);
    userInput.pop_back();

    shared.lock();
    totalIteration = userInput.size();
    shared.unlock();

    int output = 0;

    while (true)
    {
        shared.lock();
        if (result.size() == 0)
        {
            shared.unlock();
            continue;
        }

        cout << "sa2a(" << id[id.size() - 1] << ") = " << result[result.size() - 1] << endl;
        id.pop_back();
        result.pop_back();
        ++output;

        if (totalIteration == output)
        {
            shared.unlock();
            break;
        }
        shared.unlock();
    }

    for (int i = 0; i < 6; i++)
    {
        workers[i].join();
    }

    // return 0;
}

//  int totalIterations = userInput.size();

//     for(int i = 0; i < workers.size(); i++){
//          workers[i] = thread(run, i);

//     }

//     static int outputsPrinted = 0;
// 	lock_guard<mutex> count_guard(shared); {
// 		while (outputsPrinted != totalIterations) {
// 			if (print)
// 			{
// 				{
// 					cout << "sa2a (" << result[count] << ") = " << result[count];
// 					print = false;
// 					outputsPrinted++;
// 				}

// 			}
// 		}
//     }

// 	for (int i = 1; i<workers.size(); i++)
// 	{
// 		workers[i].join();
// 	}
// 	return 0;
// }
