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
const ll N=100005;
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

// struct segtree{
//     ll x,y;
//     ll tree[4*N];

//     void build_tree(vector<ll>&v , ll ind,ll l, ll r)
//     {
//         if(l==r)
//         {
//             tree[ind]=v[l];
//             return;
//         }
//         ll mid=(l+r)/2;
//         build_tree(v,2*ind,l,mid);
//         build_tree(v,2*ind+1,mid+1,r);
//         tree[ind]=max(tree[2*ind],tree[2*ind+1]);
//     }

//     ll query(ll ind, ll l, ll r)
//     {
//         // cout<<l<<" "<<r<<" "<<endl;
//         if(x>r || y<l)return -LLONG_MAX;
//         if(l>=x && r<=y)return tree[ind];
//         ll mid=(l+r)/2;
//         return max(query(2*ind,l,mid),query(2*ind+1,mid+1,r));
//     }
// }obj;

bool check_1(vector<ll>&v1, vector<ll>&v2)
{
    set<ll>d;
    rep(i,0,v1.size())
    {
        d.insert(v1[i]-v2[i]);
    }
    if(d.size()==1)
    {
        return true;
    }
    d.clear();
    rep(i,0,v1.size())
    {
        if(v1[i]==0 || v2[i]%v1[i]!=0)
        {
            return false;
        }
        d.insert(v2[i]/v1[i]);
    }
    if(d.size()==1)
    {
        return true;
    }
    return false;
}

bool check_2(V & v1, V& v2)
{
    set<ll>d;
    rep(i,0,v1.size())
    {
        d.insert(v1[i]-v2[i]);
    }
    if(d.size()==2)
    {
        return true;
    }
    rep(i,0,v1.size())
    {
        ll flg=0;
        rep(j,0,v1.size())
        {
            if(j!=i)
            {
                if(v1[j]==0){flg=1;break;}
                if(v2[j]%v1[j]!=0)flg=1;
            }
        }
        if(flg==0)
        {
            set<ll> d2;
            rep(j,0,v1.size())
            {
                if(j!=i)
                {
                    d2.insert(v2[j]/v1[j]);
                }
            }
            if(d2.size()==1)
            {
                ll val=*d2.begin();
                if(v2[i]%val==0)
                {
                    
                }
            }
        }
    }   
}

int main()
{
    fast;
    ll T=1;
    cin>>T;
    while(T--)
    {
        ll p,q,r;
        ll a,b,c;
        cin>>p>>q>>r;
        cin>>a>>b>>c;
        vector<ll>v1,v2;
        if(a!=p)
        {
            v1.pb(p);
            v2.pb(a);
        }
        if(b!=q)
        {
            v1.pb(q);
            v2.pb(b);
        }
        if(c!=r)
        {
            v1.pb(r);
            v2.pb(c);
        }
        if(v1.size()==0)
        {
            cout<<"0"<<endl;
            continue;
        }
        bool is_1=check_1(v1,v2);
        if(is_1)
        {
            cout<<"1"<<endl;
            continue;
        }

        bool is_2=check_2(v1,v2);
        
    }

}