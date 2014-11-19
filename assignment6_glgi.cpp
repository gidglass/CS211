#include <iostream>
#include <cmath>
using namespace std;
int main() {
	//set board
	int q[8], c=0, count=0;
	q[0]=0;

	nc: c++;
	if (c==8) 
		goto print;
	q[c]=-1;

	nr: q[c]++;
	if (q[c]==8)
		goto backtrack;
	
	// test
	for (int i=0; i<c; i++){
		if (c-i==abs(q[c]-q[i]) || q[c]==q[i])
				goto nr;
	}
	goto nc;

	backtrack: c--;
		if (c==-1)
			return 0;
		goto nr;

	print: 
		cout << "\nSolution #: " << ++count << endl;
		cout << "Configuration: ";
		for (int i=0; i<8; i++)
			cout << q[i] << ' ';
		cout << endl;
		int r=0;
		while (r<8){
			for (int i=0; i<8; i++){
				if (r==q[i])
					cout << "Q" << ' ';
				else 
					cout << "*" << ' ';
			}
		cout << endl;
		r++;
		}
		cout << endl << endl;
		goto backtrack;
}
	

	 
