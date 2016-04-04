#include <bits/stdc++.h>

using namespace std;

vector<int> g[300000];
vector<int> ig[300000];
vector<int> top;
bool w[300000];

void dfstop(int v){
    w[v]=true;

    for(int i=0;i<g[v].size();++i){
        if(!w[g[v][i]]) dfstop(g[v][i]);
    }

    top.push_back(v);
}

void dfscomp(int v){
    w[v]=true;

    for(int i=0;i<ig[v].size();++i){
        if(!w[ig[v][i]]) dfscomp(ig[v][i]);
    }
    
    cout<<v+1<<" ";

}

int main(void){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;++i){
        int a,b;cin>>a>>b;a--;b--;
        g[a].push_back(b);
        ig[b].push_back(a);
    }

    for(int i=0;i<n;++i){
        if(!w[i]) dfstop(i);
    }

    for(int i=0;i<n;++i) w[i]=false;

    for(int i=top.size()-1;i>=0;--i){
        if(!w[top[i]]){
            dfscomp(top[i]);
            cout<<endl;
        }
    }

    return 0;
}
