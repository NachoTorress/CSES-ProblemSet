#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll n; cin>>n;
	for (int i=1;i<=n;i++){
		cin>>nums[i];
	}
	sort (nums.begin(), nums.end());
	ll num=1; 
	for (int i=1;i<=n;i++){
		if (nums[i]>num){
			cout<<num;
			return 0;
		}
		else num+=nums[i];
	}
	cout<<num<<endl;
}
