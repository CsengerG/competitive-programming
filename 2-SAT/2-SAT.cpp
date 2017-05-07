#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<(int)n;++i)
#define REP(i,s,n) for(int i=s;i<(int)n;++i)
#define vi vector<int>
#define mp make_pair
#define pb push_back

using namespace std;

typedef pair<int,int> path;
const int maxn = 300100;

int komp = 0;
int cnt = 0;

int scc[maxn];
bool ans[maxn];

vector<path> paths;
vector<int> g[maxn];
vector<int> tg[maxn]; // transpose graph

stack<int> s;
vector<int> tp;

bool visited[maxn];

// check if two paths intersect
bool intersect(path p1, path p2){
    if(p1>p2) swap(p1,p2);
    
    if(p1.first < p2.first and p2.first < p1.second and p1.second < p2.second) return true;

    return false;
}

void dfs(int v){
    visited[v] = true;

    for(auto u: g[v]) if(!visited[u]) dfs(u);

    s.push(v);
    tp.pb(v);
}

// dfs on transpose graph
void dfs2(int v){
    visited[v] = true;
    scc[v] = komp;

    for(auto u: tg[v]){
        if(!visited[u]) dfs2(u);
    }
}

// fill logical values
void fill(int v, bool mustbetrue){
    visited[v] = true;

    if(scc[v] > scc[v^1] or mustbetrue){
        ans[v] = true;
        mustbetrue = true;
    } else {
        ans[v] = false;
    }

    for(auto u: g[v]) if(not visited[u]) fill(u, mustbetrue);
}

int main(){
    int n, m;
    cin >> n >> m;

    FOR(i,m) {
        int a,b;
        cin >> a >> b;
        paths.pb(mp(min(a,b), max(a,b)));
    }

    FOR(i,m){
        REP(j,i+1,m){
            if(intersect(paths[i], paths[j])){
                int i_inside = 2*i;
                int j_inside = 2*j;

                // cleverly choose the edges

                // i inside -> j outside
                g[i_inside].pb(j_inside^1);

                //  i outside -> j inside
                g[i_inside^1].pb(j_inside);

                
                // j inside -> i outside
                g[j_inside].pb(i_inside^1);

                // j outside -> i inside
                g[j_inside^1].pb(i_inside);

                // transpose graph
                tg[j_inside^1].pb(i_inside);
                tg[j_inside].pb(i_inside^1);
                tg[i_inside^1].pb(j_inside);
                tg[i_inside].pb(j_inside^1);
            }
        }
    }

    // dfs
    FOR(i,2*m) if(!visited[i]) dfs(i);
    memset(visited, false, sizeof(visited));

    // count components in order
    while(!s.empty()){
        int v = s.top(); s.pop();

        if(!visited[v]){
            dfs2(v);
            ++komp;
        }
    }

    // check if it is possible
    for(int i=0;i<2*m;i+=2){
        if(scc[i] == scc[i^1]){
            cout << "Impossible" << endl;
            return 0;
        }
    }

    // fill in the good values
    memset(visited, false, sizeof visited);
    FOR(i,2*m) if(not visited[i]) fill(i, false);

    // output answer
    for(int i=0;i<2*m;i+=2) cout << (ans[i] ? "i" : "o");
    cout << endl;

    return 0;
}
