#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector <pair<ll,pair<ll,ll>>> edges;
#define desde first
#define hacia second.first
#define costo second.second 
vector <ll> padre;
vector <ll> dist;
int main(){
	ll n,m; cin>>n>>m;
	padre.resize(n+1), dist.resize(n+1,0);
	while (m--){
		ll a,b,c; cin>>a>>b>>c; 
		pair <ll,pair<ll,ll>> aux={a,{b,c}};
		edges.push_back(aux);
	}
	ll x;
	for (int i=1;i<=n;i++){
		x=-1;
		
		
		for (auto i:edges){
			ll a=i.desde, b=i.hacia, c=i.costo;
			if (dist[a]+c<dist[b]){
				dist[b]=dist[a]+c;
				padre[b]=a;
				x=b;
			}
		}
	}
	if (x==-1) {
		cout<<"NO";
		return 0;
		
	}
	for (int i=1;i<=n;i++){
		x=padre[x];
	}
	vector <ll> res;
	ll original=x;
	res.push_back(x);
	x=padre[x];
	while (x!=original){
		res.push_back(x);
		x=padre[x];
	}
	res.push_back(x);
	reverse (res.begin(), res.end());
	cout <<"YES"<<endl;
	for (auto i:res) cout<<i<<" ";
	return 0;
}
