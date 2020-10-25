#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;
class node
{    public:
	 int data ;
	  node *next;
	};
   class Stack
	{
	node * top;
	public:
		Stack()
		{

			 top=NULL;
		}
		int index(int data);
		bool isEmpty();
		int getsize();
		void Push(int data);
		void Pop();
		int Peek();
		int merge(Stack A,Stack B);
		void display();

};

		int Stack::index(int data)
		{
		 int index=-1,i=0;
		node *cur;
		if(top==NULL)//  NULL is a macro;
			return index;
		 cur=top;
		  while(cur->data!=data&&cur!=NULL)
		  {
		  	cur=cur->next;
		  	i=i+1;
		  }
		  index=i;
		  return index;
	
		}
bool Stack::isEmpty()
{
	if(top==NULL)
		return true;
	return false;
}
int Stack::getsize()
{
	int sz=0;
	node *cur=top;
	while(cur)
	{
		sz++;
		cur=cur->next;
	}
	return sz;
}
void Stack::Push(int data)
{ node *cur=new node;
if(cur==NULL)
cout<<"Somthing went wrong";

cur->data=data;
cur->next=top;                         //  different approach  Move  right to left 
top=cur;

}
void Stack::Pop()
{
node *del=top;
top=del->next;
del->next=NULL;
delete del;
}
int Stack::Peek()
{
cout<<"\n top stack Value ="<<top->data<<endl;
}
void Stack::display()
{
	node *cur=top;

	while(cur)
	{
		cout<<cur->data;
		cur=cur->next;
	cout<<" ";
	}
cout<<endl;
}
int Stack::merge(Stack B,Stack C)
{node *cur;
cur=B.top;
while(cur->next!=NULL)
{
	cur=cur->next;
}
cur->next=C.top;
}


int main()
{
	Stack l,m;
	
	l.Push(22);
	l.Push(33);
	l.Push(44);
	l.Push(55);
	l.Push(66);
	l.Peek();
	l.Push(77);
	l.Push(88);
	l.Push(99);

	l.display();
l.Pop();

	l.display();
 
	m.Push(333);
	m.Push(444);
	m.Push(556);
	m.Push(666);
	m.Push(777);
    m.Push(888);
	m.Push(999);
	m.display();

l.merge(l,m);
l.display();


	return 0;
}
