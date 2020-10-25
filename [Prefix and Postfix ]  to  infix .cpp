#include <iostream> 
#include <stack> 
using namespace std; 

bool isOperator(char x) 
{ 
switch (x) 
{ 
	case '+': 
	case '-': 
	case '/': 
	case '*': 
	return true; 
} 
return false; 
} 
// Convert postfix to Infix expression 
string postToInfix(string postfix) 
{ 
stack<string> S; 

// length of expression 
int length = postfix.size(); 

// reading from  left    to right           
for (int i = 0; i < length; i++) 
{ 

	// check if symbol is operator 
	if (isOperator(postfix[i])) 
	{ 
	// pop two operands from stack 
	string op1 = S.top(); S.pop(); 
	string op2 = S.top(); S.pop(); 

	// concat the operands and operator 
	string temp = "(" + op2 + postfix[i] + op1 + ")";       		 // B operator A

	// Push string temp back to stack 
	S.push(temp); 
	} 
	// if symbol is an operand 
	else 
	{ 
		// push the operand to the stack 
		S.push(string(1,postfix[i]));               //Because (S) is String type Object ---------Not a Char type Object....
    }  									          // Create a string of size n and fill   the string with character x. ---- string s(int n, char x); 
} 

// Stack now contains the Infix expression 
return S.top(); 
} 

// Convert prefix to Infix expression 
string preToInfix(string prefix) 
{ 
stack<string> S; 

// length of expression 
int length = prefix.size(); 

// reading from right to left                 Resverse  order 
for (int i = length - 1; i >= 0; i--) 
{ 

	// check if symbol is operator 
	if (isOperator(prefix[i])) 
	{ 
	// pop two operands from stack 
	string op1 = S.top(); S.pop(); 
	string op2 = S.top(); S.pop(); 

	// concat the operands and operator 
	string temp = "(" + op1 + prefix[i] + op2 + ")"; 					// A operator B

	// Push string temp back to stack 
	S.push(temp); 
	} 
	// if symbol is an operand 
	else 
	{ 
		// push the operand to the stack 
		S.push(string(1,prefix[i]));               //Because (S) is String type Object ---------Not a Char type Object....
    }  									          // Create a string of size n and fill   the string with character x. ---- string s(int n, char x); 
} 

// Stack now contains the Infix expression 
return S.top(); 
} 

int main() 
{ 
string prefix = "*-A/BC-/AKL"; 
string postfix = "ABC/-AK/L-*";
cout << "\nPostfix to Infix : " << postToInfix(postfix); 
cout << "\nPrefix to Infix : " << preToInfix(prefix); 
return 0; 
} 

