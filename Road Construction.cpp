#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector <ll> ID;
vector <vector <ll>> comp;
ll componentes;
ll maxComp=-1;
bool unionFind(ll a, ll b){
	if (ID[a]==ID[b]) return false;
	ll x=ID[a], y=ID[b];
	if (comp[x].size()<comp[y].size())
		swap (x,y);
	for (auto i:comp[y]){
		ID[i]=x;
		comp[x].push_back(i);
	}
	ll tam=comp[x].size();
	maxComp=max(maxComp, tam);
	return true;	
}
int main (){
	ll n,  m;
	cin>>n>>m;
	componentes=n;
	ID.resize(n+1), comp.resize(n+1);
	for (int i=1;i<=n;i++){
		ID[i]=i; comp[i].push_back(i);
	}
	for (int i=0;i<m;i++){
		ll a, b; 
		cin>>a>>b;
		if (unionFind(a,b)) componentes--;
		cout<<componentes<<" "<<maxComp<<endl;
	}
}
