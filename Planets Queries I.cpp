#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n, q; cin>>n>>q;
	ll m=30;
	vector <vector <ll>> dp (m, vector <ll> (n+1));
	for (int i=1;i<=n;i++) cin>>dp[0][i];
	for (int i=1;i<m;i++){
		for (int j=1;j<=n;j++){
			dp[i][j]=dp[i-1][dp[i-1][j]];
		}
	}
	while (q--){
		ll x, k; cin>>x>>k; 
		ll act=x;
		for (int i=m-1;i>=0;i--){
			if ((1<<i) & k) act=dp[i][act];
			
		}
		cout<<act<<'\n';
	}
}
