/**
 * File: main.cpp
 * -------------------
 * This file contains a function to compute the amount of champagne
 * in the glass of a champagne tower after pouring from the top
 *
 */

#include<iostream>

using namespace std;

/* Function prototypes */
double champagneTower(int poured, int query_row, int query_glass);
double champagneFlow(double to_pour,int row, int col);
double positive(double res);
/* Main program */
int main(){
    int query_row, query_glass, poured;
    cin >> poured >> query_row >> query_glass;
    if (poured<0||query_glass<0||query_row<0||query_glass>query_row)
        return -1;
    double result = champagneTower(poured, query_row, query_glass);
    cout << result << endl;
    return 0;
}


/*
 * Function: champagneTower(int poured, int query_row, int query_glass)
 * Usage: double result = champagneTower(poured, query_row, query_glass);
 * -----------------------------------------------------
 * return the amount of champagne that is left in the position
 * (query_row, query_glass) after pouring from the top `poured`
 * amount of champagne
 *
 * The result will range from 0 to 1
 */
double champagneTower(int poured, int query_row, int query_glass) {
    /** FILL IN HERE */
    double flow=champagneFlow(poured,query_row,query_glass);
    if (flow<=0)
        return 0;
    if (flow<1)
        return flow;
    return 1;
}

/*
 * Function: champagneFlow(int to_pour, int row, int col)
 * Usage: double result = champagneFlow(double to_pour,int row, int col);
 * -----------------------------------------------------
 * return the amount of champagne that will flow into a glass during the whole process of pouring in the position
 * (row,col) after pouring from the top `poured`
 * amount of champagne
 *
 * The result will range from 0 to 1
 */
double champagneFlow(double to_pour,int row, int col){
    if (row==0 && col==0)
        return to_pour;
    if (row==col)
        return 0.5*positive(champagneFlow(to_pour,row-1,col-1)-1);
    if (col==0)
        return 0.5*positive(champagneFlow(to_pour,row-1,0)-1);
    return 0.5*(positive(champagneFlow(to_pour,row-1,col-1)-1)+positive(champagneFlow(to_pour,row-1,col)-1));
}

/*
 *Function:postive(double res)
 *Usage:double result =  positive(double res)
 *-----------------------------------------------
 *return the amount of champagne that flows out of a glass
 *
 */
double positive(double res){
    if(res>0)
        return res;
    else
        return 0;
}

/** TODO:
 * You should write another recursive function to calculate
 * the flow of the champagne */
