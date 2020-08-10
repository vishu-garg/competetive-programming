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

struct segtree{
    ll x,y;
    ll tree[4*N];

    void build_tree(vector<ll>&v , ll ind,ll l, ll r)
    {
        if(l==r)
        {
            tree[ind]=v[l];
            return;
        }
        ll mid=(l+r)/2;
        build_tree(v,2*ind,l,mid);
        build_tree(v,2*ind+1,mid+1,r);
        tree[ind]=max(tree[2*ind],tree[2*ind+1]);
    }

    ll query(ll ind, ll l, ll r)
    {
        // cout<<l<<" "<<r<<" "<<endl;
        if(x>r || y<l)return -LLONG_MAX;
        if(l>=x && r<=y)return tree[ind];
        ll mid=(l+r)/2;
        return max(query(2*ind,l,mid),query(2*ind+1,mid+1,r));
    }
}obj;

int main()
{
    // fast;
    ll T=1;
//     cin>>T;
    while(T--)
    {
        ll n;
        cin>>n;
        // err()
        vector<ll>a(n);
        rep(i,0,n)
        cin>>a[i];
        ll dp[n+1][100];
        rep(i,0,n+1)
        rep(j,0,100)
        dp[i][j]=LLONG_MAX;
        ll shift=50;
        rep(i,0,n)
        dp[i][a[i]+shift]=i;

        repb(i,n-2,0)
        {
            rep(j,0,100)
            {
                dp[i][j]=min(dp[i][j],dp[i+1][j]); // storing that first index where j occured starting from index i;
            }
        }

        vector<ll>pref(n);
        pref[0]=a[0];
        rep(i,1,n)
        pref[i]=a[i]+pref[i-1];

        obj.build_tree(pref,1,0,n-1);

        // cout<<<<endl;

        ll ans=0;

        rep(i,0,n)
        {
            ll ind=i,val=a[i]+shift;
            // cout<<i<<endl;
            vector<pll>vec;
            rep(j,0,100)
            {
                if(dp[i][j]!=LLONG_MAX && j!=val)
                vec.pb(make_pair(dp[i][j],j));
            }
            vec.pb(make_pair(n,1000));
            sort(all(vec));
            for(auto it:vec)
            {
                if(it.sd>val)
                {
                    // cout<<it.sd-shift<<" "<<it.ft<<" "<<i<<"<---"<<endl;
                    obj.x=ind;
                    obj.y=it.ft-1;
                    // cout<<obj.x<<" "<<obj.y<<" "<<endl;
                    ll sum=obj.query(1,0,n-1);
                    // cout<<it.ft-1<<" "<<it.sd-shift<<" "<<sum<<endl;
                    if(i!=0)
                    sum-=pref[i-1];
                    sum-=(val-shift);
                    ans=max(ans,sum);
                    val=it.sd;
                    ind=it.ft;
                }
            }
        }
        cout<<ans<<endl;
    }

}