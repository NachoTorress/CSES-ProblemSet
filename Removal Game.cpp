#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll n; cin>>n;
	vector <ll> nums (n);
	vector <vector <ll>> dp (n, vector <ll> (n,0));
	ll sumTotal=0;
	for (int i=0;i<n;i++){
		cin>>nums[i];
		dp[i][i]=nums[i];
		sumTotal+=nums[i];
	}
	for (int izq=n-1;izq>=0;izq--){
		for (int der=izq+1;der<n;der++){
			dp[izq][der]=max(nums[izq]-dp[izq+1][der], nums[der]-dp[izq][der-1]);
		}
	}
	cout<<(sumTotal+dp[0][n-1])/2;
}
