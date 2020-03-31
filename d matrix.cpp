#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;

class Dmatrix
{
	float *a; int n;
	public:
Dmatrix(int n);

	int read();
	void print();
	float det();
	Dmatrix inverse();
	void transpose();
	Dmatrix mul(Dmatrix B);
Dmatrix add(Dmatrix B);
};
Dmatrix ::Dmatrix(int n)
{

	this->n=n;
	a=new float[n];
}
int Dmatrix::read()
{
	cout<<"enter \t"<<n<<"diagonal element of daigonal matrix\n";
	for(int i=0;i<n;i++)
	cin>>a[i];

}

void Dmatrix::print()
{
		cout<<"the diagonal matrix is\n";//throw new ArrayException("Array is full in insertion operation");
	for(int i=0; i<n ; i++)
	{
	for(int j=0;j<n;j++)
	{
	if(i==j)
	cout<<a[i]<<"\t";
	else
	cout<<"0\t";
	}
	cout<<"\n";
}
}
float Dmatrix::det()
{
	float d=1.0;
	for(int i=0;i<n;i++)
	{
		d=d*a[i];
	}
	return d;
}

Dmatrix Dmatrix::inverse()
{
	if(det()==0)
	cout<<"invalid\n";
Dmatrix b(n);

for(int i=0;i<n;i++)
{
	b.a[i]=1.0/a[i];
}
return b;
}
Dmatrix	Dmatrix ::mul(Dmatrix B)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j)
			{
				a[i]=a[i]*B.a[i];
			}
		}
	}
}
Dmatrix Dmatrix::add(Dmatrix B)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j)
			{
				a[i]=a[i]+B.a[i];
			}
		}
	}

}

void Dmatrix::transpose()
{
	for(int i = 0; i<n; i++)
	{

	for(int j = 0; j < n; j++)
	{
	if(i==j)
		cout << a[i]<<"\t";
else
cout<<"0\t";
}
cout<<"\n";
}
}
int main()
{
Dmatrix obj1(3);
obj1.read();
obj1.print();
Dmatrix obj2(3);

obj2.read();
obj2.print();
obj1.mul(obj2);
obj1.print();
getch();
	return 0;
}

