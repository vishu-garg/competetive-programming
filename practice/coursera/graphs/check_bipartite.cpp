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

vector<vector<ll> >adj;

int main()
{
    fast;
    ll t=1;
//     cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        adj=vector<V>(n);
        rep(i,0,m)
        {
            ll u,v;
            cin>>u>>v;
            u--;v--;
            adj[v].pb(u);
            adj[u].pb(v);
        }
        queue<ll>q;
        vector<ll> vis(n,-1);
        vector<ll>side(n,-1);
        rep(i,0,n)
        {
            if(vis[i]==1)
            continue;
            q.push(i);
            vis[i]=1;
            side[i]=0;
            while(!q.empty())
            {
                ll ele=q.front();
                q.pop();
                for(auto it : adj[ele])
                {
                    if(vis[it]!=1)
                    {
                        // err2(ele,it)<<"<---"<<endl;
                        // err2(side[ele],side[it])<<endl;
                        side[it]=(side[ele]^1);
                            vis[it]=1;
                            q.push(it);
                    }
                    else 
                    {
                        if(side[it]==side[ele])
                        {
                            cout<<"0";
                            return 0;
                        }
                    }
                }
            }
            cout<<"1";
            return 0;
        }
    }

}