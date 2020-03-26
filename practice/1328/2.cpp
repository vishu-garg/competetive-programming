#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
 
#define ll long long
#define ld long double
 
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repb(i,a,b) for(ll i=a;i>=b;i--)
 
 
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
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        ll x[n];
        rep(i,1,n)
        {
            x[i]=(i*(i+1))/2;
        }
        ll pos=1;
        ll f=0;
//        ll x=0;
        pos=lower_bound(x+1,x+n,k)-x;
//        cout<<pos<<endl;
        ll tmp=n-pos;
//        cout<<"  --- "<<tmp<<endl;
        string ans="";
        rep(i,1,tmp)
        ans+='a';
        ans+='b';
        tmp=(pos)*(pos+1)/2;
        
//        cout<<"  --- "<<tmp<<endl;
        tmp=tmp-k;
//        cout<<tmp<<endl;
        rep(i,0,tmp)
        ans+='a';
        ans+='b';
        while(ans.length()!=n)
		ans+='a';
        cout<<ans<<endl;
    }
}