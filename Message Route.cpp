#include <bits/stdc++.h>
using namespace std;
vector <bool> visited;
vector <vector <int>> ady;
vector <int> padres;
vector <int> dist;
void bfs (int inicio){
	queue <int> cola;
	visited[inicio]=true;
	dist[inicio]=0;
	cola.push(inicio);
	while (!cola.empty()){
		int s=cola.front(); cola.pop();
		for (auto vecino : ady[s]){
			if (visited[vecino]) continue;
			visited[vecino]=true;
			dist[vecino]=dist[s]+1;
			cola.push(vecino);
			padres[vecino]=s;
		}
	}
}

int main(){
	int n, m;
	cin>>n>>m;
	visited.resize(n+1); ady.resize(n+1); padres.resize(n+1, -1); dist.resize(n+1, 2<<29);
	while (m--)
	{
	int a, b;
	cin>>a>>b;
	ady[a].push_back(b); ady[b].push_back(a);
	}
	bfs(1);
	if (padres[n]==-1){
		cout<<"IMPOSSIBLE"<<endl;
		return 0;
	}
	vector <int> camino;
	int actual=n;
	camino.push_back(n);
	while (padres[actual]!=-1){
		camino.push_back(padres[actual]);
		actual=padres[actual];
	}
	reverse(camino.begin(), camino.end());
	cout<<camino.size()<<endl;
	for (auto i: camino) cout<<i<<" ";
	return 0;
}
