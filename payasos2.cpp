#include <bits/stdc++.h>
#define ll long long
#define ff first 
#define sc second 
using namespace std;
vector <ll> criba; 
vector <ll> longs; 
vector <ll> dist; 
vector <int> ady;
ll mod;
void dfs(ll nodo, ll distAct){
	if (dist[nodo]) return; 
	dist[nodo]=distAct;
	ll vec=ady[nodo];
	if (dist[vec]){
		longs.push_back(dist[nodo]-dist[vec]+1); 
		return; 
	}
	else dfs(ady[nodo], distAct+1);
}
long long potenciaMod(long long base, long long exp, long long mod) {
    base %= mod;
    long long resultado = 1;
    while (exp > 0) {
        if (exp & 1)                      
            resultado = (resultado * base) % mod;
        base = (base * base) % mod;       
        exp >>= 1;                       
    }
    return resultado;
}
map <ll, ll> exponentes; 
void factorizar (ll n){
	while (n>1){
		ll exp=0; 
		ll primo=criba[n];
		while (!(n%primo)) exp++, n/=primo; 
		exponentes[primo]=max(exponentes[primo], exp); 
	}
}
int payasos2(vector<int> &A){
	ll mod=1000000007;
	ll n=A.size();
	ady=A;
	criba.resize(n+1,0), dist.resize(n+1,0);
	for (ll i=2;i<=n;i++){
		if (!criba[i]){
			for (ll j=i*i; j<=n;j+=i) criba[j]=i;
			criba[i]=i;
		}
	}
	for (int i=0;i<n;i++){
		if (!dist[i]) dfs(i,1); 
	}
	for (auto i:longs) factorizar(i); 
	ll res=1; 
	for (auto i:exponentes){
		res=res*potenciaMod(i.ff,i.sc, mod)%mod;
	}
	return res;
}
