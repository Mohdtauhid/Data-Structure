#include<iostream>
#include<conio.h>
using namespace std;		 
void bubble_sort(int a[],int n)
{ int sorted,t;
	for(int i=1;i<n-1;i++)
	{ 
	sorted=true;
	for(int j=0;j<=n-i-1;j++)
	{ 		sorted=false;
		if(a[j]>a[j+1])
		{
		t=a[j];
	a[j]=a[j+1];
	a[j+1]=t;
}
	}
	

if(sorted==true)
break;
}
}
int main()
{
	int a[8];
	cout<<"\nENTER VALUES";
	for(int i=0;i<8;i++)
	cin>>a[i];
	bubble_sort(a,8);
	cout<<"\nAFTER SORTING";

	for(int i=0;i<8;i++)
	cout<<" "<<a[i];


}
