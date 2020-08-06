//Collaborators:N/A
//Sources: Introduction to Algorithms: 3rd edition. Hash Table with chaining. Using the given integers as keys, and the general
//structure that the first input as the size of the hash, and do the appropriate function dependent on the following letters:
//i’, ‘s’, ‘d’,‘o’, or ‘e’.
//Must also use hash function h(k) = k mod m
#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <iterator>

using namespace std;

class Hash_Table{
	list<int> hash_chain;
	public:
		Hash_Table(int key){
			hash_chain.push_front(key);
		}
		void push(int key){
			hash_chain.push_front(key);
		}
		int find(int key){
			list<int> :: iterator test;
			int i = 0;
			for(test = hash_chain.begin(); test != hash_chain.end(); test++){
				if(*test == key){
					return i;
				}
				i++;
			}
			return -1;
		}
		bool remove(int key){
			int position = find(key);
			if(position != -1){
				list<int> :: iterator test = hash_chain.begin();
				while(position > 0){
					test++;
					position--;
				}
				hash_chain.erase(test);
				return true;
			}
			return false;
		}

		void printChain(){
			list<int> :: iterator test;
			for(test = hash_chain.begin(); test != hash_chain.end(); test++){
				cout << *test << "->";
			}
		}
};
class HashTable{
	Hash_Table **hash_table;
	int HashSize = 0;
	public:
		HashTable(int size){			
			hash_table = new Hash_Table*[size];
			HashSize = size;		
			for(int i = 0; i < size; i++){
				hash_table[i] = NULL;
			}
		}
		~HashTable(){		
			for(int i = 0; i < HashSize; i++){	
				if(hash_table[i]){
					delete hash_table[i];
				}
				delete hash_table;
			}
		}
		string search(int key){
			int hash = key % HashSize;		
			if(hash_table[hash]){
				if(hash_table[hash]->find(key) != -1){
					return to_string(hash) + "," + to_string(hash_table[hash]->find(key));
				}
			}
			return "";
		}
		void Insert(int key){
			int hash = key % HashSize;
			if(hash_table[hash]){
				hash_table[hash]->push(key);
			}else{
				hash_table[hash] = new Hash_Table(key);
			}
		}
		bool remove(int key){
			string index = search(key);	
			if(index != ""){
				istringstream istring(index);
				string test;
				getline(istring, test, ',');
				int index = stoi(test);

				if(hash_table[index]->remove(key)){
					return true;
				}	
			}
			return false;
		}
		void print(){
			for(int i = 0; i < HashSize; i++){
				cout << i << ":";
				if(hash_table[i]){
					hash_table[i]->printChain();
				}
				cout << ";" << endl;
			}
		}
};
int main(){
	int size;
	cin >> size;
	HashTable *hash_table = new HashTable(size);
	string input;
	cin >> input;
	while(input[0] != 'e'){
		if(input[0] == 'i'){
			hash_table->Insert(stoi(input.substr(1)));
		}
		if(input[0] == 's'){
			int key = stoi(input.substr(1));
			string index = hash_table->search(key);
			if(index != ""){
				cout << key << ":FOUND_AT" << index << ";" << endl;
			}else{
				cout << key << ":NOT_FOUND;" << endl;
			}
		}
		if(input[0] == 'd'){
			int key = stoi(input.substr(1));
			if(hash_table->remove(key)){
				cout << key << ":DELETED;" << endl;
			}else{
				cout << key << ":DELETE_FAILED;" << endl;
			}
		}
		if(input[0] == 'o'){
			hash_table->print();
		}
		cin >> input;
	}
}		