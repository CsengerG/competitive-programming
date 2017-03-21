/* suffix array O(N log N) implementation with O(N) LCP array*/
#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;++i)
#define REP(i,s,n) for(int i=s;i<n;++i)
#define pb push_back
#define mp make_pair

using namespace std;

string S;
int n;

const int maxn = 1234567;
const int alphabet = 256;

int cnt[maxn]; // array for counting sort
int c[maxn]; // array for equivalence classes
int rank[maxn]; // inverse suffix array
int sa[maxn]; // suffix array
int lcp[maxn]; // longest common prefix array
pair<int, pair<int,int> > sorted[maxn];

void counting_sort(vector<pair<int,pair<int,int> > > & array){
	FOR(i,max(alphabet,n)) cnt[i]=0;

	// firstly sort according to the second element
	FOR(i,n) cnt[array[i].second.second]++;
	REP(i,1,max(alphabet,n)) cnt[i] += cnt[i-1];
	FOR(i,n) sorted[--cnt[array[i].second.second]] = array[i];

	FOR(i,n) array[i] = sorted[i];

	// reverse
	reverse(array.begin(), array.end());

	// now sort according to the first - the order according to the second elements is now OK
	FOR(i,max(alphabet,n)) cnt[i]=0;
	FOR(i,n) cnt[array[i].second.first]++;
	REP(i,1,max(alphabet,n)) cnt[i] += cnt[i-1];
	FOR(i,n) sorted[--cnt[array[i].second.first]] = array[i];

	// modify original array - we are done
	FOR(i,n) array[i] = sorted[i];
}

vector<pair<int, pair<int,int> > > SA; // (suffix-index, (equivalence-class, equivalence-class of the suffix starting +2^k))

void build_SA(){
	// assigning equivalence classes
	FOR(i,n) SA.pb(mp(i, mp((int)S[i], 123)));
	FOR(i,n) SA[i].second.second = n > i+1 ? SA[i+1].second.first : 0;
	
	for(int gap=2;gap<=n;gap*=2){
		counting_sort(SA);

		// equivalence classes 
		int classes = 0;
		c[0] = classes;

		REP(i,1,n){
			if( SA[i].second != SA[i-1].second ) c[i] = ++classes;
			else c[i] = classes;
		}

		FOR(i,n) SA[i].second.first = c[i];

		FOR(i,n) rank[SA[i].first] = i;
		FOR(i,n) {
			int sufind = SA[i].first;
			SA[i].second.second = n > sufind+gap ? SA[rank[sufind+gap]].second.first : 0;
		}
	}

	FOR(i,n) sa[i] = SA[i].first;
}

void build_LCP(){
	int k = 0;

	FOR(i,n){
		if( rank[i] == n-1 ){ // nincs n-edik elem
			k=0;
			continue;
		}

		int j = sa[rank[i]+1]; // the suffix after the i. suffix lexicografically

		while( i+k < n and j+k < n and S[i+k] == S[j+k] ) ++k; // compute lcp

		lcp[rank[i]] = k; // store lcp between the i. and i+1. suffix
		
		if(k > 0) k--;
	}

}

int main(){
	cin >> S;
	S = S + "$";
	n = S.size();

	build_SA();

	FOR(i,n) cout << SA[i].first << " ";
	cout << endl;
	FOR(i,n) cout << rank[i] << " ";
	cout << endl;

	build_LCP();

	FOR(i,n) cout << lcp[i] << " ";
	cout << endl;
}
