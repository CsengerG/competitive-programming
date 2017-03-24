#include <bits/stdc++.h>

#define int long long 
using namespace std;

// our chosen polynomial modulo n and with varying constant
// it produces a pseudorandom sequence
int g(int x, int c, int n){
	return (x*x+c)%n;
}

// greates common divisor
int gcd(int a, int b){
	if(b==0) return a;
	else return gcd(b,a%b);
}

// pollard-rho algorithm
int pollard(int n){
	if(n==1) return 1; // n=1 -> corner case
	
	int x = (rand()%(n-1))+1; // let x be between 1 and n-1
	int y = x; // the y starting value has to be the same
	int c = (rand()%(n-1))+1; // constant factor between 1 and n-1

	int d = 1;

	while(d==1){
		x = g(x,c,n);
		y = g(g(y,c,n),c,n);

		d = gcd(abs(x-y), n);
	}

	if(d==n) { // failure, not handled here 
		return d;
	}

	return d;
}

main(){
	// testing
	srand( time(NULL) );

	int N;
	cin >> N;

	while(N>1){ // write out some divisors
		int d = pollard(N);
		cout << d << endl;
		N = N/d;
	}
}
