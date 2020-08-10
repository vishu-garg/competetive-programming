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
ll st=-1,en=-1,cnt=0;
// bool vis[n+1]{false};
// vis[1]=true;
ll c1[100005],c2[100005],c3[100005];
ll cst=0;
        
        
vector<vector<ll> >adj(100005);
ll ans=LLONG_MAX;
void dfs(ll src , ll prv)
{
    if(adj[src].size()==1)
    {
        if(cnt==0)
        {st=src;cnt++;}
        else 
        en=src;
        // return;
    }
    for(auto it : adj[src])
    {
        if(it!=prv)
        {
            dfs(it,src);
        }
    }
}

vector<ll> arr(100005),arr2(100005);

void dfs2(ll st2, ll prv, ll &cst ,ll sl,ll l)
{
    if(sl!=1 && l!=1)
    {cst+=c1[st2];arr[st2]=1;}
    else if(sl!=2 && l!=2)
    {cst+=c2[st2];arr[st2]=2;}
    else 
    {cst+=c3[st2];arr[st2]=3;}
    // cout<<st2<<" "<<cst<<" ### "<<endl;
    for(auto it: adj[st2])
    {
        if(it!=prv)
        {
            if(sl!=1 && l!=1)
            dfs2(it,st2,cst,l,1);
            else if(sl!=2 && l!=2)
            dfs2(it,st2,cst,l,2);
            else 
            dfs2(it,st2,cst,l,3);
        }
    }
}


int main()
{
    ll t=1;
//    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        rep(i,1,n+1)
        cin>>c1[i];
        rep(i,1,n+1)
        cin>>c2[i];
        rep(i,1,n+1)
        cin>>c3[i];
        adj=vector<vector<ll> >(n+1);
        rep(i,0,n-1)
        {
            ll u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        bool flag=false;
        rep(i,1,n+1)
        {
            if(adj[i].size()>2)
            {
                flag=true;
                break;
            }
        }
        if(flag)
        {
            cout<<"-1";
            return 0;
        }
        
        dfs(1,0);
        // cout<<st<<" "<<en<<"<---"<<endl;
        ll cst=0;
        dfs2(st,0,cst,2,3);
        // cout<<cst<<endl;
        // cout<<"----------------------------"<<endl;
        if(cst<ans)
        arr2=arr;
        ans=min(ans,cst);
        cst=0;
        dfs2(st,0,cst,2,2);
        // cout<<cst<<endl;
        // cout<<"----------------------------"<<endl;
        if(cst<ans)
        arr2=arr;
        ans=min(ans,cst);
        cst=0;
        dfs2(st,0,cst,1,3);
        // cout<<cst<<endl;
        // cout<<"----------------------------"<<endl;
        if(cst<ans)
        arr2=arr;
        ans=min(ans,cst);
        cst=0;
        dfs2(st,0,cst,1,1);
        // cout<<cst<<endl;
        // cout<<"----------------------------"<<endl;
        if(cst<ans)
        arr2=arr;
        ans=min(ans,cst);
        cst=0;
        dfs2(st,0,cst,1,2);
        // cout<<cst<<endl;
        // cout<<"----------------------------"<<endl;
        if(cst<ans)
        arr2=arr;
        ans=min(ans,cst);
        cst=0;
        dfs2(st,0,cst,2,1);
        // cout<<cst<<endl;
        // cout<<"----------------------------"<<endl;
        if(cst<ans)
        arr2=arr;
        ans=min(ans,cst);
        // cst=0;
        cout<<ans<<endl;
        rep(i,1,n+1)
        cout<<arr2[i]<<" ";
        // cout<<endl;
    }
}