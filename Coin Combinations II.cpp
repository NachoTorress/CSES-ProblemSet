#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int main(){
	long long n, x;
	cin>>n>>x;
	vector <long long> coins (n);
	for (auto &i : coins) cin>>i;
	vector <long long> DP (x+1, 0);
	DP[0]=1;
	/*for (int i=0;i<=x;i++){
		for (int j=0;j<n;j++){
			if (coins[i]+)
			DP[i+coins[j]]+=DP[i];
		}
	}*/
	for (long long i=0;i<n;i++){
		for (long long j=0;j<=x;j++){
			if (coins[i]+j<=x) DP[j+coins[i]]=(DP[j+coins[i]]+DP[j])%MOD;
		}
	}
	cout<<DP[x];
}
