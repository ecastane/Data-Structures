#include<iostream>
using namespace std;

int main ()
{
	int var = 10;
	int another = 5;
	int *pal; //friendly kind of variable
	
	cout << "Value of the variable: " << var << endl;
	cout << "Address of this variable " << &var <<endl;
	/*
	* pal is a "pointer"
	* pal can ONLY store addresses, and never literal values
	*/
	
	//referencing a pointer 
	pal = &var; //now, pal knows the address of var
	
	//var = var + 10;
	//*pal = deferencing a pointer
	
	*pal = *pal + 10; //pal pays a visit to var, and changes the value of var to 20
	
	cout << "Value of var after pal paid a visit: " << var << endl;	
	
	//===================================================
	//now lets get pal to grab the addres of another
	//(meaning pall will forget about var)
	
	pal = &another;
	*pal = 500;
	cout << "Another is now: " << another << endl;
	
	
	


	
}  