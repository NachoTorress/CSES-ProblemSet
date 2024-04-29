#include <bits/stdc++.h>
using namespace std;
#define MAX_N 200000 
#define ll long long
ll ST[MAX_N*4], L[MAX_N*4], R[MAX_N*4];
ll sigPot(ll n){
	ll pot=1;
	while (pot<n){
		pot*=2;
	}
	return pot;
}
ll query(ll nodo, ll a, ll b){
	if (L[nodo]>b || R[nodo]<a) return 0;
	if (L[nodo]>=a && R[nodo]<=b) return ST[nodo];
	return query(nodo*2,a,b)+query(nodo*2+1,a,b);
}
void update (int k, int u, int n){
	k+=n-1;
	ST[k]=u;
	while (k/=2){
		ST[k]=ST[k*2]+ST[k*2+1];
	}
}
int main(){
	ll n, q; cin>>n>>q;
	vector <ll> nums (n);
	for (auto &i:nums) cin>>i;
	n=sigPot(n);
	nums.resize(n, 0);
	for (ll i=0;i<n;i++){
		ST[i+n]=nums[i];
		L[n+i]=R[n+i]=n+i;
	}
	for (ll i=n-1;i>=1;i--){
		ST[i]=ST[i*2]+ST[i*2+1];
		L[i]=L[i*2], R[i]=R[i*2+1];
	}
	while (q--){
		int option;
		cin>>option;
		if (option==1){
			int k, u;
			cin>>k>>u;
			update(k,u,n);
		}
		else {
			int a, b;
			cin>>a>>b;
			a+=n-1;
			b+=n-1;
			cout<<query(1, a,b)<<endl;
		}
	}
}
