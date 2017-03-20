/* suffix array naive implementation */
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

int w[maxn], c[maxn], inv[maxn];
pair<int, pair<int,int> > sorted[maxn];

void counting_sort(vector<pair<int,pair<int,int> > > & array){
	int N = array.size();
	FOR(i,max(alphabet,N)) w[i]=0;

	// firstly sort according to the second element
	FOR(i,N) w[array[i].second.second]++;
	REP(i,1,max(alphabet,N)) w[i] += w[i-1];
	FOR(i,N) sorted[--w[array[i].second.second]] = array[i];

	FOR(i,N) array[i] = sorted[i];

	// reverse
	reverse(array.begin(), array.end());

	// now sort according to the first - the order according to the second elements is now OK
	FOR(i,max(alphabet,N)) w[i]=0;
	FOR(i,N) w[array[i].second.first]++;
	REP(i,1,max(alphabet,N)) w[i] += w[i-1];
	FOR(i,N) sorted[--w[array[i].second.first]] = array[i];

	// modify original array - we are done
	FOR(i,N) array[i] = sorted[i];
}

vector<pair<int, pair<int,int> > > SA; // (suffix-index, (equivalence-class, equivalence-class of the suffix starting +2^k))

void build_SA(){
	int N = S.size();

	// assigning equivalence classes
	FOR(i,N) SA.pb(mp(i, mp((int)S[i], 123)));
	FOR(i,N) SA[i].second.second = N > i+1 ? SA[i+1].second.first : 0;
	
	for(int gap=2;gap<=N;gap*=2){
		counting_sort( SA );

		// equivalence classes 
		int classes = 0;
		c[0] = classes;

		REP(i,1,N){
			if( SA[i].second != SA[i-1].second ){
				c[i] = ++classes;
			} else c[i] = classes;
		}

		FOR(i,N) SA[i].second.first = c[i];

		FOR(i,N) inv[SA[i].first] = i;
		FOR(i,N) {
			int sufind = SA[i].first;
			SA[i].second.second = N > sufind+gap ? SA[inv[sufind+gap]].second.first : 0;
		}
	}

}

int main(){
	cin >> S;
	S = S + "$";
	int N = S.size();

	build_SA();

	FOR(i,N) cout << 1+SA[i].first << " ";
	cout << endl;
}
