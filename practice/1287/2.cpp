#include<bits/stdc++.h>
using namespace std;
#define ll long long

string predict_string(string a,string b){
ll o=a.size();
string z;
for(ll x=0;x<=o-1;x++){
if(a[x]==b[x]) z.push_back(a[x]);
else{
if(a[x]=='S'&&b[x]=='E') z.push_back('T');
else if(a[x]=='E'&&b[x]=='S') z.push_back('T');
else if(a[x]=='S'&&b[x]=='T') z.push_back('E');
else if(a[x]=='T'&&b[x]=='S') z.push_back('E');
else if(a[x]=='T'&&b[x]=='E') z.push_back('S');
else if(a[x]=='E'&&b[x]=='T') z.push_back('S');
}
}
return z;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,k;
    cin>>n>>k;
    string v[n];
    for(ll i=0;i<n;i++)
    {
        cin>>v[i];
    }
    sort(v,v+n);
    ll ans=0;
    for(ll i=0;i<n-1;i++)
    {
        for(ll j=i+1;j<n;j++)
        {
            if(i!=j){
            if(binary_search(v,v+n,predict_string(v[i],v[j])))
                ans++;
        }}
    }
    cout<<ans/3;
}