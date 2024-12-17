#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX_N 200000
ll n;
ll ST[MAX_N*4], L[MAX_N*4], R[MAX_N*4];
ll sigPot(ll n){
	ll aux=1;
	while (aux<n) aux*=2;
	return aux;
}
ll query (ll min, ll nodo){
	if (ST[nodo]<min) return 0;
	if (L[nodo]==R[nodo]) return L[nodo]+1;
	if (ST[nodo*2]>=min) return query(min, nodo*2);
	return query(min, nodo*2+1);
}
void update(ll indice, ll valor){
	indice+=n;
	ST[indice]=valor;
	while (indice/=2){
		ST[indice]=max(ST[indice*2], ST[indice*2+1]);
	}
}
int main(){
	ll m; cin>>n>>m;
	vector <ll> nums(n);
	for (auto &i:nums) cin>>i;
	n=sigPot(n);
	nums.resize(n,-1);
	for (ll i=0;i<n;i++){
		ST[i+n]=nums[i];
		L[i+n]=R[i+n]=i;
	}
	for (ll i=n-1; i>=1;i--){
		ST[i]=max(ST[i*2],ST[i*2+1]);
		L[i]=L[i*2], R[i]=R[i*2+1]; 
	}
	
	while (m--){
		ll min; cin>>min;
		ll indice=query(min,1);
		update(indice-1, ST[indice-1+n]-min);
		cout<<indice<<" ";
	}
	//cout<<"ST FINAL: "<<endl;
	//for (int i=0;i<n;i++) cout<<ST[i]<<" ";
}
