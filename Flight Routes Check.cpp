#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector <bool> visited;
vector <vector <ll>> ady;
vector <set <ll>> cfcs;
set <ll> apilados;
vector <ll> orden;
vector <ll> masBajo;
stack <ll> pila;
ll indice=0;
void cfc (ll n){
	visited[n]=1;
	apilados.insert(n);
	pila.push(n);
	masBajo[n]=orden[n];
	for (auto u:ady[n]){
		if (!visited[u]){
			orden[u]=indice+1;
			indice++;
			
			cfc(u);
			masBajo[n] = min(masBajo[n], masBajo[u]);

		}
		else if (apilados.count(u)) {
			masBajo[n]=min(orden[u],masBajo[n]);
		}
	}
	if (orden[n]==masBajo[n]){
		set <ll> nuevaCFC;
		while (true) {
    		ll v = pila.top();
    		pila.pop();
   			 apilados.erase(v);
    		nuevaCFC.insert(v);
    		if (v == n) break;
		}
		cfcs.push_back(nuevaCFC);
	}
}
int main(){
	ll n,m; cin>>n>>m;
	visited.resize(n+1,0), ady.resize(n+1), orden.resize(n+1), masBajo.resize(n+1);
	orden[1]=0;
	while (m--){
		ll a,b; cin>>a>>b;
		ady[a].push_back(b);
	}
	for (int i=1;i<=n;i++){
		if (!visited[i]) cfc(i);
	}
	reverse(cfcs.begin(), cfcs.end());
	for (int i=1;i<=n;i++){
		if (!cfcs[0].count(i)){
			for (auto u:ady[i]){
				if (u==*cfcs[0].begin()){
					
					cout<<"NO"<<endl;
					cout<<*cfcs[0].begin()<<" "<<i<<endl;
					
					return 0;
				}
			}
			cout<<"NO"<<endl;
			cout<<i<<" "<<*cfcs[0].begin();
			return 0;	
		}
	}
	cout<<"YES";
	return 0;
}
