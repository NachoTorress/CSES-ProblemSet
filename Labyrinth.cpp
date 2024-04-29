#include <bits/stdc++.h>
using namespace std;
vector <vector <long long>> dist;
vector <vector <char>> lab;
vector <vector <char>> padres;
vector <vector <bool>> visited;
int n, m;
pair <long long, long long> a, b;
void bfs (){
	queue <pair <long long, long long>> q;
	q.push({a.first, a.second});
	dist[a.first][a.second]=0;
	visited[a.first][a.second]=true;
	while (q.size()>0){
		long long i=q.front().first, j=q.front().second;
		q.pop();
		visited[i][j]=true;
		if (i-1>=0){
			if (lab[i-1][j]!='#' && dist[i][j]+1<dist[i-1][j]){
				padres[i-1][j]='D';
				dist[i-1][j]=dist[i][j]+1;
				//cout<<"DIST [i-1][j]"<<dist[i-1][j]<<endl;
				q.push({i-1,j});
				
			}
		}
		if (i+1<n){
			if (lab[i+1][j]!='#' && dist[i][j]+1<dist[i+1][j]){
				padres[i+1][j]='U';
				dist[i+1][j]=dist[i][j]+1;
				q.push({i+1,j});
			}
		}
		if (j-1>=0){
			if (lab[i][j-1]!='#' && dist[i][j]+1<dist[i][j-1]){
				padres[i][j-1]=+'R';
				dist[i][j-1]=dist[i][j]+1;
				q.push({i,j-1});
			}
		}
		if (j+1<m){
			if (lab[i][j+1]!='#' && dist[i][j]+1<dist[i][j+1]){
				padres[i][j+1]='L';
				dist[i][j+1]=dist[i][j]+1;
				q.push({i,j+1});
			}
		}
}
}
int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cin>>n>>m;
	lab.resize(n,vector<char>(m));
	dist.resize(n, vector <long long>(m, 9223372036854775806));
	padres.resize(n, vector <char> (m));
	visited.resize(n, vector <bool> (m, false));
	for (long long i=0;i<n;i++){
		for (long long j=0;j<m;j++){
			cin>>lab[i][j];
			if (lab[i][j]=='A') a.first=i, a.second=j;
			else if (lab[i][j]=='B') b.first=i, b.second=j;
		}
	}
	bfs();
	if (!visited[b.first][b.second]){
		cout<<"NO";
		return 0;
	}
	int i=b.first, j=b.second;
	char charAct='a';
	string solucion;
	while (charAct!='A'){
		if (padres[i][j]=='U'){
			solucion+='D';
			i--;
		}
		else if (padres[i][j]=='D'){
			solucion+='U';
			i++;
		}
		else if (padres[i][j]=='L'){
			solucion+='R';
			j--;
		}
		else if (padres[i][j]=='R'){
			solucion+='L';
			j++;
		}
		charAct=lab[i][j];
		
	}
	reverse(solucion.begin(), solucion.end());
	cout<<"YES \n";
	cout<<dist[b.first][b.second]<<"\n";
	cout<<solucion;
}
