#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define sz size
#define FOR(i,n) for(ll i=0;i<(ll)n;++i)

using namespace std;

const ll maxn=300000;
vector<ll> g[maxn];
vector<ll> dominator;
bool del[maxn],w[maxn];
stack<ll> top;

void dfstop(ll v){
    w[v]=true;

    FOR(i,g[v].sz()){
        ll cur=g[v][i];
        if(!w[cur]) dfstop(cur);
    }

    top.push(v);
}

void dfsdel(ll v){
    del[v]=true;

    FOR(i,g[v].sz()){
        ll cur=g[v][i];
        if(!del[cur]) dfsdel(cur);
    }
}

int main(void){
    ll n,m;
    cin>>n>>m;

    FOR(i,m){
        ll a,b;
        cin>>a>>b;
        a--;b--;
        g[a].pb(b);
    }

    FOR(i,n) if(!w[i]) dfstop(i);
    while(!top.empty()){
        ll cur=top.top(); top.pop();
        if(!del[cur]){
            dfsdel(cur);
            dominator.pb(cur+1);
        }
    }

    FOR(i,dominator.sz()) cout<<dominator[i]<<" ";
    cout<<endl;

    return 0;
}
