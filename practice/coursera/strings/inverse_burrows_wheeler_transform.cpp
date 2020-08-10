#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,s,e) for(ll i=s;i<e;i++)
int main()
{
    string s;
    cin>>s;
    string s2=s;
    sort(s2.begin(),s2.end());
    ll n=s.length();
    map<char,ll>mp1,mp3;
    map<pair<char,ll>,pair<char,ll> >mp2;
    rep(i,0,n)
    {
        pair<char,ll>p1,p2;
        p1={s2[i],mp1[s2[i]]};
        p2={s[i],mp3[s[i]]};
        mp1[s2[i]]++;
        mp3[s[i]]++;
        mp2[p1]=p2;
    }
    string ans="";
    pair<char,ll> p=make_pair('$',0ll);
    rep(i,0,n)
    {
        ans+=p.first;
//        cout<<p.first<<"<---"<<endl;
        p=mp2[p];
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}