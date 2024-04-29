#include <bits/stdc++.h>
using namespace std;
vector <int> hijos;
vector <int> padre;
vector <int> resp;
int main(){
	int n; cin>>n;
	hijos.resize(n); padre.resize(n); resp.resize(n,0);
	padre[0]=0;
	for (int i=1;i<n;i++){
		int jefe; cin>>jefe;
		hijos[jefe-1]++;
		padre[i]=jefe-1;
	}
	queue <int> cola;
	for (int i=1;i<n;i++) if(!hijos[i]) cola.push(i);
	while (cola.size()){
		int nodo=cola.front(); cola.pop();
		if (nodo==0) break;
		hijos[padre[nodo]]--;
		if (!hijos[padre[nodo]]) cola.push(padre[nodo]);
		resp[padre[nodo]]+=resp[nodo]+1;
	}
	for (auto i:resp) cout<<i<<" ";
}
