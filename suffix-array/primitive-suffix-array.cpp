/* Suffix array naive implementation */
#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;++i)

using namespace std;

vector< pair<string, int> > suffixes;

int main(){
	string S;
	cin >> S;

	S = S + "$";

	int n = S.size();

	FOR(i,n){
		suffixes.push_back( make_pair( S.substr(i,n-i), i ) );
	}

	sort( suffixes.begin(), suffixes.end() );

	FOR(i,n){
		cout << suffixes[i].first << endl;
	}
}
