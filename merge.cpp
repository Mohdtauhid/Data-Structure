#include<iostream>
#include<conio.h>
using namespace std;		 
int *merge_sort(int a[],int m,int b[],int n)
{ int i=0,j=0,k=0,*c=new int[m+n];
while(i<m and j<n)
{
	if(a[i]<b[j])
	{
		c[k]=a[i];
		i=i+1;
	}
	else
{
	c[k]=b[j];
	j=j+1;
}
k=k+1;
}
while(i<m)
{
	c[k]=a[i];
	i=i+1;
	k=k+1;
}
while(j<n)
{
	c[k]=b[j];
	j=j+1;
	k=k+1;
} 
return c;
}
int main()
{

int a[]={1,3,5,7,9,11,13,14};
int b[]={2,4,6,8,10};
	int *cc=merge_sort(a,8,b,5);
	cout<<"\nAFTER SORTING";
	for(int i=0;i<8+5;i++)
	cout<<"\n"<<cc[i];


}
