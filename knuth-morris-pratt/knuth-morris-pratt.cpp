#include <bits/stdc++.h>

#define int long long
#define FOR(i,n) for(int i=0;i<n;++i)
#define sz size

using namespace std;

const int maxn = 300100;

int n,m;
string t,p;
string T, P;
int pi[maxn];

// compute the KMP table
void computePi(){
    pi[1] = 0;

    for(int i=1;i<P.sz();++i){
        int q = pi[i];
        if ( P[i+1] == P[q+1] ) pi[i+1] = q + 1;
        else {
            while(q != 0){
                q = pi[q];
                if( P[i+1] == P[q+1] ){
                    pi[i+1] = q + 1;
                    break;
                }
            }

            if(q==0) pi[i+1]=0;
        }
    }
}

//kmp
void kmp(){
    int q = 0;
    int i = 0;

    while( i < n ){
        if( P[q+1] == T[i+1] ){
            q++;
            i++;
            if( q == m ){
                cout << "match from " << i-m+1 << endl;
                q = pi[q];
            }
        } else {
            if(q==0) ++i;
            else q = pi[q];
        }
    }
}

main(){
    cin >> t; // original string
    cin >> p; // the pattern we want to search for

    // more readable
    n = t.size();
    m = p.size();
    
    T = "$";
    P = "#";

    // start indexing from 1
    FOR(i,t.sz()) T = T + t[i];
    FOR(i,p.sz()) P = P + p[i];

    computePi();
    kmp();
    
    return 0;
}
