#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
   ll t;
   cin>>t;
   while(t--){
   	ll r,g,b;
   	cin>>r>>g>>b;
   	ll a[3];
   	a[0]=r;a[1]=g;a[2]=b;
   	sort(a,a+3);
   	ll z=0;
   	r=a[0];g=a[1];b=a[2];
    if(b-(r+g)>=2){
    	cout<<"No"<<endl;
	}
	else{
		cout<<"Yes"<<endl;
	}
}
}