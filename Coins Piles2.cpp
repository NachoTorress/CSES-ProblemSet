#include <bits/stdc++.h>
using namespace std;
int main(){
	int q;
	cin>>q;
	while (q--){
	int a,b;
	cin>>a>>b;
	if ((a+b)%3==0){
			while (a>0 && b>0){
		while (a>=b){
			
			long long aux=a/2;
			if (b-aux>=0){
			 a-=aux*2; b-=aux;
		}
			else{
			 a-=2;
			 b--;
		}
			//cout<<"a "<<a<<" b "<<b<<endl;
			if (a==0 && b>=1) break;
			if (a>=1 && b==0) break;
			
		}
			while (b>a){
			long long aux=b/2;
			b-=aux*2; a-=aux;
			if (a==0 && b>=1) break;
			if (a>=1 && b==0) break;
			if (a==0 && a==b) break;
		//	cout<<a<<" "<<b<<endl;
		}
	
}
	if (a==0 && b==0) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
	else cout<<"NO";
}
}

