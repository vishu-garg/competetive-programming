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
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        sort(all(s));
        string ans[k];
        rep(i,0,k)
        ans[i]="";
        rep(i,0,k)
        ans[i]+=s[i];
        if(ans[k-1]!=ans[0])
        {
        	cout<<ans[k-1]<<endl;
        	continue;
		}
        map<ll,ll> mp;
        rep(i,0,n)
        mp[s[i]]++;
        if(mp.size()==1)
        {
            ll j=0;
            rep(i,k,n)
            {
                ans[j]+=s[i];
                j++;
                j%=k;
            }
            sort(ans,ans+k);
            cout<<ans[k-1]<<endl;
            continue;
        }

        if(mp.size()==2)
        {
            ll i=k;
//            ll j=0;
            while(i<s.length() && s[i]==s[0])
            {
            	ans[0]+=s[i];
            	i++;
//            	j++;
//            	j%=k;
			}
            ll tmp=0;
            if(i==k){
            rep(j,i,n)
            {
                ans[tmp]+=s[j];
                tmp++;
                tmp%=k;
            }
        	}
			else 
			rep(j,i,n)
			ans[0]+=s[i];
            sort(ans,ans+k);
            cout<<ans[k-1]<<endl;
            continue;
        }

        rep(i,k,n)
        ans[0]+=s[i];

        sort(ans,ans+k);
        cout<<ans[k-1]<<endl;

        

    }

}