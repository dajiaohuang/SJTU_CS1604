/**
 * File: main.cpp
 * ------------------------
 * This file contains a tail recursive function to compute the greatest common divisor and a tail recursive function to compute the factorial.
 *
 */

#include<iostream>
using namespace std;

/* Function prototypes */
int gcd(int x, int y);
int factorial(int n);
int factorial_aux(int n,int y);
/* Main program */
int main(){
    int x,y,n;
    cin>>x>>y>>n;
    cout<<gcd(x,y)<<endl<<factorial(n)<<endl;
    return 0;
}

/*
 * Function: gcd(int x, int y)
 * Usage: int result = gcd(x,y);
 * -----------------------------------------------------
 * return the greatest common divisor of x and y
 */
int gcd(int x, int y) {
    if (y == 0)
        return x;
    else
        return gcd(y, x%y);
}



/*
 * Function: factorial_aux(int n, int y)
 * Usage: int result = factorial_aux(n,y);
 * -----------------------------------------------------
 * Auxiliary function to compute the factorial of n
 * implemented in a tail recursive way
 *
 * n: the number to compute the factorial of
 * y: the result of the factorial computation for the previous recursive call
 *
 */
int factorial_aux(int n, int y) {
    /** TODO: (delete this comment when you are finished)
     * fill the function body in tail recursive way */
    if(n>1)
        return factorial_aux(n-1,n*y);
    else
        return y;
}

/*
 * Function: factorial(int n)
 * Usage: int result = factorial(n);
 * -----------------------------------------------------
 * Compute the factorial of n
 *
 */
int factorial(int n) {
    /** TODO: (delete this comment when you are finished)
     * what should be filled in the argument of factorial_aux
     * if we want to compute the factorial of n?
     *
     * replace the 0's here to make factorial work
     */
    return factorial_aux(n, 1);
}
