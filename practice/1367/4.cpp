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
        map<char,ll>mp;
        string s;
        cin>>s;
        for(auto it:s)mp[it]++;
        ll n;
        cin>>n;
        V a(n);
        rep(i,0,n)
        cin>>a[i];
        set<pll>s1;
        rep(i,0,n)
        {
            s1.insert(make_pair(a[i],i));
        }

        vector<ll> ans[n];
        ll cnt1=0;
        while(s1.size()>0)
        {
            // cout<<cnt1<<endl;
            V tmp;
            // cout<<(*s1.begin()).first<<"###"<<endl;
            while(s1.size()>0 && (*s1.begin()).first==0)
            {
                // cout<<(*s1.begin()).second<<"<---"<<cnt1<<endl;
                tmp.pb((*s1.begin()).second);
                ans[cnt1].pb((*s1.begin()).second);
                s1.erase(s1.begin());
            }
            set<pll>s2;
            cnt1++;
            for(auto it:s1)
            {
                ll tmp1=0;
                for(auto it2:tmp)tmp1+=(abs((it.second)-it2));
                // cout<<tmp1<<" "<<it.second<<"##"<<endl;
                tmp1=it.first-tmp1;
                // cout<<tmp1<<" "<<it.second<<"##"<<endl;
                s2.insert(make_pair(tmp1,it.second));
            }
            s1=s2;
            // err1(s1.size())<<endl;
        }

        vector<char> v(n);
        // err();
        char ch='z';

        rep(i,0,cnt1)
        {
            // cout<<ans[i].size()<<endl;
            while(mp[ch]<ans[i].size())ch--;

            if(mp[ch]>=ans[i].size())
            {
                for(ll j=0;j<ans[i].size();j++)
                {
                    v[ans[i][j]]=ch;
                }
            }
            ch--;
        }

        for(auto it:v)
        cout<<it;
        cout<<endl;

    }  

}