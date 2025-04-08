#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll n, obj; cin>>n>>obj;
	vector <pair<ll,ll>> nums (n);
	
	for (int i=0;i<n;i++){
		ll aux; cin>>aux; 
		nums[i]={aux,i+1};
	}
	sort (nums.begin(), nums.end());
	ll i=0,j=1,k=n-1;
	if (n<3){
		cout<<"IMPOSSIBLE";
		return 0;
	}
	if (n==3){
		if (nums[0].first+nums[1].first+nums[2].first==obj){
			cout<<nums[0].second<<" "<<nums[1].second<<" "<<nums[2].second;
			return 0;
		}
		cout<<"IMPOSSIBLE";
		return 0;
		}
	
	for (i=0;i<n;i++){
		ll x2=obj-nums[i].first;
		for (int j=i+1,k=n-1;j<k;j++) 
		{
		while (nums[j].first+nums[k].first>x2 ) k--;
		if (nums[i].first+nums[j].first+nums[k].first==obj){
				cout<<nums[i].second<<" "<<nums[j].second<<" "<<nums[k].second;
				return 0;
				}
	}
}
	cout <<"IMPOSSIBLE";
	return 0;
}
