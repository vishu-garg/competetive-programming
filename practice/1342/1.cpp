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
    ll t=1;
    cin>>t;
    while(t--)
    {
        ll x,y;
        cin>>x>>y;
        ll a,b;
        cin>>a>>b;
        ll max_cost=a*((abs(x))+(abs(y)));
        ll x1=min(x,y);
        ll x2=max(x,y);
        ll cost2=a*(x2-x1)+(b*abs(x1));
        ll ans=min(cost2,max_cost);
        cout<<ans<<endl;
    }

}