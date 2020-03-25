#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
 
#define ll long long
#define ld long double
 
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repb(i,a,b) for(ll i=a;i>=b;i--)
 
#define err() cout<<"=================================="<<endl;
#define errA(A) for(auto i:A)   cout<<i<<" ";cout<<endl;
#define err1(a) cout<<#a<<" "<<a<<endl
#define err2(a,b) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<endl
#define err3(a,b,c) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<endl
#define err4(a,b,c,d) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<" "<<#d<<" "<<d<<endl
 
#define pb push_back
#define all(A)  A.begin(),A.end()
#define allr(A)    A.rbegin(),A.rend()
#define ft first
#define sd second
 
#define pll pair<ll,ll>
#define V vector<ll>
#define S set<ll>
#define VV vector<V>
#define Vpll vector<pll>
 
#define endl "\n"
 
const ll logN = 20;
const ll M = 1000000007;
const ll INF = 1e12;
#define PI 3.14159265

int main(){
	ll t;
	cin>>t;
	while(t--){
	ll n,x;
	cin>>n>>x;
	V v;
	rep(i,0,n){
		ll j;
		cin>>j;
		v.pb(j);
	}
	sort(v.begin(),v.end());
	ll z=2*(v[n-1]);
	ll ans=0;
	ll pos=0;
	ll num=v[n-1];
	ll rem=x-pos;
	ll chk=0;
    if(x>z){
	ll num2=x-(2*num);
	ll val=num2/num;
	if(num2%num!=0){
		val++;
	}
	ans+=val;
	pos+=(val*num);
}
	while(chk==0){
		rem=x-pos;
		if(binary_search(v.begin(),v.end(),rem)){
			ans++;
			chk=1;
		}
		else{
				ans+=2;
				chk=1;
		}
	}
	cout<<ans<<endl;
	}
}