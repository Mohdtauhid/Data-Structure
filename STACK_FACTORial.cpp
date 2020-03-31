#include<iostream>
//#include<conio.h>
using namespace std;
int gcd(int,int);
template<class T>
class stack
{T *a;
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
				cout<<"]"<<" "<<"\b\b";
						}
						cout<<"\n";			
			
		}
		
};

int fact(int m)
{   stack<int> s1(1);
int n,g=1;
	while(m>1)
	{
		
		
			s1.push(m);
		
	n=	s1.pop();
	m=m-1;
g=g*n;
	}

	return g;
}

int main()
{
	
	
	cout<<fact(5);
	return 0;
}

