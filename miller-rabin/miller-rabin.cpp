#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;++i)
#define int long long

using namespace std;

int powmod(int base, int k, int m){
	int ret = 1;

	while(k>0){
		if(k%2==1){
			ret*=base;
			ret = ret % m;
		}

		base*=base;
		base = base % m;
		k /= 2;
	}

	return ret;
}

bool miller_rabin(int n, int k){
	if(n<2) return false;
	if(n==2 or n==3) return true;

	// write n-1 in the form of d*2^r
	int d = n-1;
	int r = 0;
	while(d%2==0){
		d/=2;
		++r;
	}

	FOR(i,k){
		int a = (rand()%(n-3)) + 2;
		int x = powmod(a,d,n);
		bool cont = false;

		if( x==1 or x==n-1) continue;
		FOR(j,r-1){
			x = (x*x) % n;
			if(x==1) return false; // composite
			if(x==n-1){
				cont = true;
				break;
			}
		}

		if(cont) continue;

		return false; // composite
	}

	return true;
}

main(){
}
