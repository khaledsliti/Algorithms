/*
Author      Khaled Sliti
Problem     Given an array of integers, sort its elements - Merge Sort
Complexity  Time    O(N log(N))
            Space   O(N)
Solution    Divide-and-Conquer
*/

#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000;
int temp[MAX];

void MERGE(int* arr,int l,int m,int r)
{
    for(int i=0,j=l,k=m+1;i<r-l+1;i++){
        if(arr[j] <= arr[k] || k>r){
            temp[i] = arr[j++];
        }else{
            temp[i] = arr[k++];
        }
    }
    for(int i=0;i<r-l+1;i++)
        arr[i+l] = temp[i];
}

void MERGE_SORT(int* arr,int l,int r)
{
    if(l<r){
        int mid = (l+r)/2;
        MERGE_SORT(arr,l,mid);
        MERGE_SORT(arr,mid+1,r);
        MERGE(arr,l,mid,r);
    }
}

int main()
{
    int A[5] = {5,4,3,2,1};
    MERGE_SORT(A,0,4);
    for(int i=0;i<5;i++)
        cout << A[i] << " \n"[i == 4];
    return 0;
}
