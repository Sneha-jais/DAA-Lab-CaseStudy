/* :)
Problem Statement: Given an array of integers. Find the Inversion Count in the array.
Inversion Count: For an array, inversion count indicates how far (or close) the array is from
being sorted. If array is already sorted then the inversion count is 0. If an array is sorted in the
reverse order then the inversion count is the maximum.
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
Input: n=5
       arr[]={2,4,1,3,5}
       Output: 3
       Explanation: It has three inversion (2,1), (4,1), (4,3).
*/

//Approach 1: Brute Force
int brute_inver(int *arr, int n) {
 int count = 0;
 for (int i = 0; i < n; ++i) {
 for (int j = i + 1; j < n; ++j) {
 if (arr[i] > arr[j]) {
 ++count;
 }
 }
 }
 return count;
}




//Approach 2: Divide and Conquer 
#include<bits/stdc++.h>
using namespace std;

int merge(int arr[],int low,int mid,int high){
    int i=low,j=mid,k=0;
    int count=0;
    int temp[high+low-1];
    
  while ((i < mid) && (j <= high)) {
    if (arr[i] <= arr[j]) {
      temp[k] = arr[i];
      ++k;
      ++i;
    } 
    else {
      temp[k] = arr[j];
      count += (mid - i);
      ++k;
      ++j;
    }
  }
 
  while (i < mid) {
    temp[k] = arr[i];
    ++k;
    ++i;
  }
 
  while (j <= high) {
    temp[k] = arr[j];
    ++k;
    ++j;
  }
 int m=0;
  for (i = low; i <= high; i++) {
    arr[i] = temp[m];
    m++;
  }    
  return count;  
}

int merge_sort(int arr[],int low,int high){
    int count=0;
    if(low<high){
        int mid=(low+high)/2;
        count=merge_sort(arr,low,mid);
        count+=merge_sort(arr,mid+1,high);
        count+=merge(arr,low,mid,high);
        
    }
    return count;
}

int main(){
    int n;
    cout<<"Enter number of elements\n";
    cin>>n;
    int arr[n];
        cout<<"Enter the elements\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
       
  //BruteForce Call
 //int invCount=brute_inver(arr,n);
       
   int invCount=merge_sort(arr,0,n-1);
      cout<<invCount;    
    return 0;
 }
