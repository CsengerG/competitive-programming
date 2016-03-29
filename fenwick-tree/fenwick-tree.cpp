#include <bits/stdc++.h>

using namespace std;

const int size=100;
int ft[size];

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

int main(void){
}
