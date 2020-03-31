#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;
class node
{ public:
	int A ;
		node *next;
};
		class CL
	{
	node *first;
	public:
		CL()
		{
			first=NULL;
		}
		int rev();
		int index(int a);
		bool isEmpty();
		int getsize();
		void insert(int a,int index);
		void del(int index);
		int merge(CL B,CL C);
		void display();
};

		int CL::index(int a)
		{
		 int index=-1,i=0;
		node *cur;
		if(first==NULL)//  NULL is a macro;
			return index;
		 cur=first;
		  while(cur->A!=a&&cur->next!=first)
		  {
		  	cur=cur->next;
		  	i=i+1;
		  }
		  index=i;
		  return index;
		}
bool CL::isEmpty()
{
	if(first==NULL)
		return true;
		else
	return false;
}
int CL::getsize()
{
	int sz=0;
	node *cur=first;
	
	if(isEmpty())
		return sz;
	while(cur->next!=first)
	{
		sz++;
		cur=cur->next;
	}
	return sz+1;
}
void CL::insert(int a,int index)
{	if(index<0 ||index>getsize())
	{		cout<<"ERROR\n";
		return;
	}
	node *cur=new node;
	node *prev;
	cur->A=a;
	if(index==0)
	{
	cur->next=cur;
	first=cur;
}


  else
   {	
  prev=first;
		for(int i=0;i<index-1;i++)
		{
			prev=prev->next;
		}
				cur->next=prev->next;
		prev->next=cur;
	}
}
void CL::del(int index)
{
	if(index<0 ||index>getsize())
	{
		cout<<"ERROR----";
		return;
	}
	node *cur;  
	node *prev;
	node *del;
	if(index==0)
	{   cur=first;
		del=first;
		while(cur->next!=first)
		{ 
			cur=cur->next;
		}
		first=del->next;  //first = NULL 
		del->next=NULL;
		delete del;
		cur->next=first;
	}
	else
	{
		prev=first;
		for(int i=0;i<index-1;i++)
		{
			prev=prev->next;
		}
		del=prev->next;  // del is pointing to next node
		prev->next=del->next;
		del->next=NULL;
		delete del;
	}
}

void CL::display()
{
	node *cur=first;
cout<<endl;
	while(cur->next!=first)
	{
		cout<<cur->A;
		cur=cur->next;
	cout<<endl;
	
	}	cout<<cur->A;
cout<<endl;
}
int CL::merge(CL B,CL C)
{node *cur,*temp;
cur=B.first;
while(cur->next!=first)
{
	cur=cur->next;
}
cur->next=C.first;
temp=C.first;
while(temp->next!=C.first)
{
	temp=temp->next;
}
temp->next=first;
}
int CL::rev()
{
	node*cur,*temp,*p1,*p2,*p3;
	cur=first;
	if(cur==NULL)
	return -1;
	p1=cur;
	p2=p1->next;
	p3=p2->next;
	p2->next=p1;
	while(p3->next!=first)//different ---- p3->next==NULL
	{ p1=p2;
	p2=p3; 
	p3=p3->next;
	p2->next=p1;
	}p1=p2;
	p2=p3; 
	p3=p3->next;
	p2->next=p1;
	
	first->next=p2;
	first=p2;
	}
int main()
{
	CL l,M;

l.insert(111,0);
l.insert(112,1);
l.insert(123,2);
l.insert(124,3);
l.insert(125,4);
l.insert(126,5);
l.insert(127,6);

l.display();

l.del(0);
l.del(4);
l.del(6);// size decrement after delete so index 6 became index 4 
l.display();
l.rev();
l.display();
}
