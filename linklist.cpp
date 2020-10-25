#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;
class node
{ public:
	int A ;
		node *next;
	};
	class LL
	{
	node *first;
	public:
		LL()
		{
			first=NULL;
			 
		}
		int rev();
		int index(int a);
		bool isEmpty();
		int getsize();
		void insert(int a,int index);
		void del(int index);
		int merge(LL A,LL B);
		void display();
		int Middle_Node();
		int Middle_EVEN_ODD_Node();
};

		int LL::index(int a)
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
bool LL::isEmpty()
{
	if(first==NULL)
		return true;
	return false;
}
int LL::getsize()
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
void LL::insert(int a,int index)
{
	if(index<0 ||index>getsize())
	{
		cout<<"ERROR";
		return;
	}
	node *cur=new node;
	node *prev;
	cur->A=a;
	if(index==0)
	{
		cur->next=NULL;
		first=cur;
	}
	else
	{
		prev=first;
		for(int i=0;i<index-1;i++)
		{
			prev=prev->next;
		}
		prev->next=cur;
	    cur->next=NULL;
	}
}
void LL::del(int index)
{
	if(index<0 ||index>=getsize())
	{
		cout<<"ERROR";
		return;
	}
	node *cur;
	node *prev;
	node *del;
	if(index==0)
	{
		del=first;
		first=del->next;  //first = NULL
		del->next=NULL;
		delete del;
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

void LL::display()
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
int LL::merge(LL B,LL C)
{node *cur;
cur=B.first;
while(cur->next!=NULL)
{
	cur=cur->next;
}
cur->next=C.first;
}
///////////////////////////////////////
int LL::Middle_Node()
{ node *slow=first;
 node *fast=first;
if(slow == NULL)
return 0;
while(fast->next->next!=NULL && fast->next!=NULL )
  {	
    fast = fast -> next -> next;
    slow = slow -> next;
  }
cout<<"\n\nMiddle Node = "<<slow->A;
}

int LL::Middle_EVEN_ODD_Node()
{ node *temp=first;
 if(temp == NULL)
return 0;
int count=0;
while(temp!=NULL )
  {	
    temp=temp-> next;
    ++count;
  }
cout<<"\n\nEVEN Middle Node = "<<count/2;

cout<<"\n\nODD Middle Node = "<<(count/2) +1;

}
int LL::rev()
{
	node*cur,*p1,*p2,*p3;
	cur=first;
	if(cur->next==NULL)
	return -1;
	p1=cur;
	p2=p1->next;
	p3=p2->next;
	p1->next=NULL;
	p2->next=p1;
	while(p3!=NULL)//different ---- p3->next==NULL
	{ p1=p2;
	p2=p3;
	p3=p3->next;
	p2->next=p1;
	}
	first=p2;
		
	}
int main()
{
	LL l,m;
	
	l.insert(22,0);
	l.insert(33,1);
	l.insert(44,2);
	l.insert(55,3);
	l.insert(66,4);
	l.insert(77,5);
	l.insert(88,6);
	l.insert(99,7);
	//	l.del(7);
//cout<<l.isEmpty()<<endl;
//cout<<l.getsize()<<endl;
	l.display();
	l.Middle_Node();
	m.insert(222,0);
	m.insert(333,1);
	m.insert(444,2);
	m.insert(555,3);
	m.insert(666,4);
	m.insert(777,5);
m.insert(888,6);
	m.insert(999,7);
	m.display();
//	cout<<"\n"<<l.index(66);
//l.isEmpty();
l.merge(l,m);
l.display();
l.rev();
l.display();
	l.Middle_Node();
	l.Middle_EVEN_ODD_Node();	
	return 0;
}
