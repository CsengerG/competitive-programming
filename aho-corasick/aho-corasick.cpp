#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;++i)
#define mp make_pair
#define pb push_back
#define FAIL -1

using namespace std;

const int maxn = 300100;
const int sigma = 100;

int g[maxn][sigma]; // goto function
int parent[maxn]; // parent
int ch[maxn]; // represented character
int failure[maxn];
bool w[maxn];

vector<int> output[maxn]; // output function
string s[maxn];

int sz = 1;
int root = 0;

void add (string S, int out_id){
    int v = 0;

    FOR(i,S.size()){
        char c = S[i];
        if(g[v][c-'A'] == FAIL){
            g[v][c-'A'] = sz; // if doesnt exist create it
            parent[sz] = v;
            ch[sz] = c - 'A';
            sz++;
        }
        
        v = g[v][c-'A'];

        if(i==S.size()-1) output[v].push_back(out_id);
    }

}

void compute_failure(){
    queue<pair<int,int> > q;
    q.push(mp(0,0));

    while(!q.empty()){
        // next node
        int v = q.front().first;
        w[v] = true;

        int depth = q.front().second;
        // delete it
        q.pop();

        // BFS - add neighbours
        FOR(i,sigma){
            if(g[v][i]!=FAIL){
                if(!w[g[v][i]])
                    q.push(mp(g[v][i],depth+1));
            }
        }

        if(depth == 0 or depth == 1) failure[v] = 0; // by definition
        else { // compute failure function
            int state = failure[parent[v]]; // its already computed due to BFS
            char c = ch[v]; // represented char by this node

            while(g[state][c] == FAIL) {
                state = failure[state]; // traverse trie by suffix links
                cout << "*" << endl;
                cout << v << endl;
            }

            state = g[state][c]; // doesnt FAIL anymore, we can get the failure node

            failure[v] = state; // set the value

            // add output from 'state'
            FOR(i,output[state].size()){
                output[v].pb(output[state][i]);
            }
        }
    }
}

int main(){
    // init
    FOR(i,maxn) FOR(j,sigma) g[i][j]=FAIL;
    FOR(i,maxn) {
        parent[i] = FAIL;
        failure[i] = FAIL;
    }

    // input
    string m;
    cin >> m;

    int n;
    cin >> n;

    FOR(i,n){
        cin >> s[i];
        add(s[i],i);
    }


    // computeing failure function
    FOR(i,sigma) if(g[0][i]==FAIL) g[0][i] = 0;
    compute_failure();

    int state = 0;
    FOR(i,m.size()){
        cout << "state: " << state << endl;
        char nextchar = m[i];

        if( g[state][nextchar] != FAIL ) state = g[state][nextchar-'A'];
        else {
            while( g[state][nextchar-'A'] == FAIL ) state = failure[state];
            state = g[state][nextchar-'A'];
        }

        cout << "found strings:" << endl;
        for(auto o: output[state]) cout << s[o] << " ";
        cout << endl;
    }

    return 0;
}
