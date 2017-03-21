#include <bits/stdc++.h>

using namespace std;

const int size=100;
int ft[size];
int ft2D[size][size];

int getsum(int i){
    int sum = 0;
    while(i>0){
        sum += ft[i];
        i-=i&-i; // the meaning of this: i can be represented as A1B, where
                 // B is 00...000 and A is some series of 1 and 0 -> then
                 // -i in binary representation is reverse(i)+1, thus
                 // reverse(A)0reverse(B), where reverse(B) is 11....111
                 // with adding 1 to this we get reverse(A)10000..0000
                 // the binary and with the original i now gives the last
                 // 1 bit of the original i
    }

    return sum;
}

void add(int i, int x){
    while(i<size){
        ft[i]+=x;
        i+=i&-i;
    }
}

void add_2d(int I, int J, int x){
	int i=I;
	while(i<size){
		int j=J;
		while(j<size){
			ft2D[i][j] += x;
			j += j&-j;
		}

		i += i&-i;
	}
}

int getsum_2d(int I, int J){
	int sum = 0;
	int i=I;

	while(i>0){
		int j = J;
		while(j>0){
			sum += ft2D[i][j];
			j-=j&-j;
		}
		i-=i&-i;
	}

	return sum;
}

int main(void){
	// TEST 1D
	
	// 0 0 0 0 0 0 0 0 0 0 ...
	add(5,10);
	add(7,20);
	// 0 0 0 0 10 0 20 0 0 ...
	cout << getsum(8) << endl; // supposed to be 30
	cout << getsum(6) << endl; // supposed to be 10
	cout << getsum(3) << endl; // supposed to be 0
	cout << endl;
	// TEST 2D

	// 0 0 0
	// 0 0 0
	// 0 0 0
	add_2d(2,2,10);
	add_2d(3,3,10);
	// 0 0 0
	// 0 10 0
	// 0 0 10
	cout << getsum_2d(3,3) << endl; // supposed to be 20
	cout << getsum_2d(2,2) << endl; // supposed to be 10;
	cout << getsum_2d(2,3) << endl; // 10
	cout << getsum_2d(1,2) << endl; // 0
}
