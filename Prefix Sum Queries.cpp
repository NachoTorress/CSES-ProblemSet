#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF -1e18
#define MAX_N 200000
ll n; 
ll ST [MAX_N*4], R[MAX_N*4], L[MAX_N*4], lazy[MAX_N*4];
ll sigPot(ll n){
	ll pot=1; while (pot<n) pot*=2; return pot;
}
void propagar(ll nodo){
	if (lazy[nodo]!=0){
		ST[nodo]+=lazy[nodo];
		if (L[nodo]!=R[nodo]){
			lazy[nodo*2]+=lazy[nodo],
			lazy[nodo*2+1]+=lazy[nodo];
		}
		lazy[nodo]=0;
	}
}
void update(ll valor, ll a, ll b, ll nodo){
	propagar(nodo);
	if (L[nodo]>b || R[nodo]<a) return;
	if (L[nodo]>= a && R[nodo]<=b){
		lazy[nodo]+=valor;
		propagar(nodo);
		return;
	} 
	update (valor, a,b,nodo*2),
	update (valor, a,b,nodo*2+1);
	ST[nodo]=max(ST[nodo*2], ST[nodo*2+1]);
	return;
}

ll query(ll a, ll b, ll nodo){
	propagar(nodo);
	if (L[nodo]>b || R[nodo]<a) return INF;
	if (L[nodo]>= a && R[nodo]<=b) return ST[nodo];
	return max(query(a,b,nodo*2), query(a,b,nodo*2+1));
	
}
int main(){
	ll q; cin>>n>>q;
	vector <ll> nums(n), prefix (n);
	cin>>nums[0]; prefix[0]=nums[0];
	for (int i=1;i<n;i++){
		cin>>nums[i];
		prefix[i]=nums[i]+prefix[i-1];
	}
	n=sigPot(n);
	prefix.resize(n,0);
	for (int i=0;i<n;i++){
		ST[i+n]=prefix[i];
		L[i+n]=R[i+n]=i;
	}
	for (int i=n-1;i>=1;i--){
		ST[i]=max(ST[i*2], ST[i*2+1]);
		L[i]=L[i*2], R[i]=R[i*2+1];
	}
	while (q--){
		ll type; cin>>type;
		if (type==1){
			ll  k, u;
			cin>>k>>u;
			ll valor=u-nums[k-1];
			nums[k-1]=u;
			update(valor,k-1,n-1, 1);
		}
		else {
			ll a,b;
			cin>>a>>b;
			a--, b--;
			ll res=query(a,b,1);
			if (a>0){
				res-=query(a-1,a-1,1);
			}
			cout<<max(res,0LL)<<endl;
		}
	}
}
