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
ll pow1(ll a,ll b){
    ll res=1;
    while(b>0){
        if(b&1){
        	res=(res*a)%M;
		}
        a=(a*a)%M;
        b>>=1;
    }
    return res%M;
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

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    
    ll T=1;
    cin>>T;
    while(T--)
    {
        ll n,m;
        cin>>n>>m;
        Vpll a(m);
        rep(i,0,m)
        cin>>a[i].first>>a[i].second;
        sort(all(a));
        reverse(all(a));
        V v(m);
        v[0]=a[0].first;
        rep(i,1,m)
        {
            v[i]=a[i].first+v[i-1];
        }
        ll ans=0;
        if(m>=n)
        ans=v[n-1];
        // rep(i,0,m)
        // cout<<a[i].first<<" "<<a[i].second<<endl;
        // err();
        rep(i,0,m)
        {
            ll k=0;
            ll lo=0,hi=m-1;
            while(lo<=hi)
            {
                ll md=(lo+hi)/2;
                if(a[md].first>a[i].second)
                {
                    k=md+1;
                    lo=md+1;
                }
                else 
                hi=md-1;
            }
            ll tmp_ans;
            // err2(k,i);
            k=min(n,k);
            if(k!=0)
            {if(a[i].first>a[i].second)
            tmp_ans=(v[k-1]+((n-k)*a[i].second));
            else
            tmp_ans=(v[k-1]+((n-k-1)*a[i].second)+a[i].first);}
            else 
            {
            tmp_ans=(n-1)*(a[i].second)+a[i].first;}
            ans=max(tmp_ans,ans);
        }
        cout<<ans<<endl;
    }

}