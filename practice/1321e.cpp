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

ll t[800005];
ll lazy[800005];
vector<pll> w,a;
vector<pair<pll,ll> > mn;

void update(ll v , ll tl, ll tr, ll l , ll r, ll addend)
{
    if(l>r)
    return;
    if(l<=tl && tr<=r)
    {
        t[v]+=addend;
        lazy[v]+=addend;
        // cout<<v<<" "<<t[v]<<"<---"<<endl;
    }
    else 
    {
        t[v*2]+=lazy[v];
        t[v*2+1]+=lazy[v];
        lazy[v*2]+=lazy[v];
        lazy[v*2+1]+=lazy[v];
        lazy[v]=0;
        ll mid=(tl+tr)/2;
        update(v*2,tl,mid,l,min(r,mid),addend);
        update(v*2+1,mid+1,tr,max(l,mid+1),r,addend);
        t[v]=max(t[2*v],t[2*v+1]);
        // cout<<v<<" "<<t[v]<<"<---"<<endl;
    }
}

ll query(ll v, ll tl, ll tr, ll l, ll r)
{
    if(l>r)
    return -INF;
    if(l<=tl && tr<=r)
    return t[v];
    t[v*2]+=lazy[v];
    t[v*2+1]+=lazy[v];
    lazy[v*2]+=lazy[v];
    lazy[v*2+1]+=lazy[v];
    lazy[v]=0;
    ll mid=(tl+tr)/2;
    return max(query(v*2,tl,mid,l,min(r,mid)),query(v*2+1,mid+1,tr,max(l,mid+1),r));
}

ll find(ll val)
{
    ll l=0,r=a.size()-1;
    ll ans=a.size();
    while(l<=r)
    {
        ll mid=(l+r)/2;
        if(a[mid].first>val)
        {
            ans=min(ans,mid);
            r=mid-1;
        }
        else 
        l=mid+1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    ll n,m,p;
    cin>>n>>m>>p;

    rep(i,0,n)
    {
        ll x,y;
        cin>>x>>y;
        w.pb({x,y});
    }
    sort(all(w));
    rep(i,0,m)
    {
        ll x,y;
        cin>>x>>y;
        a.pb({x,y});
    }
    sort(a.begin(),a.end());
    
    rep(i,0,p)
    {
        ll x,y,z;
        cin>>x>>y>>z;
        mn.pb({{x,y},z});
    }
    sort(all(mn));
    for(ll i=0;i<m;i++)
    {
        // cout<<a[i].second<<" ### "<<endl;
        update(1,0,m-1,i,i,-a[i].second);
    }

    ll ptr=0,ans=0;
    int flag=1;
    rep(i,0,n)
    {
        ll cur=w[i].first;
        while(ptr<mn.size())
        {
            if(mn[ptr].first.first>=cur)
            break;

            ll x=find(mn[ptr].first.second);
            update(1,0,m-1,x,m-1,mn[ptr].second);
            ptr++;
        }
        ll val=query(1,0,m-1,0,m-1);
        if(flag)
        {
            flag=0;
            ans=val-w[i].second;
        }
        else
        ans=max(ans,val-w[i].second);
    }
    cout<<ans<<endl;
}