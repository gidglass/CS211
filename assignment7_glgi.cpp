#include <iostream>
#include <cmath>
using namespace std;
void print(int q[], int count){
	cout << "\nSolution #: " << ++count << endl;
	cout << "Configuration: ";
       	for (int i=0; i<8; i++)
        	cout << q[i] << ' ';
        cout << endl;
        int r=0;
        while (r<8){
        	for (int i=0; i<8; i++){
                	if (r==q[i])
                        	cout << 1 << ' ';
                        else
                        	cout << 0 << ' ';
                }
        cout << endl;
        r++;
        }
        cout << endl << endl;

}
int main(){
	//set board
	int column=0, q[8], count = -1;
	q[0] = 0;

	while(true){
        	++column;
        	if(column==8){
           		++count;
           		print(q,count);
           		column--;
        	}
        else
        	q[column] = -1;
        	for( ; ; ){
                	q[column]++;
               		if(q[column]==8){
                   		--column;
                   		if(column==-1)
                        		return 0;
                   		else
                        		continue;
                	}
                bool nextRow = false;
                for(int i=0;i<column;++i){
                	if(q[column]==q[i] || column-i == abs(q[column]-q[i])){
                        	nextRow = true;
                        	break;
                   	}
                }
                if(nextRow)
                	continue;
                break;
           	}
	}
return 0;
}
