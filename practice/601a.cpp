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

vector<ll> v[1000],v2[1000];
ll ans_rail=0;
int main()
{
    ll n,m;
    cin>>n>>m;
    rep(i,0,m)
    {
        ll x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
        if(fabs(y-x)==n-1)
        ans_rail=1;
    }
    rep(i,1,n+1)
    {
        rep(j,1,n+1)
        {
            ll flag=1;
            rep(k,0,v[i].size())
            {
                if(j==v[i][k])
                flag=0,break;
            }
            if(flag)
            v2[i].pb(j);
        }
    }

    if(ans_rail)
    {
        ll distance[n+1]={-1};
        distance[1]=0;
        bool visited[n+1]={false};
        visited[1]=true;
        queue<ll> q;
        q.push(1);
        while(!q.empty())
        {
            ll tmp=q.front();
            q.pop();
            rep(i,0,v2[tmp].size())
            {
                if(!visited[v2[tmp][i]]){visited[v2[tmp][i]]=true;
                distance[v2[tmp][i]]=distance[tmp]+1;}
            }
        }
        cout<<distance[n];
    }
    else
    {
        
        ll distance[n+1]={-1};
        distance[1]=0;
        bool visited[n+1]={false};
        visited[1]=true;
        queue<ll> q;
        q.push(1);
        while(!q.empty())
        {
            ll tmp=q.front();
            q.pop();
            rep(i,0,v[tmp].size())
            {
                if(!visited[v[tmp][i]]){visited[v[tmp][i]]=true;
                distance[v[tmp][i]]=distance[tmp]+1;}
            }
        }
        cout<<distance[n];
    }
    
    
}