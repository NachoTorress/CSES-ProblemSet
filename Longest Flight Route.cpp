#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector <vector<ll>> ady;
vector <ll> padre;
vector <ll> apuntaA;
vector <bool> desdeRaiz;
vector <ll> dist;
int main(){
	ll n, m;
	cin>>n>>m;
	ady.resize(n+1), padre.resize(n+1,-1), apuntaA.resize(n+1), desdeRaiz.resize(n+1,false), dist.resize(n+1,0);
	while (m--){
		ll a,b; cin>>a>>b;
		ady[a].push_back(b);
		apuntaA[b]++;
	}
	queue <ll> cola;
	cola.push(1);
	desdeRaiz[1]=1;
	dist[1]=0;
	padre[1]=0;
	for (int i=2;i<=n;i++){
		if (apuntaA[i]==0) cola.push(i);
	}
	while (cola.size()){
		ll nodo=cola.front(); cola.pop();
		for (auto i:ady[nodo]){
			apuntaA[i]--;
			if (!apuntaA[i]) cola.push(i);
			if (desdeRaiz[nodo]){
				if (dist[nodo]+1>dist[i]){
					padre[i]=nodo;
					dist[i]=dist[nodo]+1;
					desdeRaiz[i]=1;
				}
			}
		}
	}
	if (padre[n]==-1){
		cout<<"IMPOSSIBLE";
		return 0;
	}
	vector <ll> resp;
	ll var=n;
	while (var){
		resp.push_back(var);
		var=padre[var];
	}
	reverse(resp.begin(),resp.end());
	cout<<resp.size()<<endl;
	for (auto i:resp) cout<<i<<" ";
}
