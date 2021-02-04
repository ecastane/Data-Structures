#include<iostream>
using namespace std;

class Chunk{
public:
	int value;
	Chunk *next;
	
	Chunk(){
		value = 0;
		next = NULL;
	}
};

class Stack{
public:
	Chunk *top;
	
	Stack() {
		top = NULL;
	}
	
	void push(int x){
		
		Chunk *another = new Chunk;
		another->value = x;
		
		if(top == NULL){
			top = another;
		}
		else{
			another->next = top;
			top = another;
		}
	}
	
	void pop(){
		if(top == NULL){
			cout << "----------------------------" << endl;
			cout << "The List is empty" << endl;	
			cout << "----------------------------" << endl;
		}
		else{
			Chunk *another;
			another = top;
			top = top->next;
			cout << "----------------------------" << endl;
			cout << "About to delete: " << another->value << endl;
			cout << "----------------------------" << endl;
			delete another;
		}
	}
	
	void displayContents() {
		if(top == NULL) {
			cout << "The list is empty" << endl;
		} 
		else{
			Chunk *another;
			another = top;
			
			while(another != NULL){
				cout << another->value << "-->";
				another = another->next;
			}
			cout << "NULL" << endl;
		}
	}
	
};




int main() 
{
	Stack myStack;
	int choice, value;
	char leave;
	
	while(1) {
		cout << "Enter 1 to add" << endl;
		cout << "Enter 2 to pop" << endl;
		cout << "Enter 3 display stack" << endl;
		cout << "Enter any key to quit" << endl;
		cin >> choice;
		
		switch(choice) {
			case 1: cout << "Add what?" << endl;
					cin >> value;
					myStack.push(value);
					break;
			
			case 2: myStack.pop();
					break;
					
			case 3: cout << "----------------------------" << endl;
					myStack.displayContents();
					cout << "----------------------------" << endl;
					break;
			
			default: cout << "Are you sure you want to quit? Enter y/n" << endl;
					 cin >> leave;
					 if(leave == 'y'){
					 cout << "Goodbye!" << endl;
					 exit(1);
					 }
					 else {
						break;
					 }
		}
	}
	
	
}