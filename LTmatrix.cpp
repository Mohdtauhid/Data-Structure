#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;
int map(int i,int j)
{
	return (i*(i+1)/2+j);
}
class LTmatrix
{
	float *a; int n;
	public:
LTmatrix(int n)
{
	this->n=n;
	a=new float(n*(n+1)/2);
}

	int read();
	void print();
	float det();	
  LTmatrix inverse();
void sort();
LTmatrix mul(LTmatrix B);
LTmatrix add(LTmatrix B);
};
int LTmatrix::read()
{
	cout<<"\n\n\nenter the non zero element "<<n<<"X"<<n<<" lower  triangular matrix\n";
	for(int i=0;i<n;i++)
	{
	for(int j=0;j<=i;j++)
	{
	
	cout<<"a["<<i<<"]"<<"b["<<j<<"]";
	
	cin>>a[map(i,j)];

}
cout<<"\n";
}
}
void LTmatrix::print()
{
		cout<<"\nthe lower triangular matrix is\n";//throw new ArrayException("Array is full in insertion operation");
	for(int i=0; i<n ; i++)
	{
	for(int j=0;j<n;j++)
	{
	if(i>=j)
	cout<<"\t"<<a[map(i,j)];
	else
	cout<<"\t0";
	}
	cout<<"\n";
}
}
float LTmatrix::det()
{cout<<"\n\nDETERMINATE  of a Matrix==" ;

	float d=1.0;
for( int i=0;i<n;i++)
	{
		d=d*a[map(i,i)];
	}
return d;
}


LTmatrix LTmatrix::add(LTmatrix B)
{ cout<<"\n\nADD of a Matrix==" ;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i>=j)
			a[map(i,j)]=a[map(i,j)]+B.a[map(i,j)];
	
		}
		
	}
	

}

LTmatrix LTmatrix ::mul(LTmatrix B)
{ cout<<"\n\n MULTIPLICATION of a Matrix==" ;
LTmatrix c(n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{  c.a[map(i,j)]=0;
			for(int k=j; k<=i;k++)
			{
				c.a[map(i,j)]+=a[map(i,k)]*B.a[map(k,j)];
			}
		}
	}
	return c;
}

void LTmatrix::sort()
{ cout<<"\n\n SORT of a Matrix==" ;
 double temp;
	for(int i = 0; i<(n*(n+1)/2); i++)
	{

	for(int j = i+1; j<(n*(n+1)/2); j++)
	{
	
		if(a[i]<a[j])
		{ 
		temp=a[i];
		
			a[i]=a[j];
			a[j]=temp;
		}
}
}
}
LTmatrix LTmatrix::inverse()
{ cout<<"\n\nINVERSE of this matrix=="; 
LTmatrix A(n) ,B(n);
for(int i=0;i<n;i++)
for(int j=0;j<=i;j++)
{
	A.a[map(i,j)]=a[map(i,j)];
	if(i==j)
	B.a[map(i,j)]=1;    				// b= 1 0 0
	                                    //    0 1 0
	                                    //    0 0 1
	else 
	B.a[map(i,j)]=0;
}
for(int i=0;i<n-1;i++)
{  float x=A.a[map(i,i)];
	for(int j=i+1;j<n;j++)
	{ float y=A.a[map(j,i)];
	for(int k=0;k<=i;k++)
	{
		A.a[map(j,k)]=A.a[map(j,k)] - A.a[map(i,k)]*y/x;
		B.a[map(j,k)]=B.a[map(j,k)] - B.a[map(i,k)]*y/x;
}
}
}for(int i=0;i<n;i++)
{float x=A.a[map(i,i)];
for(int k=0;k<=i;k++)
{
	A.a[map(i,k)]=A.a[map(i,k)]/x;
	B.a[map(i,k)]=B.a[map(i,k)]/x;
}
}
return B;	
}
int main()
{ int n;
	cout<<"\n enter n value";
	cin>>n;
LTmatrix obj1(n) ,obj2(n);
obj1.read();
obj1.print();
//obj2.read();
//obj2.print();
cout<<"\n"<<obj1.det();
obj1=obj1.inverse();
obj1.print();
//obj1.sort();
//obj1.print();

getch();
	return 0;
}

