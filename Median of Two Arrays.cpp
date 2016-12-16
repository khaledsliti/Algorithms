/*
Author      Khaled Sliti
Problem     Given two sorted arrays with equal lengths,
            find the median of the array obtained after merging two arrays.
Complexity  Time    O(log(N))
            Space   O(N)
Solution    Divide-and-Conquer
*/
#include <bits/stdc++.h>
using namespace std;

int GET_MEDIAN(int* A, int* B, int n)
{
    if(n == 1)
        return (A[0] + B[0]) / 2;
    if(n == 2)
        return (max(A[0],B[0]) + max(A[1],B[1])) / 2;
    int m1 = (n&1 ? A[n/2] : (A[n/2]+A[n/2-1])/2);
    int m2 = (n&1 ? B[n/2] : (B[n/2]+B[n/2-1])/2);
    if(m1 == m2)
        return m1;
    if(m1 > m2){
        return GET_MEDIAN(A, B + n/2 - (n%2 == 0), n - n/2 + (n%2 == 0));
    }else{
        return GET_MEDIAN(A + n/2 - (n%2 == 0), B, n - n/2 + (n%2 == 0));
    }
}

int main()
{
    int n = 5;
    int A[] = {5, 9, 11, 78, 100};
    int B[] = {4, 33 , 45 , 102, 188};
    printf("Median = %d", GET_MEDIAN(A, B, n));
    return 0;
}



