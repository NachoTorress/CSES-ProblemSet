#include <bits/stdc++.h>
#define INF 1e18
using namespace std;
vector <vector <pair <long long, long long>>> ady;
void construir (){
	long long a, b, c;
	cin>>a>>b>>c;
	ady[a].push_back({b,c});
	ady[b].push_back({a,c});
}
 long long dijkstra (long long x, long long y,  long long n){
	vector <bool> processed (n+1, false);
	vector <long long> distance (n+1, INF);
	priority_queue <pair <long long, long long>> pq;
	distance[x]=0;
	pq.push({0, x});
	while (!pq.empty()){
		long long nodo=pq.top().second;
		pq.pop();
		if (processed[nodo]) continue;
		processed[nodo]=true;
		for (auto u : ady[nodo]){
			int vecino=u.first, costo=u.second;
			if (distance[nodo]+costo<distance[vecino]){
				distance[vecino]=distance[nodo]+costo;
				pq.push({-distance[vecino], vecino});
			}
		}
	}
	
	if (distance[y]<INF)return distance[y];
	return -1;
}
int main(){
	long long n, m,q;
	cin>>n>>m>>q;
	ady.resize(n+1);
	while (m--){
		construir();
	}
	//vector <long long > distancias = dijkstra(1, n);
	for (long long i=0;i<q;i++) {
	int x, y;
	cin>>x>>y;	
	cout<<dijkstra(x,y,n);
	cout<<endl;
}
}
