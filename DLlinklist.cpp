#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;
class node
{ public:
	int A ;
		node *next;
	node *prev;
};
class DLL
{
node *first;
	public:
		DLL()
		{
		first=NULL;
		}
		int rev();
		int index(int a);
		bool isEmpty();
		int getsize();
		void insert(int a,int index);
		void del(int index);
		int merge(DLL B,DLL C);
		void display();
};

		int DLL::index(int a)
		{
		int index=-1,i=0;
		node *cur;
		if(first==NULL)//  NULL is a macro;
		return index;
		 cur=first;
		  while(cur->A!=a&&cur!=NULL)
		  {
		  	cur=cur->next;
		  	i=i+1;
		  }
		  index=i;
		  return index;
		}
bool DLL::isEmpty()
{
	if(first==NULL)
		return true;
	return false;
}
int DLL::getsize()
{
	int sz=0;
	node *cur=first;
	while(cur)
	{
		sz++;
		cur=cur->next;
	}
	return sz;
}
void DLL::insert(int a,int index)
{
	if(index<0 ||index>getsize())
	{
		cout<<"ERROR";
		return;
	}
	node *cur=new node;
	node *temp;
	cur->A=a;
	if(index==0)
	{
		cur->next=NULL;
		
		cur->prev=NULL;
		first=cur;
	}
	else
	{ 
		temp=first;
		for(int i=0;i<index-1;i++)
		{
			temp=temp->next;  
		
		} 
		cur->prev=temp;
		temp->next=cur;
		cur->next=NULL;
	}
}
void DLL::del(int index)
{if(index<0 ||index>getsize())
	{
		cout<<"ERROR";
		return;
	}
	node *temp,*del;
	if(index==0)
	{
		del=first;
first=del->next;
	del->next=NULL;
	del->prev=NULL;
		delete del;
		first->prev=NULL;
	}
	else
	{
		temp=first;
		for(int i=0;i<index-1;i++)
		{
			temp=temp->next;
		}
		del=temp->next;
		temp->next=del->next;
		
		if(del->next==NULL)
		{
		  del->prev=NULL;
		}
		else
		{
		del->prev=NULL;
		del->next->prev=temp;
	   }
}
		delete del;

}


void DLL::display()
{
	node *cur=first;

	while(cur)
	{
		cout<<cur->A;
		cur=cur->next;
	cout<<" ";
	}
cout<<endl;
}
int DLL::merge(DLL B,DLL C)
{node *cur;
cur=B.first;
while(cur->next!=NULL)
{
	cur=cur->next;
}
cur->next=C.first;
C.first->prev=cur;
}
int DLL::rev()
{
		node*cur,*p1,*p2,*p3;
	cur=first;
	if(cur->next==NULL)
	return -1;
		p1=cur;
	p2=p1->next;
	p3=p2->next;
	p1->next=NULL;
	p1->prev=p2;
	p2->next=p1;
	 
	while(p3!=NULL)//different ---- p3->next==NULL
	{ p1=p2;
	p2=p3;
	p3=p3->next;
	p2->next=p1;
p1->prev=p2;
	}
	first=p2;
	
	}
int main()
{
	DLL l,m;
	
	l.insert(22,0);
	l.insert(33,1);
	l.insert(44,2);
	l.insert(55,3);
	l.insert(66,4);
	l.insert(77,5);
	l.insert(88,6);
	l.insert(99,7);
	l.display();
	
	l.del(0);
	l.display();
	l.del(2);
	l.display();
	l.del(5);
	l.display();
	l.rev();
	l.display();
	l.del(2);
	l.display();
	l.rev();
	l.display();
	return 0;
}
