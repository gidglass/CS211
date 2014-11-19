// Rat class i.e. a class for rational nbers
#include <iostream>
using namespace std;
class Rat{
private:
	int n;
	int d;
public:
	// constructors
	// default constructor
	Rat(){
		n=0;
		d=1;
	}
	// 2 parameter constructor
	Rat(int i, int j){
		n=i;
		d=j;
	}
	// conversion constructor
	Rat(int i){
		n=i;
		d=1;
	}
	//accessor functions (usually called get() and set(...) )
	int getN(){ return n;}
	int getD(){ return d;}
	void setN(int i){ n=i;}
	void setD(int i){ d=i;}

	//arithmetic operators
	Rat operator+(Rat r) {
		Rat t;
		t.n = n*r.d + d*r.n;
		t.d = d*r.d;
        lowestTerms(t);
        improperFraction(t);
		return t;
	}
    Rat operator*(Rat r) {
        Rat t;
        t.n = n*r.n;
        t.d = d*r.d;
        lowestTerms(t);
        improperFraction(t);
        return t;
    }
    Rat operator/(Rat r) {
        Rat t;
        t.n = n*r.d;
        t.d = d*r.n;
        lowestTerms(t);
        improperFraction(t);
        return t;
    }
    
    // functions to manipulate the fractions to lowest terms and mixed numbers
    int gcd(int a, int b) {
        if(b == 0) {
	        return a;
        }
        else {
            return gcd(b, a % b);
        }
    }
    void lowestTerms(Rat &t) {
        int x = t.gcd(t.getN(), t.getD());
        t.n/=x;
        t.d/=x;
    }
    void improperFraction(Rat &t) {
        if (t.n > t.d) {
            cout << t.n/t.d << " ";
            t.n%=t.d;
        }
    }
};

int main() {
    Rat a = Rat(1,2);
    Rat b = Rat(3,4);
    
    Rat add = a.operator+(b);
    cout << add.getN() << "/" << add.getD() << endl;
    
    Rat mult = a.operator*(b);
    cout << mult.getN() << "/" << mult.getD() << endl;
    
    Rat div = a.operator/(b);
    cout << div.getN() << "/" << div.getD() << endl;
}
