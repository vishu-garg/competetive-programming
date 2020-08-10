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

vector<multiset<ll> >pwr(200005);

int main()
{
    fast;
    ll t=1;
//     cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll> a(n);
        ll mx=0;
        rep(i,0,n)
        {
            cin>>a[i];mx=max(mx,a[i]);
        }

        rep(i,0,n)
        {
            ll num=a[i];
            ll tmp=sqrt(num)+1;
            map<ll,ll> mp2;
            rep(j,2,tmp)
            {
                while(num%j==0)
                {mp2[j]++;num/=j;}
            }
            if(num>1)
            mp2[num]++;
            ll cnt=0;
            for(auto it:mp2)
            {
                pwr[it.first].insert(it.second);
            }
            
        }
        
        ll ans=1;
        for(ll i=2;i<mx+1;i++)
        {
            auto it=pwr[i];
            if(it.size()==n)
            {
                auto it2=it.begin();it2++;
                // cout<<i<<" "<<*pwr[i].begin()<<" "<<*it2<<"<--"<<endl;
                ans*=(ll)pow(i,*it2);
            }
            if(it.size()==n-1)
            {
                auto it2=it.begin();
                // cout<<i<<" "<<"0"<<" "<<*it2<<"<--"<<endl;
                ans*=(ll)pow(i,*it2);
            }
        }
        cout<<ans<<endl;
    }

}