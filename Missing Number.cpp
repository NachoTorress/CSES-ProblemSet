#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector <int> nums (n-1);
	for (auto &i : nums) cin>>i;
	if (n>2){
	sort (nums.begin(), nums.end());
	int hi=n-1, lo=0, mid;
	while (hi-lo>1){
		mid=(hi+lo)/2;
		if (nums[mid]==mid+1) lo=mid;
		else hi=mid;
	}
	cout<<hi+1;
} 
else {
	if (nums[0]==1)	cout<<2;
	else cout<<1;
}
}
