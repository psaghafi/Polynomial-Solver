# Polynomial-Solver using Horner's Algorithm and Bisection Method
The program will print a table with
numRows rows to the screen and print and output file containing numRows tables, one table
corresponding to each row in the table printed to the screen. Each row will show information about the
approximations to the roots of a polynomial, P(X), of order up to 4 for a different initial range
intervalEndMin<=X<=intervalEndMax.

The program will complete each of the following tasks

 The coefficients (coef4, coef3, coef2, coef1, coef0) of the polynomial P(X) are input by the user
and verified by the program in the order listed. One coefficient must be verified before the next
coefficient is read. These coefficients are used to evaluate the polynomial within your program.

All coefficients must be in the range (-50.0 <= coef☺ <= 50.0) ☺ may be 0,1,2,3 or 4.

 Then the values of intervalEndMin, IntervalEndMax are supplied by the user and verified by the
program. These values are the endpoints of an initial interval that may contain a root Y (P(Y) = 0),
intervalEndMin <= Y <= intervalEndMax. The interval is used in the bisection algorithm used to
determine the value of a root if one is found. 

 Then the values of numRows (1 <= numRows <= 25) and intervalShift (0.0 < intervalShift <= 20.0)
are input by the user and verified by the program. The value of numRows determines the number
of rows printed in the table output to the screen and the number of tables printed to the output
file. For the first row of the table printed to the screen
o intervalEndMin <= X <= intervalEndMax.

For the second row of the table printed to the screen .

 (intervalEndMin + intervaIShift) <= X <= (intervalEndMax + intervalShift).

For the Nth row of the table printed to the screen

 (intervalEndMin + (N-1)*intervalShift) <= X
 <= intervalEndMax + (N-1)*intervalShift). 
