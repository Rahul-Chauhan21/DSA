/*
    Since every level on each mergeSort call takes O(n) time & to get to the base case of
    this recursive algorithm we keep dividing the subArray in half, giving us a total of log(n) O(n)
    operations resulting into a time complexity of O(n*log(n))

    Space complexity is O(n) since we create an auxiliary array at the merge call.
*/
#include<iostream>
using namespace std;
void
Merge(int* arr,int l,int mid,int r)
{
int temp[r-l+1];
int i=l,j=mid+1,k=0;
    while(i<=mid&&j<=r)
    {
        if(arr[i]<=arr[j])
        {
            temp[k++]=arr[i++];
        }
        else
        {
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid)
    {
        temp[k++]=arr[i++];
    }
    while(j<=r)
    {
        temp[k++]=arr[j++];
    }

    for(int i=l;i<=r;i++)
    {
        arr[i]=temp[i-l];
    }
    //cout<<l<<" "<<r<<"\n";
    // prints every sorted subarray at a merge call
    for(int i=l;i<=r;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
//time O(nlogn) | space O(n)
void
mergesort(int* arr,int l,int r)
{
    if(l<r)
    {
        int mid=l+(r-l)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        Merge(arr,l,mid,r);
    }
}
int main()
{
 int n;
 cout<<"Enter the size of array";
 cin>>n;
 int *p= new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>*(p+i);
    }
    mergesort(p,0,n-1);
    /*for(int i=0;i<n;i++)
    {
        cout<<*(p+i)<<" ";
    }*/
return 0;
}
