#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;++i)

using namespace std;

// simple NIM game
const int maxn = 300100;
int a[maxn];

int main(){
	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;

		int one = 0;
		int kek = 0;

		FOR(i,n){
			cin >> a[i];
			kek ^= a[i];
			if(a[i]==1) one++;
		}

		if(one==n and one%2==1) cout << "Brother" << endl;
		else if(one==n and one%2==0) cout << "John" << endl;
		else if(kek==0) cout << "Brother" << endl;
		else cout << "John" << endl;
	}

    return 0;
}
