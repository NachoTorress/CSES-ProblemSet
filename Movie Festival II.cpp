#include <bits/stdc++.h>
using namespace std;
#define tipo second.first
#define a second.second
int main(){
	multiset <int> disp;
	vector <pair<int, pair<int,int>>> pelis;
	int n, k; cin>>n>>k;
	int vistas=0;
	for (int i=0;i<n;i++){
		int x, b; cin>>x>>b;
		pelis.push_back({-x,{1,0}});
		pelis.push_back({-b,{2,-x}});
	}
	sort(pelis.rbegin(), pelis.rend());
	for (int i=0;i<pelis.size();i++){
		//cout<<"size: "<<disp.size()<<endl;
		//cout<<"tipo actual "<<pelis[i].tipo<<" tiempo: "<<pelis[i].first<<endl;
		if (pelis[i].tipo==2){
			auto it=disp.lower_bound(pelis[i].a);
			if (it!=disp.end()){
				disp.erase(it);
				disp.insert(pelis[i].first);
				vistas++;
			}
			else {
				if (disp.size()<k){
					disp.insert(pelis[i].first);
					vistas++;
				}
			}
		}
	}
	cout<<vistas;
}
