#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i,s,e) for(ll i=s;i<e;i++)
#define V vector<ll>
#define mS multiset<ll>
ll n;



bool check(V sa , V sb , V ea , V eb)
{
    vector<vector<ll> > evnt;
    rep(i,0,n){
        vector<ll> tmp;
        tmp.push_back(sa[i]);
        tmp.push_back(sb[i]);
        tmp.push_back(eb[i]);
        tmp.push_back(1);
        evnt.emplace_back(tmp);
        vector<ll> tmp2;
        tmp2.push_back(ea[i]+1);
        tmp2.push_back(sb[i]);
        tmp2.push_back(eb[i]);
        tmp2.push_back(0);
        evnt.emplace_back(tmp2);
    }
    sort(evnt.begin(),evnt.end());
    mS S,E;

    rep(i,0,2*n)
    {
        if(evnt[i][3]==1)
        {
            if(!S.empty())
            {
                ll maxS=*(S.rbegin());
                ll minE=*(E.begin());
                if(maxS>evnt[i][2] || minE<evnt[i][1])
                return false;
            }
            S.insert(evnt[i][1]);
            E.insert(evnt[i][2]);
        }
        else 
        {
            E.erase(E.find(evnt[i][2]));
            S.erase(S.find(evnt[i][1]));
        }
    }
    return true;   
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    V sa(n),sb(n),ea(n),eb(n);
    rep(i,0,n)
    {
        cin>>sa[i]>>ea[i]>>sb[i]>>eb[i];
    }
    if(check(sa,sb,ea,eb) && check(sb,sa,eb,ea))
    cout<<"YES";
    else 
    cout<<"NO";
    return 0;


}