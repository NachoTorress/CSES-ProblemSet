#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll n; cin>>n;
	vector <ll> nums (n);
	for (auto &i:nums) cin>>i;
	sort (nums.begin(), nums.end());
	ll costo=0;
	int medio=nums[n/2];
	for (auto i:nums) costo+=abs(i-medio);
	cout<<costo;
}
