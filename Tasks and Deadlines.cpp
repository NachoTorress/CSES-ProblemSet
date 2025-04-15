#include <bits/stdc++.h>
using namespace std;
#define ff first 
#define sc second
#define ll long long
int main(){
	ll n; cin>>n;
	vector <pair<ll,ll>> tareas;
	for (int i=0;i<n;i++){
		ll a,b; cin>>a>>b;
		tareas.push_back({a,b});
	}
	sort(tareas.begin(), tareas.end());
	ll diaAct=0, res=0;
	for (int i=0;i<n;i++){
		diaAct+=tareas[i].first;
		res+=tareas[i].second-diaAct;
		
	}
	cout<<res;
}
