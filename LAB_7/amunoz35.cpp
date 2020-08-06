//Collaborators: Mark Mccullough
//Sources: Introduction to Algorithms 3rd Edition. Rod cutting presents a problem where one wants
//to determine maximum revenue by "cutting" and "selling" the rod pieces. If some P_n price is 
//is large enough for some size n, then it can be solved without cutting
#include <iostream>
#define MIN -2147483648;

using namespace std;

void Cut_Rod(int P[], int n){						//Use an array P[] for the prices and int n for size
	int V[n + 1];									//Use an array V[] for the values 
	int C[n + 1];									//Use an array C[] for the cuts that will be made
	V[0] = 0;										//Initialize to 0 at Value index 0

	for(int i = 1; i <= n; i++){
		int max = MIN;								//Use the smallest value and updates with the new max value
		for(int j = 0; j < i; j++){
			if(max < P[j] + V[i - j - 1]){
				max = P[j] + V[i - j - 1];
				C[i] = j + 1;		
			}
		}
		V[i] = max;									//Sets the new value to the maximum possible cost
	}
	cout << V[n] << endl;

	while(n > 0){									//Iterates through the cut array.
		cout << C[n] << " ";
		n = n - C[n];
	}
}

int main(){
	int size;
	cin >> size;
	int P[size];	
	for(int i = 0; i < size; i++){
		cin >> P[i];
	}
	Cut_Rod(P, size);
	cout << -1 << endl;
}