#include <iostream>
using namespace std;

double cont_frac(int a[], int l, int f){
	if (l==f) return (double) a[l];
	return ((double)a[l] + 1/cont_frac(a, l+1, f));
}
int *lowest(int a[], int l, int *c){
    c[1]=0;
    c[0]=1;
	for (int i=l; i>-1; i--){
        int t=c[0];
        c[0]= c[1]+a[i]*c[0];
        c[1]=t;
	}
	return c;
}

int * lowest_terms(int a[], int l, int *c){
	if (c==NULL){
		c=new int [2];
		c[0]=0;
		c[1]=1;
	}
	if (l==0){
		c[0]=c[0]+c[1]*a[l];
		return c;
	}
	int t=c[1];
	c[1]=c[0]+c[1]*a[l];
	c[0]=t;
	return lowest_terms(a, l-1, c);
}

int main()
{
	int a[5]={1,2,3,4,5};
	cout<<cont_frac(a, 0, 4)<<endl;
	int *c= new int [2];
	c=lowest(a,4, c);
	cout<<c[0]<<"/"<<c[1]<<endl;
	int *b =NULL;
	b=lowest_terms(a, 4, b);
	cout<<b[0]<<"/"<<b[1]<<endl;
	
	delete [] b;

    return 0;
}
