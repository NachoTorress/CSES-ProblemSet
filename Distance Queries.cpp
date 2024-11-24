#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector <vector <ll>> ady;
vector <ll> dist;
vector <ll> padres;
vector <bool> visited;
ll up[200002][20];
void dfs(ll n){
	//if (visited[n]) return;
	visited[n]=1;
	for (auto i:ady[n]){
		if (!visited[i]){
		padres[i]=n;
		dist[i]=dist[n]+1;
		dfs(i);
		}
	}
}
void subir(ll &a, ll distancia){
	for (int i=0;i<20;i++){
		if (distancia&(1<<i)) a=up[a][i];
	}
}
int main(){
	ll n, q; cin>>n>>q;
	ady.resize(n+2), dist.resize(n+2); padres.resize(n+2), visited.resize(n+2,0);
	for (int i=1;i<n;i++){
		ll a, b; cin>>a>>b;
		ady[a].push_back(b), ady[b].push_back(a);
	}
	dist[1]=0;
	dfs(1);
	for (int i=1;i<=n;i++){
		up[i][0]=padres[i];
	}
	for (ll i=1;i<20;i++){
		for (ll j=1;j<=n;j++){
			up[j][i]=up[up[j][i-1]][i-1];
			if (!up[j][i]) up[j][i]=1;
		}
	}
	for (int i=0;i<q;i++){
		ll a, b; cin>>a>>b;
		if (dist[a]<dist[b]) swap(a,b);
		ll diferenciaNivel=dist[a]-dist[b];
		ll distTotal=0;
		subir(a, diferenciaNivel);
		if (a==b){
			cout<<diferenciaNivel<<endl;
			continue;
		}
		for (int j=19;j>=0;j--){
			if (up[a][j]!=up[b][j]){
				a=up[a][j], b=up[b][j];
				distTotal+=(1<<j);
			//	cout<<"subiendo "<<endl;
			}
		}
		
		cout<<distTotal*2+diferenciaNivel+2<<endl;
	}
	return 0;
}
