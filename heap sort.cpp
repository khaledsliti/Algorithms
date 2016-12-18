/*
Author      Khaled Sliti
Problem     Given an array of integers, sort its elements - Heap Sort
Complexity  Time    O(N log(N))
            Space   O(N)
*/
#include <bits/stdc++.h>
using namespace std;

int L(int i){ return (i<<1)+1; }
int R(int i){ return (i<<1)+2; }

void MaxHeapify(int* A, int i,int n)
{
    int l = L(i);
    int r = R(i);
    int largest = i;
    if(l < n && A[i] < A[l])
        largest = l;
    if(r < n && A[largest] < A[r])
        largest = r;
    if(largest!=i){
        swap(A[i], A[largest]);
        MaxHeapify(A,largest,n);
    }
}

void HeapSort(int* A,int n)
{
    // Build Max-Heap
    for(int i=n/2;i>=0;i--)
        MaxHeapify(A,i,n);
    for(int i=n-1;i>0;--i){
        swap(A[0],A[i]);
        MaxHeapify(A,0,i);
    }
}

int n;
int A[1000];

int main()
{
	n = 10;
	int A[] = {16,14,10,8,7,9,3,2,4,1};
    HeapSort(A,n);
    for(int i=0;i<n;i++)
        printf("%d ",A[i]); printf("\n");
    return 0;
}
