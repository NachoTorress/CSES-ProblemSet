#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector <vector <ll>> ady;
vector <ll> depende;
int main(){
	
	int n, m, total=0; cin>>n>>m;
	ady.resize(n+1); depende.resize(n+1);
	for (int i=0;i<m;i++){
		int a, b;
		cin>>a>>b;
		depende[b]++;
		ady[a].push_back(b);
	}
	queue <ll> topo;
	vector <int> resp;
	for (int i=1;i<=n;i++){
		if (!depende[i]) topo.push(i);
	}
	while (topo.size()){
		ll nodo=topo.front(); topo.pop();
		for (int i=0;i<ady[nodo].size();i++){
			depende[ady[nodo][i]]--;
			if (depende[ady[nodo][i]]==0) topo.push(ady[nodo][i]);
		}
		resp.push_back(nodo);
	}
	//cout<<"SIZE "<<resp.size()<<endl;
	//for (auto i:resp) cout<<i<<endl;
	if (resp.size()<n){
		cout<<"IMPOSSIBLE"; return 0;
	}
	for (auto i:resp) cout<<i<<" ";
}
