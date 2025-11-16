#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll a,b; cin>>a>>b;
	vector <ll> nums1 (a), nums2(b);
	for (auto &i:nums1)cin>>i;
	for (auto &i:nums2)cin>>i;
	vector <vector <ll>> dp (a+1, vector <ll>(b+1));
	for (int i=1;i<=a;i++){
		for (int j=1;j<=b;j++){
			dp[i][j]=max(dp[i-1][j-1]+(nums1[i-1]==nums2[j-1]), max(dp[i-1][j], dp[i][j-1]));
		}
	}
	vector <ll> res;
	ll i=a, j=b;
	while (i && j)
	{
		if (nums1[i-1]==nums2[j-1]){
			res.push_back(nums1[i-1]);
			i--,j--;
		}
		else if (dp[i][j-1]>dp[i-1][j]) j--;
		else i--;
	}
	reverse (res.begin(), res.end());
	cout<<res.size()<<endl;
	for (auto i:res) cout<<i<<" ";
}

