#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;

class UTmatrix
{
	float *a; int n;
	public:
UTmatrix(int n)
{
	this->n=n;
	a=new float(n*(n+1)/2);
}
int map(int i,int j)
{ 
	return (n*i-i*(i+1)/2 + j);
}

	int read();
	void print();
	float det();	
  UTmatrix inverse();
void sort();
UTmatrix mul(UTmatrix B);
UTmatrix add(UTmatrix B);
};

int UTmatrix::read()
{
	cout<<"\n\n\nenter the non zero element "<<n<<"X"<<n<<" Upper triangular matrix\n";
	for(int i=0;i<n;i++)
	{
	for(int j=i;j<n;j++)
	{
	
	cout<<"a["<<i<<"]"<<"b["<<j<<"]";
	
	cin>>a[map(i,j)];

}
cout<<"\n";
}
}
void UTmatrix::print()
{
		cout<<"\nthe lower triangular matrix is\n";//throw new ArrayException("Array is full in insertion operation");
	for(int i=0; i<n ; i++)
	{
	for(int j=0;j<n;j++)
	{
	if(i<=j)
	cout<<"\t"<<a[map(i,j)];
	else
	cout<<"\t0";
	}
	cout<<"\n";
}
}
float UTmatrix::det()
{cout<<"\n\nDETERMINATE  of a Matrix==" ;

	float d=1.0;
for( int i=0;i<n;i++)
	{
		d=d*a[map(i,i)];
	}
return d;
}


UTmatrix UTmatrix::add(UTmatrix B)
{ cout<<"\n\nADD of a Matrix==" ;

	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			//if(i<=j)
			a[map(i,j)]=a[map(i,j)]+B.a[map(i,j)];
	
		}
		
	}
	

}

UTmatrix UTmatrix ::mul(UTmatrix B)
{ cout<<"\n\n MUUTIPLICATION of a Matrix==" ;
UTmatrix c(n);
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{  c.a[map(i,j)]=0;
			for(int k=i; k<=j;k++)
			{
				c.a[map(i,j)]+=a[map(i,k)]*B.a[map(k,j)];
			}
		}
	}
	return c;
}

void UTmatrix::sort()
{ cout<<"\n\n SORT of a Matrix==" ;
 double temp;
	for(int i = 0; i<(n*(n+1)/2); i++)
	{	for(int j = i+1; j<(n*(n+1)/2); j++)
	{	if(a[i]<a[j])
		{ 
		temp=a[i];
				a[i]=a[j];
			a[j]=temp;
		}
}
}
}
UTmatrix UTmatrix::inverse()
{ cout<<"\n\nINVERSE of this matrix=="; 
UTmatrix A(n) ,B(n);
for(int i=0;i<n;i++)
for(int j=i;j<=n;j++)
{
	A.a[map(i,j)]=a[map(i,j)];
	if(i==j)
	B.a[map(i,j)]=1;    				// b= 1 0 0
	                                    //    0 1 0
	                                    //    0 0 1
	else 
	B.a[map(i,j)]=0;
}
for(int i=n-1;i>1;i--)
{  float x=A.a[map(i,i)];
	for(int j=0;j<i-1;j++)
	{ float y=A.a[map(i,j)];
	for(int k=i;k<=n-1;k++)
	{
		A.a[map(i,k)]=A.a[map(j,k)] - A.a[map(i,k)]*y/x;
		B.a[map(j,k)]=B.a[map(i,k)] - B.a[map(i,k)]*y/x;
}
}
}for(int i=0;i<n-1;i++)
{float x=A.a[map(i,i)];
for(int k=i;k<n;k++)
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
UTmatrix obj1(n) ,obj2(n);
obj1.read();
obj1.print();
//obj2.read();
//obj2.print();
//obj1=obj1.mul(obj2);
//obj1.sort();
obj1=obj1.inverse();

obj1.print();

getch();
	return 0;
}

