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

ll pow1(ll a,ll b){
    ll res=1;
    a=(a%M);
    while(b>0){
        if(b&1){
        	res=(res*a)%M;
		}
        a=(a*a)%M;
        b>>=1;
    }
    res%=M;
    return res;
}

bool is_pfct_sqr(ll n)
{
    ll tmp=sqrt(n);
    return (n==tmp*tmp);
}

bool is_overflow(ll a, ll b)
{
	return b>(1e18+10)/a;
}
int mp[1000006];
void solve()
{
		ll n;
        cin>>n;
        memset(mp,0,sizeof(mp));
		ll sqrn=sqrt(n);
        ll cbrn=cbrt(n);
//        map<ll,ll> mp;
        ll ans=0;
        ans+=n;
        mp[1]=1;
        rep(i,2,cbrn+1)
        {
            if(mp[i] || is_pfct_sqr(i))
            continue;
            ll k=(i*i*i);
            while(k<=n)
            {
                ll tmp=((n/k)*(k))%M;
                ans=(ans+tmp)%M;
                if(k<=cbrn)
				mp[k]=1;
                if(is_overflow(k,i*i))
                break;
                k=(k*i*i);
            }
        }
//        cout<<ans<<"<---"<<endl;
        ll blw=(ll)pow1(6,M-2);
        for(ll i=sqrn;i>1;i--)
        {
            ll cnt=n/(i*i);
            ll j=(n/(cnt+1));
            j=sqrt(j);
            if(j==i)
            --j;
//            cout<<cnt<<" : "<<i<<" "<<j<<endl;
            ll sum=(i*(i+1ll))%M;
            sum=(sum*(2ll*i+1ll))%M;
//            cout<<sum<<"###"<<endl;
            sum=(sum*blw)%M;
//            cout<<sum<<" ### "<<endl;
			
            ll s2=(j*(j+1ll))%M;
            s2=(s2*(2ll*j+1ll))%M;
            s2=(s2*blw)%M;
            
//            cout<<s2<<" "<<sum<<" "<<cnt<<" "<<j<<" "<<i<<"<---"<<endl;

            ll tmp=((sum-s2)+M)%M;
            tmp=(tmp*cnt)%M;
            ans=(ans+tmp)%M;
            i=j+1;
        }
        cout<<ans<<endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    ll t=1;
   cin>>t;
    while(t--)
    {
        solve();
    }

}

/*
    we can do last loop in forward direction it will be easy
    upper limit=sqrtl(cnt/i) 
    lower limit=i;

    yeh yahan par apan ne sqrtl liya  dusre code me kyonki sqrtl high precision ka hota he

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

ll pow1(ll a,ll b){
    ll res=1;
    a=(a%M);
    while(b>0){
        if(b&1){
        	res=(res*a)%M;
		}
        a=(a*a)%M;
        b>>=1;
    }
    res%=M;
    return res;
}

bool is_pfct_sqr(ll n)
{
    ll tmp=sqrt(n);
    return (n==tmp*tmp);
}

bool is_overflow(ll a, ll b)
{
	return b>(1e18+10)/a;
}
int mp[1000006];
void solve()
{
		ll n;
        cin>>n;
        memset(mp,0,sizeof(mp));
		ll sqrn=sqrtl(n);
        ll cbrn=cbrt(n);
//        map<ll,ll> mp;
        ll ans=0;
        ans+=n;
        mp[1]=1;
        rep(i,2,cbrn+1)
        {
            if(mp[i] || is_pfct_sqr(i))
            continue;
            ll k=(i*i*i);
            while(k<=n)
            {
                ll tmp=((n/k)*(k))%M;
                ans=(ans+tmp)%M;
                if(k<=cbrn)
				mp[k]=1;
                if(is_overflow(k,i*i))
                break;
                k=(k*i*i);
            }
        }
//        cout<<ans<<"<---"<<endl;
        ll blw=(ll)pow1(6,M-2);
        for(ll i=2;i<=sqrn;)
        {
            ll cnt=n/(i*i);
            ll en=(n/(cnt));
            en=sqrtl(en);
//            if(j==i)
//            --j;
//            cout<<cnt<<" : "<<i<<" "<<j<<endl;
            ll sum=((i-1ll)*((i)))%M;
            sum=(sum*(2ll*(i-1ll)+1ll))%M;
//            cout<<sum<<"###"<<endl;
            sum=(sum*blw)%M;
//            cout<<sum<<" ### "<<endl;
			
            ll s2=(en*(en+1ll))%M;
            s2=(s2*(2ll*en+1ll))%M;
            s2=(s2*blw)%M;
            
//            cout<<s2<<" "<<sum<<" "<<cnt<<" "<<j<<" "<<i<<"<---"<<endl;

            ll tmp=((s2-sum)+M)%M;
            tmp=(tmp*cnt)%M;
            ans=(ans+tmp)%M;
            i=en+1;
        }
        cout<<ans<<endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    ll t=1;
   cin>>t;
    while(t--)
    {
        solve();
    }

}
*/