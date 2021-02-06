# Programming assignment 3 - A python program to read matrices A and B, multiply them and calculate the result matrix C
#                       the input is gotten from the command line and prints all matrices A,B and C
# CS 320
# October 19th, 2020
# author: Hrishikesh .M

import sys

#The following function opens the inputfile and reads and stores matrices
def read_matrices(A,B):
        file = sys.argv[1]
        with open(file, 'r') as f:
                m = int(next(f))
                n = int(next(f))
                p = int(next(f))
                for x in range(m):
                        A.append([int(x) for x in next(f).split()])
                for y in range(n):
                        B.append([int(x) for x in next(f).split()])
        C = [[0 for i in range(p)] for j in range(m)]
        f.close()
        return  C

#The following function uses a matrix multiplication algorithm and gets the resultant C matrix.
#If A = m*n and B=n*p, then resultant is m*p matrix. 
#Column of first matrix should be equal to rows of second matrix        

def mult_matrices(A,B,C):
        m = len(A)
        n = len(A[0])
        p = len(B[0])
#Matrix multiplication algorithm
        for i in range(m):
                for j in range(p):
                        C[i][j]=0
                        for k in range(n):
                                C[i][j] += A[i][k]*B[k][j]

#The following function is employed to print the matrices
def print_matrix(arr):
        for r in arr:
                for c in r:
                        print(c,end = "\t")
                print()

def main():                                     #calls the required functions and respective matrices are passed
        print("Programming assignment 3, Hrishikesh Manjunath, CSSC2644")
        A = []
        B = []
        C  = read_matrices(A,B)
        mult_matrices(A,B,C)
        print(' the Matrix A is')
        print_matrix(A)                         #matrix A is print by calling print_matrix with A as argument
        print(' the Matrix B is')
        print_matrix(B)                         #matrix B is printed
        print('the multiplied matrix A*B is')
        mult_matrices(A,B,C)
        print_matrix(C)
if __name__ == '__main__':
        main()
