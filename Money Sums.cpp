#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    vector <int> coins (n);
    int total=0;
    for (auto &i : coins){ cin>>i; total+=i;}
    map <int, int> mapa, mapAux;
    mapa[0]++, mapAux[0]++, mapa[coins[0]]++, mapAux[coins[0]]++;
    for (int i=1;i<n;i++){
        for (auto j : mapa){
            mapAux[j.first+coins[i]]++;
            }
            mapa=mapAux;
            }
            cout<<mapa.size()-1<<endl;
            for (auto i:mapa){
             if (i.first!=0) cout<<i.first<<" ";
            }
            }
