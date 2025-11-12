#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	string a, b; cin>>a>>b;
	ll sizeA=a.size(), sizeB=b.size();
	vector <vector <ll>> dp (sizeA+1, vector <ll>(sizeB+1,0));
	for (int i=0;i<=sizeA;i++){
		dp[i][0]=i;
	}
	for (int i=0;i<=sizeB;i++){
		dp[0][i]=i;
	}
	for (int i=1;i<=sizeA;i++){
		for (int j=1;j<=sizeB;j++){
			dp[i][j]=min(dp[i-1][j]+1, min(dp[i][j-1]+1, dp[i-1][j-1]+(a[i-1]!=b[j-1])));
		}
	}
	cout<<dp[sizeA][sizeB];
}
