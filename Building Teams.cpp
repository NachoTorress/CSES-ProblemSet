#include <bits/stdc++.h>
#define ll long long
#define INF 1e18
using namespace std;
vector <ll> dist;
vector <vector <ll>> ady;
vector <ll> color;
void BFS(int i){
	color[i]=1;
	queue <int> lista;
	dist[i]=0;
	lista.push(i);
	while (lista.size()){
		ll nodo=lista.front(); lista.pop();
		ll colorN;
		if (color[nodo]==1){
			colorN=2;
		}
		else colorN=1;
		for (auto i:ady[nodo]){
			if (dist[nodo]+1<dist[i]){
				dist[i]=dist[nodo]+1;
				color[i]=colorN;
				lista.push(i);
			}
		}
	}
}

int main(){
	int n, m; cin>>n>>m;
	ady.resize(n+1);
	dist.resize(n+1,INF);
	color.resize(n+1,0);
	for (int i=0;i<m;i++){
		int a, b; cin>>a>>b;
		ady[a].push_back(b); ady[b].push_back(a);
	}
	for (int i=1;i<=n;i++){
		if (dist[i]==INF) BFS(i);
	}
	bool rompe=false;
	for (int i=1;i<=n;i++){
		for (int j=0;j<ady[i].size();j++){
			if (color[i]==color[ady[i][j]]) rompe=true;
		}
	}
	if (rompe){
		cout<<"IMPOSSIBLE";
		return 0;
	}
	else {
		for (int i=1;i<=n;i++) cout<<color[i]<<" ";
	}
	
}
