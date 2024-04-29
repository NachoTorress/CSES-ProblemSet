#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, x; cin>>n>>x;
	map <int, vector <int>> nums;
	int aux, pos1=0, pos2=0, pos3=0;
	for (int i=1;i<=n;i++){
		cin>>aux;
		
		for (auto j:nums){
		int aBuscar=x-aux-j.first;
		if (aBuscar>0){
			if (aBuscar!=j.first){
				if (nums[aBuscar].size()!=0){
					pos1=i, pos2=j.second[0], pos3=nums[aBuscar][0];
				}
			}
			else {
				if (nums[aBuscar].size()>2){
					pos1=i, pos2=j.second[0], pos3=j.second[1];
				}
			}
		}
		}
		nums[aux].push_back(i);
	}
	if (pos1!=0) cout<<pos1<<" "<<pos2<<" "<<pos3;
	else cout<<"IMPOSSIBLE";
}
