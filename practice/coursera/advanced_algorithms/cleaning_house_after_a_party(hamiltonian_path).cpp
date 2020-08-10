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
//     cin>>T;
    while(T--)
    {
        ll n,m;
        cin>>n>>m;
        ll v=1;
        map<pll,ll>mp;
        rep(i,1,n+1)
        {
            rep(j,1,n+1)
            {
                mp[{i,j}]=v;
                v++;
            }
        }

        vector<vector<ll> >adj(n+1,vector<ll>(n+1,0));
        // vector<ll> vis(n+1);
        rep(i,0,m)
        {
            ll u,v;
            cin>>u>>v;
            adj[u][v]=1;
            adj[v][u]=1;
            
        }

        ll edg=0;
        rep(i,1,n+1)
        rep(j,1,n+1)
        if(adj[i][j]==1)
        {
            // cout<<i<<" "<<j<<"<---"<<endl;
            edg++;
        }
        edg/=2;

        v=n*n;
        ll c=0;
        c+=2*n;
        c+=2*((n)*((n*(n-1))/2));
        ll tmp=((n*(n-1))/2)-(edg);
        tmp*=2;
        tmp*=(n-1);
        // err1(edg)<<endl;
        // cout<<tmp<<"<----"<<endl;
        c+=tmp;

        cout<<c<<" "<<v<<endl;

        rep(i,1,n+1)
        {
            rep(j,1,n+1)
            cout<<mp[{j,i}]<<" ";
            cout<<"0"<<endl;
        }

        rep(i,1,n+1)
        {
            rep(j,1,n+1)
            {
                rep(k,j+1,n+1)
                cout<<"-"<<mp[{j,i}]<<" -"<<mp[{k,i}]<<" 0"<<endl;
            }
        }

        rep(i,1,n+1)
        {
            rep(j,1,n+1)
            {
                cout<<mp[{i,j}]<<" ";
            }
            cout<<"0"<<endl;
        }

        rep(i,1,n+1)
        {
            rep(j,1,n+1)
            {
                rep(k,j+1,n+1)
                cout<<"-"<<mp[{i,j}]<<" -"<<mp[{i,k}]<<" 0"<<endl;
            }
        }

        rep(i,1,n)
        {
            rep(j,1,n+1)
            {
                rep(k,1,n+1)
                {
                    if(j!=k && adj[j][k]==0)
                    {
                    // cout<<j<<" "<<k<<"<---"<<endl;
                    cout<<"-"<<mp[{i,j}]<<" -"<<mp[{i+1,k}]<<" 0"<<endl;
                    }
                }
            }
        }

        
    }

}