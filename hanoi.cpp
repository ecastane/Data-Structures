#include<iostream>
using namespace std;

void hanoi(int N, char S, char I, char D)
{
	static int counter = 0;
	
	if(N == 1) {
		//base-case or anchor-value
		cout << ++counter << " Move disc " << N << " from " << S << " ---> " << D << endl;
		
	}
	else {
		//recurrent relationship
		hanoi(N-1, S, D, I); //n-q from S--->I
		cout << ++counter << " Move disc " << N << " from " << S << " ---> " << D << endl; // S--->D
		hanoi(N-1, I, S, D);
		
	}
	
}

int main()
{
	int N;
	char S = 'S', I = 'I', D = 'D';
	
	cout << "How many discs?" << endl;
	cin >> N;
	
	hanoi(N, S, I, D);
	
	
	return 1;
}