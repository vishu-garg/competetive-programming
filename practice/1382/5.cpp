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

vector<ll>ind,mx,ind3;
ll n;

void func(vector<ll>&v,ll ind2)
{

    if(ind2<0)
    return;

    ll num=mx[ind2];

    ll nxt=ind3[num-1];

    ll tot=(ind2-nxt+1);

    ind.pb(tot);

    ind2=nxt-1;

    func(v,ind2);

    return;


}

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
        cin>>n;
        V v(2*n);
        ind3=V(2*n);
        ind.clear();mx.clear();
        rep(i,0,2*n)cin>>v[i];
        mx.pb(v[0]);
        for(ll i=1;i<2*n;i++)
        {
            mx.pb(max(v[i],mx.back()));
        }

        rep(i,0,2*n)
        {
            ind3[v[i]-1]=i;
        }

        ll lst=2*n;
    
        func(v,lst-1);

        // errA(ind);

        int num=ind.size();

        ll dp[num+1][2*n+1];



        rep(i,0,2*n+1)
        rep(j,0,num+1)
        dp[j][i]=0;


        dp[0][0]=1;

        for(ll i=1;i<num+1;i++)
        {

            for(ll j=0;j<=2*n;j++)
            {
                if(dp[i-1][j]==1)
                {

                    // cout<<i-1<<" "<<j<<"<=="<<endl;

                    dp[i][j]=1;
                    dp[i][j+ind[i-1]]=1;

                    // cout<<i<<" "<<j<<endl;
                    // cout<<i<<" "<<j+ind[i-1]<<endl;
                }

            }

        }

        if(dp[num][n]==1)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
        

    }
}