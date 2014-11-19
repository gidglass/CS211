#include <iostream>
using namespace std;
int main() {
	//set board
	int b[8][8]={0};
	int r=0;
	int c=0;
	int count=1;
	b[0][0]=1;
	
	nc: c++;
		if (c==8)
			goto print;
	r=-1;
	nr: r++;
		if (r==8)
			goto backtrack;
	//test to left
	for (int i=0; i<c; i++){
		if (b[r][i]==1)
			goto nr;
	}
	//test diagonal up to left
	for (int i=1; (r-i>=0 && c-i>=0); i++){
		if (b[r-i][c-i]==1)
			goto nr;
	}
	//test diagonal down to left
	for (int i=1; (r+i<8 && c-i>=0); i++){
		if (b[r+i][c-i]==1)
			goto nr;
	}	
	b[r][c]=1;//if passes above conditions, place queen
	goto nc;
	backtrack: c--;
		if (c==-1)
			return 0;
		r=0;
		while (b[r][c]!=1)
			r++;
		b[r][c]=0;
		goto nr;
	print: 	
	cout << "Solution #: " << count <<  endl;
		for (int i=0; i<8; i++){
			for (int j=0; j<8; j++){
				cout << b[i][j] << ' ';
			}
		cout << endl;
		}
		count++;
		cout << endl;
		goto backtrack;
}
		 

		
