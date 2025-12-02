#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX_N 200000
ll ST[MAX_N*4], R[MAX_N*4], L[MAX_N*4];
ll sigPot(ll n){
	ll aux=1;
	while (aux<n) aux*=2;
	return aux;
}
ll query(ll nodo, ll a, ll b ){
	if (L[nodo]>=a && R[nodo]<=b)return ST[nodo];
	else if (L[nodo]>b || R[nodo]<a) return 0;
	return query(nodo*2,a,b)+query(nodo*2+1,a,b);
}
void update (ll v, ll n){
	ST[v+n]=(ST[v+n]+query(1,0,v-1)+1)%MOD;
	ll aux=v+n;
	while (aux/=2){
		ST[aux]=(ST[aux*2]+ST[aux*2+1])%MOD;
	}
}
int main(){
	ll n; cin>>n;
	vector <ll> nums (n);
	for (auto &i:nums) cin>>i;
	vector <ll> all=nums;
	sort(all.begin(), all.end());
	all.erase(unique(all.begin(), all.end()), all.end());
	unordered_map <ll,ll> indices;
	for (int i=0;i<all.size();i++){
		indices[all[i]]=i;
	}
	n=sigPot(n);
	for (int i=0;i<n;i++){
		L[i+n]=R[i+n]=i;
	}
	for (int i=n-1;i>0;i--){
		L[i]=L[i*2], R[i]=R[i*2+1];
	}
	for (int i=0;i<nums.size();i++){
		update(indices[nums[i]],n);
	}
	cout<<ST[1];
}
