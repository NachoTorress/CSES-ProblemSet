#include <bits/stdc++.h>
using namespace std;
#define pii pair <int, int>
int main(){
	int n; cin>>n;
	vector <pii> nums(n);
	for (int i=0;i<n;i++){
		cin>>nums[i].first;
		nums[i].second=i;
	}
	sort (nums.begin(), nums.end());
	int inicio=0, contador=0;
	while (inicio<n){
		while (nums[inicio].second<nums[inicio+1].second){
			inicio++;
			//cout<<"hola"<<endl;
		}
		//cout<<"chau"<<endl;
		contador++;
		inicio++;
	}
	cout<<contador;
}
