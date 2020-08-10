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

ll n;
ll ans2=1;
string s;
V a(26);
map<ll,ll>mp,mp2;

ll calc1(string s, ll tmp)
{
    // errA(s);
    if(mp.find(tmp)!=mp.end())return mp[tmp];
    if(s=="")return 1ll;
    if(s.length()==1)return 1ll;
    ll lmt=a[s[0]-'a'],cur=0,ans=0;
    ll sz=s.length();
    // err1(lmt)<<endl;
    while(cur<min(lmt,sz))
    {
        if(a[s[cur]-'a']<cur+1)
        break;
        // err1(cur+1)<<endl;
        ans2=max(ans2,cur+1);
        ans=(ans+calc1(s.substr(cur+1),tmp+cur+1))%M;
        cur++;
        lmt=min(lmt,a[s[cur-1]-'a']);
    }
    mp[tmp]=ans;
    // err2(tmp,ans)<<endl;
    return ans;
}

ll calc2(string s , ll tmp)
{
    // err1(tmp)<<endl;
    if(mp2.find(tmp)!=mp2.end())return mp2[tmp];
    if(s=="")return 0ll;
    if(s.length()==1)return 1ll;
    ll lmt1=a[s[0]-'a'];
    ll lmt=1;
    ll ans=1;
    while(lmt<s.length() && lmt<lmt1)
    {
        if(a[s[lmt]-'a']<lmt+1)
        break;
        else 
        lmt++;
        lmt1=min(lmt1,a[s[lmt-1]-'a']);
    }
    // err1(lmt)<<endl;
    ans+=calc2(s.substr(lmt),tmp+lmt+1);
    mp2[tmp]=ans;
    return ans;
}

int main()
{
    fast;
    ll T=1;
//     cin>>T;
    while(T--)
    {
        cin>>n;
        cin>>s;
        rep(i,0,26)cin>>a[i];
        ll ans1=calc1(s,0);
        

        ll ans3=calc2(s,0);
        cout<<ans1<<endl<<ans2<<endl<<ans3<<endl;
    }

}