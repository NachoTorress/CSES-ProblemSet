#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool can(vector <ll> nums, ll x, ll k){
	ll kAct=1, sumAct=0;
	for (auto i:nums){
		if (i>x) return false;
		if (sumAct+i<=x) sumAct+=i;
		else kAct++, sumAct=i;
		
	}
	return kAct<=k;
}
int main(){
	ll n,k; cin>>n>>k; 
	vector <ll> nums (n);
	unsigned ll suma=0;
	for (auto &i:nums){
		cin>>i;
		suma+=i;
	}
	ll lo=0, hi=suma, mid;
	while (lo!=hi){
		mid= lo + ((hi-lo)/2);
		if (can(nums,mid,k)) hi=mid;
		else lo=mid+1;		
	}
	cout<<hi;
}
