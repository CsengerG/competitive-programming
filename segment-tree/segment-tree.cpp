#include <bits/stdc++.h>

// Segment tree with lazy propagation
// NOT TESTED

using namespace std;

const int maxn = 300100;
const int nonsense = -1; // arbitrary nonsense value

int ST[4*maxn];
int lazy[4*maxn];

int get(int s, int e, int qs, int qe, int ind){
	if( lazy[ind] != 0 ){ // this node needs to be updated
		ST[ind] += lazy[ind];

		// the children too
		lazy[2*ind+1] += lazy[ind];
		lazy[2*ind+2] += lazy[ind];
		lazy[ind]=0;
	}

	if(qe < s or e < qs) return nonsense;
	if(qs <= s and e <= qe) return ST[ind];

	int m = (s+e)/2;
	return max(get(s,m,qs,qe,2*ind+1), get(m+1,e,qs,qe,2*ind+2));
}

void update(int s, int e, int qs, int qe, int ind, int val){
	if( lazy[ind] != 0 ){ // this node needs to be updated
		ST[ind] += lazy[ind];

		// the children too
		lazy[2*ind+1] += lazy[ind];
		lazy[2*ind+2] += lazy[ind];
		lazy[ind]=0;
	}
	
	if(qe < s or e < qs) return;
	if(qs <= s and e <= qe){
		ST[ind]+=val;

		lazy[2*ind+1] += val;
		lazy[2*ind+2] += val;
		return;
	}

	int m = (s+e)/2;
	update(s,m,qs,qe,2*ind+1, val);
	update(m+1,e,qs,qe,2*ind+2, val);
}

int main(void){
	
}
