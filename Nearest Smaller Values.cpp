#include <bits/stdc++.h>
#define ll long long
#define INF 1e18
#define maxN 200000
#define PB push_back
using namespace std;
ll indice;
ll pot;
ll ST[maxN*4], L[maxN*4], R[maxN*4];
vector <ll> resp;
void sigPot(ll n){
	pot=1;
	while (pot<n) pot*=2;
}
bool query(ll nodo, ll menorQue){
	if (nodo>=pot && ST[nodo]<menorQue && L[nodo]<indice ){
		resp.PB(nodo-pot+1);
		return true;
	}
	if ((nodo>=pot*2) || (nodo>=pot && ST[nodo]>=menorQue)  || ST[nodo]>=menorQue || nodo-pot>=indice || L[nodo]>indice) return false;
	if (!query(nodo*2+1, menorQue)) return query(nodo*2, menorQue);
	else return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	ll n; cin>>n; 
	sigPot(n);
	vector <ll> nums (n);
	for (auto &i:nums) cin>>i;
	for (ll i=0;i<pot;i++){
		if (i<n){
			ST[pot+i]=nums[i];
		}
		else ST[pot+i]=INF;
		L[i+pot]=R[i+pot]=i;
	}
	for (ll i=pot-1;i>0;i--){
		L[i]=L[i*2], R[i]=R[i*2+1];
		ST[i]=min(ST[i*2], ST[i*2+1]);
	}
	resp.PB(0);
	for (int i=1;i<n;i++){
		indice=i;
		if(!query(1, nums[i])) resp.PB(0);
	}
	for (auto i:resp) cout<<i<<" ";
}

