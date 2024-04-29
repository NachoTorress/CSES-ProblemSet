#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
void mostrarM(vector <vector <int>> m){
	for (int i=0;i<m.size();i++){
		for (int j=0;j<m[i].size();j++)cout<<m[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}
int main(){
	long long n;
	cin>>n;
	vector <string> path (n);
	for (auto &i : path) cin>>i;
	vector <vector <long long>> dp (n+1, vector <long long> (n+1,0));
	dp[1][1]=0;
	if (path[0][0]=='*'){
		cout<<0;
		return 0;
	}
	if (n==1){
		cout<<1;
		return 0;
	}
	if (path[0][1]=='.')dp[1][2]=1;
	if (path[1][0]=='.') dp[2][1]=1;
	//mostrarM(dp);
	for (long long i=1;i<=n;i++){
		for (long long j=1;j<=n;j++){
			if ((i==1 && j==2) || (i==2 && j==1) || (i==1 && j==1)) continue;
			if (path[i-1][j-1]=='.') dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
		}
	}
	//mostrarM(dp);
	cout<<dp[n][n];
}
