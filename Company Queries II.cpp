#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll up [200002][20];
vector <vector <ll>> ady;
vector <ll> dist;
ll subir(ll a, ll distancia){
	for (int i=0;i<20;i++){
		if (distancia&(1<<i)) a=up[a][i];
	}
	return a;
}
void dfs(ll n){
	for (auto i:ady[n]){
		dist[i]=dist[n]+1;
		dfs(i);
	}
}
int main(){
	ll n,q;
	cin>>n>>q;
	dist.resize(n+2); ady.resize(n+2); 
	for (ll i=2;i<=n;i++){
		ll jef; cin>>jef;
		up[i][0]=jef;
		ady[jef].push_back(i);
	}
	dist[1]=0;
	dfs(1);
	for (ll i=1;i<20;i++){
		for (ll j=1;j<=n;j++){
			up[j][i]=up[up[j][i-1]][i-1];
			if (!up[j][i]) up[j][i]=1;
		}
	}
	while (q--){
		ll a, b; cin>>a>>b;
		if (dist[a]<dist[b]) swap(a,b);
		a=subir(a,dist[a]-dist[b]);
		if (a==b){
			cout<<a<<endl;
			continue;
		}
		for (int j=19;j>=0;j--){
			if (up[a][j]!=up[b][j]){
				a=up[a][j], b=up[b][j];
			}
		}
		cout<<up[a][0]<<endl;
		}
		return 0;
	}

