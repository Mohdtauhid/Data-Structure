#include<iostream>
#include<conio.h>
using namespace std;
class queue
{
	private:
		int rear,front,length;
		int *a;
		public:
			queue(int m)
			{ rear=front=-1;
				a=new int[m];
				length=m;
					for(int i=0;i<length;i++)
					a[i]=0;
				
			}
bool empty()
{
	if(front==-1||rear==-1)
return true;
else
return false;
}
int getsize()
{
	if(rear==-1||front==-1)
	return 0;
	else if(front<=rear)
	return(rear-front+1);
	else 
	return(length+rear-front+1);
	
}
int insert(int x)   // insert alway from rear 
{ 
	if(front==0&&rear==length-1||front==rear+1) //(r+1)%length==f;
	{
		cout<<"\nERROR FULL QUEUE";
	}
	else
	{
	if(rear==-1)
	{
		front=0;
		rear=0;
	}
else	if(rear==length-1)
	rear=0;
	else
	rear++;
	a[rear]=x;
}
}
int del()    // delete alway from front 
{ int value;
if(front==-1)
	cout<<"\nERROR QUEUE is EMPTY";

else
{
value=a[front];
a[front]=0;	
if(rear==front)
	rear=front=-1;
else if(front==length-1)
front==0;
else
front++;
return value;
}
}
void display()
{	
	for(int i=0;i<length;i++)
	cout<<"["<<a[i]<<"]"<<" ";
cout<<endl;
}
 };
 int main()
 { int l=0; 
 cout<<"Enter size of queue";
 cin>>l;
 	queue obj(l);
 	obj.insert(11);
 	obj.insert(12);
 	obj.insert(13);
 	 	obj.insert(14);
 	obj.insert(15);
 	obj.insert(24);
 	obj.insert(25);
 	obj.insert(26);
	  	 cout<<obj.getsize();
 	obj.display();	
  } 
