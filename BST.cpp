#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std; 
class Node
{	
public:
int data;
Node *left,*right;
int freq;
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
int getroot(Node *cur)
{
	cout<<"\nROOT OF TREE = "<<cur->data;
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
	{
		cout<<" "<<cur->data;
//cout<<"=== "<<cur->freq<<endl;
}
	else 
	{
	printlevel(cur->left,level-1);
	printlevel(cur->right,level-1);
}
}
Node *deleteNode(Node *root,int key)
{  
    if (root == NULL) 
	return root; 
  
    if (key < root->data) 
        root->left = deleteNode(root->left, key); 
    else if (key > root->data) 
        root->right = deleteNode(root->right, key); 

 

else 
{ 
        // node with only one child -----OR------ no child 
        if (root->left == NULL) 
        { 
            Node *temp = root->right; 
            delete root; 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            Node *temp = root->left; 
               delete root; 
            return temp;
           } 
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree)   
Node * temp = minValueNode(root->right); 
  
        // Copy the inorder successor's content to this node 
        root->data = temp->data;
        
        // Delete the inorder successor 
        root->right = deleteNode(root->right, temp->data); 
    } 
    return root; 
} 
Node *minValueNode(Node *temp) 
{ 
Node *current = temp; 
  
    /* loop down to find the leftmost leaf */
    while (current->left != NULL) 
        current = current->left; 
    return current; 
}
Node *search(int key,Node *cur)
{static  Node *temp;
	if(cur==NULL)
	{
	cout<<"\n\n----TREE IS EMPTY---";
	return cur;
	}if(cur->data==key)
{
	cout<<"\n\nELEMENT "<<key<<" FOUND IN TREE ";
 temp=cur;
 
}
if(cur->data>key)
{
	if(cur->left!=NULL)
	search(key,cur->left);
}
if(cur->data<key)
{ 
	if(cur->right!=NULL)
	search(key,cur->right);
}
return temp;
}
Node *insert(Node *temp,int item )
{  if (temp == NULL) 
	{
	 temp = new Node;     //TEMP->LEFT=NEW NODE     
    temp->data = item; 
    temp->freq=1;
    temp->left = temp->right = NULL; 
    return temp; 
}  
  if (item < temp->data) 
    temp->left  = insert(temp->left, item); 

	else if (item > temp->data) 
        temp->right = insert(temp->right, item);    
else if(item==temp->data)
{ 
	(temp->freq)++;
}
	return temp; 
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
cout<<"\n\n\n";
obj.root=obj.insert(obj.root,20);
obj.insert(obj.root,10);
obj.insert(obj.root,11);
obj.insert(obj.root,5);
obj.insert(obj.root,16);
obj.insert(obj.root,14);
obj.insert(obj.root,13);
obj.insert(obj.root,15);

cout<<"\n\n\n\n------------LEVEL-ORDER----------\n";
obj.level_order(obj.root);

cout<<"\n\n\n\n------------HEIGHT OF TREE----------\n";
cout<<endl<<obj.height(obj.root);
obj.root=obj.deleteNode(obj.root,16);
cout<<"\n\n\n\n------------INORDER----------\n";
obj.in_order(obj.root);

///cout<<"\n\n\n\n------------PREORDER----------\n";
//obj.pre_order(obj.root);
//cout<<"\n\n\n\n------------POSTORDER----------\n";
//obj.post_order(obj.root);
//cout<<"\n\n\n";
//obj.search(85,obj.root);

//cout<<"\n\n\n\n------------POSTORDER----------\n";
//obj.pre_order(obj.root);
//cout<<"\n\n\n\n------------POSTORDER----------\n";
//obj.pre_order(obj.root);

cout<<"\n\n\n\n------------LEVEL-ORDER----------\n";
obj.level_order(obj.root);
obj.getroot(obj.root);
}


