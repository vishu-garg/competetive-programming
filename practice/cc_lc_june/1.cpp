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
ll freq[1000005]{0};
int main()
{
    fast;
    ll T=1;
    cin>>T;
    while(T--)
    {
        ll n,x;
        cin>>n>>x;
        V a(n+1,0);
        rep(i,1,n+1)
        cin>>a[i];

        rep(i,2,n+1)
        a[i]+=a[i-1];

        V fac;

        fac.pb(1);

        rep(i,2,sqrt(x)+1)
        {
            if(x%i==0)
            {
                fac.pb(i);
                fac.pb(x/i);
            }
        }
        fac.pb(x);

        sort(all(fac));
        ll ans=0;

        for(auto t :fac)
        {
            if(t>n)continue;
            ll x2=x/t;
            rep(i,t,n+1)
            {
                ll num=a[i]-a[i-t];
                if(num<=x2)
                freq[num]++;
            }
            rep(i,t,n+1)
            {
                ll num=a[i]-a[i-t];
                if(num<=x2){
                ll tot=(freq[x2-num]);
                ans+=tot;}
            }
            rep(i,t,n+1)
            {
                ll num=a[i]-a[i-t];
                if(num<=x2)
                freq[num]=0;
            }

        }

        cout<<ans<<endl;


    }

}