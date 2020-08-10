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

ll count_bits(ll n)
{
    ll tmp=0;
    while(n>0)
    {
        if(n%2)tmp++;
        n/=2;
    }
    return tmp;
}

int main()
{
    fast;
    ll T=1;
//     cin>>T;
    while(T--)
    {
        ll n,m,k;
        cin>>n>>m>>k;
        vector<ll>a(n+1);
        rep(i,0,n)
        cin>>a[i];
        ll ext[21][21]{0};
        rep(i,0,k)
        {
            ll x,y,c;
            cin>>x>>y>>c;
            ext[--x][--y]=c;
        }

        vector<ll>b(n+1);

        b[0]=1;
        for(ll i=1;i<=n;i++)b[i]=(2*b[i-1]);

        ll dp[b[n]][n];

        rep(i,0,b[n])
        rep(j,0,n)dp[i][j]=0;

        rep(i,0,n)
        {
            dp[b[i]][i]=a[i];
        }

        for(ll i=0;i<b[n];i++)
        {
            for(ll j=0;j<n;j++)
            {
                if((i&b[j])!=0)
                {
                    for(ll k=0;k<n;k++)
                    {
                        if(k==j)continue;
                        // cout<<i<<" "<<j<<" "<<k<<endl;
                        if((i&b[k])==0)
                        {
                            // cout<<(i|b[k])<<" <<<<<"<<endl;
                            // cout<<dp[i|b[k]][k]<<" "<<dp[i][j]+ext[j][k]+a[k]<<"###"<<endl;
                            dp[i|b[k]][k]=max(dp[i|b[k]][k],dp[i][j]+ext[j][k]+a[k]);
                            // cout<<dp[i|b[k]][k]<<"<---"<<endl;
                        }
                    }
                }
            }
        }

        ll ans=0;

        for(ll i=0;i<b[n];i++)
        {
            ll cnt=count_bits(i);
            if(cnt==m)
            {
                for(ll j=0;j<n;j++)
                ans=max(ans,dp[i][j]);
            }
        }

        cout<<ans<<endl;

    }

}


// dp[state][last_val]     