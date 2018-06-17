\ collcount.fs
\ Samuel Grenon
\ 29 April 2017
\ CS 331 
\ Excersise B
\ This program performs the collats sequence

: collatz { count n -- c }
  n 1 =
  if
    count
  else
    n 2 mod
    0 =
    if
      count 1 + 
      n 2 / 
      recurse
    else
      count 1 + 
      n 3 * 
      1 + 
      recurse
    then
  then
;
  
: collcount ( n -- c )
  0 swap
  collatz
;