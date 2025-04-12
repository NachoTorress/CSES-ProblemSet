#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define sc second
int main(){
	ll n,q; cin>>n>>q;
	vector <ll> pos(n+1), nums(n+1);
	for (int i=1;i<=n;i++){
		cin>>nums[i];
		pos[nums[i]]=i;
	}
	ll ciclos=1;
	for (int i=2;i<=n;i++){
		if (pos[i]<pos[i-1]) ciclos++;
	}
	
	while (q--){
		ll pos1, pos2; cin>>pos1>>pos2;
		set <pair<ll,ll>> pares;
		if (nums[pos1]-1>=1) pares.insert({nums[pos1]-1,nums[pos1]});
		if (nums[pos2]-1>=1) pares.insert({nums[pos2]-1,nums[pos2]});;
		if (nums[pos1]+1<=n) pares.insert({nums[pos1], nums[pos1]+1});
		if (nums[pos2]+1<=n) pares.insert({nums[pos2], nums[pos2]+1});
		
		for (auto i:pares){
			if (pos[i.ff]>pos[i.sc]) ciclos--;
		}
		
		swap (pos[nums[pos1]], pos[nums[pos2]]);
		swap(nums[pos1], nums[pos2]);
		for (auto i:pares){
			if (pos[i.ff]>pos[i.sc]) ciclos++;
		}
		cout<<ciclos<<endl;
	}
	return 0;
}
