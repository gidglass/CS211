#include<iostream>
using namespace std;

long fib2(int n, long x, long y){
    if (n==1) return y;
    return fib2(n-1, y, x+y);
};

long fib(int n){
    return fib2(n, 0, 1);
};

int main(){
    for(int i=1; i<70; i++)
        cout<<" fib("<<i<<") = "<<fib(i)<<endl;
        return 0;
}


