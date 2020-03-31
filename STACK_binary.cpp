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

int bin(int m)
{ stack<int> s1(1);

int p=1,b=0;
while(m!=0)
{
	s1.push(m%2);
	m=m/2;
	p=10*p;
}
	p=p/10;
	while(s1.empty()==false)
	{	
	b=b+p*s1.pop();
p=p/10;
}
return b;
}
int main()
{

	cout<<bin(14);
	return 0;
}

