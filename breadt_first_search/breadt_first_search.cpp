#include <bits/stdc++.h>

using namespace std;

const int maxn=100;
int dist[maxn];
bool w[maxn];
vector<int> g[maxn];
int n,m;
queue<int> q;

void bfs(int v){
    q.push(v);
    dist[v]=0;

    while(!q.empty()){
        int currv = q.front();
        w[currv]=true;

        for(int i=0;i<g[currv].size();++i){
            int neighb = g[currv][i];
            if(!w[neighb]){
                q.push(neighb);
                dist[neighb]=1+dist[currv];
            }
        }

        q.pop();
    }
}

int main(void){
    cin>>n>>m;

    for(int i=0;i<m;++i){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bfs(1);

    for(int i=1;i<=n;++i){
        cout<<i<<" -> "<<dist[i]<<endl;
    }
}
