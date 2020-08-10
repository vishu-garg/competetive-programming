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
ll pow1(ll a,ll b){
    ll res=1;
    while(b>0){
        if(b&1){
        	res=(res*a)%M;
		}
        a=(a*a)%M;
        b>>=1;
    }
    return res%M;
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

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    
    ll T=1;
//     cin>>T;
    while(T--)
    {
        ll n;
        cin>>n;
        V b(n);
        rep(i,0,n)
        cin>>b[i];

        vector<string>ans;

        string s="";

        ll t=(b[0]/9);
        ll fr=(b[0]%9);
        if(fr!=0)
        s+=(fr+'0');

        rep(i,0,t)
        s+=('9');

        ans.pb(s);

        rep(i,1,n)
        {
            string s2="";
            ll num=b[i];
            ll diff=b[i]-b[i-1];
            // err1(diff);
            if(diff<=0)
            diff-=1;
            if(diff<0)
            {
                ll req=abs(diff);
                ll n2=s.length();
                ll pos;
                for(ll j=n2-1;j>=0 && req>0;j--)
                {
                    pos=j;
                    ll num=s[j]-'0';
                    if(num==0){s2+='0';continue;}
                    ll num1;
                    // err2(num,req);
                    if(num>0)
                    {
                        num1=max(0ll,num-req);
                    }
                    req-=(num-num1);
                    // err2(num1,req);
                    s2+=('0'+num1);
                }
                if(pos==0)
                {
                    // err();
                    sort(all(s2));
                    reverse(all(s2));
                    s2+='1';
                }
                else 
                {
                    ll fnd=0;
                    repb(i,pos-1,0)
                    {
                        ll num=s[i]-'0';
                        if(num<9 && fnd==0)
                        {fnd=1;num+=1;sort(all(s2));reverse(all(s2));s2+=(num+'0');}
                        else 
                        s2+=(num+'0');
                    }
                    if(fnd==0)
                    {sort(all(s2));
                    reverse(all(s2));
                    s2+='1';}
                }
                reverse(all(s2));

                    s=s2;

                    ans.pb(s2);
            }
            else 
            {
                ll req=diff;
                ll pos;
                ll n2=s.length();
                // err1(s);
                for(ll j=n2-1;j>=0 && req>0;j--)
                {
                    pos=j;
                    ll num=s[j]-'0';
                    if(num==9){s2+='9';continue;}
                    ll num1=min(req,9-num);
                    req-=num1;
                    num+=num1;
                    // err1(num);
                    s2+=(num+'0');
                }
                string s3="";
                if(req>0 && pos==0)
                {
                    // err1(req);
                    if(req%9!=0)
                    s3+=((req%9)+'0');
                    rep(j,0,req/9)
                    s3+='9';
                }
                else 
                {
                    string s4="";
                    repb(i,pos-1,0)
                    s4+=s[i];
                    reverse(all(s4));
                    s3+=s4;
                }

                reverse(all(s2));
                s3+=s2;
                s=s3;

                ans.pb(s3);

            }
        }

        for(auto it:ans)
        cout<<it<<endl;



    }

}