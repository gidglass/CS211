#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

bool ok( int* q, int c ){
    int checkValues[][5] = {
        { -1 },
        { 0, -1 },
        { 0, -1 },
        { 0, 1, 2, -1 },
        { 0, 1, 3, -1 },
        { 1, 4, -1 },
        { 2, 3, 4, -1 },
        { 3, 4, 5, 6, -1 }};
    
    //row test
    for ( int i = 0 ; i < c ; ++i )
        if ( q[i] == q[c] )
            return false;
    //adjacent test
    for ( int i = 0 ; checkValues[c][i] != -1 ; ++i )
    {
        if (abs( q[c] - q[ checkValues[c][i] ] ) == 1 )
            return false;
    }
    return true;
}

void print(int* q){
    cout << " " << q[0] << q[1] << endl;
    cout << q[2] << q[3] << q[4] << q[5] << endl;
    cout << " " << q[6] << q[7] << " ";
    cout << endl << endl << endl;
}

void move(int* q, int i) 
{
    if(i==8)
    {
        print(q);
        return;
    }
    for(int j=0;j<8;j++) 
    { q[i]=j;
        if(ok(q,i)) 
            move(q,i+1);
    }
    // no value of j worked so return;
}


int main(){
    int q[8];
    move(q,0);
    return 0;
}


