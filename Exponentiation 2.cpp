#include <bits/stdc++.h>
//#define MOD 1000000007
const long long MOD=1000000007;
long long modPow(long long base, long long exponente){
	if (exponente=0) return 1;
	long long ans=modPow(base, exponente/2);
	ans=(ans*ans)%MOD;
	if (exponente%2==1) ans=(ans*base)%MOD;
	return ans;
}
using namespace std;
int main(){
	//long long MOD=1000000007;
	int n; cin>>n;
	
	while (n--){
	
	long long a, b, c; cin>>a>>b>>c;
	long long aux=modPow(b,c);
	cout<<"AUX"<<aux<<endl;
	long long num=(modPow(a,aux));
//	num%=1000000007;
	cout<<num<<endl;
}
}
