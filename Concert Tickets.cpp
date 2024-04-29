#include <bits/stdc++.h>
using namespace std; 
int main(){
	int n, m; cin>>n>>m;
	multiset<int> tickets;
	while (n--){
		int aux; cin>>aux; tickets.insert(-aux);
	}
	while (m--){
		int aux;cin>>aux;
		auto it=tickets.lower_bound(-aux);
		if (it!=tickets.end() && *it<=aux){
			cout<<-*it<<endl;
			tickets.erase(it);
		}
		else {
			cout<<-1<<endl;
		}
	}
}
