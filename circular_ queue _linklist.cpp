#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;
class node
{ public:
	int A ;
		node *next;
};
	class QQ
	{
	node *front,*rear;
	public:
		QQ()
		{
			rear=NULL;
			front=NULL;
		}
		int rev();
		int index(int a);
		bool isEmpty();
		int getsize();
		void insert(int a);
		void del();
		int merge(QQ A,QQ B);
		void display();
};

		int QQ::index(int a)
		{
		 int index=-1,i=0;
		node *cur;
		if(front==NULL)//  NULL is a macro;
			return index;
		 cur=front;
		  while(cur->A!=a&&cur->next!=front)
		  {
		  	cur=cur->next;
		  	i=i+1;
		  }
		  index=i;
		  return index;
	
		}
bool QQ::isEmpty()
{
	if(front==NULL)
		return true;
	return false;
}
int QQ::getsize()
{
	int sz=0;
	node *cur=front;
	while(cur)
	{
		sz++;
		cur=cur->next;
	}
	return sz;
}
void QQ::insert(int a)
{	node *cur=new node;
	if(cur==NULL)
	{cout<<"ERROR FULL memory";
		return;
 }
	cur->A=a;
	if(front==NULL)
{	front=cur;
	rear=cur;
		cur->next=cur;
}
else
{
cur->next=rear->next;
		rear->next=cur;		
	rear=cur;
}

}
void QQ::del()
{ 
	if(front==NULL)
	{cout<<"\nqueue is empty";
		return;
		}
	node *temp;
	temp=front;
	int value=front->A;  //first = NULL
	front=temp->next;
	rear->next=front;
	temp->next=NULL;
	delete temp;
//	return value;
}

void QQ::display()
{node *cur=front;
	while(cur->next!=front)
	{
		cout<<cur->A;
		cur=cur->next;
	cout<<" ";
	}
	cout<<cur->A;
	cout<<endl;
}
int QQ::merge(QQ B,QQ C)
{node *cur;
cur=B.front;
while(cur->next!=NULL)
{
	cur=cur->next;
}
cur->next=C.front;
}
int QQ::rev()
{
	node*cur,*p1,*p2,*p3;
	cur=front;
	if(cur->next==NULL)
	return -1;
	p1=cur;
	p2=p1->next;
	p3=p2->next;
	p2->next=p1;
	while(p3->next!=front)//different ---- p3->next==NULL
	{ p1=p2;
	p2=p3;
	p3=p3->next;
	p2->next=p1;
	} p1=p2;
	p2=p3;
	p3=p3->next;
	p2->next=p1;
	front->next=p2;
	front=p2;
		
	}
int main()
{
	QQ l,m;
	
	l.insert(22);
	l.insert(33);
	l.insert(44);
	l.insert(55);
	l.insert(66);
	l.insert(77);
	l.insert(88);
l.display();
	l.del();
	l.del();
	l.display();
	l.insert(1);
	l.insert(2);
	l.insert(3);
	l.insert(4);
l.display();
l.rev();
l.display();
	return 0;
}
