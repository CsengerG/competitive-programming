#include <bits/stdc++.h>
#define pb push_back

using namespace std;

const int maxn=300000; 
int r[maxn];
int apa[maxn];

struct El{
    int a,b;
    long long w;
    El(int u, int v, long long c){
        a = u;
        b = v;
        w = c;
    }

    bool operator<(const El& other){
        return (w < other.w);
    }
};

int find(long long x){
    if(apa[x]==x){
        return apa[x];
    } else {
        apa[x]=find(apa[x]);
        return apa[x];
    }
}

void unio(long long x, long long y){
    int xroot=find(x);
    int yroot=find(y);

    if(r[xroot]>r[yroot]) apa[yroot]=xroot;
    else if(r[yroot]>r[xroot]) apa[xroot]=yroot;
    else {
        r[xroot]++;
        apa[yroot]=xroot;
    }
}

vector<El> elek;
int main(void){
	ios_base::sync_with_stdio(false);
    
    elek.clear();
    for(long long i=0;i<maxn;++i){
        apa[i]=i;
        r[i]=0;
    }
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i){
        long long c;
        int a,b;cin>>a>>b>>c;
        elek.pb(El(a,b,c));
    }

    sort(elek.begin(),elek.end());

    int i=0;
    int bent=0;
    while(bent!=n-1){
        int a = elek[i].a;
        int b = elek[i].b;
        long long c = elek[i].w;

        if(find(a)!=find(b)){
            unio(a,b);
            cout<<a<<" "<<b<<" "<<c<<endl;
            bent++;
        }
        ++i;
    }

    return 0;
}
