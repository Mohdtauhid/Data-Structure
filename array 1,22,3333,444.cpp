#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;
class ArrayException{
	char *s;
	public:
	ArrayException(char x[])
	{
		s = new char[strlen(x)+1];
		strcpy(s, x);
	}
	friend ostream &operator << (ostream &abc, ArrayException &x)
	{   abc << x.s;
		return abc;
	}
};
class Array
{	int *a, length, size;
	public:
	Array(int n);
	int getsize();
	void insert(int x, int index);
	int del(int index);
	void best_duplicate(Array &a,int index);
	void worst_duplicate(Array &a,int index);
	void best_getpattern(Array &a,int index);
	void worst_getpattern(Array &a,int index);
    void display();
};
Array::Array(int n)
{   length = n;
	a = new int[n];
	size = 0;
	}
int Array::getsize()
{
	return size;
}
void Array::insert(int x, int index)
{if(index < 0 || index > size)
		cout<<"\n invalid";
		//throw  ArrayException("Invalid index in insertion operation");
	if(size == length)
		cout<<"\n full";
		//throw  ArrayException("Array is full in insertion operation");
	for(int i = size-1 ; i >=index; i--)
		{		a[i+1] = a[i]; 
}
	a[index] = x;
	size++;
	
}
void Array::worst_getpattern(Array &a,int n)
{	for(int i=n;i>=1;i--)
	{		for(int j=1;j<=i;j++)
		{		a.insert(i,0);
		}
	}		
}
void Array::best_getpattern(Array &a,int n)
{	for(int i=1;i<=n;i++)
	{		for(int j=1;j<=i;j++)
		{		a.insert(i,a.getsize());
		}
	}		
}
int Array::del(int index)
{  
if(index<0||index>size)
cout<<"\n invalid";
//throw  ArrayException("Invalid in deletion");
	int x=a[index]; 	
	for(int i=index;i<size-1;i++)
{
	a[i]=a[i+1];	 	
}  size--;
return x;
}

void Array::best_duplicate(Array &a,int n)
{for(int i=1;i<=n-1;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			a.del(a.getsize()-i);
		}
	}		
}
void Array::worst_duplicate(Array &a,int n)
{
for(int i=1;i<=n-1;i++)
	{		for(int j=1;j<=i;j++)
		{		a.del(i);	
		}
	}	
}
void Array::display()
{	cout<<"\n[";
	for(int i = 0; i < size; i++)
		cout << a[i] << ", ";
	cout<<"\b]\n";

}
int main()
{   int n; //  number of element;
	cout<<"\n enter array size ";
	cin>>n;    
	int r=(n*(n+1))/2;
	Array obj(r);
	obj.worst_getpattern(obj,n);
	obj.display();
	obj.worst_duplicate(obj,n);
	//cout<<"\n\n deleted number="<<obj.del(8)<<endl;
	//obj.display();
	//obj.insert(555,8);
	obj.display();
getch();

	return 0;
}

