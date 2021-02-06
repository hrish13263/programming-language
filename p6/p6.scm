;Program 6: A program in scheme to define fiven functions of even, oddrev, middle and bookends. 
;CS 320
;Hrishikesh cssc 2644
;Date: 12/07/2020

(define list0 (list 'j 'k 'l 'm 'n 'o 'j) )
(define list1 (list 'a 'b 'c 'd 'e 'f 'g) )
(define list2 (list 's 't 'u 'v 'w 'x 'y 'z) )
(define list3 (list 'j 'k 'l 'm 'l 'k 'j) )
(define list4 (list 'n 'o 'p 'q 'q 'p 'o 'n) )
(define list5 '((a b) c (d e d) c (a b)) )
(define list6 '((h i) (j k) l (m n)) ) 
(define list7 '(f (a b) c (d e d) (b a) f) )

; Here is a typical function definition from Sebesta Ch. 15
;included as told we have to leave it be
(define (adder lis)
  (cond
      ((null lis) 0)
      	(else (+ (car lis) (adder (cdr lis))))
))
; helper function rev that is used when needed
; as stated, it reverses a given list 
(define (rev lis)
	(cond 	((null? lis) '())
		((list? lis) (append (rev (cdr lis)) (list(car lis))))
		(else (display " USAGE: (rev [LIST])"))))

;evens give the list with even positions from a given list
(define (evens lis)
         (cond
           ((null? lis) '())
               ((eq? (cdr lis) '()) '())
               (else (cons (cadr lis) (evens (cddr lis)))))
  )

;oddrevs gives the reversed list of elements at odd positions 
(define (oddrev lis)
	(if (list? lis)
	(cond	((null? lis) '())
		((null? (cdr lis)) (append (oddrev (cdr lis)) (list(car lis))))
		((list? lis) (append (oddrev (cddr lis)) (list (car lis)))))
		(display " USAGE: (oddrev [LIST])")
))
;middle outputs the middle element by recursivley taking of elements from the ends
;if even number of elements, then empty list is outputted
(define (middle lis)
	(if (list? lis)
	(cond	((null? lis) lis) 
		((null? (cdr lis)) lis)
		((list? lis) (middle (cdr (rev (cdr lis))))))
	(display " USAGE: (middle [LIST])")
))

;bookends gives "#t" if ends of a list are same and "#F" if they don't
(define (bookends lis)
	(if (list? lis)
	(cond	((null? lis) #F)
		((list? lis) (eq? (car lis) (car (rev lis)))))	 ;last element taken by car of reversed list
	(display " USAGE: (bookends [LIST])")
))
