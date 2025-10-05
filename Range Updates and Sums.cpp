#include <bits/stdc++.h>
#define ff first
#define sc second
#define ll long long
#define MAX_N 200000
using namespace std;
ll ST[MAX_N*4], L[MAX_N*4], R[MAX_N*4], lazy[MAX_N*4], sum[MAX_N*4], cubre[MAX_N*4];
void sigPot(ll &n){
	ll aux=1;
	while (aux<n) aux*=2;
	n=aux;
}
void actualizar(ll nodo){
    if(lazy[nodo] != 0){
        ST[nodo] = lazy[nodo] * cubre[nodo];
        if(L[nodo] != R[nodo]){
            lazy[nodo*2] = lazy[nodo];
            lazy[nodo*2+1] = lazy[nodo];
            sum[nodo*2]=sum[nodo*2+1]=0;	
        }
        lazy[nodo] = sum[nodo] = 0;
    }
    else if(sum[nodo]!=0){
        ST[nodo] += sum[nodo] * cubre[nodo];
        if(L[nodo] != R[nodo]){
            if(lazy[nodo*2] != 0) lazy[nodo*2] += sum[nodo]; else sum[nodo*2] += sum[nodo];
            if(lazy[nodo*2+1] != 0) lazy[nodo*2+1] += sum[nodo]; else sum[nodo*2+1] += sum[nodo];
        }
        sum[nodo] = 0;
    }
}
void setear (ll nodo, ll a, ll b, ll x){
	actualizar(nodo);
	if (L[nodo]>b || R[nodo]<a) return;
	if (L[nodo]>=a && R[nodo]<=b) lazy[nodo]=x, sum[nodo]=0,actualizar(nodo);
	else setear (nodo*2,a,b,x), setear(nodo*2+1, a,b,x), ST[nodo]=ST[nodo*2]+ST[nodo*2+1];
	
}
void sumar (ll nodo, ll a, ll b, ll x){
	actualizar(nodo);
	if (L[nodo]>b || R[nodo]<a) return;
	if (L[nodo]>=a && R[nodo]<=b) sum[nodo]+=x, actualizar(nodo);
	else sumar (nodo*2,a,b,x), sumar(nodo*2+1, a,b,x), ST[nodo]=ST[nodo*2]+ST[nodo*2+1];
}
ll query (ll nodo, ll a, ll b){
	actualizar(nodo);
	if (L[nodo]>b || R[nodo]<a) return 0;
	if (L[nodo]>=a && R[nodo]<=b)return ST[nodo];
	else return query (nodo*2,a,b)+ query(nodo*2+1, a,b);
}
int main(){
	ll n, q; cin>>n>>q;
	vector <ll> nums(n);
	ll nViejo=n;
	for (auto &i:nums) cin>>i;
	sigPot(n);
	for (int i=0;i<n;i++){
		if (i<nViejo) ST[i+n]=nums[i];
		L[i+n]=R[i+n]=i;
		cubre[i+n]+=(i<nViejo)? 1:0;
	}
	for (int i=n-1;i>0;i--){
		cubre[i]=cubre[i*2]+cubre[i*2+1];
		L[i]=L[i*2], R[i]=R[i*2+1];
		ST[i]=ST[i*2]+ST[i*2+1];
	}
	while (q--){
		ll op; cin>>op;
		if (op==1){
			ll a, b, x; cin>>a>>b>>x;
			sumar(1,a-1,b-1,x);
		}
		else if (op==2){
			ll a,b,x; cin>>a>>b>>x;
			setear(1,a-1,b-1,x);
		}
		else{
			ll a,b; cin>>a>>b; 
			cout<<query(1,a-1,b-1)<<endl;
		}
	}
}
