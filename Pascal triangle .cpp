#include <iostream>
using namespace std;
 /*
int main()
{
    int rows;

    cout << "Enter number of rows: ";
    cin >> rows;

    for(int i = 1; i <= rows; ++i)                             // For reverse   for(int i = rows; i >=1; i--)      
    { 
	
	     for(int j = 1; j <=rows-i; ++j)
            cout << " ";
        
        for(int j = 1; j <= i; ++j)
            cout << "*";
        
        for(int j = 1; j <i; ++j)
            cout << "*";

    cout << "\n";
    }
    return 0;
}
 
*/

/*
int main()
{
    char input, alphabet = 'A';

    cout << "Enter the uppercase character you want to print in the last row: ";
    cin >> input;

    for(int i = 1; i <= (input-'A'+1); ++i)
    {
        for(int j = 1; j <= i; ++j)
        {
            cout << alphabet << " ";
        }
        ++alphabet;

        cout << endl;
    }
    return 0;
}

*/

/*
int main()
{
    int rows;

    cout << "Enter number of rows: ";
    cin >> rows;

    for(int i = rows; i >= 1; --i)
    { 
	
	 for(int j = 1; j <=rows-i; ++j)
        {
            cout << " ";
        }
        
        for(int j = 1; j <= i; ++j)
        {
            cout << "* ";
        }
        cout << "\n";
    }
    return 0;
}
*/


int main()
{
    int rows;

    cout << "Enter number of rows: ";
    cin >> rows;

    for(int i = 0; i <rows; i++)
    { 
	
	 for(int j = 0; j <rows-i; ++j)
        {
            cout << " ";
        }
        
        for(int j = 0; j <=i; ++j)
        {
            cout << "* ";
        }
        cout << "\n";
    }
    return 0;
}




/*
int main()
{
    char input, alphabet = 'A';

    cout << "Enter the uppercase character you want to print in the last row: ";
    cin >> input;

    for(int i = 1; i <= (input-'A'+1); ++i)
    {
        for(int j = 1; j <= i; ++j)
        {
            cout << alphabet << " ";
        }
        ++alphabet;

        cout << endl;
    }
    return 0;
}

*/

/*
int main()
{
    int rows;

    cout << "Enter number of rows: ";
    cin >> rows;

    for(int i = rows; i >= 1; --i)
    { 
	
	 for(int j = 1; j <=rows-i; ++j)
        {
            cout << " ";
        }
        
        for(int j = 1; j <= i; ++j)
        {
            cout << "* ";
        }
        cout << "\n";
    }
    return 0;
}
*/

/*
int main()
{
    int rows;

    cout << "Enter number of rows: ";
    cin >> rows;
    int C=1;

    for(int i = 1; i <=rows; i++)
    { 
	
	    for(int j = 1; j <=rows-i; ++j)
        {
            cout << " ";
        }
        
        for(int j = 1; j <= i; ++j)
        { 
            cout <<" "<< C<<" ";  C=C+2;
        }
        cout << "\n";
       
    }
    return 0;
}
*/
