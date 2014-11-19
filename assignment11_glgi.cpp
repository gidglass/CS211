#include <iostream>
#include <cmath>
using namespace std;
bool ok(int q[], int column){
    int mp[3][3]={
        {0,2,1},
        {0,2,1},
        {1,2,0}};
    int wp[3][3]={
        {2,1,0},
        {0,1,2},
        {2,0,1}};
    
    for (int i=0; i<column; i++){
            if (q[column]==q[i])
                return false;
        if((mp[i][q[column]] < mp[i][q[i]] && wp[q[column]][i] < wp[q[column]][column]) || (mp[column][q[i]] < mp[column][q[column]] && wp[q[i]][column] < wp[q[i]][i]))
                return false;
    }
    return true;
}
void backtrack(int &col){
    --col;
    
    if(col == -1)
        exit(1);
}

void print(int q[], int count){
    cout << "\nStable Matching #" << count << ": " << endl;
    cout << "Men:   0 1 2" << endl << "Women: ";
    for (int i=0; i<3; i++)
        cout <<  q[i] << ' ';
    cout << endl << endl;
}


int main() {
    int c=0, q[3], count =0;
    q[0] = 0;
    bool test=false;
    
    
    
        while(true){
            while(c<3){
                if(!test)
                    q[c] = -1;
                
                test =  false;
        
                while(q[c]<3){
                    q[c]++;
                    
                    if(q[c] == 3){
                        backtrack(c);
                        continue;
                    }
                    
                    if (ok(q,c) ) break;
                }
                
                c++;
            }
            
            print(q, ++count);
            backtrack(c);
            test = true;
        }
        return 0;
    }
