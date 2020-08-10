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
ll n,m;
vector<vector<char> >adj;
vector<vector<bool> >vis;

void dfs(ll i, ll j)
{
    vis[i][j]=true;
    if(i+1<n && adj[i+1][j]=='#' && !vis[i+1][j] )
    dfs(i+1,j);
    if(i-1>=0 && adj[i-1][j]=='#' && !vis[i-1][j])
    dfs(i-1,j);
    if(j+1<m && adj[i][j+1]=='#' && !vis[i][j+1])
    dfs(i,j+1);
    if(j-1>=0 && adj[i][j-1]=='#' && !vis[i][j-1])
    dfs(i,j-1);
}

int main()
{
    ll t=1;
//     cin>>t;
    while(t--)
    {
        cin>>n>>m;
        adj=vector<vector<char> >(n,vector<char>(m));
        rep(i,0,n)
        rep(j,0,m)
        cin>>adj[i][j];

        ll r=0,c=0;

        rep(i,0,n)
        {
            ll cnt_w=0;
            rep(j,0,m)
            {
                if(adj[i][j]=='.')
                cnt_w++;
            }
            if(cnt_w==m)
            r++;
        }

        rep(i,0,m)
        {
            ll cnt_w=0;
            rep(j,0,n)
            {
                if(adj[j][i]=='.')
                cnt_w++;
            }
            if(cnt_w==n)
            c++;
        }

        if(r==0 && c!=0)
        {
            cout<<"-1";
            return 0;
        }
        if(r!=0 && c==0)
        {
            cout<<"-1";
            return 0;
        }

        rep(i,0,n)
        {
            int crnt=-1;
            rep(j,0,m)
            {
                if(adj[i][j]=='#' && crnt==-1)
                crnt=j;
                else if(adj[i][j]=='#')
                {
                    ll tmp=j-crnt;
                    if(tmp!=1)
                    {
                        cout<<"-1";
                        return 0;
                    }
                    else
                    crnt=j; 
                }
            }
        }

        rep(i,0,m)
        {
            ll crnt=-1;
            rep(j,0,n)
            {
                if(adj[j][i]=='#' && crnt==-1)
                crnt=j;
                else if(adj[j][i]=='#')
                {
                    ll tmp=j-crnt;
                    if(tmp!=1)
                    {
                        cout<<"-1";
                        return 0;
                    }
                    else 
                    crnt=j;
                }
            }
        }

        vis=vector<vector<bool> >(n,vector<bool>(m,false));
        ll ans=0;
        rep(i,0,n)
        {
            rep(j,0,m)
            {
                if(adj[i][j]=='#' && !vis[i][j])
                {
                    ans++;
                    dfs(i,j);
                }
            }
        }
        cout<<ans;
    }
}