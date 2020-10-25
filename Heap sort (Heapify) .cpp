// C++ program for implementation of Heap Sort 
#include <iostream> 
using namespace std; 

// To heapify a subtree rooted with node i which is 
// an index in arr[]. n is size of heap 
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


void heapSort(int arr[], int n) 
{     // -----------1 step-----------O(N)
	// Build max-heap (rearrange array)  ------we just adjusting node top to bottom ----direction
	for (int i = n / 2 - 1; i >= 0; i--)     	// Last Non-leaf node index = (N/2 - 1)--------
		heapify(arr, n, i); 

       // -----------2 step-----------  O(Nlog(N))
	// Swaping Root Node with it last element of array-------------decrease array size by 1 ------------
	//Deleting Node one by one------------------to delete the root from Heap 
	for (int i = n - 1; i >= 0; i--) { 
		// Move current root to end 
		swap(arr[0], arr[i]); 

		// call max heapify on the reduced heap 
		heapify(arr, i, 0); 
	} 
} 

void printArray(int arr[], int n) 
{ 
	for (int i = 0; i < n; ++i) 
		cout << arr[i] << " "; 
	cout << "\n"; 
} 

int main() 
{ 
	int arr[] = { 12, 11, 13, 5, 6, 7 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	heapSort(arr, n); 

	cout << "Sorted array is \n"; 
	printArray(arr, n); 
} 

