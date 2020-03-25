#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,s,e) for(ll i=s;i<e;i++)
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        ll n=s.length();
        ll ans=0;
        for(ll i=1;i<18;i++){
        ll j=0;
        // cout<<j+i<<"poppo";
        // cout<<n;
        while(j+i<=n)
        {
            // cout<<j<<" ";
            ll temp=0;
            for(ll k=j+i-1;k>=j;k--)
            temp+=((s[k]-'0')*(ll)(pow(2,(j+i-1-k))));
            // cout<<temp<<" "<<i<<endl;
            if(temp==i)
            ans++;
            j++;
        }
        // cout<<endl;
        }
        cout<<ans<<endl;
    }
}