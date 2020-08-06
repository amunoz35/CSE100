//Collaborators: N/A
//Sources: Introduction to Algorithms: 3rd Edition. Radix Sort: The Radix sorting algorithm relies on using a stable alg-
//orithm. The radix sort is similar to a counting sort, except it should compare the places of each value. It compares
//the ones place with the other ones, then the tens, and continues till completed

#include <iostream>
#include <vector>

//create a global variable
#define INTEGER 4
#define V_LENGTH 10

using namespace std;

void CountingSort(vector<vector<int>> &A, int d) {
	vector<vector<int>> result(A.size());
	int C[INTEGER];
	for (int i = 0; i < INTEGER; i++) {
		C[i] = 0;
	}
	for (int i = 0; i < A.size(); i++) {
		result[i] = vector<int>(V_LENGTH);
	}
	for (int i = 0; i < A.size(); i++) {
		C[A[i][d]]++;
	}
	for (int i = 1; i < 4; i++) {
		C[i] = C[i] + C[i - 1];
	}
	for (int i = A.size() - 1; i >= 0; i--) {
		result[C[A[i][d]] - 1] = A[i];
		C[A[i][d]]--;
	}
	for (int i = 0; i < A.size(); i++) {
		A[i] = result[i];
	}
}

void RadixSort(vector<vector<int>> &A) {
	for (int i = 9; i >= 0; i--) {
		CountingSort(A, i);
	}
}

int main() {
	int size;
	cin >> size;
	vector<vector<int>> A(size, vector<int>(V_LENGTH));
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < V_LENGTH; j++) {
			cin >> A[i][j];
		}
	}
	RadixSort(A);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < V_LENGTH; j++) {
			cout << A[i][j] << ";";
		}
		cout << endl;
	}
}