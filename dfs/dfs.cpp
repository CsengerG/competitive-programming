//A simple depth-first search
#include <bits/stdc++.h>

#define ll long long
#define FOR(i,n) for(int i=0;i<n;++i)
#define MAXN 300000
#define sz size
#define pb push_back

using namespace std;

bool w[MAXN];
void dfs(int v);

vector<ll> g[MAXN];//Vectors storing our graph
int main(){
	int n;//n - the number of vertexes in our graph
	int m;//m - the number of edges in our graph
	cin >> n >> m;

	for(int i=0;i<m;i++){
		ll a,b;
		cin >> a; a--;
		cin >> b; b--;

		g[a].push_back(b);
		g[b].push_back(a);
	}

	//let's make some fun - determine, how many
	//components our graph has
	ll comp=0;
	FOR(i,n) if(w[i]==false){
		dfs(i);
		comp++;
	}

	cout<<comp<<endl;

	return 0;
}

//The depth first search:
void dfs(int v){
	w[v]=true;
	FOR(i,g[v].sz()) if(!w[g[v][i]]) dfs(g[v][i]);
}
