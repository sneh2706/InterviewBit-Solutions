/*

Given an array of integers A of size N and an integer B.

array A is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2 ).

You are given a target value B to search. If found in the array, return its index, otherwise return -1.

You may assume no duplicate exists in the array.

NOTE:- Array A was sorted in non-decreasing order before rotation.

NOTE : Think about the case when there are duplicates. Does your current solution work? How does the time complexity change?*

*/

int search1(const vector<int> &arr, int low, int high, int B) 
{ 
    if (low > high) return -1; 
  
    int mid = (low) + (high-low)/2; 
    if (arr[mid] == B) return mid; 
  
    if (arr[low] <= arr[mid]) 
    { 
        if (B >= arr[low] && B <= arr[mid]) 
        return search1(arr, low, mid-1, B); 
 
        return search1(arr, mid+1, high, B); 
    } 
  
    else if (arr[mid] <= arr[high])
    {
    if (B >= arr[mid] && B <= arr[high]) 
        return search1(arr, mid+1, high, B); 
  
    return search1(arr, low, mid-1, B); 
    }
} 
 
 
int Solution::search(const vector<int> &A, int B) {
    
   int n = A.size();
   int i = search1(A, 0, n-1, B); 
  
    if (i != -1) 
    return i;
    else
    return -1;
    
}
