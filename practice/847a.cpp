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
    // fast;
    ll T=1;
//     cin>>T;
    while(T--)
    {
        ll n;
        cin>>n;
        vector<pll>a(n+1);
        V lst;
        rep(i,1,n+1)
        {
            ll l , r;
            cin>>l>>r;
            a[i]=make_pair(l,r);

            if(l==0)
            lst.pb(i);

        }

        vector<V>l1;
        rep(i,0,lst.size())
        {
            vector<ll>tmp;
            ll num=lst[i];
            while(num!=0)
            {
                tmp.pb(num);
                num=a[num].second;
            }
            l1.pb(tmp);
        }

        V ans;

        if(l1.size()==1)
        {
            rep(i,1,n+1)
            {
                cout<<a[i].first<<" "<<a[i].second<<endl;
            }
            continue;
        }

        rep(i,0,l1.size())
        {
            for(auto it:l1[i])
            ans.pb(it);
        }

        a=vector<pll>(n+1);
        
        rep(i,0,ans.size())
        {
            if(i==0)
            {
                a[ans[i]].first=0;
                a[ans[i]].second=ans[i+1];
            }
            else if(i==ans.size()-1)
            {
                a[ans[i]].second=0;
                a[ans[i]].first=ans[i-1];
            }
            else 
            {
                a[ans[i]].first=ans[i-1];
                a[ans[i]].second=ans[i+1];
            }
        }

        rep(i,1,n+1)
        {
            cout<<a[i].first<<" "<<a[i].second<<endl;
        }

    }

}