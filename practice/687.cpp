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
bool ok=true;
void dfs(ll s, vector<ll>&side , vector<vector<ll> >&adj)
{
    for(auto it:adj[s])
    {
        if(side[it]!=-1)
        {   
            if(side[it]!=(side[s]^1))
            {
                ok=false;
            }
        }
        else 
        {
            side[it]=side[s]^1;
            dfs(it,side,adj);
        }
    }
}

int main()
{
    fast;
    ll T=1;
//     cin>>T;
    while(T--)
    {
        // cout<<"==="<<e
        ll n,m;
        cin>>n>>m;
        // err()
        vector<vector<ll> >adj(n);
        rep(i,0,m)
        {
            ll u,v;
            cin>>u>>v;
            u--;v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        // err()
        vector<ll>side(n,-1);
        rep(i,0,n)
        {
            if(side[i]!=-1)continue;
            side[i]=0;
            // err()
            dfs(i,side,adj);
            if(!ok)
            {
                cout<<"-1";
                return 0;
            }
        }
        ll cnt1=0,cnt2=0;
        for(auto it:side)
        {
            if(it==1)cnt2++;
            else 
            cnt1++;
        }
        cout<<cnt1<<endl;
        for(ll i=0;i<n;i++)
        {
            if(side[i]==0)
            cout<<i+1<<" ";
        }
        cout<<endl<<cnt2<<endl;
        for(ll i=0;i<n;i++)
        {
            if(side[i]==1)
            cout<<i+1<<endl;
        }
        return 0;
    }

}