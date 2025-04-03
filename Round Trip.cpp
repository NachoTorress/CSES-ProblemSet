#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector <vector <ll>> ady;
vector <bool> visited;
vector <ll> padre;
vector <ll> nivel;
bool cicloEncontrado=false;
ll nodoCiclo=0;
ll padreNodoCiclo=0;
void dfs(ll n, ll padreN){
	if (cicloEncontrado) return;
	if (visited[n]){
		//if (abs(nivel[padreN]-nivel[n]>1)){
			if (abs(nivel[padreN]-nivel[n]>1)){
			cicloEncontrado=1;
			nodoCiclo=n;
			padreNodoCiclo=padreN;
			return;
		}
		return;
	}
	nivel[n]=nivel[padreN]+1;
	visited[n]=true;
	padre[n]=padreN;
	for (auto i:ady[n]){
		dfs(i,n);
	}
}
int main(){
	ll n,m;
	cin>>n>>m;
	ll nodoRaiz=0;
	ady.resize(n+1); visited.resize(n+1,false); padre.resize(n+1); nivel.resize(n+1);
	while (m--){
		ll a, b; cin>>a>>b;
		if (!nodoRaiz) nodoRaiz=a;
		ady[a].push_back(b); ady[b].push_back(a);
		
	}
	padre[nodoRaiz]=0;
	nivel[nodoRaiz]=0;
	dfs(nodoRaiz,nodoRaiz);
	if (!cicloEncontrado){
		for (int i=1;i<=n;i++){
			if (!visited[i]){
				padre[i]=i;
				nivel[i]=0;
				dfs(i,i);
			}
		}
		if (!cicloEncontrado){
			cout<<"IMPOSSIBLE";
			return false;
		}
	}
	vector <ll> resp;
	resp.push_back(nodoCiclo); resp.push_back(padreNodoCiclo);
	ll var=padre[padreNodoCiclo];
	while (var!=nodoCiclo){
		resp.push_back(var);
		var=padre[var];
	}
	resp.push_back(var);
	reverse(resp.begin(), resp.end());
	cout<<resp.size()<<endl;
	for (auto i:resp) cout<<i<<" ";
	return 0;
}
