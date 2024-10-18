int n,k;

/* Function prototypes */
int permutations_aux(int n,int k,int y);

/*Function:permutations(int n,int k)
 *Usage:int result=permutations(n,k)
 * -----------------------------------------------------
 *Function to calculate permutation from n to k
 */
int permutations(int n,int k){
    return permutations_aux(n,k,1);
}

/*
 * Function: permutations_aux(int n,int k,int y)
 * Usage: int result = permutations_aux(int n,int k,int y));
 * -----------------------------------------------------
 * Auxiliary function to compute permutation from n to k
 * implemented in a tail recursive way
 *
 */
int permutations_aux(int n,int k,int y){
    if(k==0)
        return y;
    else
        return permutations_aux(n-1,k-1,y*n);
}

/*Function:combinations(int n,int k)
 *Usage:int result=combinations(n,k)
 * -----------------------------------------------------
 *Function to calculate combination from n to k
 */
int combinations(int n,int k){
    return permutations(n,k)/permutations(k,k);
}
