#include <bits/stdc++.h>
using namespace std;
int main(){
	long long t; cin>>t;
	while (t--){
	
	
	long long x, y;
	cin>>x>> y;
	long long z=max(x,y);
	if (z%2){
		if (x>=y)		cout<<((z-1)*(z-1)+y)<<endl;
		else cout<<z*z-x+1<<endl;
	}
	else {
		if (x>=y) cout<<x*x-y+1<<endl;
		else cout<<(y-1)*(y-1)+x<<endl;
	}
}
}
