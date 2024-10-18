/** File: main.cpp
 * ----------------
 * This file computes the plans for three scenarios of dividing balls into buckets.
 *
 * Organize the project yourself. The project should have the following structures:
 *
 *  - main.cpp
 *    + main function to process input/output
 *    + countPlanA/countPlanB/countPlanC functions
 *
 *  - combinatorics.h: interfaces for
 *    + permutations
 *    + combinations
 *
 *  - combinatorics.cpp: implementations for
 *    + permutations that does not use factorial
 *    + combinations that does not use factorial
 *
 *
 */
#include <iostream>
#include "combinatorics.h"
using namespace std;

/* Function prototypes */
int countPlanA(int n, int k);
int countPlanB(int n, int k);
int countPlanC(int n, int k);

/* Main program */
int main(){
    char ch;
    int n,k;
    cin>>ch>>n>>k;
    switch(int(ch))
    {
        case 65:cout<<countPlanA(n,k)<<endl;break;
        case 66:cout<<countPlanB(n,k)<<endl;break;
        case 67:cout<<countPlanC(n,k)<<endl;break;
    }
}

/*Scenario A: Distribute n distinguishable balls into k buckets of different colors,
 *and each bucket should at most contain one ball
 */
int countPlanA(int n, int k){
    if(n>k)
        return 0;
    return permutations(k,n);
}

/*Scenario B: Divide n indistinguishable balls into k buckets of different colors,
 *and each bucket should contain at least one ball.
 */
int countPlanB(int n, int k){
    if(n<k)
        return 0;
    return combinations(n-1,k-1);
}

/*Scenario C: Divide n indistinguishable balls into k buckets of different colors,
 *and buckets can be empty.
 */
int countPlanC(int n, int k){
    return combinations(n+k-1,k-1);
}
