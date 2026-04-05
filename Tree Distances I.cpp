#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define sc second
vector <vector <ll>> ady;
vector <ll> distA, distB;
pair <ll,ll> maxi={0,0};
void dfs(ll n, ll padre, ll dist, vector <ll>&raiz){
	raiz[n]=dist;
	if (dist>maxi.sc) maxi={n,dist};
	for (auto i:ady[n]) if (i!=padre) dfs(i,n,dist+1,raiz); 
}
int main(){
	ll n; cin>>n;
	ady.resize(n+1),distA.resize(n+1), distB.resize(n+1);
	for (int i=0;i<n-1;i++){
		ll a,b; cin>>a>>b;
		ady[a].push_back(b), ady[b].push_back(a);
	}
	vector <ll> aux (n+1);
	dfs (1,0,0,aux);
	ll a=maxi.ff;
	maxi={0,0};
	dfs (a,0,0,distA);
	ll b=maxi.ff;
	dfs(b,0,0,distB);
	for (int i=1;i<=n;i++){
		cout<<max(distA[i], distB[i])<<" ";
	}
}
