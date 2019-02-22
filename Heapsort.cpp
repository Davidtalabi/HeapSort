//Heapsort by David Talabi, Created Februrary 21, 2019

#include<iostream>
using namespace std;

void MaxHeapify(int A[], int n, int i) //heapify function	
{
	int left = 2*i + 1; //Left child
	int right = 2*i + 2; //Right child
	int max = i; //Making max equal to parent
	
	
	if(left < n && A[left] > A[max]) //When left child is greater than the parent
		max = left;
	if(right<n && A[right] > A[max]) //When right child is greater than either the parent or left child, whichever one is greater
		max = right;
	if(max!=i) //When the maximum is not the parent, then some swapping needs to be done! Keep doing this until the max is the parent
	{
		int temp = A[i]; //swapping A[i] with A[max], Temp variable used later to swap max and i
		A[i] = A[max];
		A[max] = temp;
		MaxHeapify(A,n,max); //Recursively calling MaxHeapify function made earlier
	}
}

void heapSort(int A[], int n) //heapsort function
{
	int temp; //Creating temp variable so that we can swap later on
	for(int i = n/2 - 1; i>=0; i--) //Creating a max heap
		MaxHeapify(A,n,i);
		
	for(int i=n-1; i>=0; i--)
	{
			temp = A[0];
			A[0] = A[i];
			A[i] = temp;
			MaxHeapify(A,i,0); //Recursively calling MaxHeapify function made earlier
	}
}

void displayarray(int A[], int n) //function to display array elements, will be recursively called in main function
{
	for(int i=0; i<n; i++)
		cout << A[i] << ";"; //displaying the array, the semi colons are so that it shows a semi colon after every number that is printed
}


int main() //Main function where we recursively call the functions made earlier so that we have an output and the user also inputs the array size and elements
{

int n; //Array size	
cin >> n; //User inputs array size
int A[n]; //Initializing array with n elements that user inputs

for(int i=0; i<n; i++)
	cin >> A[i]; //user inputs array elements

	heapSort(A,n); //recursively calling heapsort function made earlier to sort the array
	displayarray(A,n); //recursively calling display array function to display the final sorted array
	
return 0;
}
