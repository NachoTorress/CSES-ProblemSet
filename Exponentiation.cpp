#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long binpow(long long a, long long b) {
    a%=MOD;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    } 
    return res;
}
int main(){
	int t; cin>>t;
	while (t--){
		long long a, b;
		cin>>a>>b;
		cout<<binpow(a,b)<<endl;
	}
}
