#include <iostream> 
using namespace std; 
void heapify(int arr[], int n, int i) 
{ 
	int largest = i; // Initialize largest as root 
	int l = 2 * (i+1) - 1;        // Index of its left child 
	int r = 2 * (i + 1);             // Index of its right child 
	
	// If left child is larger than root 
	if (l < n && arr[l] > arr[largest]) 
		largest = l; 

	// If right child is larger than largest so far 
	if (r < n && arr[r] > arr[largest]) 
		largest = r; 

	// If largest is not root 
	if (largest != i) { 
		swap(arr[i], arr[largest]); 

		// Recursively heapify the affected sub-tree 
		heapify(arr, n, largest); 
	} 
} 

// Function to build a Max-Heap from the given array 
void buildHeap(int arr[], int n)                // -----   O(N)
{ 
	// Index of last non-leaf node 
	int startIdx = (n / 2) - 1; 

	// Perform reverse level order traversal  from last non-leaf node and heapify each node 
	for (int i = startIdx; i >= 0; i--) 
	{ 
		heapify(arr, n, i); 
	} 

// ------ Note: there is no Deletion OR  Swaping --- Root Node  one by one....
           // There is No sorting Method here........
              //----------------------//
               //----------------------//
                //----------------------//
                 //----------------------//

} 
//////////////////////////////////////////////////////////////////
void Delete(int arr[],int &n,int D )
{
	for(int i=0;i<n;i++)
	{
if(D==arr[i])	
{
arr[i]=arr[n-1];
n=n-1;         // array size reduce
buildHeap(arr,  n);     
break;
}
}
}

void Insert(int arr[],int &n,int I )
{ 
arr[n]=I;
n=n+1; // array size increase 
buildHeap(arr, n);   
}

/////////////////////////////////////////////////////////////////////////////////////
void printHeap(int arr[], int n) 
{ 
	cout << "Array representation of Heap is:\n"; 

	for (int i = 0; i < n; ++i) 
		cout << arr[i] << " "; 
	cout << "\n"; 
} 

// Driver Code 
int main() 
{ 
	// Binary Tree Representation 
	// of input array 
	//         1 
	//		 /	 \ 
	//     3	  5 
	//	 / \	 / \ 
	// 4	 6 13 10 
	// / \ / \ 
	// 9 8 15 17 
	int arr[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 }; 

	int n = sizeof(arr) / sizeof(arr[0]); 
	buildHeap(arr, n); 
	printHeap(arr, n);
Delete(arr,n,13 );           ///---------
printHeap(arr, n); 
    Insert(arr,n,22);       ///-----------
	printHeap(arr, n); 
	// Final Heap: 
	//        17 
	//		 /	 \ 
	//    15	 13 
	//	 / \	 / \ 
//      9	 6  5  10 
//    / \ / \ 
//   4  8 3 1 

	return 0; 
} 

