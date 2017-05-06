#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;++i)
#define point pair<long long,long long>
#define mp make_pair
#define pb push_back
#define xx first
#define yy second

using namespace std;

const int maxn = 310;
const int infty = 7777;

int rescap[maxn][maxn];
int cap[maxn][maxn];

bool visited[maxn];
long long parent[maxn];

vector<long long> edges[maxn];
int n;

bool BFS(long long s, long long t){
    memset(visited,false,sizeof(visited));
    memset(parent, -1, sizeof(parent));

    queue<long long> q;
    parent[s] = -1;
    visited[s] = true;
    q.push(s);

    while(!q.empty()){
        int current = q.front(); q.pop();

        for(int next=1;next<=n;++next){
            if(visited[next]==false and rescap[current][next] > 0){
                visited[next] = true;
                parent[next] = current;
                q.push(next);
            }
        }

        if(current == t) {
            break;
        }
    }

    int current = t;
    while(parent[current] != -1){
        int from = parent[current];

        rescap[from][current]--;
        rescap[current][from]++;

        current = from;
    }

    return visited[t];
}

void init(){
    FOR(i,maxn){
        FOR(j,maxn) {
            cap[i][j] = 0;
            rescap[i][j] = 0;
        }

        edges[i].clear();
        visited[i] = false;
        parent[i] = -1;
    }
}

int main(){
    int t;
    cin >> t;

    while(t--){
        init();
        cin >> n;
       
        for(int i=1;i<=n-1;++i){
            int m; cin >> m;

            FOR(j,m){
                int v; cin >> v;
                
                edges[i].pb(v);
                if(i == 1 or v == n) rescap[i][v] = 1;
                else rescap[i][v] = infty;
            }
        }

        int ans = 0;
        while(BFS(1,n)) ans++;
        cout << ans << endl;
    }

    return 0;
}
