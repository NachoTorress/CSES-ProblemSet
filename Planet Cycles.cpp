#include <bits/stdc++.h>
using namespace std;
#define ll long long 
vector <ll> ady; 
vector <bool> visited; 
vector <ll> dist; 
vector <ll> dp ;
ll longCiclo, inicioCiclo; 
void dfs (ll nodo, ll distAct){
	if (visited[nodo]) return; 
	visited[nodo]=1; 
	dist[nodo]=distAct; 
	ll vec=ady[nodo]; 
	if (!visited[vec]) dfs(vec,distAct+1); 
	else {
		if (!dp[vec]) longCiclo=dist[nodo]-dist[vec]+1, inicioCiclo=vec; 
		else longCiclo=dp[vec];
	}
	if (inicioCiclo){
		dp[nodo]=longCiclo; 
		if (inicioCiclo==nodo) inicioCiclo=0;
	}
	else dp[nodo]=dp[vec]+1;
	
}
int main(){
	ll n; cin>>n; 
	ady.resize(n+1), visited.resize(n+1), dist.resize(n+1), dp.resize(n+1);
	for (int i=1;i<=n;i++) cin>>ady[i]; 
	for (int i=1;i<=n;i++){
		longCiclo=0, inicioCiclo=0; 
		if (!visited[i]) dfs(i,1);
	}
	for (int i=1;i<=n;i++) cout<<dp[i]<<" ";
}
