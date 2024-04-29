#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	cin>>n;
	vector <long long> nums (n);
	for(auto &i : nums) cin>>i;
	vector <long long> sumaPref (n+1);
	sumaPref[0]=0;
	for (int i=1;i<=n;i++){
		sumaPref[i]=sumaPref[i-1]+nums[i-1];
	}
	long long q; cin>>q;
	//for (auto i: sumaPref ) cout<<i<<" ";
	while (q--){
		long long a, b;
		cin>>a>>b;
		cout<<sumaPref[b+1]-sumaPref[a]<<"\n";
	}
	
}
