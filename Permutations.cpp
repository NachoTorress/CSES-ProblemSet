#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	if (n==2 || n==3) cout<<"NO SOLUTION";
	else if (n==4) cout<<"2 4 1 3 ";
	else if (n==1) cout<<1;
	else if (n>4){
	vector <int> nums;
	priority_queue<int> lista1, lista2;
	for (int i=1;i<=n/2+1;i++){
		nums.push_back(i);
		if (n+1-i>n/2+1)
		nums.push_back(n+1-i);
	}
	swap (nums[0], nums[nums.size()-1]);
	for( auto i: nums){
		cout<<i<<" ";
	}
}
}
