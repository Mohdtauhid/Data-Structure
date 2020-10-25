#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;
class node
{ public:
char A ;
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
		void insert(char a);
		char del();
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
		  while(cur->A!=a&&cur!=NULL)
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
void QQ::insert(char a)
{	node *cur=new node;
	if(cur==NULL)
	{cout<<"ERROR FULL memory";
		return;
 }
	cur->A=a;
	
		cur->next=NULL;
		if(front==NULL)
		{
 		front=cur;
		rear=cur;
    
    	}
    	else
    	{
		rear->next=cur;
		rear=cur;
         }
}
char QQ::del()
{ 
	if(front==NULL)
	{
	cout<<"\nqueue is empty";
	return 0;
	}

	node *temp;
	temp=front;
char value=front->A;  //first = NULL
	front=temp->next;
	temp->next=NULL;
	delete temp;
return value;
}

void QQ::display()
{node *cur=front;
	while(cur)
	{
		cout<<cur->A;
		cur=cur->next;
	cout<<" ";
	}
	cout<<endl;
}
int QQ::merge(QQ B,QQ C)
{ 
B.rear->next=C.front;
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
	p1->next=NULL;
	p2->next=p1;
	while(p3!=NULL)//different ---- p3->next==NULL
	{ p1=p2;
	p2=p3;
	p3=p3->next;
	p2->next=p1;
	}
	front=p2;
		
	}
	
int main()
{
	QQ l,m;
	
	l.insert('A');
	l.insert('B');
	l.insert('C');
	l.insert('D');
	l.insert('E');
	l.insert('F');
	l.insert('G');
	l.display();
	l.del();
l.display();
l.rev();
l.display();
	l.del();
l.display();
l.rev();
l.display();
	return 0;
}



