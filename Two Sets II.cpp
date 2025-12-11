#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define sc second
#define MOD 1000000007
int main(){
	ll n; cin>>n;
	ll sum=((n+1)*n)/2;
	if (sum%2){
		cout<<0;
		return 0;
	}
	ll res=sum/2;
	vector <ll> dp (res+1);
	dp[0]=1;
	for (int i=1;i<=n;i++){
		for (int j=res;j>=i;j--) dp[j]=(dp[j-i]+dp[j])%MOD;
	}
   	cout<<(dp[res]*500000004)%MOD;
}
