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
V a;
ll n,k;
bool fnd(ll md)
{
    // err1(md)<<endl;
    V tmp;
    ll cnt=0;
    ll i=0;
    while(i<n)
    {
        if(cnt%2==0)
        {
            if(a[i]<=md){tmp.pb(i);i++;cnt++;}
            else i++;
        }
        else
        {
            tmp.pb(i);i++;cnt++;
        }
    }
    // if(md==2)err1(tmp.size())<<endl;
    if(tmp.size()>=k)return true;
    tmp.clear();
    if(k==1)
    return false;
    cnt=0;
    i=0;
    while(i<n)
    {
        if(cnt%2)
        {
            if(a[i]<=md){tmp.pb(i);i++;cnt++;}
            else i++;
        }
        else 
        {
            tmp.pb(i);i++;cnt++;
        }
    }
    // if(md==2)err1(tmp.size())<<endl;
    if(tmp.size()>=k)
    return true;
    return false;
}

int main()
{
    fast;
    ll T=1;
//     cin>>T;
    while(T--)
    {
        // ll n;
        cin>>n>>k;
        rep(i,0,n)
        {ll t; cin>>t;a.pb(t);}
        ll st=1;ll en=1e9;
        while(st<=en)
        {
            ll md=(st+en)/2;
            if(fnd(md))
            {
                en=md-1;
            }
            else 
            {
                st=md+1;
            }
        }
        cout<<st;
    }

}