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
const ll M = 1000000007;
const ll INF = 1e12;
#define PI 3.14159265

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

int main()
{
    ll t=1;
    cin>>t;
    while(t--)
    {
        ll a,b,q;
        cin>>a>>b>>q;
        rep(xyz,0,q)
        {
            ll l,r;
            cin>>l>>r;
            map<ll> ma,mb;
            ll tmp1=(r-l)/a;
            ll tmp2=(r-l)/b;
            rep(i,0,a)
            {
                ma[i]=tmp1;
            }
            ma[l%a]++;
            tmp1=(r-l)%a;
            ll t2=l%a;
            rep(i,0,tmp1)
            {
                t2=(t2+1)%a;
                ma[t2]++;
            }

            rep(i,0,b)
            {
                mb[i]=tmp2;
            }
            mb[l%b]++;
            tmp2=(r-l)%b;
            ll t2=l%b;
            rep(i,0,tmp2)
            {
                t2=(t2+1)%a;
                mb[t2]++;
            }

            map<ll,ll> cnt,cnt2;
            rep(i,0,a)
            {
                cnt[i%b]+=ma[i];
            }
            rep(i,0,b)
            {
                cnt2[i%a]+=mb[i];
            }

            ll mn=min(a,b);
            ll sum=0;
            rep(i,0,mn)
            {
                ll t4=min(cnt[i],cnt2[i]);
                sum+=t4;
            }
            ll tot=r-l+1;
            tot-=sum;
            cout<<tot<<" ";
        }
        cout<<endl;
    }

}