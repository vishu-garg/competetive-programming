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

int main()
{
    fast;
    ll T=1;
//     cin>>T;
    while(T--)
    {
        ll n,q;
        cin>>n>>q;
        V a(n);
        rep(i,0,n)cin>>a[i];
        V cnt(n+1,0);
        Vpll tmp2;
        rep(i,0,q)
        {
            ll l,r;
            cin>>l>>r;
        tmp2.pb({l-1,r-1});
            l--;
            cnt[l]+=1;
            cnt[r]-=1;
        }
        rep(i,1,n)
        {
            cnt[i]+=cnt[i-1];
        }

        // errA(cnt);

        Vpll v;
        rep(i,0,n)
        v.pb({cnt[i],i});

        sort(all(v));

        reverse(all(v));

        // for(auto it:v)cout<<it.first<<" "<<it.second<<endl;

        sort(all(a));reverse(all(a));

        V mn(n);

        rep(i,0,n)
        {

            mn[v[i].second]=a[i];
        }



        rep(i,1,n)
        {
            mn[i]+=mn[i-1];
        }

        // errA(mn);
        ll sum=0;
        for(auto it:tmp2)
        {
            ll l=it.first;
            ll r=it.second;
            ll ans=mn[r];
            if(l>0)
            ans-=mn[l-1];
            sum+=ans;
        }

        cout<<sum<<endl;
        

    }

}