#include<iostream>
#include<conio.h>
using namespace std;		 
void selection_sort(int a[],int n)
{ int min_index,t;
	for(int i=0;i<n-2;i++)
	{ min_index=i;
	
	for(int j=i+1;j<=n-1;j++)
	{ 	
		if(a[j]<a[min_index])
	min_index=j;
	}
	if(i!=min_index)
	{ t=a[i];
	a[i]=a[min_index];
	a[min_index]=t;
	
	}
}
}
int main()
{
	int a[8];
	cout<<"\nENTER VALUES";
	for(int i=0;i<8;i++)
	cin>>a[i];
	selection_sort(a,8);
	cout<<"\nAFTER SORTING";

	for(int i=0;i<8;i++)
	cout<<" "<<a[i];


}
