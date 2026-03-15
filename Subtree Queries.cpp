#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX_N 200000
ll ST[MAX_N*4], R[MAX_N*4], L[MAX_N*4];
ll timer=0;
vector <vector<ll>> ady;
vector <ll> tiempo;
vector <ll> size;
vector <bool> visited;
void dfs(ll nodo, ll padre ){
	if (visited[nodo]) return;
	visited[nodo]=true;
	tiempo[nodo]=timer++;
	size[nodo]=1;
	for (auto i:ady[nodo]){
		if (i==padre) continue;
		dfs(i,nodo);
		size[nodo]+=size[i];
	}
}
ll sigPot (ll n){
	ll aux=1; 
	while (aux<n) aux*=2;
	return aux;
}
ll query(ll nodo, ll a, ll b){
	if (R[nodo]<a || L[nodo]>b) return 0;
	if (L[nodo]>=a && R[nodo]<=b) return ST[nodo];
	return query(nodo*2,a,b)+query(nodo*2+1,a,b);
}
void update (ll nodo, ll valor, ll pot){
	ll pos=tiempo[ nodo]+pot;
	ST[pos]=valor;
	while (pos/=2) ST[pos]=ST[pos*2]+ST[pos*2+1];
}
int main(){
	ll n, q; cin>>n>>q;
	ady.resize(n+1); tiempo.resize(n+1); size.resize(n+1); visited.resize(n+1);
	vector <ll> vals(n);
	for (auto &i:vals) cin>>i;
	for (int i=0;i<n-1;i++){
		ll a,b; cin>>a>>b;
		ady[a].push_back(b);ady[b].push_back(a);
	}
	dfs (1,0);
	ll pot=sigPot(n);
	for (int i=1;i<=n;i++){
		ST[pot+tiempo[i]]=vals[i-1];
	}
	for (int i=0;i<pot;i++){	
		L[i+pot]=R[i+pot]=i;
	}
	for (int i=pot-1; i>0;i--){
		ST[i]=ST[i*2]+ST[i*2+1];
		L[i]=L[i*2], R[i]=R[i*2+1];
	}
	while (q--){
		ll op; cin>>op;
		if (op==2){
			ll nod; cin>>nod;
			cout<<query(1,tiempo[nod], tiempo[nod]+size[nod]-1)<<endl;
		}
		else {
			ll nod, valor; cin>>nod>>valor; 
			update (nod,valor, pot);
		}
	}
}
