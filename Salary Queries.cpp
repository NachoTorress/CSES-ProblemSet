#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX_N 600000
#define ff first 
#define sc second
ll ST[MAX_N*4];
ll sigPot(ll n){
	ll aux=1;
	while (aux<n) aux*=2;
	return aux;
}
ll query(ll nodo, ll l, ll r, ll a, ll b){
    if (l >= a && r <= b) return ST[nodo];
    if (l > b || r < a) return 0;
    ll mid = (l + r) / 2;
    return query(nodo*2, l, mid, a, b) + query(nodo*2+1, mid+1, r, a, b);
}
void actualizar(ll nodo){
	ll aux=nodo/2;
	while (aux){
		ST[aux]=ST[aux*2]+ST[aux*2+1];
		aux/=2; 	
	}
}
int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	ll n, q; cin>>n>>q;
	vector <ll> nums;
	vector <ll> all;
	for (int i=0;i<n;i++){
		ll aux; cin>>aux;
		nums.push_back(aux);
		all.push_back(aux);
	}
	vector <pair<ll,pair<ll,ll>>> querys;
	for (int i=0;i<q;i++){
		char aC; cin>>aC;
		ll a,b,c; cin>>b>>c;
		a=(aC=='?')+1;
		querys.push_back({a,{b,c}});
		if (a==1){
			all.push_back(c);
		}
		else all.push_back(b), all.push_back(c);
	}
	sort (all.begin(), all.end());
	all.erase(unique(all.begin(), all.end()), all.end());
	unordered_map <ll,ll> indices;
	ll indice=0;
	n=sigPot(all.size());
	for (auto i:nums){
		ll indiceI=lower_bound(all.begin(),all.end(),i)-all.begin();
		ST[indiceI+n]++;
	}
	for (int i=n-1;i>0;i--){
		ST[i]=ST[i*2]+ST[i*2+1];
	}
	for (int i=0;i<q;i++){
		ll a=querys[i].ff, b=querys[i].sc.ff, c=querys[i].sc.sc;
		if (a==1){
			ll indiceViejo=lower_bound(all.begin(),all.end(),nums[b-1])-all.begin(), indiceNuevo=lower_bound(all.begin(),all.end(),c)-all.begin();
			ST[n+indiceViejo]--; ST[n+indiceNuevo]++;
			nums[b-1]=c;
			actualizar(n+indiceViejo);
			actualizar(n+indiceNuevo);
		}
		else {
			b=lower_bound(all.begin(),all.end(),b)-all.begin(),c=lower_bound(all.begin(),all.end(),c)-all.begin();
			cout<<query(1,0,n-1,b,c)<<endl;
		}
	}
}
