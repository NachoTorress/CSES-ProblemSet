#include <bits/stdc++.h>
using namespace std;
void mostrar(vector <int> v){
	cout<<endl;
	for (auto i: v) cout<<i<<" ";
	cout<<endl;
}
int main(){
	int n, x;
	cin>>n>>x;
	vector <int> coins (n);
	for (auto &i : coins) cin>>i;
	vector <int> dp (x+1, 1e9);
	dp[0]=0;
	for (int i=0;i<=x;i++){
		for (int j=0;j<n;j++){
			if (i+coins[j]<=x)
				dp[i+coins[j]]=min(dp[i]+1, dp[i+coins[j]]);
		}
	}
	//mostrar(dp);
	if (dp[x]==1e9) dp[x]=-1;
	cout<<dp[x];
}
