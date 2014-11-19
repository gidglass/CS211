#include <iostream>
using namespace std;
bool equivalent(int a[], int b[], int n){
       // find the shift value to the right
	int shift=0;
        for (int i=0; i<n; i++){
                if (a[0]==b[i])
                        shift=i;
        }

        bool answer=false;

	// compare element in a to shifted in b 
        for (int i=0; i<(n-shift); i++){
                if (a[i]==b[(i+shift)])
                        answer=true;
                else
                        return false;
        }
	// compare element in a to shifted in b which wraps around
        for (int j=(n-shift); j<n; j++){
                if (a[j]==b[(j+shift)%n])
                        answer=true;
                else
                        return false;
        }

        return answer;
}

int main(){
        int x[5], y[5];
        cout << "Please enter five values: ";
        for (int i=0; i<5; i++)
                cin >> x[i];
        cout << "... and five more please: ";
        for (int i=0; i<5; i++)
                cin >> y[i];

        bool ans=equivalent(x, y, 5);
        if (ans==true)
                cout << "TRUE-Shift equivalent!" << endl;
        else
                cout << "FALSE- Not shift equivalent." << endl;

        return 0;
}

