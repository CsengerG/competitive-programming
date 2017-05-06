#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;++i)
#define point pair<long long,long long>
#define mp make_pair
#define pb push_back
#define xx first
#define yy second

using namespace std;

const long long maxperson = 410;
const long long maxtaxicab = 210;
const long long maxn = maxtaxicab + maxperson + 10;

const long long source = maxn-5;
const long long sink = maxn-4;

long long flow[maxn][maxn];
long long res[maxn][maxn];
long long cap[maxn][maxn];

bool was[maxn];
long long parent[maxn];

vector<long long> edges[maxn];
vector<point> persons, taxicabs;

long long dist(point a, point b){
    return abs(a.xx-b.xx) + abs(a.yy-b.yy);
}

long long augment(long long s, long long t){
    FOR(i,maxn) was[i] = false;
    queue<long long> q;

    parent[s] = -1;
    q.push(s);
    was[s] = true;

    while(!q.empty()){
        long long current = q.front(); q.pop();

        for(auto neighbour: edges[current]){
            if(!was[neighbour] and res[current][neighbour] > 0){
                parent[neighbour] = current;
                q.push(neighbour);
                was[neighbour] = true;
            }
        }

        if(current == t) {
            long long ret = 999999999;
            while(parent[current] != -1){
                ret = min(ret, res[parent[current]][current]);
                current = parent[current];
            }

            return ret;
        }
    }

    return 0;
}

long long maxflow(long long s, long long t){
    long long f = 0;
    FOR(i,maxn){
        FOR(j,maxn){
            flow[i][j] = 0;
            res[i][j] = 0;
            
            if(cap[i][j] > 0){
                res[i][j] = cap[i][j] - flow[i][j];
                res[j][i] = flow[i][j];
            }
        }
    }

    while(true){
        long long delta = augment(s,t);

        if(delta == 0) return f;
        else {
            f += delta;

            long long current = t;
            while(parent[current] != -1){
                // flow[parent[current]][current] += delta;
                res[parent[current]][current] -= delta;
                res[current][parent[current]] += delta;

                current = parent[current];
            }
        }
    }
}

int main(){
    long long k;
    cin >> k;

    while(k--){
        FOR(i,maxn){
            FOR(j,maxn) {
                cap[i][j] = 0;
                flow[i][j] = 0;
                res[i][j] = 0;
            }

            edges[i].clear();
            was[i] = false;
            parent[i] = -1;
        }

        persons.clear();
        taxicabs.clear();

        long long number_of_persons, number_of_taxicabs, speed, time;
        cin >> number_of_persons >> number_of_taxicabs >> speed >> time;

        FOR(i,number_of_persons){
            long long x,y;
            cin >> x >> y;
            persons.pb(mp(x,y));

            edges[maxtaxicab+i].pb(sink);
            edges[sink].pb(maxtaxicab+i);
            cap[maxtaxicab+i][sink] = 1;
        }

        FOR(i,number_of_taxicabs){
            long long x,y;
            cin >> x >> y;
            taxicabs.pb(mp(x,y));

            edges[source].pb(i);
            edges[i].pb(source);
            cap[source][i] = 1;
        }

        FOR(i,number_of_persons){
            FOR(j,number_of_taxicabs){
                long long d = dist(persons[i], taxicabs[j]) * 200;

                if( d <= speed*time ){
                    edges[j].pb(maxtaxicab+i);
                    edges[maxtaxicab+i].pb(j);
                    cap[j][maxtaxicab+i] = 1;
                }
            }
        }

        cout << maxflow(source, sink) << endl;
    }

    return 0;
}
