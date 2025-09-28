#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1e16
#define ff first
#define sc second
int main(){
	ll n, x; cin>>n>>x;
	vector <ll> pesos (n);
	for (auto &i:pesos) cin>>i;
	vector <pair<ll,ll>> dp (1<<n, {INF,INF});
	dp[0]={1,0};
	for (ll mask=1; mask<1<<n;mask++){
		for (int bit=0;bit<n;bit++){
			if (mask & 1<<bit){
				ll prevMask =mask^(1<<bit);
				ll ocupado=dp[prevMask].sc;
				if (ocupado+pesos[bit]<=x){
					dp[mask]=min(dp[mask], {dp[prevMask].ff,ocupado+pesos[bit]});
				}
				else {
					dp[mask]=min(dp[mask], {dp[prevMask].ff+1, pesos[bit]});
				}
			}
		}
	}
	cout<<dp[(1<<n)-1].ff;
}
