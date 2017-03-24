#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;++i)
#define mp make_pair
#define pb push_back
#define vi vector<int>

using namespace std;

vi x, y;
int main(){
	int n;
	cin >> n;

	FOR(i,n){
		int a,b;
		cin>>a>>b;
		x.pb(a);
		y.pb(b);
	}

	double area = 0.0;

	// count the area of a polygon by the determinant of the matrix formed from its points
	FOR(i,n) {
		area += x[i]*y[(i+1)%n];
		area -= y[i]*x[(i+1)%n];
	}
	
	area = 0.5*area;
	area = fabs(area);

	cout << area << endl;
}
