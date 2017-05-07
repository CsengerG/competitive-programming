#include <bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;++i)
#define REP(i,s,n) for(int i=s;i<n;++i)
#define pb push_back
#define sz size

using namespace std;

int MEX(set<int> S){
    int i = 0;
    while(true){
        if( S.find(i) == S.end() ) return i;
        ++i;
    }
}

vector<int> heaps;
int memo[60][60];

int G(int hanyadik, int mennyi){
	if( memo[hanyadik][mennyi] != -1 ) return memo[hanyadik][mennyi];
	else {
		if(heaps.size() - hanyadik == 0){
			memo[hanyadik][mennyi] = 0;
			return memo[hanyadik][mennyi];
		}
		
		if(heaps.size() - 1 == hanyadik){
			memo[hanyadik][mennyi] = heaps[hanyadik];
			return memo[hanyadik][mennyi];
		}

		set<int> nextstates;

		for(int poss = 0; poss < mennyi; ++poss){
			if(poss == 0) nextstates.insert(G(hanyadik+1,heaps[hanyadik+1]));
			else nextstates.insert(G(hanyadik, poss));
		}


		// EVALUATE THIS TYPE OF GRUNDY GAME (calculate MEX of the possible next states from this state)
		memo[hanyadik][mennyi] = MEX(nextstates);
		return memo[hanyadik][mennyi];
	}
}

int t,n,m;
int solveOne(){
	// init
	FOR(i,55) FOR(j,55) memo[i][j] = -1;
	heaps.clear();

	// input
	FOR(i,m) {
		int h; cin >> h; 
		heaps.pb(h);
	}

	return G(0, heaps[0]);
}

int main(){
    int t; cin >> t;

    while(t--){
        cin >> n >> m;

        // WE ARE PARALELLY PLAYING - TAKE THE NIM SUM AND SEE WHETHER WE CAN WIN
        int outcome = 0;
        FOR(i,n){
        	outcome = outcome ^ solveOne();
        }

        if(outcome == 0) cout << "SECOND" << endl; // first loses
        else cout << "FIRST" << endl; // first can win
    }

    return 0;
}
