#include<iostream>
#include<conio.h>
using namespace std;		 
void insertion(int a[],int n)
{ int x,j;
	for(int i=1;i<n;i++)
	{ 
x=a[i];
j=i-1;
	while(j>=0 and a[j]>x)
	{ 		
	a[j+1]=a[j];
j=j-1;
}
	a[j+1]=x;
	

}
}
int main()
{
	int a[8];
	cout<<"\nENTER VALUES";
	for(int i=0;i<8;i++)
	cin>>a[i];
	insertion(a,8);
	cout<<"\nAFTER SORTING";

	for(int i=0;i<8;i++)
	cout<<" "<<a[i];


}
