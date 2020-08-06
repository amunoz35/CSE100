//Collaborators: Mark Mccullough
//Sources: Introduction to Algorithms: 3rd Edition. Heap Sort Algorithm puts the date set on a binary tree.
//also known as a heap. The heap will have the largest value at the top of the tree and will swap the top 
//to the bottom until the heap is essentially sorted

#include <iostream>
#include <fstream>
using namespace std;

void swap(int A[], int x, int y){
	int check = A[x];
	A[x] = A[y];
	A[y] = check;
}

void maxHeapify(int A[], int size, int i){
	int L, R, largest;
	L = 2*i + 1;
	R = 2*i + 2;
	largest = i;
	if(L < size && A[L] > A[i]){
		largest = L;
	}
	if(R < size && A[R] > A[largest]){
		largest = R;
	}
	if(largest !=i){
		swap(A, i, largest);
		maxHeapify(A, size, largest);
	}
}

void buildMaxHeap(int A[], int size){
	for(int i = (size/2)-1; i >= 0; i--)
		maxHeapify(A, size, i);
}

void heapSort(int A[], int size){
	buildMaxHeap(A, size);
	for(int i = size - 1; i >= 0; i--){
		swap(A, i, 0);
		maxHeapify(A, i, 0);
	}
}

int main(){
	int size;
	cin>>size;
	int A[size];
	for(int i = 0; i < size; i++){
		cin>>A[i];
	}
	heapSort(A,size);
	for (int i = 0; i < size; i++){
		cout <<A[i]<< ";";
	}
}
