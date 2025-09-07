#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll n,x; cin>>n>>x;
	vector <ll> nums (n);
	for (auto &i : nums) cin>>i;
	ll sum=0, respuesta=0;
	ll i=0,j=0;
	while (j<n){
			sum+=nums[j];
			j++;
		
		if (sum>=x){
			
			while (sum>x){
				sum-=nums[i];
				i++;
			}
			if (sum==x) respuesta++;
		}
	}
	cout<<respuesta;
}
