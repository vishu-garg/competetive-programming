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
vector<vector<pll>>adj;
vector<ll> ans,vis;
ll dp[105][105][27][2];

char dfs(ll a, ll b, ll prv , ll rnd)
{
    if(dp[a][b][prv][rnd%2]!=-1)return dp[a][b][prv][rnd%2];

   if(rnd%2==0)
   {
       bool tmp=false;
       if(adj[a].size()==0)
       {
           dp[a][b][prv][rnd%2]=1;
           return dp[a][b][prv][rnd%2];
       }
       ll fnd=0;
       ll ch;
       for(auto it : adj[a])
       {
           if(it.second>=prv)
           {
               fnd=1;
              ch= dfs(it.first,b,it.second,rnd+1);
              if(ch==0)
              break;
           }
       }
       if(fnd==0)
       {
           dp[a][b][prv][rnd%2]=1;
           return dp[a][b][prv][rnd%2];
       }
       if(ch==0)
       {
           dp[a][b][prv][rnd%2]=0;
           return dp[a][b][prv][rnd%2];
       }
       else
       {
           dp[a][b][prv][rnd%2]=1;
           return dp[a][b][prv][rnd%2];
       }
   }
   else 
   {
       if(adj[b].size()==0)
       {
           dp[a][b][prv][rnd%2]=0;
           return dp[a][b][prv][rnd%2];
       }
       ll fnd=0;
       ll ch;
       for(auto it: adj[b])
       {
           if(it.second>=prv)
           {
               fnd=1;
               ch=dfs(a,it.first,it.second,rnd+1);
               if(ch==1)
               break;
           }
       }
       if(fnd==0)
       {
           dp[a][b][prv][rnd%2]=0;
           return dp[a][b][prv][rnd%2];
       }
       if(ch==0)
       {
           dp[a][b][prv][rnd%2]=0;
           return dp[a][b][prv][rnd%2];
       }
       else
       {
           dp[a][b][prv][rnd%2]=1;
           return dp[a][b][prv][rnd%2];
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
        rep(i,0,105)rep(j,0,105)rep(k,0,27)rep(rnd,0,2)dp[i][j][k][rnd]=-1;
        ll n,m;
        cin>>n>>m;
        adj=vector<vector<pll>>(n+1);
        ans=vector<ll>(n+1);
        vis=vector<ll>(n+1,0);
        rep(i,0,m)
        {
            ll u,v,w;
            char ch;
            cin>>u>>v>>ch;
            w=(ll)(ch);
            w-=97;
            adj[u].pb({v,w});
        }
        
        

        rep(i,1,n+1)
        {
            rep(j,1,n+1)
            {
                dfs(i,j,0,0);
                if(dp[i][j][0][0]==0)
                cout<<"A";
                else
                cout<<"B";
            }
            cout<<endl;
        }
    }

}