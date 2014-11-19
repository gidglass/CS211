#include <iostream>
#include <vector>
using namespace std;
void move (int from, int to, int n){
    static int move = 0;
    vector <int> tower[3];
    
    for (int i=n+1; i>=1; i--)
        tower[0].push_back(i);
    tower[1].push_back(n+1);
    tower[2].push_back(n+1);
    
    int candidate= tower[from].back();
    
    if (n%2!=0){
        while (tower[1].size() < n+1){
            cout << "Step " << ++move << ": Move ring " << candidate << " from tower " << from+1 << " to tower " << to+1 << endl;
            
            tower[to].push_back(tower[from].back());
            tower[from].pop_back();
            
            if (tower[(to+1)%3].back() < tower[(to+2)%3].back())
                from = (to+1)%3;
            else
                from = (to+2)%3;
            
            candidate= tower[from].back();
            
            if (tower[from].back() < tower[(from+1)%3].back())
                to = (from+1)%3;
            else
                to = (from+2)%3;  
        }
    } // Odd
    
    if (n%2==0){
        to = 2;
        while (tower[1].size() < n+1){
            cout << "Step " << ++move << ": Move ring " << candidate << " from tower " << from+1 << " to tower " << to+1 << endl;
            
            tower[to].push_back(tower[from].back());
            tower[from].pop_back();
            
            if (tower[(to+2)%3].back() < tower[(to+1)%3].back())
                from = (to+2)%3;
            else
                from = (to+1)%3;
            
            candidate= tower[from].back();
            
            if (tower[(from+2)%3].back() < tower[(from)].back())
                to = (from+1)%3;
            else
                to = (from+2)%3;
        }
    } // Even
}

int main() {
    int n;
    cout << "How many rings? ";
    cin >> n;
    move(0,1, n);
    return 0;
} // main
