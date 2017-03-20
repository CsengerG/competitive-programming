#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;

	for(int i=0;i<n;++i){
		int m = (int)('z')-(int)('a');
		char c = rand()%m + (int)('a');
		cout << c;
	}

	cout << endl;
}
