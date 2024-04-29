#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; cin>>n; 
	set <int> nums; 
	for (int i=1;i<=n;i++){
		nums.insert(i);
	}
	auto it=nums.begin();
	auto aux=it;
	it++;
	vector <int> borrar;
	int contador=0;
	while (contador<n){
		cout<<*it<<" ";
		borrar.push_back(*it);
		it++;
		contador++;
		if (contador==n) continue;
		if (it==nums.end()){
			for (auto i:borrar) nums.erase(i);
			borrar.resize(0);
			it=nums.begin();
		}
		it++;
		if (it==nums.end()){
			for (auto i:borrar) nums.erase(i);
			borrar.resize(0);
			it=nums.begin();
		}
	
		
			
	}
}
