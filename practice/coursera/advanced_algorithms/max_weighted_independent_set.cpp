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
vector<vector<ll>>adj;
vector<ll>w;
vector<ll>dv;
ll fun_party(ll s,ll prv)
{
    if(dv[s]==INF)
    {
        ll ans1=w[s];
            for(auto it:adj[s])
            {
                if(it!=prv)
                {
                for(auto it2:adj[it])
                {
                    if(it2!=s)
                    {
                    // cout<<it2<<" ";
                    ans1+=fun_party(it2,it);
                    }
                }
                }
            }
            ll ans2=0;
            for(auto it: adj[s])
            {
                if(it!=prv)
                {
                ans2+=fun_party(it,s);
                }
            }
            // cout<<s<<" "<<ans1<<" "<<ans2<<" "<<endl;
            dv[s]=max(ans1,ans2);
    }
    return dv[s];
}

int main()
{
    fast;
    ll T=1;
//     cin>>T;
    while(T--)
    {
        ll n;
        cin>>n;
        adj=vector<vector<ll>>(n+1);
        w=vector<ll>(n+1);
        dv=vector<ll>(n+1,INF);
        for(int i=1;i<=n;i++)
        {
            cin>>w[i];
        }

        for(int i=1;i<n;i++)
        {
            ll u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        ll ans=fun_party(1,-1);
        cout<<ans<<endl;
    }

}