#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define tiempo first.first
#define tipo first.second
#define procede second.first
#define pos second.second
int main(){
	int n; cin>>n;
	vector <pair<pair<int,int>,pair <int, int>>> rooms;
	map <int, vector <int>> disp;
	vector <int> resp(n);
	for (int i=0;i<n;i++){
		int a, b; cin>>a>>b;
		rooms.PB({{-a,1},{0,i}}); rooms.PB({{-b,2},{-a,i}});
	}
	sort (rooms.rbegin(), rooms.rend());
	int cuartoAct=1,  posi;
	for (int i=0;i<rooms.size();i++){
		if (rooms[i].tipo==2){
			disp[rooms[i].tiempo].PB(cuartoAct);
			resp[rooms[i].pos]=cuartoAct;
			posi=i;
			//cout<<"POSI "<<rooms[i].pos<<endl;
			break;
			
		}
	}
	
	for(int i=posi+1;i<rooms.size();i++){
		if (rooms[i].tipo==2){
			auto it=disp.upper_bound(rooms[i].procede);
			if (it !=disp.end()){
				resp[rooms[i].pos]=it->second.back();
				disp[rooms[i].tiempo].PB(it->second.back());
				it->second.pop_back();
				if (it->second.empty()) {
        			auto temp = it; // Guarda el iterador en una variable temporal
        			++it; // Avanza el iterador antes de borrar el elemento
        			disp.erase(temp); // Borra el elemento del mapa
    			}
			}
			else {
				cuartoAct++;
				disp[rooms[i].tiempo].PB(cuartoAct);
				resp[rooms[i].pos]=cuartoAct;
			}
		}
	}
	cout<<cuartoAct<<endl;
	for (auto i:resp) cout<<i<<" ";
}
