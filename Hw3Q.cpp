#include<iostream>
using namespace std;

class Chunk{
public:
	int value;
	Chunk *next;
	
	Chunk() {
		value = 0;
		next = NULL;
	}
	
	
};

class Queue{
public:
	Chunk *head;
	Chunk *tail;
	Queue() {
		head = tail = NULL;
		
	}
	
	void enqueue(int x){
		Chunk *temp = new Chunk;
		temp->value = x;
		
	if(tail == NULL){
		head = tail = temp; 
	}
	else{
		tail->next = temp;
		tail = tail->next;
	}
		
		
	}
	void dequeue(){
		if (head == NULL){
			cout << "Queue is Empty: Nothing to delete" << endl;
		}
		else if (head->next == NULL){
			cout << "About to delete: " << endl;
			delete head;
			head = tail = NULL;
		}
		else {
			Chunk* temp = head;
			head = head->next;
			cout << "About to delete: " << temp->value << endl;
			delete temp;
		}
	}

	void printContents() {
		if(head == NULL){
			cout << "Empty Q, nothing to display" << endl;
		}
		else {
			Chunk *temp;
			temp = head;
			cout << "------------------------" << endl;
			while(temp != NULL){
				cout << temp->value << "-->";
				temp = temp->next;
				}
			cout << "NULL" <<endl;
			cout << "------------------------" << endl;
		}
		
	}
	
};

int main()
{
	Queue q;
	int value, choice;
	while(1) {
		cout << "Enter 1 to add (enqueue)" << endl;
		cout << "Enter 2 to remove (dequeue)" << endl;
		cout << "Enter 3 to display" << endl;
		cout << "Enter any key to quit " << endl;
		cin >> choice;
		
		switch(choice) {
			case 1: cout << "Add what? " << endl;
			cin >> value;
			q.enqueue(value);
			break;
			case 2: q.dequeue();
					break;
			case 3: q.printContents();
			break;
			default: cout << "Goodbye " << endl;
					 exit(1);
		}
		
	}
	

}