#include <bits/stdc++.h>
using namespace std;
#define NMAX 200000
#define ll long long
vector <int> resp;
ll ST[NMAX*4], L[NMAX*4], R[NMAX*4];
ll n, k;
vector <ll> nums;
ll sigPot(int n){
	ll pot=1;
	while (pot<n){
		pot*=2;
	}
	return pot;
}
ll query (int nodo, int buscando){
	if ( L[nodo]==R[nodo] && ST[nodo]==buscando){
	ST[nodo]=0;
	ll nodo2=nodo;
	 resp.push_back(nodo-n+1);
	while (nodo2/=2){
		ST[nodo2]=ST[nodo2*2]+ST[nodo2*2+1];
	}	
	 return L[nodo];
}
	 if (ST[nodo*2]>=buscando) return query(nodo*2,buscando);
	else return query(nodo*2+1,buscando-ST[nodo*2]);
}
int main(){
	 cin>>n>>k;
	vector <ll> respuesta;
	nums.resize(n);
	for (int i=1;i<=n;i++){
		nums[i-1]=i;
	}
	ll N=n;
	n=sigPot(n);
	for (ll i=0;i<nums.size();i++){
		ST[i+n]=1;
		L[i+n]=R[i+n]=i+n;
	}
	for (ll i=0;i<n;i++){
		L[i+n]=R[i+n]=i+n;
	}
	for (ll i=n-1;i>0;i--){
		ST[i]=ST[i*2]+ST[i*2+1];
		L[i]=L[i*2], R[i]=R[i*2+1];
	}
ll posActual=1;
	for (int i=0;i<nums.size();i++){
		 posActual=(posActual+k)%(ST[1]);
		if (!posActual)posActual=ST[1];
		//cout<<"pos actual: "<<posActual<<endl;
		//cout<<"ST[1]: "<<ST[1]<<endl;
		ll a=query(1, posActual);
	}
	for (auto i:resp) cout<<i<<" ";
}
