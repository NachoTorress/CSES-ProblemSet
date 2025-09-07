#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll n, x; cin>>n>>x;
	vector <ll> nums (n);
	for (auto &i:nums) cin>>i;
	map<ll,ll> prefixes;
	ll sum=nums[0];
	prefixes[0]=1;
	ll resultado=0;
	for (int i=1;i<n;i++){
		resultado+=prefixes.count(sum-x)? prefixes[sum-x]:0;
		prefixes[sum]++;
		sum+=nums[i];
	}
	resultado+=prefixes.count(sum-x)? prefixes[sum-x]:0;
	cout<<resultado;
}
