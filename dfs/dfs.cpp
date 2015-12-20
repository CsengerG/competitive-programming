#include <bits/stdc++.h>

#define ll long long
#define FOR(i,n) for(int i=0;i<n;++i)
#define MAXN 300000
#define sz size
#define pb push_back

using namespace std;

vector<ll> g[MAXN];
bool w[MAXN];

void dfs(int v){
	w[v]=true;

	FOR(i,g[v].sz()){
		if(w[g[v][i]]==false) dfs(g[v][i]);
	}
}

int main(void){
	ll n,m; cin >> n >> m;

	FOR(i,m){
		ll a,b;
		cin >> a;
		cin >> b;
		a--; b--;
		g[a].pb(b);
		g[b].pb(a);
	}

	ll comp=0;

	FOR(i,n) if(w[i]==false){
		dfs(i);
		comp++;
	}

	cout<<comp<<endl;

	return 0;
}
