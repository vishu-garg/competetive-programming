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
const ll INF = LLONG_MAX;
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
ll n,m;
vector<pair<pll,ll> >vec;
vector<bool>vis;
bool flg=false;
void func(ll s)
{
    vector<ll>dist(n,INF);
        dist[s]=0;
        
        vis[s]=true;
        rep(i,1,n)
        {
            rep(j,0,m)
            {
                ll u=vec[j].first.first;
                ll v=vec[j].first.second;
                ll w=vec[j].second;
                if(vis[u] && dist[v]>dist[u]+w)
                {dist[v]=dist[u]+w;vis[v]=true;}
            }
        }
        rep(i,0,m)
        {
            ll u=vec[i].first.first;
                ll v=vec[i].first.second;
                ll w=vec[i].second;
                if(vis[u] && dist[v]>dist[u]+w)
                {
                    flg=true;
                    break;
                }
        }
}


int main()
{
    fast;
    ll t=1;
//     cin>>t;
    while(t--)
    {
        // ll n,m;
        cin>>n>>m;
        
        rep(i,0,m)
        {
            ll u,v,w;
            cin>>u>>v>>w;
            u--;v--;
            vec.pb({{u,v},w});
        }

        vis=vector<bool>(n,false);
        // func(0);
        // cout<<flg<<"<--"<<endl;
        rep(i,0,n)
        {
            if(vis[i]==false)
            func(i);
            if(flg)
            break;
        }

        if(flg)cout<<"1";
        else cout<<"0";
        
    }

}