#include<iostream>
#include<conio.h>
using namespace std;		 
int merge_sort(int *a,int low,int mid,int high)
{ int i=low,j=mid+1,k=0;
int c[high -low + 1 ];     //  size
while(i<=mid and j<=high)
{
	if(a[i]<=a[j])
	{
		c[k++]=a[i++];
		
	}
	else
{
	c[k++]=a[j++];

}
}
while(i<=mid)
{
	c[k++]=a[i++];

}
while(j<=high)
{
	c[k++]=a[j++];
	}
	
for(int i=low;i<=high;i++)
a[i]=c[i-low];	
}
int merge(int *arr, int low, int high) 
{ 
    if (low < high) 
    { 
        int mid = (low+high)/2; 
  
        merge(arr, low, mid); 
        merge(arr, mid+1, high); 
   merge_sort(arr, low, mid, high); //calling 
    } 
} 
int main()
{

int a[]={1,13,5,17,9,3,2,4};
int size=sizeof(a)/sizeof(a[0]);
merge(a,0,size-1);
	cout<<"\nAFTER SORTING";
	for(int i=0;i<size;i++)
	cout<<" "<<a[i];

}
