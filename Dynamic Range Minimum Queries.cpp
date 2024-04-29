#include <bits/stdc++.h>
using namespace std;
#define MAX_N 200000
#define INF 1000000002
int ST[MAX_N*4], L[MAX_N*4], R[MAX_N*4];
int sigPot(int n){
	int pot=1;
	while (pot<n){
		pot*=2;
	}
	return pot;
}
int query (int nodo, int a, int b){
	if (a>R[nodo] || b<L[nodo]) return INF;
	if (L[nodo]>=a && R[nodo]<=b) return ST[nodo];
	return min(query(nodo*2, a,b), query(nodo*2+1, a,b));
}
void update(int k, int u, int n){
	k+=n-1;
	ST[k]=u;
	while (k/=2){
		ST[k]=min(ST[k*2], ST[k*2+1]);
	}
}
int main(){
	int n, q; cin>>n>>q;
	vector <int> nums(n);
	for (auto &i:nums) cin>>i;
	n=sigPot(n);
	//cout<<"N "<<n<<endl;
	nums.resize(n,INF);
	for (int i=0;i<n;i++){
		ST[n+i]=nums[i];
		L[n+i]=R[n+i]=n+i;
	}
	for (int i=n-1;i>=1;i--){
		ST[i]=min(ST[i*2+1], ST[i*2]);
		L[i]=L[i*2], R[i]=R[i*2+1];
	}
	while (q--){
		int a, b, c;
		cin>>a>>b>>c;
		if (a==1) update(b,c, n);
		else{
		b+=n-1;
		c+=n-1;
		cout<<query(1,b,c)<<endl;
	}
	}
}
