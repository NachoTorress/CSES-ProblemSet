#include <bits/stdc++.h>
using namespace std;
vector <bool> visited;
vector <vector <int>> ady;
void dfs (int nodo){
	if (visited[nodo]) return;
	visited[nodo]=true;
	for (auto u:ady[nodo]) dfs(u);
}
int main(){
	int n, m;
	cin>>n>>m;
	visited.resize(n+1);
	ady.resize(n+1);
	for (int i=0;i<m;i++){
		int a, b;
		cin>>a>>b;
		ady[a].push_back(b);
		ady[b].push_back(a);
	}
		vector <int> cabecera;
		for (int i=1;i<=n;i++){
			if (!visited[i]){
				cabecera.push_back(i);
				dfs(i);
			}
		}
	cout<<cabecera.size()-1<<endl;
	for (int i=0;i<cabecera.size()-1;i++){
		cout<<cabecera[i]<<" "<<cabecera[i+1]<<endl;
	}
}
