#include <iostream>
#include <cmath>
using namespace std;
bool ok(int b[][8]){
	int r;
        for (int c=7; c>0; c--){
		r=0;
		while (b[r][c]!=1)
			r++;
		for (int i=1; i<=c; i++){
			if (b[r][c-i]==1)
				return false;
		} //row test
        	for (int i=1; (r-i>=0 && c-i>=0); i++){
                	if (b[r-i][c-i]==1)
				return false;
       		 } //diagonal up 
        	for (int i=1; (r+i<8 && c-i>=0); i++){
                	if (b[r+i][c-i]==1)
				return false;
		} //diagonal down

	}
	return true;
}
void print(int b[][8], int count){
	cout << "Solution #: " << count <<  endl;
	for (int r=0; r<8; r++){
		for (int c=0; c<8; c++)
			cout << b[r][c] << ' ';
		cout << endl;
	}
	cout << endl;
}
int main() {
	int b[8][8]={0};//set board
	int count=0;
		for (int i0=0; i0<8; i0++){					
			for (int i1=0; i1<8; i1++){	
				for (int i2=0; i2<8; i2++){
					for (int i3=0; i3<8; i3++){
						for (int i4=0; i4<8; i4++){
							for (int i5=0; i5<8; i5++){
								for (int i6=0; i6<8; i6++){
									for (int i7=0; i7<8; i7++){
										b[i0][0]=1;		
										b[i1][1]=1;
										b[i2][2]=1;
										b[i3][3]=1;
										b[i4][4]=1;
										b[i5][5]=1;
										b[i6][6]=1;
										b[i7][7]=1;
										if (ok(b))
											print (b, ++count);
										b[i0][0]=0;
										b[i1][1]=0;
										b[i2][2]=0;
										b[i3][3]=0;
										b[i4][4]=0;
										b[i5][5]=0;
										b[i6][6]=0;
										b[i7][7]=0;
									}
								}
							}
						}
					}
				}
			}
		}
return 0;
}
