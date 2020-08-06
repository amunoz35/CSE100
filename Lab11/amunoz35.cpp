//Collaborators: N/A
//Sources: Introduction to Algorithms: 3rd Edition. pg. 428 - 434. Huffman's algorithm can check the frequency 
//of each characters listed in a string. By using nodes in a set, lower frequency nodes will be moved lower, and higher 
//frequency nodes move up. As seen in the table provided, symbols 'A' through 'F' can have any set frequency and must be
//sorted in increasing frequency.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Initialize all character strings to be empty
char arr[] = {'A', 'B', 'C', 'D', 'E', 'F'};
string A = "";
string B = "";
string C = "";
string D = "";
string E = "";
string F = "";

struct Node{
	char Nchar;
	int frequency;
	Node* Left;
	Node* Right;					
	Node(char Nchar, int frequency){
		this->Nchar = Nchar;
		this->frequency = frequency;
		Left = 0;
		Right = 0;
	}
	~Node(){}
};
struct compare{
	bool operator()(Node* left, Node* right){
		return(left->frequency > right->frequency);
	}
};
void print(struct Node* root, string test){
	if(root == 0)
		return;
	if(root->Nchar != 'G'){
		if(root->Nchar == 'A')
			A += "A:" + test;
		else if(root->Nchar == 'B')
			B += "B:" + test;
		else if(root->Nchar == 'C')
			C += "C:" + test;
		else if(root->Nchar == 'D')
			D += "D:" + test;
		else if(root->Nchar == 'E')
			E += "E:" + test;
		else if(root->Nchar == 'F')
			F += "F:" + test;
	}
	print(root->Left, test + "0");
	print(root->Right, test + "1");	
}
void Huffman(char Nchar[], int frequency[]){
	struct Node *Left, *Right, *top;
	priority_queue <Node*, vector<Node*>, compare> Heap;
	for(int i = 0; i < 6; i++){
		Heap.push(new Node(Nchar[i], frequency[i]));
	}
	while(Heap.size() != 1){
		Left = Heap.top();
		Heap.pop();
		Right = Heap.top();
		Heap.pop();
		top = new Node('G', Left->frequency + Right->frequency);
		top->Left = Left;
		top->Right = Right;
		Heap.push(top);
	}
	print(Heap.top(), "");
}
int main(){
	int frequency[6];
	for(int i = 0; i < 6; i++){
		cin >> frequency[i];
	}
	Huffman(arr, frequency);
	cout << A << endl;
	cout << B << endl;
	cout << C << endl;
	cout << D << endl;
	cout << E << endl;
	cout << F << endl;
}