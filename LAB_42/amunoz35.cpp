//Collaborators: N/A
//Sources: Introduction to Algorithms; 3rd Edition. Quick Sort Algorithm. An efficient algorithm that runs
//in O(nlogn) time using divide and conquer. It takes the array and splits it into sub arrays and compares the
//values using a pivot value
#include <iostream>
#include <time.h>
#include <stdio.h>
using namespace std;

int Partition(int A[], int p, int r){
	int i = p-1;
	int randy = p + (rand() % (r - p));
	int x = A[randy];
	

	int swap = A[r];
	A[r] = A[randy];
	A[randy] = swap;

	for(int j = p; j < r; j++){
		if(A[j] <= x){
			i++;
			swap = A[i];
			A[i] = A[j];
			A[j] = swap;
		}
	}
	swap = A[i + 1];
	A[i+1] = A[r];
	A[r] = swap;
	return i+1;
}

void quickSort(int A[], int p, int r){
	if(p < r){
		int q = Partition(A, p, r);
		quickSort(A, p, q-1);
		quickSort(A, q+1,r);
	}
}

int main(){
	srand(time(0));
	int size;
	cin >> size;
	int A[size];
	for(int i = 0; i < size; i++){
		cin >> A[i];
	}
	quickSort(A, 0, size-1);
	for(int i = 0; i < size; i++){
		cout<<A[i]<<";";
	}
	return 0;
}
