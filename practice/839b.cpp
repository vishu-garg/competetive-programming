#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n,k;
    cin>>n>>k;
    ll have[5],cnt[3]={0};
    have[2]=2*n,have[4]=n,have[1]=0;
    for(ll i=0;i<k;i++)
    {
        ll grp;
        cin>>grp;
        while(grp>=3)
        {
            if(have[4]>0) grp-=4,have[4]--;
            else if(have[2]>0)grp-=2,have[2]--;
            else return cout<<"NO",0;
        }
        if(grp>0)
        cnt[grp]++;
    }
    while(cnt[2]>0)
    {
        if(have[2]>0) cnt[2]--,have[2]--;
        else if(have[4]>0)cnt[2]--,have[4]--,have[1]++;
        else cnt[2]--,cnt[1]+=2;
    }
    if(cnt[1]>have[1]+have[2]+have[4]*2)
    return cout<<"NO",0;
    cout<<"YES";return 0;

}