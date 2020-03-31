#include<iostream>
#include<conio.h>
using namespace std;
int gcd(int,int);
template<class T>
class stack
{T *a;
	int length,tos;
	public:
		stack(int n)
		{
			length=n;
			a=new T[n];
			tos=-1;
		}
		bool empty()
		{if(tos==-1)
			return true;
		else
		return false;
		}
		int getsize()
		{
			return tos+1;
		}
		void push(T x)
		{
			a[++tos]=x;
		}
		T pop()
		{
			return a[tos--];
		}
		void disp()
		{
			cout<<"["<<" ";
			for(int i=tos;i>0;i--)
			{
				cout<<"]"<<" "<<"\b\b";
						}
						cout<<"\n";			
						}
		
};

int fib(int m)
{ stack<int> s1(1);
s1.push(m);
int n,t=0;
	while(s1.empty()==false)
	{	
	n=s1.pop();
if(n>2)
{ 
	s1.push(n-1);
	s1.push(n-2);
}
else
t=t+1;
}
return t;
}
int main()
{
	cout<<fib(6);
	return 0;
}

