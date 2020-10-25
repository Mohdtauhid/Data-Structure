#include <bits/stdc++.h> 
using namespace std; 

bool isOperator(char c) 
{ 
	return (!isalpha(c) && !isdigit(c)); 
} 

int getPriority(char C) 
{ 
	if (C == '-' || C == '+') 
		return 1; 
	else if (C == '*' || C == '/') 
		return 2; 
	else if (C == '^') 
		return 3; 
	return 0; 
} 

string infixToPostfix(string infix) 
{ 
	infix = '(' + infix + ')';              //    (   (a-b/c)*(a/k-l)   )
	int l = infix.size(); 
	stack<char> C; 
	string output; 

	for (int i = 0; i < l; i++) 
	{ 

		// If the scanned character is an operand, add it to output. 
		if (isalpha(infix[i]) || isdigit(infix[i])) 
			output += infix[i]; 

		// If the scanned character is an  ‘(‘, push it to the stack. 
		else if (infix[i] == '(') 
			C.push('('); 

		// If the scanned character is an  ‘)’, pop and output from the stack  until an ‘(‘ is encountered. 
		else if (infix[i] == ')') 
		{ 

			while (C.top() != '(') 
			{ 
				output += C.top(); 
				C.pop(); 
			} 

			// Remove '(' from the stack 
			C.pop(); 
		} 

		// Operator found 
		else 
		{ 
			
			if (isOperator(C.top())) 
			{ 
				while (getPriority(infix[i]) <= getPriority(C.top())) 
				{ 
					output += C.top(); 
					C.pop(); 
				} 

				// Push current Operator on stack 
				C.push(infix[i]); 
			} 
		} 
	} 
	return output; 
} 

string infixToPrefix(string infix) 
{ 
	/* Reverse String  Replace ( with ) and vice versa  Get Postfix  Reverse Postfix * */
	int l = infix.size(); 

	// Reverse infix 
	reverse(infix.begin(), infix.end());                 //      ) l-k/a(*)c/b-a (
 
	// Replace ( with ) and vice versa 
	for (int i = 0; i < l; i++)                        //       (l-k/a) * (c/b-a)
	{ 

		if (infix[i] == '(') 
		{ 
			infix[i] = ')'; 
			i++; 
		} 
		else if (infix[i] == ')') 
		{ 
			infix[i] = '('; 
			i++; 
		} 
	} 

	string prefix = infixToPostfix(infix); 

	// Reverse postfix 
	reverse(prefix.begin(), prefix.end()); 

	return prefix; 
} 

// Driver code 
int main() 
{ 
	string s = "(a-b/c)*(a/k-l)"; 

	cout << infixToPostfix(s) << endl;
	cout << infixToPrefix(s) << endl; 
	 
	return 0; 
} 

