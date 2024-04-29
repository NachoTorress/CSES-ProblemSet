#include <bits/stdc++.h>
#define ll long long
#define INF 1e18
using namespace std;
int n;
int nodoMax;
int maxi;
vector <vector <ll>> ady;
void BFS(int x){
	vector <ll> dist(n+1,INF);
	dist[x]=0;
	queue <ll> cola;
	cola.push(x);
	while (cola.size()){
		ll nodoAct=cola.front(); cola.pop();
		for (auto i:ady[nodoAct]){
			if (dist[i]>dist[nodoAct]+1){
				dist[i]=dist[nodoAct]+1;
				if (dist[i]>maxi){
					maxi=dist[i];
					nodoMax=i;
					
				}
				cola.push(i);
			}
		}
	}
}
int main(){
	maxi=0;
	cin>>n; 
	ady.resize(n+1);
	for (int i=0;i<n-1;i++){
		int a, b; cin>>a>>b;
		ady[a].push_back(b);
		ady[b].push_back(a);
	}
	BFS(1);
	//cout<<"maxi: "<<maxi<<" maxiNodo: "<<nodoMax<<endl;
	maxi=0;
	BFS(nodoMax);
	cout<<maxi;
}
