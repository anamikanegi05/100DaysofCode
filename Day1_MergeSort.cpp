#include <iostream>
using namespace std;

void merge(int arr[],int left,int mid,int right) {  //functions to arrange two half sorted array
	int i =left,k=0;
	int j = mid+1;
	int temp[right -left +1];                    //temp array to store merge values
	
	while(i<=mid && j<=right) {          //merge two sorted subarrays
		if(arr[i]<=arr[j]) {
			temp[k++] =arr[i++];             
		}
		else {
			temp[k++]=arr[j++];
		}
	}
	while(i<=mid ) {            //copy remaining elements of the left subarray(if any)
		temp[k++] =arr[i++];
	}
	while( j<=right) {           //copy remaining elements of the right subarray(if any)
		temp[k++]=arr[j++];
	}
	for(int p=0; p<k; p++) {      //copy sorted element back to its original form
		arr[left+p] = temp[p];
	}
}

void mergeSort(int arr[],int left,int right) {         //functions to perform merge sort
	if(left>=right)           //Base case: if the array has 1 or 0 elements
		return;
		
	int mid = left+(right-left)/2;           //to find middle index
	
	mergeSort(arr,left,mid);            //recursively sort left and right subarray
	mergeSort(arr,mid+1,right);
	
	merge(arr,left,mid,right);           //merge two sorted array
}

int main()
{
	int arr[100];
	int n = sizeof(arr)/ sizeof(arr[0]);
	
	cout<<"Enter size: ";
	cin>>n;
	
	cout<<"Enter elements: ";
	for(int i=0; i<n; i++) {
		cin>>arr[i];
	}
	
	mergeSort(arr,0,n-1);      //call merge sort
	
	cout<<"Sorted Array: ";
	for(int i=0; i<n; i++) {
		cout<<arr[i]<<" ";
	}

	return 0;
}
