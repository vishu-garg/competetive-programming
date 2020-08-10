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
        ll n,k;
        cin>>n>>k;
        V a(n);
        rep(i,0,n)cin>>a[i];

        map<vector<pll>,ll>mp;

        rep(i,0,n)
        {
            vector<pll>mp2;
            // if(a[i]=='1')
            // {mp[mp2]++;continue;}
            ll st=2;
            ll tmp=a[i];
            while(st<=sqrt(tmp))
            {
                if(tmp%st!=0){st++;continue;}
                else
                {
                    ll cnt=0;
                    while(tmp%st==0)
                    {
                        cnt++;
                        tmp/=st;
                    }
                    // err();
                    ll t1=(cnt%k);
                    if(t1!=0)mp2.pb({st,t1});
                    // cout<<st<<" "<<t1<<endl;
                }
                st++;
            }
            if(tmp>=2)
            {
                ll cnt=1%k;
                if(cnt!=0)mp2.pb({tmp,cnt});
            }
            if(mp2.size()==0)
            mp2.pb({-1,-1});
            mp[mp2]++;

            // for(auto it:mp2)
            // {
            //     err2(it.first,it.second)<<endl;
            // }
        }

        ll tot=0;
        for(auto it:mp)
        {
            vector<pll>mp2=it.first;
            ll k1=it.second;
            Vpll mp3;
            mp3.pb({-1,-1});
            if(mp2==mp3)
            {
                tot+=(k1*(k1-1));
            }
            else{
            mp3.clear();
            for(auto it2:mp2)
            {
                ll tmp=(k-it2.second+k)%k;
                if(tmp!=0)
                mp3.pb({it2.first,tmp});
            }
            if(mp2==mp3)
            {
                // err2(k1,k1);
                tot+=(k1*(k1-1));
            }
            else{
            ll k2=mp[mp3];
            // err2(k1,k2);
            tot+=(k1*k2);}
            }
        }

        tot/=2;

        cout<<tot<<endl;
        

    }

}