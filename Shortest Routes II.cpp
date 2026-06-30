#include <bits/stdc++.h>
using namespace std; 
#define ll long long
#define ff first
#define sc second 
ll INF=1e16;
vector <vector <ll>> ady;
int main(){
	ll n,m,q; cin>>n>>m>>q;
	ady.resize(n+1, vector <ll>(n+1,INF));
	for (int i=0;i<m;i++){
		ll a,b,c; cin>>a>>b>>c;
		if (c<ady[a][b]) ady[a][b]=c, ady[b][a]=c;
	}
	
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			for (int k=1;k<=n;k++){
				if (i==j || i==k ) continue;
				if (j==k){ ady[j][k]=ady[k][j]=0; break;}
				ady[j][k]=ady[k][j]=min(ady[j][k], ady[j][i]+ady[i][k]);
			}
		}
	}
	while (q--){
		ll a,b; cin>>a>>b;
		cout<<(ady[a][b]!=INF ? ady[a][b]:-1)<<endl;
	}
}
