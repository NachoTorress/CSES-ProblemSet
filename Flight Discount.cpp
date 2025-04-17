	#include <bits/stdc++.h>
	using namespace std;
	#define ff first
	#define sc second
	#define ll long long
	#define INF 1e17
	int main(){
		ll n, m; cin>>n>>m; 
		vector <vector <ll>> dist (n+1, vector<ll>(2,INF));
		vector <vector <pair<ll,ll>>> ady(n+1);
		while (m--){
			ll a,b,c; cin>>a>>b>>c;
			ady[a].push_back({b,c});
		}
		dist[1][0]=dist[1][1]=0;
		priority_queue <pair<ll,pair<ll,ll>>> pq;
		pq.push({0,{1,0}});
		while (pq.size()){
			
			auto top=pq.top(); pq.pop();
			ll nodo=top.sc.ff,  costo=-top.ff, usado=top.sc.sc;
			if (costo>dist[nodo][usado]) continue;
			for (auto i:ady[nodo]){
				if (costo+i.sc<dist[i.ff][usado]){
					dist[i.ff][usado]=costo+i.sc;
					pq.push({-costo-i.sc,{i.ff, usado}});
				}
				if (!usado && dist[i.ff][1]>costo+i.sc/2){
					dist[i.ff][1]=costo+i.sc/2;
					pq.push({-costo-i.sc/2, {i.ff, 1}});
				}
			}
		}
		cout<<dist[n][1];
	}
