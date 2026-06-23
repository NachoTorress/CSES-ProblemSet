#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define sc second
#define max_n 200000
#define INF 1e18
pair <ll,ll> ST[max_n*4];
ll L[max_n*4], R[max_n*4];
ll sigPot (ll n){
	ll aux=1;
	while (aux<n) aux*=2;
	return aux;
}
void update(ll pos, ll val, ll pot){
	pos--;
	ST[pos+pot].ff=val-pos; 
	ST[pos+pot].sc=val+pos; 
	ll aux=(pos+pot)/2;
	while (aux){
		ST[aux].ff=min(ST[aux*2].ff, ST[aux*2+1].ff);
		ST[aux].sc=min(ST[aux*2].sc, ST[aux*2+1].sc);
		aux/=2;
	}
}
ll query (ll nodo, ll a, ll b, ll index){
	pair <ll,ll> val; 
	if (L[nodo]>=a && R[nodo]<=b) val=ST[nodo];
	else if (R[nodo]<a || L[nodo]>b) val={INF,INF};
	else return min(query(nodo*2,a,b,index),query(nodo*2+1,a,b,index));
	return index? val.ff : val.sc;
}
int main(){
	ll n,q; cin>>n>>q;
	vector <ll> pizzerias (n);
	for (auto &i:pizzerias) cin>>i;
	ll pot=sigPot(n);
	for (int i=0;i<pot;i++){
		if (i<n){
	 		ST[i+pot].ff=pizzerias[i]-i; 
	 		ST[i+pot].sc=pizzerias[i]+i; 
		 }	
		else ST[i+pot].ff=ST[i+pot].sc=INF;
		L[i+pot]=R[i+pot]=i;
	}
	for (int i=pot-1;i>0;i--){
		ST[i].ff=min(ST[i*2].ff, ST[i*2+1].ff);
		ST[i].sc=min(ST[i*2].sc, ST[i*2+1].sc);
		L[i]=L[i*2], R[i]=R[i*2+1];
	}
	while (q--){
		ll a; cin>>a;
		if (a==1){
			ll k,x; cin>>k>>x;
			update (k,x,pot);
		}
		else {
			ll k; cin>>k;
			k--;
			ll query1=query(1,0,k,1);
			ll query2=query(1,k+1,pot-1,0);
			cout<<min(query1+k,query2-k)<<endl;
		}
	}
}
