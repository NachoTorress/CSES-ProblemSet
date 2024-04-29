#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int main(){
	int n, x;
	cin>>n>>x;
	vector <int> coins (n);
	vector <int> dp(x+1, 0);
	for (auto &i : coins) cin>>i;
	for (int i=0;i<n;i++){
		if (coins[i]<x+1)
			dp[coins[i]]=1;
	}
	for (int i=0;i<=x;i++){
		for (int j=0;j<n;j++){
			if (i+coins[j]<=x+1)
			dp[i+coins[j]]=(dp[i]+dp[i+coins[j]])%MOD;
		}
	}
	cout<<dp[x];
}
