#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std; 
class BTREE
{
private:
char *a; int size,nn;

public:
BTREE(int b)
{ 	a=new char[int(pow(2,b)-1)];
	this->nn=b;
	for(int i=0; i<pow(2,b)-1; i++)
    a[i]='\0';
	}
	int	height(int b)
		{   size=b;
		   return size+1;
		}
int build(int i)
{   if(i==0)
	cout<<"\nENTER ROOT NODE";
	else if(i%2==1)
	cout<<"ENTER LEFT CHILD OF NODE  "<<a[(i-1)/2];
	else
	cout<<"ENTER RIGHT CHILD OF NODE   "<<a[(i-1)/2];
	cin>>a[i];
	char ans,ans1;
	cout<<"DOES  "<< a[i]  <<" HAS LEFT CHILD (Y/N)";
	cin>>ans;
	
	if(ans=='Y'&&((2*(i+1)-1)<pow(2,nn)-1))
	build(2*(i+1)-1);
	cout<<"DOES "<< a[i] <<" HAS RIGHT CHILD (Y/N)";
	cin>>ans1;
	if(ans1=='Y'&&2*(i+1)<pow(2,nn)-1)
	build(2*(i+1));
}
int Inorder(int i)
{ 
if((2*(i+1)-1)<(pow(2,nn)-1)&&a[2*(i+1)-1]!='\0')
Inorder(2*(i+1)-1);
if(a[i]!='\0')
cout<<a[i];
if((2*(i+1)<pow(2,nn)-1)&&a[2*(i+1)]!='\0')
Inorder(2*(i+1));
}

int PREorder(int i)
{  if(a[i]!='\0')
cout<<a[i];
if((2*(i+1)-1)<(pow(2,nn)-1)&&a[2*(i+1)-1]!='\0')
PREorder(2*(i+1)-1);
if((2*(i+1)<pow(2,nn)-1) and a[2*(i+1)]!='\0')
PREorder(2*(i+1));
}
int POSorder(int i)
{ 
if(((2*(i+1)-1)<(pow(2,nn)-1))&&a[2*(i+1)-1]!='\0')
POSorder(2*(i+1)-1);
if((2*(i+1)<pow(2,nn)-1)&&a[2*(i+1)]!='\0')
POSorder(2*(i+1));
if(a[i]!='\0')
cout<<a[i];
}

int level_order()
{  
if(a[0]=='\0')
return 0;
for(int i=0;i<pow(2,nn)-1;i++)
{
if(a[i]=='\0')
continue;
else
cout<<" "<<a[i];
}
}

int search(int i ,char key)
{  static int temp;
	if(a[0]=='\0')
	return -1;
	if(a[i]==key)
	{  temp=i;
}
if((2*(i+1)-1)<(pow(2,nn)-1)and(a[2*(i+1)-1]!='\0'))
search((2*(i+1)-1),key);
	if((2*(i+1))<(pow(2,nn)-1)and(a[2*(i+1)]!='\0'))
search(2*(i+1),key);
return temp;
}
int insert(char key, char item)
{ char ans;
	int i=search(0,key);
	if((2*(i+1))>((pow(2,nn)-1)))
cout<<"\n\n------ERROR NO SPACE-------";
if((a[2*(i+1)-1]!='\0')and(a[2*(i+1)]!='\0'))
cout<<"\n\nERROR---LEFT AND RIGHT NODE ARE NOT EMPTY-----";
if((a[2*(i+1)-1]=='\0')and(a[2*(i+1)]=='\0'))
{cout<<"\n\nDO YOU WANT NEW item as LEFT child(Y|N)";
cin>>ans;
if(ans=='Y')
a[2*(i+1)-1]=item;
else
a[2*(i+1)]=item;
}
else if(a[2*(i+1)-1]=='\0')
{
cout<<"\n\nNODE ( "<<item<<" ) HAVE ADDED TO  LEFT SIDE OF PARENT NODE ( "<<key<<" )";
a[2*(i+1)-1]=item;
}
else
{
cout<<"\n\nNODE ( "<<item<<" ) HAVE ADDED TO  RIGHT SIDE OF PARENT NODE ( "<<key<<" )";
a[2*(i+1)]=item;
}
}
int Delete(int key)
{	int i=search(0,key);
	if(i==-1)
	cout<<"\n\nKEY DOEST NOT EXIST";
if((2*(i+1)-1)<(pow(2,nn)-1) and ((a[2*(i+1)-1])!='\0') or ((a[2*(i+1)])!='\0'))	
cout<<"\n\n------IT IS NOT A LEAF-------";
else
{
cout<<"\n\nLEAF ( "<<a[i]<<" ) OF PARENT NODE ( "<<a[(i-1)/2]<<" ) IS DELETED ";
a[i]='\0';
}
}
};
int main()
{   int nn;
cout<<"\n\nENTER LEVEL OF TREE";
cin>>nn;
class BTREE obj(nn+1);
obj.build(0);
cout<<"\n\n\n\n------------INORDER----------\n";
obj.Inorder(0);
cout<<"\n\n\n\n------------POSTORDER----------\n";
obj.POSorder(0);
cout<<"\n\n\n\n------------PREORDER----------\n";
obj.PREorder(0);

cout<<"\n\n\n\n------------LEVEL---ORDER----------\n";

obj.level_order();
cout<<"\n\n\n\n------------HEIGHT----------\n";

cout<<endl<<obj.height(nn);



cout<<"\n\n\n\n------------INDEX OF NODE----------\n";
cout<<"\nINDEX 0F (F) == "<<obj.search(0,'F');
cout<<"\n\n\n";
/*
obj.insert('C','T');	
cout<<"\n\n";
cout<<"\n\n\n\n------------PREORDER----------\n";
obj.PREorder(0);
cout<<"\n\n\n";
obj.Delete('C');
cout<<"\n\n\n";
obj.Delete('T');
*/
}
