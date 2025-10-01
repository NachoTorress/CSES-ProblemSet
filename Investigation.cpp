#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define sc second
#define INF 1e16
#define MOD 1000000007
vector <vector <pair <ll,ll>>> ady;
vector <pair <pair <ll,ll>, pair<ll,ll>>> dist;
int main(){
	ll n, m; cin>>n>>m;
	ady.resize(n+1), dist.resize(n+1, {{INF,0}, {INF,INF}});
	for (int i=0;i<m;i++){
		ll a, b, c; cin>>a>>b>>c;
		ady[a].push_back({b,c});
	}
	
	dist[1]={{0,1},{0,0}};
	priority_queue <pair<ll,ll>> pq;
	pq.push({0,1});
	while (pq.size()){
		ll costo=-pq.top().ff, nodo=pq.top().sc; pq.pop();
		for (auto i:ady[nodo]){
			if (costo+i.sc<dist[i.ff].ff.ff){
				dist[i.ff].ff={costo+i.sc, dist[nodo].ff.sc};
				dist[i.ff].sc={dist[nodo].sc.ff+1,dist[nodo].sc.sc+1};
				pq.push({-(costo+i.sc), i.ff});
			}
			else if (costo+i.sc==dist[i.ff].ff.ff){
				dist[i.ff].ff.sc = (dist[i.ff].ff.sc + dist[nodo].ff.sc) % MOD;
				dist[i.ff].sc.ff=min(dist[i.ff].sc.ff, dist[nodo].sc.ff+1);
				dist[i.ff].sc.sc=max(dist[i.ff].sc.sc, dist[nodo].sc.sc+1);
				
			}
		}
	}
	cout<<dist[n].ff.ff<<" "<<dist[n].ff.sc<<" "<<dist[n].sc.ff<<" "<<dist[n].sc.sc;
}
