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
int n, m;
vector<string> c, s;
map<char, array<int,2> > d;
vector<vector<vector<array<int,2> > > > adj;
vector<vector<bool>> vis1, vis2;
vector<array<int,2> > cyc;
vector<int> a;
array<int,2> nxt(array<int,2> pnt)
{
    return {pnt[0]+d[s[pnt[0]][pnt[1]]][0],pnt[1]+d[s[pnt[0]][pnt[1]]][1]};
}

void dfs1(array<int,2> u)
{
    if(vis1[u[0]][u[1]]==1)
    {
        cyc.pb(u);
        return;
    }
    vis1[u[0]][u[1]]=1;
    dfs1(nxt(u));
    if(cyc.back()==nxt(u) && cyc[0]!=u)
    cyc.pb(u);
}

void dfs2(array<int,2> u,int d=0)
{
    vis2[u[0]][u[1]]=1;
    if(c[u[0]][u[1]]=='0')
    {
        ++a[d%cyc.size()];
    }
    for(auto it : adj[u[0]][u[1]])
    {
        if(!vis2[it[0]][it[1]])
        dfs2(it,d+1);
    }
}

int main()
{
    d['D']={1,0};
    d['U']={-1,0};
    d['L']={0,-1};
    d['R']={0,1};
    ll t=1;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        c=s=vector<string>(n);
        rep(i,0,n)
        {
            cin>>c[i];
        }
        rep(i,0,n)
        {
            cin>>s[i];
        }
        
        adj=vector<vector<vector<array<int,2>>>>(n,vector<vector<array<int,2>>>(m));
        rep(i,0,n)
        {
            rep(j,0,m)
            {
                array<int,2> pnt={i,j};
                array<int,2> v=nxt(pnt);
                adj[v[0]][v[1]].pb({i,j});
            }
        }

        vis1=vis2=vector<vector<bool> >(n,vector<bool>(m));
        int a1=0,a2=0;

        rep(i,0,n)
        {
            rep(j,0,m)
            {
                if(vis2[i][j]==1)
                continue;
                cyc.clear();
                dfs1({i,j});
                a1+=cyc.size();
                a=vector<int>(cyc.size());
                dfs2(cyc[0]);
                rep(i,0,a.size())
                {
                    if(a[i]>0)
                    a2++;
                }
            }
        }

        cout<<a1<<" "<<a2<<endl;
    }
}

/*
    This question involves :

    1) How to find connected components in a directed graph not exactly but as done by storing reversed direction and the calling dfs2;
    2)  We came to know about functional graph:-
            It involves atleast one connected component and exactly one cycle in each connected component
            We also found that cycle present in the connected component by dfs1;
            dfs1 is a standard function used to find the cyc in directed graph; 
*/