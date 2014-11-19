#include <iostream>
using namespace std;
void move (char f, char t, char e, int n){
	static int move_number=0;
	if (n==1)
		cout << ++move_number<< ": Move from " << f << " to " << t << endl;
    	else {
        	move(f,e,t,(n-1));
        	cout << ++move_number << ": Move from " << f << " to " << t << endl;
        	move(e,t,f,(n-1));
    	}
}
int main() {
	int n;
    	cout << "How many rings? ";
    	cin >> n;
    	move('a','b','c', n);
    	return 0;
}//main
