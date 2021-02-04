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

class LinkedList {
public:
	Chunk *head;
	int length;
	
	LinkedList() {
		head = NULL;
		length = 0;
		
	}
	
	void insertAtHead(int value){
		Chunk *temp = new Chunk;
		temp->value = value;
		if(head == NULL){
			head = temp;
			
		}
		else{
			temp->next = head;
			head = temp;
		}
		length++;
	}

	void insertAtPosition(int position, int value){

		if (position  > 0 && position <= length + 1){
			Chunk *temp = new Chunk;
			temp->value = value;
			if(position == 1){
				temp->next = head;
				head = temp;
			}
			else if (position > 1 && position <= length + 1){
				Chunk *helper = head;
				for (int i = 1; i < position -1; i++) {
					helper = helper->next;
				}
				temp->next = helper->next;
				helper->next = temp;
				length++;	
			}
			
		}
		else {

			cout << "Invalid position" << endl;
			
		}
		
		
		
	}
	void removeEveryOtherNode(){
		if(length <= 1){
			cout << "Cannot Remove " << endl;
			
		}
		else{
			Chunk *temp = head;
			Chunk *helper  = head->next;
			while(helper != NULL && temp != NULL){
				temp->next = helper->next;
				delete helper;
				temp = temp->next;
				if(temp != NULL){
					helper = temp->next;
				}
				length--;
			}
			
	
		}
	}
	void reverseLinkedList(){
		if(length <= 1){
			cout << "Cannot Reverse" << endl;

		}
		else{
			Chunk *helper, *current = head;
			Chunk *temp = NULL; 
			 
			
			while(current != NULL){
				helper = current->next;
				current->next = temp;
				temp = current;
				current = helper;
				
			}
			head = temp;
			
			
		}
			
			
		
	}
	void removeFromPosition(int position){
		if(position > 0 && position <= length){
			if(position == 1 && length == 1){
				delete head;
				head = NULL;
			}
			else if(position == 1 && length > 1){
				Chunk *temp = head;
				head = head->next;
				delete temp;
			}
			else{
				Chunk *temp, *helper;
				temp = helper = head;
				
				for (int i = 1; i < position; i++){
					helper = temp;
					temp = temp->next;
				}
				helper->next = temp->next;
				delete temp;
			}
			length--;
		}
		else{
			cout << "Invalid position" << endl;
		}
		
	}
	void displayContents() {
		if(head == NULL){
			cout << "Empty list, nothing to display" << endl;
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
	LinkedList LL;
	LL.insertAtHead(1);
	LL.insertAtHead(1);
	LL.insertAtHead(2);
	LL.insertAtHead(2);
	LL.insertAtHead(3);
	LL.insertAtHead(3);
	int value, choice, position;
	while(1){
		cout << "Enter 1 to add at head(1st position) " << endl;
		cout << "Enter 2 to add at any other position " << endl;
		cout << "Enter 3 to remove from any position " << endl;
		cout << "Enter 4 to display list " << endl;
		cout << "Enter any key to quit " << endl;
		cin >> choice;
		switch(choice) {
			case 1: cout << "Add what? " << endl;
					cin >> value;
					LL.insertAtHead(value);
					break;
			case 2: cout << "Add what? " << endl;
					cin >> value;
					cout << "What position? " << endl;
					cin >> position;
					LL.insertAtPosition(position, value);
					break;
			case 3: cout << "Remove from where? " << endl;
					cin >> position;
					LL.removeFromPosition(position);
					break;
			case 4: LL.displayContents();
					break;
			case 5: cout << "Reversing " << endl;
					LL.reverseLinkedList();
					break;
			case 6: cout << "Removing Every Other Node " << endl;
					LL.removeEveryOtherNode();
					break;
			case 7: cout << "Length: " << LL.length << endl;
					break;
					
			default:cout << "Goodbye " << endl;
					exit(1);
		}
			
	}

	
}