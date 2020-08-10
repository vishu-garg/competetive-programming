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
    a%=M;
    while(b>0){
        if(b&1){
        	res=(res*a)%M;
		}
        a=(a*a)%M;
        b>>=1;
    }
    return res%M;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
//     cin>>t;
    while(t--)
    {
        string txt;
        cin>>txt;
        ll n;
        cin>>n;
        string s;
        vector<vector<pair<ll,char> > >adj(500005);
        ll cnt=1;
        rep(j,0,n)
        {
            ll u=0;
            cin>>s;
            s+='$';
            rep(i,0,(ll)s.length())
            {
                ll fnd=0;
                for(auto it : adj[u])
                {
                    if(it.second==s[i])
                    {
                        fnd=1;
                        u=it.first;
                    }
                }
                if(fnd==0)
                {
                    adj[u].pb({cnt,s[i]});
                    u=cnt;
                    cnt++;
                }
            }    
        }

        rep(i,0,(ll)txt.length())
        {
            ll j=i;
            ll u=0;
            while(true)
            {
                // if(i==2)
                // cout<<u<<" "<<endl;
                
                ll fnd=0;
                for(auto it : adj[u])
                {
                    // if(i==0)
                    // cout<<it.second<<" "<<endl;
                    if(it.second=='$')
                    {
                        cout<<i<<" ";
                        fnd=1;
                        break;
                    }
                }
                if(fnd==1)
                break;
                if(j==(ll)txt.length())
                break;    
                fnd=0;
                for(auto it: adj[u]){
                    if(it.second==txt[j])
                    {
                        fnd=1;
                        j++;
                        u=it.first;
                        break;
                    }
                }
                
                if(fnd==0)
                break;
            }
        }
    }

}