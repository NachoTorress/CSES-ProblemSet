#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, x; cin>>n>>x;
	vector <int> pesos (n);
	for (auto &i:pesos)	cin>>i;
	sort(pesos.begin(), pesos.end());
	int pesoMedio=x/2, posMedio=0;
	for (auto i:pesos){
		if (i>=pesoMedio) break;
		else posMedio++;
	}
	if (posMedio==n){
	
	 cout<<n/2+n%2;
	 return 0;
	}
	priority_queue <int> cola1, cola2;
	for (int i=0;i<posMedio;i++){
		cola1.push(-pesos[i]);
	}
	for (int i=posMedio;i<n;i++){
		cola2.push(pesos[i]);
	}
	int gondolas=0;
	while (cola1.size()!=0 && cola2.size()!=0){
	//	cout<<"CICLO DOBLE: cola2: "<<cola2.top()<<" cola1 "<<cola1.top()*-1<<endl; 
 
		int final=cola2.top(); cola2.pop();
		if (final+(cola1.top()*-1)<=x) cola1.pop();
		gondolas++;
			//	cout<<"GONDOLAS: "<<gondolas<<endl;
	}
	if (cola1.size()>0){
		while (cola1.size()>0){
		int ult=cola1.top()*-1; cola1.pop();
		
		//cout<<"CICLO INDIVIDUAL: PRIMERO: "<<ult<<" SEGUNDO: "<<cola1.top()*1<<endl;
		if (cola1.size()>0){
		if (ult+(cola1.top()*-1)<=x) cola1.pop();
	
		}
			gondolas++;
	}
	}
	else if (cola2.size()>0){
		while (cola2.size()>0){
			int ulti=cola2.top(); cola2.pop();
			if (cola2.size()>0){
				if (ulti+cola2.top()<=x) cola2.pop();
			}
			gondolas++;
		}
	}
	cout<<gondolas;
}
