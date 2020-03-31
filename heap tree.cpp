#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std; 
class HEAP_TREE
{
public:
int insert(int *a,int n)
{ 
cout<<"\nENTER  VALUE  TO BE INSERT";
cin>>a[n+1];
build(a,n+1);
}
int Delete(int *a,int n)
{
if(n==0)
cout<<"\n\nEmpty tree";	
int x=a[1];
a[1]=a[n-1];
adjust(a,1,n-1);
return x;
}
int build(int *a,int n)
{  
for(int i=(n)/2;i>=1;i--)
adjust(a,i,n);
}
int heap_sort(int *a,int n)
{    build(a,n); int i;
	for(i=n-1;i>=1;i--)
	{
		int t=a[i];
		a[i]=a[1];
		a[1]=t;
	adjust(a,1,i-1);
	}

}
int adjust(int *a,int i,int n)
{
int j=2*i;
int y=a[i];
while(j<=n)
{
if(j<n and a[j+1]>a[j])
j=j+1;
if(y>a[j])
break;
else if(y<=a[j])
{
a[j/2]=a[j];
j=2*j;	
}
}
a[j/2]=y;
}

void display(int *a,int n)
{cout<<endl;
  	
if(n==0)
	{
		cout<<"\nHeap is empty\n";
		return;
	}
	for(int i=1;i<=n;i++)
	cout<<" "<<a[i];
}
};
int main()
{ int a[20],n,x;
cout<<"\n\nEnter no of element";
cin>>n;
for(int i=1;i<=n;i++)
{   
cout<<"\nEnter element =="<<i<<endl;
 cin>>a[i];
 
}
HEAP_TREE obj;
obj.build(a,n);
obj.display(a,n);
obj.insert(a,n);
obj.display(a,n+1);
obj.insert(a,n+1);
obj.display(a,n+2);
obj.heap_sort(a,n+2);
obj.display(a,n+5);
}

