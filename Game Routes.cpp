#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
vector <vector <ll>> ady;
vector <ll> entradas;
vector <ll> ops;
int main(){
	ll n, m; cin>>n>>m;
	ady.resize(n+1), entradas.resize(n+1); ops.resize(n+1,0);
	for (int i=0;i<m;i++){
		ll a,b; cin>>a>>b;
		ady[a].push_back(b); entradas[b]++;
	}
	queue <ll> cola;
	for (int i=1;i<=n;i++){
		if (!entradas[i]) cola.push(i);
	}
	ops[1]=1;
	while (cola.size()){
		
		ll nodo=cola.front(); cola.pop();
	//	cout<<"Procesando nodo:" <<nodo<<endl;
		
		for (auto i:ady[nodo]){
			ops[i]=(ops[nodo]+ops[i])%MOD;
			entradas[i]--;
			if (!entradas[i]) cola.push(i);
		}
		//cout<<"OPS: "<<endl;
//	for (auto i:ops) cout<<i<<" ";
//	cout<<endl;
	}
	//cout<<"OPS: "<<endl;
	//for (auto i:ops) cout<<i<<" ";
//x	cout<<endl;
	cout<<ops[n];
}
