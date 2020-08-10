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
ll  crnt;
int main()
{
    fast;
    ll T=1;
//     cin>>T;
    while(T--)
    {
        ll n,m;
        cin>>n>>m;
        ll a[m][n];
        rep(i,0,m)
        rep(j,0,n)cin>>a[i][j];
        vector<pair<V,ll>>tmp;
        rep(i,0,m)
        {
            vector<ll>v1;
            rep(j,0,n)v1.pb(a[i][j]);
            tmp.pb({v1,i});
        }
        V ans;
        rep(i,0,m)
        ans.pb(i+1);
        rep(i,0,n-1)
        {
            crnt=i;
            V tmp2;
            ll sum1=0,sum2=0;
            rep(j,0,m)
            sum1+=a[j][i],sum2+=a[j][n-1];

            sort(all(tmp),[&](pair<V,ll>p1,pair<V,ll>p2){
                ll d1=p1.first[n-1]-p1.first[crnt];
                ll d2=p2.first[n-1]-p2.first[crnt];
                return d1>d2;
            });

            ll d=sum2-sum1;
            ll crnt=0;
            // err1(d)<<endl;
            while(d>0 && crnt<m)
            {
                // err1(crnt);
                tmp2.pb(tmp[crnt].second+1);
                d-=(tmp[crnt].first[n-1]-tmp[crnt].first[i]);
                crnt++;
            }

            if(ans.size()>tmp2.size())
            ans=tmp2;
        }
        cout<<ans.size()<<endl;
        errA(ans);
    }

}