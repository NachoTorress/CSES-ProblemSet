#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector <pair<ll, pair <ll,ll>>> edges;
#define costo first
#define desde second.first
#define hasta second.second
//vector <arista> edges;
vector <vector<ll>> comp;
vector <ll> ID;
bool unionFind(ll a, ll b){
	if (ID[a]==ID[b]) return false;
	ll x=ID[a], y=ID[b];
	if (comp[x].size()<comp[y].size()){
		swap(x,y);
	}
	for (auto i:comp[y]){
		comp[x].push_back(i);
		ID[i]=x;
	}
	return true;
}
int main(){
	ll n, m; cin>>n>>m;
	edges.resize(m); comp.resize(n+1); ID.resize(n+1);
	for (int i=1;i<=n;i++){
		comp[i].push_back(i);
		ID[i]=i;
	}
	for (auto &i:edges){
		cin>>i.desde>>i.hasta>>i.costo;
	}
	ll total=0;
	sort(edges.begin(), edges.end());
	for (int i=0;i<edges.size();i++){
		if (unionFind(edges[i].desde, edges[i].hasta)) total+=edges[i].costo;
	}
	bool rompe=false;
	for (int i=1;i<=n;i++){
		if (ID[i]!=ID[1]) rompe=true;
	}
	if (rompe) cout<<"IMPOSSIBLE";
	else cout<<total;
}
