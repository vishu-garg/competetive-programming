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
        ll n,m,x,y;
        cin>>n>>m>>x>>y;
        ll sum[m+1][2];
        sum[0][1]=sum[0][0]=0;
        char mat[n][m];

        rep(i,0,n)
        {
            string s;
            cin>>s;
            rep(j,0,m)
            {
                mat[i][j]=s[j];
            }
        }

        rep(i,1,m+1)
        {
            ll cnt_0=0,cnt_1=0;
            rep(j,0,n)
            {
                if(mat[j][i-1]=='.')cnt_0++;
                else cnt_1++;
            }
            sum[i][0]=cnt_0;
            sum[i][1]=cnt_1;
        }

        rep(i,2,m+1)
        {
            sum[i][0]+=sum[i-1][0];
            sum[i][1]+=sum[i-1][1];
        }

        ll dp[m+1][2];

        dp[0][0]=dp[0][1]=0;


        for(ll i=1;i<=m;i++)
        {
            dp[i][0]=dp[i][1]=1e18;
            for(ll a=x;a<=y;a++)
            {
                if(i-a>=0)
                {
                    dp[i][0]=min(dp[i][0],dp[i-a][1]+sum[i][0]-sum[i-a][0]);
                    dp[i][1]=min(dp[i][1],dp[i-a][0]+sum[i][1]-sum[i-a][1]);
                }
            }
        }

        cout<<min(dp[m][0],dp[m][1])<<endl;
        


    }

}