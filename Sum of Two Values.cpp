#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n, x;
	cin>>n>>x;
	map <int, int> nums;
	for (int i=1;i<=n;i++){
		int aux; cin>>aux;
		
		if (x-aux>0)
			if (nums[x-aux]>0){
			 cout<<i<<" "<<nums[x-aux];
			 return 0;
		}
			
		nums[aux]=i;
	}
	cout<<"IMPOSSIBLE";
	}

