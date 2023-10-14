//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
        
        int len1=m-l+1;
        int len2=r-m;
        int *arr1=new int[len1];
        int *arr2=new int[len2];
        int main=l;
        for(int i=0;i<len1;i++){
            arr1[i]=arr[main++];
        }
         for(int i=0;i<len2;i++){
            arr2[i]=arr[main++];
        }
        int index1=0;
        int index2=0;
        main=l;
        while(index1<len1 && index2<len2){
            if(arr1[index1]<arr2[index2]){
                arr[main++]=arr1[index1++];
            }
            else{
                arr[main++]=arr2[index2++];
            }
        }
        while(index1<len1){
            arr[main++]=arr1[index1++];
        }
        while(index2<len2)
        {
            arr[main++]=arr2[index2++];
        }
         
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        
        if(l>=r){
            return;
        }
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends