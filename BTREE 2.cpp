#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std; 
class Node
{	
public:
char data;
Node *left,*right;		
};

class BTREE
{
public:
int size;	
Node *root;
		BTREE()
		{	
		root=NULL;
		
		}
int height(Node *temp)
{
if(temp==NULL)
return 0;
if(height(temp->left)>height(temp->right))
return height(temp->left)+1;
else 
return height(temp->right)+1;
}

int build(Node *cur,Node *P)	
{	char A,B;
if(cur==NULL)
{
cur=new Node;
cout<<"\nENTER ROOT Node";

}
else
{
if(cur==P->left)
cout<<"\nENTER LEFT CHILD OF "<<P->data;
else
cout<<"\nENTER RIGHT CHILD OF "<<P->data;
}
cin>>cur->data;
if(root==NULL)
{
root=cur;
}
cout<<"\nDOES IF "<<cur->data<<" HAS LEFT CHILD (Y|N)";
cin>>A;
if(A=='Y')
{
cur->left=new Node;
P=cur;
cur=P->left;
build(cur,P);
cur=P;
}
else
{cur->left=NULL;
}
cout<<"\nDOES IF "<<cur->data<<" HAS RIGHT CHILD (Y|N)";
cin>>B;
if(B=='Y')
{ 
cur->right=new Node;
P=cur;
cur=P->right;
build(cur,P);
}
else
{
cur->right=NULL;
}
}
int level_order(Node *cur)
{ 
int h=height(cur);   // 3
for(int i=1;i<=h;i++)
printlevel(cur,i);
}
void printlevel(Node *cur,int level)
{
	if(cur==NULL)
	return ;
	if(level==1)
	cout<<" "<<cur->data;
	else 
	{
	printlevel(cur->left,level-1);
	printlevel(cur->right,level-1);
}
}
int Delete(char key,Node *T)
{
	Node *temp=search(key,T);
	if(temp==NULL)
	cout<<"\n\n KEY NOT EXIST IN TREE";
	if(temp->left!=NULL or temp->right!=NULL)
	cout<<"\n\nIT IS NOT A LEAF";
	else
	 delete temp;

}
Node *search(char key,Node *cur)
{static  Node *temp;
	if(cur==NULL)
	cout<<"\n\n----TREE IS EMPTY---";
	if(cur->data==key)
{
	cout<<"\n\nELEMENT "<<key<<" FOUND IN TREE ";
 temp=cur;
}
	if(cur->left!=NULL)
	search(key,cur->left);
	
	if(cur->right!=NULL)
	search(key,cur->right);
return temp;
}
int insert(char key ,char item ,Node *T)
{ char A; 
 Node *temp=search(key,T);

if(temp->left!=NULL and temp->right!=NULL)
cout<<"\n\nERROR----LEFT AND RIGHT Node ARE NOT EMPTY-----";

if(temp->left==NULL and temp->right==NULL)
{
cout<<"\n\nDO YOU WANT NEW item as LEFT child(Y|N)";
cin>>A;
if(A=='Y')
{
cout<<"\n\nNode ( "<<item<<" ) HAVE ADDED TO  LEFT SIDE OF PARENT Node ( "<<key<<" )";
temp->left=new Node;
temp=temp->left;
temp->data=item;
temp->left=NULL;
temp->right=NULL;
}
else
{ 
cout<<"\n\nNode ( "<<item<<" ) HAVE ADDED TO  RIGHT SIDE OF PARENT Node ( "<<key<<" )";
temp->right=new Node;
temp=temp->right;
temp->data=item;
temp->left=NULL;
temp->right=NULL;
}
}
else if(temp->left==NULL)
{
cout<<"\n\nNode ( "<<item<<" ) HAVE ADDED TO  LEFT SIDE OF PARENT Node ( "<<key<<" )";
temp->left=new Node;
temp=temp->left;
temp->data=item;
temp->left=NULL;
temp->right=NULL;
}
else
{
cout<<"\n\nNode ( "<<item<<" ) HAVE ADDED TO  RIGHT SIDE OF PARENT Node ( "<<key<<" )";
temp->right=new Node;
temp=temp->right;
temp->data=item;
temp->left=NULL;
temp->right=NULL;
}
}
int in_order(Node *cur)
{ 
if(cur->left!=NULL)
in_order(cur->left);
if(cur!=NULL)
cout<<" "<<cur->data;
if(cur->right!=NULL)
in_order(cur->right);
}
int pre_order(Node *cur)
{ 
if(cur!=NULL)
cout<<" "<<cur->data;
if(cur->left!=NULL)
pre_order(cur->left);
if(cur->right!=NULL)
pre_order(cur->right);
}
int post_order(Node *cur)
{ 
if(cur->left!=NULL)
post_order(cur->left);
if(cur->right!=NULL)
post_order(cur->right);
if(cur!=NULL)
cout<<" "<<cur->data;

}
};
int main()
{
BTREE obj;
obj.build(NULL,NULL);


cout<<"\n\n\n\n------------INORDER----------\n";
obj.in_order(obj.root);

cout<<"\n\n\n\n------------PREORDER----------\n";
obj.pre_order(obj.root);
cout<<"\n\n\n\n------------POSTORDER----------\n";
obj.post_order(obj.root);
/*
//cout<<"\n\n\n\n------------HEIGHT OF TREE----------\n";
//cout<<endl<<obj.height(obj.root);
//cout<<"\n\n\n";
//obj.search('E',obj.root);
*/
cout<<"\n\n\n";
obj.insert('E','Z',obj.root);

//cout<<"\n\n\n\n------------POSTORDER----------\n";
//obj.pre_order(obj.root);
//cout<<"\n\n\n";
//obj.Delete('Z',obj.root);

cout<<"\n\n\n\n------------POSTORDER----------\n";
obj.pre_order(obj.root);
cout<<"\n\n\n\n------------LEVEL-ORDER----------\n";
obj.level_order(obj.root);
}
