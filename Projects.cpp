#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll n; cin>>n;
	vector <vector<ll>> proyectos (n,vector<ll>(3));
	for (auto &i:proyectos){
		cin>>i[2]>>i[0]>>i[1];
	}
	sort(proyectos.begin(),proyectos.end());
	set <pair <ll,ll>> disp;
	ll maxi=-1;
	disp.insert({0,0});
	for (auto act:proyectos){
		auto it=disp.lower_bound({act[2],-1});
		 it--;
		maxi=max(it->second+act[1],maxi);
		disp.insert({act[0],maxi});
	}
	cout<<maxi;
}
