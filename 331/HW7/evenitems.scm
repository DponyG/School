
#lang scheme

; evenitems.scm
; Samuel Grenon
; Excersis C
 

(define (evenitems list)
  (if (null? list) '()
       (if (not(null? (cdr list)))
                (cons (car list) (evenitems (cddr list))) 
         list)
       
   )
 )
