#include <bits/stdc++.h>
using namespace std;
vector <vector <pair <long long, long long>>> ady;
vector <bool> processed;
vector <long long> dist;
vector <long long> costoso;
int main(){
	long long n, m;
	cin>>n>>m;
	ady.resize(n+1); 
	processed.resize(n+1, false);
	dist.resize(n+1, 1e18);
	costoso.resize(n+1, 0);
	for (int i=0;i<m;i++){
		long long a, b, c; cin>>a>>b>>c;
		ady[a].push_back({b,c});
		ady[b].push_back({a,c});
	}
	priority_queue<pair<long long, long long>> pq;
	pq.push({0,1});
	dist[1]=0;
	costoso[1]=0;
	while (pq.size()){
		int nodo=pq.top().second;
		pq.pop();
		if (processed[nodo]) continue;
		processed[nodo]=true;
		for (auto par:ady[nodo]){
			int vecino = par.first;
            long long costo = par.second;
            int maxCosto=max(costo, costoso[nodo]);
            if (maxCosto==costoso[nodo]) 
            if(dist[vecino] > dist[nodo]+costo-maxCosto/2)
            {
            	costoso[vecino]=max(costo, costoso[nodo]);
                dist[vecino] = dist[nodo]+costo;
				if (costoso[nodo]!=costoso[vecino]) dist[vecino]+=costoso[nodo]/2;
                pq.push({-dist[vecino], vecino});
            }
        }

		}
		//for(int i=1; i<=n; i++)
    //{
    cout<<"costoso "<<costoso[n]<<endl;
    
        cout << dist[n]-(costoso[n]/2) << " ";
    //}

	}

