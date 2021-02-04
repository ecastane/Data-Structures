#include<iostream>
using namespace std;

class TreeChunk {
public:
	int data;
	TreeChunk *right;
	TreeChunk *left;
	
	TreeChunk() {
		data = 0;
		left = right = NULL;
	}
	
};

class BST {
public:
	TreeChunk *root;
	
	BST() {
		root = NULL;
	}
	//1. Add new values to the tree 
	void add(int x) {
		if(root == NULL) {
			//empty tree!
			root = new TreeChunk;
			root->data = x;
			cout << "Just added value: " << x << endl;
			return;
		}
		
		TreeChunk *slow, *fast;
		slow = fast = root;
		
		while(fast != NULL) {
			if(x < fast->data) {
				slow = fast;
				fast = fast->left;
			}
			else if (x > fast->data) {
				slow = fast;
				fast = fast->right;
			}
			else {
				cout << "We do not allow duplicates" << endl;
				return;
			}
		}
		
		if(x < slow->data) {
			slow->left = new TreeChunk;
			slow->left->data = x;
		}
		else {
			slow->right = new TreeChunk;
			slow->right->data = x;
		}
		cout << "Successfully added: " << x << endl;
	}
	//2. Search for a value
	bool search(int key, TreeChunk *start){
		//anchor
		if(start == NULL){
			cout << "Could not find the value you are looking for" << endl;
			return false;
		}
		//recursive step
		else{
			if(key == start->data){
				cout << "Success value found in  the tree" << endl;
				return true;
			}
			if(key < start->data)
				search(key, start->left);
			else
				search(key, start->right);
		}
	}
	//3. Display
	void preorder(TreeChunk *start){
		//anchor value
		if(start == NULL)
			return;
		else {
			//root, left, right
			cout << start->data << endl;
			preorder(start->left);
			preorder(start->right);
		}
	}
	
	void postorder(TreeChunk *start){
		//anchor value
		if(start == NULL)
			return;
		else {
			//left, right, root
			postorder(start->left);
			postorder(start->right);
			cout << start->data << endl;
		}
	}
	void inorder(TreeChunk *start){
				//anchor value
		if(start == NULL)
			return;
		else {
			//left,root, right
			inorder(start->left);
			cout << start->data << endl;
			inorder(start->right);
			
		}
	}
	//4. Deleting valaues from the tree
	void deleteNode(int key) {	
		//empty tree test
		if(root == NULL){
			cout << "Empty tree, nothing to delete" << endl;
			return;
		}
		
		//step1: Search and find that node.
		TreeChunk *slow, *fast;
		slow = fast = root;
		
		while(fast != NULL && fast->data != key) {
			//keep going left or right
			if(key < fast->data) {
				slow = fast;
				fast = fast->left;
			} 
			else {
			slow = fast;
			fast = fast->right;
			}
			
		}
		if(fast == NULL) {
			cout << "This node does not exist in this tree: " << key << endl;
			return;
		}
		
		//step2: Begin to classify the case for delete (1,2 or 3)
		cout << "Found the node, now trying to classify the type of delete" << endl;
		//case1: both the left and the right pointers are NULL (no children)
		if(fast->right == NULL && fast->left ==NULL){
			cout << "Looks like a case-I delete for " << key << endl;
			if (root->data == key) {
				cout << "About to delete: " << fast->data << endl;
				root = NULL;
				delete root;
			} 
			else if(slow->right == fast) {
				//the node is to the right of slow
				slow->right = NULL;
				cout << "About to delete: " << fast->data << endl;
				delete fast;
			}
			else {
				slow->left = NULL;
				cout << "About to delete: " << fast->data << endl;
				delete fast;			
			}
		}
		else if ((fast->right == NULL && fast->left != NULL) || (fast->right != NULL && fast->left == NULL)){
			cout << "Case II delete for " << key << endl;
				if(fast->left != NULL) {
					if (root->data == key) {
						root = root->left;
						cout << "About to delete: " << fast->data << endl;
						delete slow;
					}
					else if(slow->left == fast) {
						//fast is to the left of slow, and the lone child is to the left of fast
						slow->left = fast->left;
						cout << "About to delete: " << fast->data << endl;
						delete fast;
					}
					else if(slow->right == fast) {
						//fast is to the right of slow. and the lone child is to the left of fast
						slow->right =  fast->left;
						cout << "About to delete: " << fast->data << endl;
						delete fast;
					}
				}
				if(fast->right != NULL) {
					if (root->data == key) {
						root = root->right;
						cout << "About to delete: " << fast->data << endl;
						delete slow;
					}
					
					else if(slow->left == fast) {
						//fast is to the left of slow, and the lone child is to the right of fast
						slow->left = fast->right;
						cout << "About to delete: " << fast->data << endl;
						delete fast;
					}
					else if(slow->right == fast) {
						//fast is to the right of slow, and the lone child is to the right of fast
						slow->right = fast->right;
						cout << "About to delete: " << fast->data << endl;
						delete fast;
					}
					
				}
			
		}

		else {
			cout << "This is a Case III delete for " << key << endl;
			slow = fast;
			fast = fast->right;
			while(fast->left != NULL) {
				fast = fast->left;
			}
			int newData = fast->data;
			deleteNode(newData);
			cout << "Replacing: " << slow->data <<" with: "<< newData << endl;
			slow->data = newData;
			
		}
	}
	
};

