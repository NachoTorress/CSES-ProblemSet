#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll n,q;
	cin>>n>>q;
	vector <vector <bool>> bosque(n+1,vector<bool>(n+1,0)); vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			char aux; cin>>aux;
			bosque[i][j]=(aux=='*');
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			dp[i][j]=dp[i-1][j]+dp[i][j-1]+bosque[i][j]-dp[i-1][j-1];	
		}
	}
	while (q--){
		ll x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		ll ans=dp[x2][y2]-dp[x2][y1-1]-dp[x1-1][y2]+dp[x1-1][y1-1];
		cout<<ans<<"\n";
	}
}
