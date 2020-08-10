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
//     cin>>T;
    while(T--)
    {
        ll n,m;
        cin>>n>>m;
        ll mat[n][m];
        rep(i,0,n)
        {string s;cin>>s;rep(j,0,m)
        mat[i][j]=s[j]-'0';}

        if(n==1 || m==1)
        {
            cout<<"0"<<endl;
            return 0;
        }

        if(n>3 && m>3)
        {
            cout<<"-1"<<endl;
            return 0;
        }

        bool ok[8][8],ok2[4][4];
        for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
        ok[i][j]=false;

        rep(i,0,4)
        rep(j,0,4)
        ok2[i][j]=false;

        ok2[0][1]=true;ok2[0][2]=true;
        ok2[1][0]=true;ok2[1][3]=true;
        ok2[2][0]=true;ok2[2][3]=true;
        ok2[3][1]=true;ok2[3][2]=true;

        ok[0][2]=true;ok[0][5]=true;

        ok[1][3]=true;ok[1][4]=true;

        ok[2][0]=true;ok[2][7]=true;

        ok[3][1]=true;ok[3][6]=true;

        ok[4][1]=true;ok[4][6]=true;

        ok[5][0]=true;ok[5][7]=true;

        ok[6][3]=true;ok[6][4]=true;

        ok[7][2]=true;ok[7][5]=true;

        VV tmp;
        if(n>3)
        {
            tmp=VV(m,V(n));
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    tmp[i][j]=mat[j][i];
                }
            }
        }
        else 
        {
            
            tmp=VV(n,V(m));
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    tmp[i][j]=mat[i][j];
                }
            }
        }
        



        ll row=tmp.size();
        ll num2=(ll)pow(2,row);
        ll col=tmp[0].size();
        ll dp[col+1][num2];

        rep(i,0,num2)
        dp[0][i]=0;

        for(int i=1;i<=col;i++)
        {
            ll col_val=0;
            for(int j=0;j<row;j++)
            {
                col_val+=((ll)pow(2,(row-j-1)))*(tmp[j][i-1]);
            }
            for(int cmask=0;cmask<num2;cmask++)
            {
                dp[i][cmask]=LLONG_MAX;
                for(int pmask=0;pmask<num2;pmask++)
                {
                    if(num2==8 && ok[pmask][cmask])
                    {
                        // cout<<col_val<<" "<<cmask<<" "<<__builtin_popcountll(cmask^col_val)<<endl;
                        dp[i][cmask]=min(dp[i][cmask],dp[i-1][pmask]+(ll)(__builtin_popcountll(cmask^col_val)));
                        // err4(pmask,cmask,dp[i-1][pmask],dp[i][cmask]);
                    }
                    else if(num2==4 && ok2[pmask][cmask])
                    {
                        dp[i][cmask]=min(dp[i][cmask],dp[i-1][pmask]+(ll)(__builtin_popcountll(cmask^col_val)));
                        // err4(pmask,cmask,dp[i-1][pmask],dp[i][cmask]);   
                    }
                }
            }
        }
        ll ans=LLONG_MAX;
        for(int mask=0;mask<num2;mask++)
        {
            ans=min(ans,dp[col][mask]);
        }


        cout<<ans<<endl;

    }

}