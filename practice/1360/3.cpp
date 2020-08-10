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
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int pow1(int a,int b){
    int res=1;
    while(b>0){
        if(b&1){
        	res=res*a;
		}
        a=a*a;
        b>>=1;
    }
    return res;
}

int main()
{
    fast;
    ll T=1;
    cin>>T;
    while(T--)
    {
         ll n;
   cin>>n;
   V v(n);
   rep(i,0,n)cin>>v[i];
   sort(all(v));
   V v1,v2;
   rep(i,0,n){
   	if(v[i]%2==0)v1.pb(v[i]);
   	else v2.pb(v[i]);
   }
   if(v1.size()%2==0){
   	cout<<"YES"<<endl;
   }
   else{
   V v3;
   rep(i,0,v1.size()){
   	v3.pb(v1[i]-1);
   	v3.pb(v1[i]+1);
   }
   ll chk=0;
   rep(i,0,v3.size()){
   	vector<ll>::iterator it=find(all(v2),v3[i]);
   	if(it!=v2.end()){
   		chk=1;
   		break;
	   }
   }
   if(chk==1)cout<<"YES"<<endl;
   else cout<<"NO"<<endl;
   }

    }

}