/*
Author      Khaled Sliti
Problem     Given an array of integers, find the maximum sub-array sum
Complexity  Time    O(N log(N))
            Space   O(N)
Solution    Divide-and-Conquer
*/

#include <bits/stdc++.h>
using namespace std;
const int oo = (int) 1e9;

struct res{
    int left, right;
    int sum;
    res(){}
    res(int l,int r,int s): left(l), right(r), sum(s){}
};

res MAXIMUM_CROSSING_SUBARRAY_SUM(int* arr,int left,int right)
{
    int mid = (left+right)/2;
    int sum = 0;
    int left_sum = -oo;
    int left_idx;
    for(int i=mid;i>=left;--i){
        sum += arr[i];
        if(sum > left_sum){
            left_sum = sum;
            left_idx = i;
        }
    }
    sum = 0;
    int right_sum = -oo;
    int right_idx;
    for(int i=mid+1;i<=right;++i){
        sum += arr[i];
        if(sum > right_sum){
            right_sum = sum;
            right_idx = i;
        }
    }
    return res(left_idx,right_idx,left_sum+right_sum);
}

res MAXIMUM_SUBARRAY_SUM(int* arr, int left,int right)
{
    if(left == right)
        return res(left,right,arr[left]);
    int mid = (left+right)/2;
    res L = MAXIMUM_SUBARRAY_SUM(arr,left,mid);
    res R = MAXIMUM_SUBARRAY_SUM(arr,mid+1,right);
    res M = MAXIMUM_CROSSING_SUBARRAY_SUM(arr,left,right);
    int max_sum = max(max(L.sum,R.sum),M.sum);
    if(L.sum == max_sum) return L;
    if(R.sum == max_sum) return R;
    return M;
}

int main()
{
    int A[16] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    res ans = MAXIMUM_SUBARRAY_SUM(A,0,15);
    printf("Maximum sum: %d\nSub-Array: [%d,%d]\n",ans.sum,ans.left+1,ans.right+1);
    return 0;
}









