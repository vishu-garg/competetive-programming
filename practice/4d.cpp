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
        ll n,w,h;
        cin>>n>>w>>h;
        vector<pair<ll,pair<ll,ll>>>v(n);
        rep(i,0,n)
        {
            cin>>v[i].first>>v[i].second.first;
            v[i].second.second=i;
        }

        sort(all(v));

        ll ind=-1;
        for(ll i=0;i<n;i++)
        {
            ll w1=v[i].first,h1=v[i].second.first;
            if(w1>w && h1>h)
            {
                ind=i;
                break;
            }
        }

        // cout<<v[ind].second.second<<endl;

        if(ind==-1)
        {
            cout<<"0"<<endl;
            return 0;
        }

        // err/()
        vector<pair<ll,pair<ll,ll> > >v2;
        for(ll i=ind;i<n;i++)
        {
            if(v[i].second.first>h)
            v2.pb(v[i]);
        }

        if(v2.size()==0)
        {
            cout<<"0"<<endl;
            return 0;
        }

        

        ll prv[v2.size()];
        rep(i,0,v2.size())prv[i]=i;
        ll len[v2.size()];
        rep(i,0,v2.size())len[i]=1;

        for(ll i=0;i<v2.size();i++)
        {
            // cout<<v2[i].first<<" "<<v2[i].second.first<<endl;
            ll h1=v2[i].second.first;
            ll w1=v2[i].first;
            for(ll j=0;j<i;j++)
            {
                ll h2=v2[j].second.first;
                ll w2=v2[j].first;
                if(w2<w1 && h2<h1)
                {
                    if(len[i]<len[j]+1)
                    {
                        len[i]=len[j]+1;
                        prv[i]=j;
                    }
                }
            }
            // cout<<i<<" "<<prv[i]<<"<---"<<endl;
        }
        // err()
        ll mx=1;
        ll st=0;
        rep(i,0,v2.size())
        {
            // cout<<v[i].second.second<<" "<<len[i]<<" "<<endl;
            if(len[i]>mx)
            {
                mx=len[i];
                st=i;
            }
        }
        cout<<mx<<endl;

        vector<ll>ans;
        ll num=st;
        // cout<<v2.size()<<endl;
        // cout<<st<<endl;
        // rep(i,0,v2.size())
        // {
        //     cout<<v2[i].first<<" "<<v2[i].second.first<<" "<<v2[i].second.second<<endl;
        // }
        while(ans.size()!=mx)
        {
            // cout<<v2[num].second.second<<endl;
            ans.pb(v2[num].second.second+1);
            if(ans.size()==mx)
            break;
            num=prv[num];
        }

        reverse(all(ans));

        for(auto it:ans)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        return 0;


    }

}