//Union-find algorithm
#include <bits/stdc++.h>

#define ll long long
#define FOR(i,n) for(int i=0;i<n;++i)
#define MAXN 300000

ll pa[MAXN];
ll r[MAXN];

using namespace std;

ll f(ll x){
	if(pa[x]==x) return x;

	return pa[x]=f(pa[x]);
}

void u(ll x, ll y){
	x=f(x);
	y=f(y);

	if(x==y) return;

	if(r[x]<r[y]) pa[x]=y;
	if(r[y]<r[x]) pa[y]=x;
	else{
		r[y]++;
		pa[x]=y;
	}
}

int main(void){
	FOR(i,MAXN){
		pa[i]=i;
		r[i]=0;
	}

	ll n; cin >> n;
	FOR(i,n){
		char tp; cin >> tp;
		if(tp == 'u'){
			ll a,b; cin >> a >> b; a--; b--;
			u(a,b);
		}
		
		if(tp == 'f'){
			ll x; cin >> x; x--;
			cout<<f(x)<<endl;
		}
	}
}
