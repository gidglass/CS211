#include <iostream>
#include <cmath>
using namespace std;
bool ok(int q[]){
    for (int c=0; c<8; c++){
        for (int i=0; i<c; i++){
            if (c-i==abs(q[c]-q[i]) || q[c]==q[i])
                return false;
        }
   }
    return true;
}
void print(int q[], int count){
    cout << "\nSolution #: " << count << endl;
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

int main() {
	int q[8] = {0};//set board
    int count=0;
    for (q[0]=0; q[0]<8; q[0]++){
        for (q[1]=0; q[1]<8; q[1]++){
            for (q[2]=0; q[2]<8; q[2]++){
                for (q[3]=0; q[3]<8; q[3]++){
                    for (q[4]=0; q[4]<8; q[4]++){
                        for (q[5]=0; q[5]<8; q[5]++){
                            for (q[6]=0; q[6]<8; q[6]++){
                                for (q[7]=0; q[7]<8; q[7]++){
                                    if (ok(q))
                                        print(q, ++count);
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

