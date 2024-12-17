#include <bits/stdc++.h>
using namespace std;
#define MAX_N 200000
#define ll long long
ll ST[MAX_N*4], R[MAX_N*4], L[MAX_N*4], lazy[MAX_N*4], activos[MAX_N*4];
ll sigPot(ll n){
	ll aux=1;
	while (aux<n) aux*=2;
	return aux;
}


void update(ll a, ll b, ll u, ll nodo){
	if (lazy[nodo]!=0){
		ST[nodo]=ST[nodo]+lazy[nodo]*activos[nodo];
		if (L[nodo]!=R[nodo])
		lazy[nodo*2]+=lazy[nodo], lazy[nodo*2+1]+=lazy[nodo];
		lazy[nodo]=0;
	}
	if (b<L[nodo] || a>R[nodo]) return;
	if (L[nodo]>=a && R[nodo]<=b){
		ST[nodo]=ST[nodo]+activos[nodo]*u;
		if (L[nodo]!=R[nodo]) lazy[nodo*2]+=u,lazy[nodo*2+1]+=u;
		return;
	}
	update(a,  b, u,nodo*2); 
	update(a,  b, u,nodo*2+1); 
	ST[nodo]=ST[nodo*2]+ST[nodo*2+1];
}
ll query(ll a, ll b, ll nodo){
	if (lazy[nodo]!=0){
		ST[nodo]+=lazy[nodo]*activos[nodo];
		if (L[nodo]!=R[nodo]){
			lazy[nodo*2]+=lazy[nodo];
			lazy[nodo*2+1]+=lazy[nodo];
		}
		lazy[nodo]=0;
	}
	if (L[nodo] > b || R[nodo]<a) return 0;
	if (L[nodo]>=a && R[nodo]<=b){
		ST[nodo]+=lazy[nodo]*activos[nodo];
		if (L[nodo]!=R[nodo])
		lazy[nodo*2]+=lazy[nodo],
		lazy[nodo*2+1]+=lazy[nodo];
		
		lazy[nodo]=0;
		return ST[nodo];
	}
	return query( a,  b, nodo*2)+
	query(a,  b,  nodo*2+1);
}
int main(){
	ll n, q;
	cin>>n>>q;
	vector <ll> nums (n);
	for (auto &i:nums) cin>>i;
	n=sigPot(n);
	nums.resize(n,-1);
//	for (auto i:nums) cout<<i;
	for (int i=0;i<n;i++){
		L[i+n]=R[i+n]=i;
		ST[i+n]=nums[i];
		if (nums[i]!=-1) activos[i+n]=1;
		else activos[i+n]=0;
	}
	for (int i=n-1;i>=1;i--){
		ST[i]=ST[i*2]+ST[i*2+1];
		activos[i]=activos[i*2]+activos[i*2+1];
		L[i]=L[i*2], R[i]=R[i*2+1];
	}
	while (q--){
		ll type; cin>>type;
		if (type==1){
			ll a,b,u; cin>>a>>b>>u;
			a--; b--;
			update(a,b,u,1);
		}
		else {
			ll a,b; cin>>a; a--;
			cout<<query(a,a,1)<<endl;
		}
	}
	
}
