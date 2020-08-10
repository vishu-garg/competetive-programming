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

vector<ll>key;
vector<ll>lft,rght;

void dfs(ll s , V&ans1 , V&ans2, V&ans3)
{
    // cout<<s<<" "<<lft[s]<<" "<<rght[s]<<endl;
    ans2.pb(s);
    if(lft[s]!=-1)
    {
        dfs(lft[s],ans1,ans2,ans3);
    }
    ans1.pb(s);
    if(rght[s]!=-1)
    {
        dfs(rght[s],ans1,ans2,ans3);
    }
    ans3.pb(s);
}

int main()
{
    // fast;
    ll T=1;
//     cin>>T;
    while(T--)
    {
        ll n;
        cin>>n;
        lft=rght=key=vector<ll>(n);
        rep(i,1,n+1)
        {
            ll k,l,r;
            cin>>k>>l>>r;
            key[i-1]=k;
            lft[i-1]=l;
            rght[i-1]=r;
        }
        // err()
        vector<ll>ans1,ans2,ans3;


        dfs(0,ans1,ans2,ans3);

        // err()

        for(auto it:ans1)
        cout<<key[it]<<" ";
        cout<<endl;

        for(auto it:ans2)
        cout<<key[it]<<" ";
        cout<<endl;

        for(auto it:ans3)
        cout<<key[it]<<" ";
        cout<<endl;
    }

}