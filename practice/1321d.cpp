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

int main()
{
    ll n,m;
    cin>>n>>m;
    vector<int> a[20010];
    int c[20010];
    rep(i,0,m)
    {
        int x,y;
        cin>>x>>y;
        a[y].pb(x)
    }
    cin>>t;v=t-1;
    rep(i,1,t+1)cin>>c[i];
    rep(i,1,n+1)d[i]=1e9;
    d[c[t]]=0;
    queue<int> q;
    q.push(c[t]);
    while(!q.empty())
    {
        int now=q.front();q.pop();
        for(auto i: a[now])
        {
            if(d[now]+1<d[i]){q.push(i);d[i]=d[now]+1};
        }
    }
    ll mi=0,ma=0;
    rep(i,1,t+1)
    {
        if(d[i+1]>d[i]-1){ma++,mi++;}
        else if(d[i+1]==d[i]-1){ma++;}
    }
    cout<<mi<<" "<<ma;
}