/*
Author      Khaled Sliti
Problem     Inversion count for an array.
            Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j
Complexity  Time    O(N log(N))
            Space   O(N)
Solution    Divide-and-Conquer
*/
#include <bits/stdc++.h>
using namespace std;

int merge_arrays(int* A, int* temp, int l,int mid,int r)
{
    int res = 0;
    int i = l, j = mid+1;
    int k = l;
    while(i <= mid && j <= r){
        if(A[i] < A[j]){
            temp[k++] = A[i++];
        }else{
            temp[k++] = A[j++];
            res += mid - i + 1;
        }
    }
    while(i <= mid) temp[k++] = A[i++];
    while(j <= r) temp[k++] = A[j++];
    for(int i=l;i<=r;i++)
        A[i] = temp[i];
    return res;
}

int merge_sort(int*A, int* temp, int l,int r)
{
    int res = 0;
    if(l < r){
        res += merge_sort(A,temp,l,(l+r)/2);
        res += merge_sort(A,temp,(l+r)/2+1,r);
        res += merge_arrays(A,temp,l,(l+r)/2,r);
    }
    return res;
}

int calc_inversion(int* A, int n)
{
    int* temp = (int*) malloc(n * sizeof(int));
    return merge_sort(A,temp,0,n-1);
}

int main()
{
	int A[] = {1, 20, 6, 4, 5};
	int n = 5;
	printf("Number of inversions = %d\n",calc_inversion(A,n));
    return 0;
}



