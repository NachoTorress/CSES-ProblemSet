#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PB push_back
bool seEncontro=false;
vector <vector <ll>> ady;
vector <bool> visited;
vector <ll> processed;
vector <ll> camino;
vector <ll> indice;
ll inicio;
void dfs(ll n){
	if (seEncontro) return;
	if (visited[n]) return;
	visited[n]=true;
	camino.PB(n);
	indice[n]=camino.size()-1;
	processed[n]=1;
	for (auto i:ady[n]){
		if (processed[i]==1 && !seEncontro){
			seEncontro=true;
			camino.PB(i);
			inicio=indice[i];
			return;
		}
		dfs(i);
	}
	if (!seEncontro) camino.pop_back();
	processed[n]=2;
	
}
int main(){
	ll n, m; cin>>n>>m;
	visited.resize(n+1,false), ady.resize(n+1), processed.resize(n+1,0), indice.resize(n+1);
	for (int i=0;i<m;i++){
		ll a,b; cin>>a>>b;
		ady[a].PB(b);
	}
	for (int i=1;i<=n;i++){
		if (seEncontro) break;
		visited.resize(n+1,false);
		dfs(i);
	}
	if (!seEncontro) cout<<"IMPOSSIBLE"<<endl;
	else {
		cout<<camino.size()-inicio<<endl;
		for (int i=inicio;i<camino.size();i++) cout<<camino[i]<<" ";
		
	}
}
