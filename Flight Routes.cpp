// Include practico para compilar con geany: puede ser necesario borrarlo en otros entornos.
#include <bits/stdc++.h>
using namespace std;

vector <vector<pair<int, int>>> grafo;
vector<long long> gps(int N, int M, int comienzo, int fin, int K, vector<int> origen, vector<int> destino, vector<int> tiempo)
{
	grafo.resize(N+1);
    for (int i=0;i<M;i++){
    	grafo[origen[i]].push_back({destino[i], tiempo[i]});
	}
    priority_queue <pair<long long, int> > pq;
    vector <long long> dist; 
    pq.push({0, comienzo});
	vector <long long> procesado(N+1,0) ;
    while(dist.size()<K && pq.size())
    {
        long long nodo = pq.top().second;
        long long costoAct=-pq.top().first;
        if (nodo==fin)dist.push_back(-pq.top().first);  
        procesado[nodo]++;
        pq.pop();       
		if(procesado[nodo]>K) continue;    
              
        for(auto par:grafo[nodo]) 
        {      	
            long long vecino = par.first;
            long long costo = par.second;
            if (procesado[vecino]<=K)
            	pq.push({-(costoAct+costo), vecino});
			}      
            }
            return dist;
}

int main()
{
    int N,M;
    cin >> N >> M;
    int comienzo, fin;
   // cin >> comienzo >> fin;
    int K;
    cin >> K;
    vector<int> origen(M), destino(M), tiempo(M);
    for(int i=0; i<M; i++)
        cin >> origen[i] >> destino[i] >> tiempo[i];
    vector<long long> result = gps(N,M,1,N,K,origen, destino, tiempo);
    for (int i=0; i<int(result.size()); i++)
    {
        if (i > 0)
            cout << " ";
        cout << result[i];
    }
    cout << "\n";
    return 0;
}
