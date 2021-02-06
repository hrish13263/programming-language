/*
 * Programming aggignment 1b - A Program to calculate the amount of time it takes to pay
 * off a loan and also states the total amount of interest paid.
 * CS 320
 * September 9th, 2020
 * @author Hrishikesh . M cssc2644
 * Copyright © 2020 hr. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>

int getMonths(double,double,double,double*);            
void getLoanFactors(char *argv[], double*loanAmt, double *intRate, double * payment){         
    *loanAmt = atof(argv[2]);
    *intRate = atof(argv[3]);
    *payment = atof(argv[4]);
        }
void printID(){
	printf(" Program 1, cssc2644, Hrishikesh Manjunath \n");
}
int main(int argc,char **argv){
    printID();
    double loanAmt, intRate, payment, totalInt=0;
    int totalMonths;
    if(argc>1){
        getLoanFactors( argv,&loanAmt,&intRate,&payment);
        printf("$%.2lf Loan amt\n",loanAmt);
        printf("$%.2lf Interest per year\n",intRate);
        printf("$%.2lf The monthly payments\n",payment);
        totalMonths=getMonths(loanAmt,intRate,payment,&totalInt);       
        printf("%d months to pay off loan\n",totalMonths);
        printf("$%.2lf total interest paid\n",totalInt);
        return 0;
    }
    else{
        printf("Usage: p1b dblLoanAmt dblIntRate dblMopayment");
	}
	return 255;
}

/* The following function is used to otain the remaining months. A while loop
 *  is utilized to repetedly print as the months progress in a year*/
int getMonths(double loanAmt,double intRate, double payment,double *totalInt)
{
    int month=1;
    double remainingAmt=loanAmt;
    double interest;
    printf("LoanAmt\tMonth\tTotalInt\n");
        while(remainingAmt>0)
        {
            interest=remainingAmt*(intRate/12);
            remainingAmt-=(payment-interest);
            *totalInt+=interest;
            printf("%.2lf\t%d\t\t%.2lf\n", remainingAmt,month,*totalInt);
            month++;
        }
    return month-1;
}
