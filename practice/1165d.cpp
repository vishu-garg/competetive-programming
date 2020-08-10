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
    cin>>T;
    while(T--)
    {
        ll n;
        cin>>n;
        V a(n);
        rep(i,0,n)
        cin>>a[i];
        map<ll,ll>mp;
        rep(i,0,n)
        {
            ll num=2;
            ll tmp=a[i];
            while(num<=sqrt(tmp))
            {
                if(tmp%num==0)
                {
                    ll cnt=0;
                    while(tmp%num==0)
                    {cnt++;tmp/=num;}
                    if(mp[num]==0)
                    mp[num]=cnt;
                    else 
                    mp[num]=max(mp[num],cnt);
                }
                num++;
            }
            if(tmp>1)
            {
                if(mp[tmp]==0)mp[tmp]=1;
            }
        }

        ll num=1;
        for(auto it:mp)
        {
            num*=(it.second+1);
        }
        if(mp.size()>1)
        num-=1;

        num-=1;

        if(num!=a.size())
        {
            cout<<"-1"<<endl;
        }
        else 
        {
            // ll tmp=1;
            ll ans=1;
            for(auto it:mp)
            {
                ans*=(ll)(pow(it.first,it.second));
            }
            if(mp.size()==1)
            {
                auto it=*mp.begin();
                cout<<ans*it.first<<endl;
            }
            else if(find(all(a),ans)!=a.end())
            {
                cout<<"-1"<<endl;
            }
            else 
            {
                cout<<ans<<endl;
            }
        }

                
    }

}