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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    ll T=1;
//     cin>>T;
    while(T--)
    {
        ll n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        ll d=n-m;
        ll dp[d+5][d+5];
        rep(i,0,d+5)
        rep(j,0,d+5)
        dp[i][j]=0;
        dp[0][0]=1;
        dp[1][1]=1;

        rep(i,1,d+1)
        {
            rep(j,0,d+1)
            {
                if(j>i)break;
                dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j])%M;
                // err2(i+1,j+1);
                if(j>0)
                {
                    dp[i+1][j-1]=(dp[i+1][j-1]+dp[i][j])%M;
                    // err2(i+1,j-1);
                }
            }
        }

        ll d1=0,b=m+1;

        for(auto it:s)
        {
            if(it=='(')d1++;
            else 
            d1--;
            b=min(b,d1);
        }

        ll ans=0;

        rep(i,0,d+1)
        {
            rep(j,0,d+1)
            {
                if(j>i)break;
                ll diff=j;
                if(diff+b<0)continue;
                ll tmp=dp[i][j];
                ll req_l=(n-m-i);
                ll req_diff_mod=(j+d1);
                if(req_l>=0 && req_diff_mod<d+5)
                {
                    // err3(i,j,tmp);
                    // err3(req_l,req_diff_mod,dp[0req_l][req_diff_mod]);
                    tmp=(tmp*(dp[req_l][req_diff_mod]))%M;
                    ans=(ans+tmp)%M;
                }
            }
        }

        cout<<ans<<endl;


    }

}