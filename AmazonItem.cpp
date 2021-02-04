#include<iostream>
using namespace std;



class AmazonItemsForSale {
public:
	//1. What is the physical look and feel of items of this type?
	//  ("attributes")
	float price;
	int sellerID;
	
	//2. When we create a new object, what does it look like?
	// constructor: special function tha "initializes" attributes to a default value

	AmazonItemsForSale() {
		price = 0.0;
		sellerID = 100;
	}

	//3. What functions are allowed for items of this type?
	void addThisItemToCart() {
		//implement this function
		cout << "Adding this to the cart" << endl;	
	}	
};

int main()
{
	int x;
	AmazonItemsForSale item1;
	
	cout << "Price of this new item: " << item1.price << endl;
	item1.price = 38.50;
	item1.sellerID = 900;
	item1.addThisItemToCart();
	cout << "Price now: " << item1.price <<", sellerID: " << item1.sellerID << endl;
	
	//===================================
	//Creating variables that have no name
	//These kinds of variables reside in the "Heap": a special zone in the memory
	//===================================
	
	//First, create a pointer
	AmazonItemsForSale *customer;
	//get a new item from the heap
	customer = new AmazonItemsForSale; //nameless.. just an address
	customer->price = 38.50;
	customer->sellerID = 900;
	
	AmazonItemsForSale *another;
	another = new AmazonItemsForSale;
	another->price = 100;
	another->sellerID = 123;
	
	cout << "FIrst box in the heap!" << endl;
	cout << customer->price << " " << customer->sellerID << endl;
	cout << "Second box in the heap: " << endl;
	cout << another->price << " " << another-> sellerID << endl;
	
	//customer = NULL;
	
	
	


	
	
}