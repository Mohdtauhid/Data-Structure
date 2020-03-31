#include<iostream>
#include<conio.h>
using namespace std;


int gcd(int,int);

template<class T>
class stack
{
	T *a;
	int length,tos;
	public:
		stack(int n){
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
				cout<<i<<"]"<<" "<<"\b\b";
						}
						cout<<"\n";			
			
		}
		
};

int gcd(int m,int n)
{   stack<int> s1(1),s2(1);
	s1.push(m);
	s2.push(n);
	while(!s1.empty())
	{
		m=s1.pop();
		n=s2.pop();
		if(m%n!=0)
		{
			s1.push(n);
			s2.push(m%n);
		}
	
	}
	return n;
}

int main()
{
	
	int a=12,b=8;
	cout<<gcd(a,b);
	return 0;
}

