//Collaborators: N/A
//Sources: Introduction to Algorithms: 3rd Edition. Radix Sorting pg 197-198. The radix sort requires a stable sorting algorithm
//in this case, we will use counting sort on pg. 195. Radix sort will sort the 2d array/vector with finding the least significant
//bit first, or digit in our case. 

#include <iostream>
#include <vector>

using namespace std;
void CountSort(vector<vector<int>>&Array, int a{
	vector<vector<int>> result(Array.size());
	int testArray[4];
	for (int i = 0; i < 4; i++) {
		testArray[i] = 0;
	}
	for (int i = 0; i < Array.size(); i++) {
		result[i] = vector<int>(10);
	}
	for (int i = 0; i < Array.size(); i++) {
		testArray[Array[i][a]]++;
	}
	for (int i = 1; i < 4; i++) {
		testArray[i] = testArray[i] + testArray[i - 1];
	}
	for (int i = Array.size() - 1; i >= 0; i--) {
		result[testArray[Array[i][a]] - 1] = Array[i];
		testArray[Array[i][a]]--;
	}
	for (int i = 0; i < Array.size(); i++) {
		Array[i] = result[i];
	}
}

void RadixSort(vector<vector<int>>&Array){
	for(int i = 9; i >=0; i--){
		CountSort(Array, i);
	}
}

int main(){
	int input;
	cin>>input;
	vector<vector<int>>Array(input, vector<int>(10));		//initialize the vector to be of max size 10, as seen in the sample output
	for(int i = 0; i < input; i++){
		for(int j = 0; j < 10; j++){
			cin >> Array[i][j];
		}
	}
	RadixSort(Array);
	for(int i = 0; < input; i++){
		cout << Array[i][j]<<";";
	}
	cout<<endl;
}