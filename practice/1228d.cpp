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
    ll n,m;
    cin>>n>>m;
    ll vis[n+1];
    rep(i,1,n+1)
    vis[i]=-1;
    V a[n+1];
    rep(i,0,m)
    {
        ll x,y;
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    rep(i,1,n+1)
    sort(all(a[i]));
    
    ll k=1;
    V ans[4];
    while(k<=3)
    {
        ll x=-1;
        rep(i,1,n+1)
        {
            // cout<<vis[i]<<" ";
            if(vis[i]==-1)
            {x=i;break;}
        }
        if(x==-1)
        {
            cout<<"-1";
            return 0;
        }
        ans[k].pb(x);
        vis[x]=k;
        // cout<<x<<" ";
        rep(i,1,n+1)
        {
            if(!binary_search(a[x].begin(),a[x].end(),i) && vis[i]==-1 && x!=i)
            {
                // cout<<i<<" ";
                vis[i]=k;
                ans[k].pb(i);
            }
        }
        // cout<<"  <---  "<<k<<endl;
        k++;
    }
    rep(i,1,n+1)
    {
        if(vis[i]==-1)
        return cout<<"-1",0;
    }
    ll tot_edges=0;
    rep(i,1,4)
    {
        rep(j,i+1,4)
        {
            for(auto x : ans[i])
            for(auto y  : ans[j])
            {
                if(!binary_search(a[x].begin(),a[x].end(),y))
                {
                    cout<<"-1";
                    return 0;
                }
                tot_edges++;
            }
        }
    }
    // ll opt[n+1];
    // rep(i,1,4)
    // {
    //     rep(j,0,ans[i].size())
    //     {
    //         opt[ans[i][j]]=i;
    //     }
    // }
    if(tot_edges!=m)
    return cout<<"-1",0;
    rep(i,1,n+1)
    cout<<vis[i]<<" ";
}