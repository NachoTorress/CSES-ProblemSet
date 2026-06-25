#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector <vector<pair<ll,ll>>> ady;
vector <ll> dist;
#define INF 1e17
#define ff first
#define sc second
int main(){
	ll n,m; cin>>n>>m;
	ady.resize(n+1), dist.resize(n+1,INF);
	while (m--){
		ll a,b,c; cin>>a>>b>>c;
		ady[a].push_back({b,-c});
	}
	dist[1]=0;
	for (int i=1;i<n;i++){
		for (int j=1;j<=n;j++){
			if (dist[j]==INF) continue;
			for (auto par:ady[j]){
				dist[par.ff]=min(dist[j]+par.sc, dist[par.ff]);
			}
		}
	}
	queue <ll> cola;
	for (int j=1;j<=n;j++){
		if (dist[j]==INF) continue;
		for (auto par:ady[j]){
			if (dist[j]+par.sc<dist[par.ff]) cola.push(j);
		}
	}
	vector <bool> visited (n+1,0);
	while (cola.size()){
		ll nodo=cola.front(); cola.pop();
		if(visited[nodo]) continue;
		visited[nodo]=true;
		for (auto i:ady[nodo]){
			cola.push(i.ff);
		}
	}
	cout<<(visited[n] ? -1: -dist[n]);
}