int main() 
{
	int value, choice;
	BST myTree;
/*
	//build the tree in code
	myTree.add(30);
	myTree.add(15);
	myTree.add(60);
	myTree.add(7);
	myTree.add(22);
	myTree.add(17);
	myTree.add(27);
	myTree.add(45);
	myTree.add(75);
	myTree.add(80);
	//search for a few values
	//succesful search
	if(myTree.search(17, myTree.root))
		cout << "Success" << endl;
	else
		cout << "Could not find 17" << endl;
	//unsuccess;ul search
	if(myTree.search(999, myTree.root))
		cout << "Success" << endl;
	else
		cout << "Could not find 999" << endl;
	cout << "===============================" << endl;
	myTree.preorder(myTree.root);
	myTree.postorder(myTree.root);
	myTree.inorder(myTree.root);
	cout << "===============================" << endl;
	myTree.deleteNode(20);
	myTree.deleteNode(75);
	myTree.deleteNode(15);
	myTree.deleteNode(1599875);
	cout << "===============================" << endl;
	myTree.inorder(myTree.root);
	cout << "===============================" << endl;
	*/
	while(1) {
		cout << "Press 1 to add node" << endl;
		cout << "Press 2 to search node" << endl;
		cout << "Press 3 to delete node" << endl;
		cout << "Press 4 to display inorder" << endl;
		cout << "Press 5 to display preorder" << endl;
		cout << "Press 6 to display postorder" << endl;		
		cout << "Anything else to quit" << endl;
		cin >> choice;
		
		switch (choice) {
			case 1: cout << "Add what?" << endl;
					cin >> value;
					myTree.add(value);
			break;
			
			case 2: cout << "Search what?" << endl;
					cin >> value;
					myTree.search(value, myTree.root);
					break;
			case 3: cout << "delete what?" << endl;
					cin >> value;
					myTree.deleteNode(value);
					break;
			
			case 4: 
					cout << "===============================" << endl;
					myTree.inorder(myTree.root);
					cout << "===============================" << endl;	
					break;
			case 5:
					
					cout << "===============================" << endl;
					myTree.preorder(myTree.root);
					cout << "===============================" << endl;							
					break;
			case 6:
					cout << "===============================" << endl;
					myTree.postorder(myTree.root);
					cout << "===============================" << endl;										
					break;
			
			default: cout << "Goodbye!" << endl;
					exit(1);
		}
	}
}