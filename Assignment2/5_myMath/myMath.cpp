#include <string>
#include <iostream>
using namespace std;
int m,n,k;
/* Function prototypes */
int factorial_aux(int k,int y);
int gcd(int m,int n);
int lcm(int m,int n);
/* Function:gcd(int m,int n)
 * Usage: result = gcd(m,n)
 *-------------------------------------
 *Function to calculate the greatest division of m and n
 */
int gcd(int m,int n) {
    if (n == 0)
        return m;
    else
        return gcd(n, m%n);
}

/* Function:lcm(int m,int n)
 * Usage: result = lcm(m,n)
 *-------------------------------------
 *Function to calculate the lcm of m and n
 */
int lcm(int m,int n){
    return m*n/gcd(m,n);
}

/* Function:gcd_lcm(int m,int n)
 *-------------------------------------
 *Function to calculate the greatest division and lcm of m and n
 */

void gcd_lcm(int m,int n){
    int g=gcd(m,n);
    cout<<g<<endl<<m*n/g<<endl;
}

/*
 * Function: factorial_aux(int k, int y)
 * Usage: int result = factorial_aux(k,y);
 * -----------------------------------------------------
 * Auxiliary function to compute the factorial of n
 * implemented in a tail recursive way
 *
 * k: the number to compute the factorial of
 * y: the result of the factorial computation for the previous recursive call
 *
 */
int factorial_aux(int k, int y) {
    if(k>1)
        return factorial_aux(k-1,k*y);
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
int factorial(int k) {
    return factorial_aux(k, 1);
}


