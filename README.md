maths
=====

A reverse polish notation calculator

##Operators
#)
Makes all the numbers before it into a vector: eg 1 2 6i 5 ) returns a vector with those elements

#}
Makes all the vectors before it into a matrix: eg 1 2 ) 3 i ) 8i 7) } returns
a matrix with first row 1,2 second row 3,i and third row 8i,7

#+
Add the two last things: eg 3 i + returns 3 + i and 3 i ) i 7 ) + returns a vector with elements 3+i,7+i

#-
Subtract the two last things: eg 5 2 - returns 3

#*
Does various things depending on what you give it 
eg:
2 i * returns 2i

4 i ) i 6 ) * returns 10i (dot product)

3 7 ) 6 * returns a vector with elements 18,42

3 7 ) i 7i ) } -2 * returns a matrix with first row -6,-14 and second row -2i,-14i

8 i ) 2 1 ) } 2 2 ) * returns a vector with elements 16+2i,4+2i (standard matrix, vector product)
1 2 ) 3 4 ) } 5 6 ) 7 8 ) } * returns  a matrix with first row  19,22 and second row 43,50 (standard matrix product)

#/
Divides stuff. Works as you would expect for numbers. For vectors and matrices it works elementwise:
6 2 / returns 3
4 i / returns -4i
12 20 ) 4 5 ) / returns a vector with elements 3,4


#def
This allows you to define variables eg:
3 x def lets you use x in place of the number 3 so:

3 x def

4 i + x *

returns 12+3i

You can define vectors and matrices similarly:

2 3 4 ) y def stores that vector in a variable y

1 2 3 ) 4 5 6 ) } z def stores that matrix in a variable z

If you def a variable more than once the new version overrides the old one:

3 x def

87 4i ) x def

x 
returns a vector with elements 87,4i

N.B. the def operator returns the value that was defined so the first example above returns 3

##Note
If you do anything not mentioned above then enjoy your free seg fault!


