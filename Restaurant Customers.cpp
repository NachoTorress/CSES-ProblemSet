#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; cin>>n; 
	vector <pair <int, int>> clients;
	for (int i=0;i<n;i++){
		int aux1, aux2; cin>>aux1>>aux2;
		clients.push_back({aux1,1}); clients.push_back({aux2,-1});
	}
	sort (clients.begin(), clients.end());
	vector <int> clientes;
	int maxClients=1;
	clientes.push_back(1);
	for (int i=1;i<clients.size();i++){
		clientes.push_back(clientes[i-1]+clients[i].second);
		maxClients=max(clientes[i], maxClients);
	}
	cout<<maxClients;
	}
