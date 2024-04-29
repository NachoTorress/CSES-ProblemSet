#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool can(vector <ll> machines, ll x, ll mid){
	ll total=0;
	for (auto i:machines) total+=mid/i;
	return total>=x;
}
int main(){
	ll n, x; cin>>n>>x;
	vector <ll> machines(n);
	ll maxT=100000000000;
	for (auto &i:machines) {
	cin>>i;
	maxT=min(maxT,i);
}

	unsigned ll lo=0, hi=maxT*x,  mid;
	while (hi-lo>1){
		mid=(hi+lo)/2;
		if (can(machines,x,mid)) hi=mid;
		else lo=mid;
	}
	cout<<hi;
	
	
}
