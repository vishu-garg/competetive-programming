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
        ll n;
        cin>>n;
        // ll v1[26]{0},v2[26]{0};
        string s1,s2;
        cin>>s1;
        cin>>s2;
        
        map<ll,vector<ll>>v1,v2;
        V cnt1,cnt2;
        rep(i,0,n)
        {
            if(s1[i]!='?')
            v1[s1[i]-'a'].pb(i+1);
            else 
            cnt1.pb(i+1);
            if(s2[i]!='?')
            v2[s2[i]-'a'].pb(i+1); 
            else 
            cnt2.pb(i+1);
        }

        ll k1[26]{0},k2[26]{0},c1=0,c2=0;

        // for(auto it:cnt1)
        // cout<<it<<" ";
        // cout<<endl;

        ll cnt=0;
        vector<pll>v;

        rep(i,0,26)
        {
            ll k=min(v1[i].size()-k1[i],v2[i].size()-k2[i]);
            cnt+=k;
            rep(j,0,k)
            {
                v.pb({v1[i][j+k1[i]],v2[i][j+k2[i]]});
            }
            k1[i]+=k;
            k2[i]+=k;
        }

        for(ll i=0;i<26 && c2<cnt2.size();i++)
        {
            ll k=min(cnt2.size()-c2,v1[i].size()-k1[i]);
            cnt+=k;
            rep(j,0,k)
            {
                v.pb({v1[i][j+k1[i]],cnt2[j+c2]});
            }
            c2+=k;
            k1[i]+=k;
        }


        for(ll i=0;i<26 && cnt1.size()>c1;i++)
        {
            ll k=min(cnt1.size()-c1,v2[i].size()-k2[i]);
            cnt+=k;
            rep(j,0,k)
            {
                v.pb({cnt1[j+c1],v2[i][j+k2[i]]});
            }
            c1+=k;
            k2[i]+=k;
        }

        ll k=min(cnt1.size()-c1,cnt2.size()-c2);
        cnt+=k;
        rep(j,0,k)
        {
            v.pb({cnt1[c1+j],cnt2[c2+j]});
        }

        cout<<cnt<<endl;
        for(auto it:v)
        cout<<it.first<<" "<<it.second<<endl;




        


    }

}