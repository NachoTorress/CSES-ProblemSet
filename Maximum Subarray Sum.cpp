#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll maxSum=-(1e18), actSum=0, n;
	cin>>n;
	vector <ll> nums(n);
	for (auto &i:nums){
		cin>>i;
	}
	for (auto i:nums){
		actSum+=i;
		
		maxSum=max(maxSum,actSum);
		if(actSum<0) actSum=0;
	}
	cout<<maxSum;
}
