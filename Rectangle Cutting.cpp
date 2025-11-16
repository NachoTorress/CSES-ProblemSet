#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1e16
int main(){
	ll a,b; cin>>a>>b;
	vector <vector <ll>> dp (a+1,vector <ll>(b+1));
	for (int i=1;i<=a;i++){
		for (int j=1;j<=b;j++){
			if (i==j) dp[i][j]=0;
			else dp[i][j]=INF;
			for (int k=1;k<i;k++) dp[i][j]=min(dp[i][j], dp[i-k][j]+dp[k][j]+1);
			for (int k=1;k<j;k++)dp[i][j]=min(dp[i][j], dp[i][j-k]+dp[i][k]+1);
		}
	}
	cout<<dp[a][b];
}
