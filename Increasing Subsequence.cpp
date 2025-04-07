#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll n; cin>>n; 
	vector <ll> nums (n);
	for (auto  &i:nums) cin>>i;
	vector <ll> res;
	res.push_back(nums[0]);
	for (int i=1;i<n;i++){
		if (nums[i]>res.back()) res.push_back(nums[i]);
		else {
			ll pos=lower_bound(res.begin(), res.end(), nums[i])-res.begin();
			res[pos]=nums[i];
			}
	}
	cout<<res.size();
}

