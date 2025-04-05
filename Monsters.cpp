#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1e17
int main(){
	ll n,m; cin>>n>>m;
	vector <string> lab (n);
	vector <pair<ll,ll>> mouns;
	vector <vector<ll>> dist(n, vector <ll> (m, INF)),distM (n, vector <ll> (m, INF));
	pair <ll,ll> pers;
	vector <vector <char>> padre (n,vector<char>(m));
	for (int i=0;i<n;i++){
		string aux="";
		for (int j=0;j<m;j++){
			char cAux; cin>>cAux; aux+=cAux;
			if (cAux=='M') mouns.push_back({i,j});
			else if (cAux=='A') pers={i,j};
		}
		lab[i]=aux;
	}
	queue <pair<ll,ll>> colaM;
	for (auto i:mouns){
		distM[i.first][i.second]=0;
		colaM.push(i);
	}
	while (colaM.size()){
		pair<ll,ll> act=colaM.front(); colaM.pop();
		ll x=act.second, y=act.first;
		if (y+1 < n && lab[y+1][x] == '.' && distM[y+1][x] > distM[y][x] + 1){
			distM[y+1][x] = distM[y][x] + 1;
			colaM.push({y+1,x});
		}
		if (y-1 >= 0 && lab[y-1][x] == '.' && distM[y-1][x] > distM[y][x] + 1){
			distM[y-1][x] = distM[y][x] + 1;
			colaM.push({y-1,x});
		}
		if (x+1 < m && lab[y][x+1] == '.' && distM[y][x+1] > distM[y][x] + 1){
			distM[y][x+1] = distM[y][x] + 1;
			colaM.push({y,x+1});
		}
		if (x-1 >= 0 && lab[y][x-1] == '.' && distM[y][x-1] > distM[y][x] + 1){
			distM[y][x-1] = distM[y][x] + 1;
			colaM.push({y,x-1});
		}
		
	}
	queue <pair <ll,ll>> cola;
	dist[pers.first][pers.second]=0;
	cola.push(pers);
	
	while (cola.size()){
		pair <ll,ll> i=cola.front(); cola.pop();
		ll x=i.second, y=i.first;
		if (x-1<0 || x+1==m || y-1<0 || y+1==n){
			string res;
			ll xAct = i.second, yAct = i.first;
			while (xAct != pers.second || yAct != pers.first){
				res += padre[yAct][xAct];
				if (padre[yAct][xAct] == 'D') yAct--;
				else if (padre[yAct][xAct] == 'U') yAct++;
				else if (padre[yAct][xAct] == 'L') xAct++;
				else xAct--;
			}
			reverse(res.begin(), res.end());
			cout << "YES" << endl;
			cout << res.size() << endl;
			for (auto i : res) cout << i;
			return 0;
			
		}	
		if (x-1>=0 && lab[y][x-1]=='.' && dist[y][x]+1<dist[y][x-1] && dist[y][x]+1<distM[y][x-1]){
			dist[y][x-1]=dist[y][x]+1;
			padre[y][x-1]='L';
			cola.push({y,x-1});
		}
		if (x+1<m && lab[y][x+1]=='.' && dist[y][x]+1<dist[y][x+1] && dist[y][x]+1<distM[y][x+1]){
			dist[y][x+1]=dist[y][x]+1;
			padre[y][x+1]='R';
			cola.push({y,x+1});
		}
		if (y-1>=0 && lab[y-1][x]=='.' && dist[y][x]+1<dist[y-1][x] && dist[y][x]+1<distM[y-1][x]){
			dist[y-1][x]=dist[y][x]+1;
			padre[y-1][x]='U';
			cola.push({y-1,x});
		}
		if (y+1>=0 && lab[y+1][x]=='.' && dist[y][x]+1<dist[y+1][x] && dist[y][x]+1<distM[y+1][x]){
			dist[y+1][x]=dist[y][x]+1;
			padre[y+1][x]='D';
			cola.push({y+1,x});
		}
	}
	cout<<"NO";
	return 0;
}
