//Collaborators: N/A
//Sources: Introduction to Algorithms: 3rd Edition. Binary Search Trees have a few properties that separate it from other types of search trees.
//Binary search trees must be in binary; in which the left subtree have to be at MOST the size of the key and the right subtree must be at LEAST
//the size of the key.
#include<iostream>
#include <cstdlib>
#include <string>
#include<stdio.h>
#include <sstream>

using namespace std;

struct node{
    int key;
    node *L, *R;				//for respective left and right nodes
};

struct node * minValueNode(node* node){
    while (node->L != NULL)
        node = node->L;
    return node;
}
node* insert(node *tnode, int key){
    if (tnode == NULL){			
		node *temp = new node;		
		temp -> key = key;		
		temp -> L = NULL;
		temp -> R = NULL;		
		return temp;
	}	
	if (key <= tnode->key){
			tnode->L  = insert(tnode->L, key);
	}else if (key > tnode -> key){
			tnode->R = insert(tnode->R, key);
	}	
	return tnode;
}
node* deleteNode(node* root, int key){
    if (root == NULL) 			//empty root
		return root; 
    else if (key < root->key)
        root->L = deleteNode(root->L, key);
    else if (key > root->key)
        root->R = deleteNode(root->R, key);
    else{
        if (root->L == NULL){
            struct node *temp = root->R;
            free(root);
            return temp;
        }
        else if (root->R == NULL){
            struct node *temp = root->L;
            free(root);
            return temp;
        }
        struct node* temp = minValueNode(root->R);
        root->key = temp->key;
        root->R = deleteNode(root->R, temp->key);
    }
    return root;
}
void inorder(node *root){
    if (root != NULL){
        inorder(root->L);
        cout << root->key << endl;
        inorder(root->R);
    }
}
void preorder(node *root){
	if(root == NULL)
		return;
	cout << root->key << endl;
	preorder(root->L);
	preorder(root->R);
}

void postorder(node *root){
	if(root == NULL)
		return;
	postorder(root->L);
	postorder(root->R);
	cout << root->key << endl;
}
 
int main(){
	node *real = NULL;
	node* temp;	
	int key;
	string input;	
	while(1){
		cin >> input;		
		string k = input.substr(1);
		stringstream convert(k);
		convert >> key;		
		if(input[0] == 'i') 
			real = insert(real, key);		
		else if(input[0] == 'd')
			real = deleteNode(real, key);	
		else if(input == "opre") 
			preorder(real);}		
		else if(input == "opost")
			postorder(real);		
		else if(input == "oin")
			inorder(real);	
		else if(input[0] = 'e')
			exit(0);		
		else
			cout<<"Invalid choice! \n Try Again.";
	}		
     return 0;
}