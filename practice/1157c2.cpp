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
        deque<ll> dq;
        rep(i,0,n)
        {
            ll t;
            cin>>t;
            dq.push_back(t);
        }
        vector<char>ans;
        V tmp2;
        while(!dq.empty() && dq.front()!=dq.back())
        {
            if(ans.size()==0){
            if(dq.front()<dq.back())
            {
                ans.pb('L');
                tmp2.pb(dq.front());
                dq.pop_front();
            }
            else 
            {
                ans.pb('R');
                tmp2.pb(dq.back());
                dq.pop_back();
            }}
            else 
            {
                if(dq.front()<dq.back())
                {
                    if(tmp2.back()<dq.front())
                    {
                        ans.pb('L');
                        tmp2.pb(dq.front());
                        dq.pop_front();
                    }
                    else if(tmp2.back()<dq.back())
                    {
                        ans.pb('R');
                        tmp2.pb(dq.back());
                        dq.pop_back(); 
                    }
                    else 
                    break;
                }
                if(dq.back()<dq.front())
                {
                    if(tmp2.back()<dq.back())
                    {
                        ans.pb('R');
                        tmp2.pb(dq.back());
                        dq.pop_back();
                    }
                    else if(tmp2.back()<dq.front())
                    {
                        ans.pb('L');
                        tmp2.pb(dq.front());
                        dq.pop_front(); 
                    }
                    else 
                    break;
                }
            }
        }
        V tmp;
        while(!dq.empty())
        {
            tmp.pb(dq.front());dq.pop_front();
        }
        ll sz1=1,sz2=1;
        ll i=1;
        n=tmp.size();
        while(i<n && tmp[i]>tmp[i-1])
        {
            sz1++;
            i++;
        }
        i=n-1;
        while(i>=1 && tmp[i]<tmp[i-1])
        {
            sz2++;
            i--;
        }
        if(tmp.size()!=0 && tmp[0]==tmp.back())
        {
        if(tmp2.size()==0 && sz1>=sz2)
        {
            rep(i,0,sz1)
            ans.pb('L');
        }
        else if(tmp2.size()==0 && sz2>=sz1)
        {
            rep(i,0,sz2)
            ans.pb('R');
        }
        else if(tmp2.back()<tmp[0] && tmp2.back()<tmp.back())
        {
            if(sz1>=sz2)
            rep(i,0,sz1)
            ans.pb('L');
            else 
            rep(i,0,sz2)
            ans.pb('R');
        }
        else if(tmp2.back()<tmp.back())
        {
            rep(i,0,sz2)
            ans.pb('R');
        }
        else if(tmp2.back()<tmp[0])
        {
            rep(i,0,sz1)
            ans.pb('L');
        }
        }
        cout<<ans.size()<<endl;
        rep(i,0,ans.size())cout<<ans[i];
        cout<<endl;
    }

}