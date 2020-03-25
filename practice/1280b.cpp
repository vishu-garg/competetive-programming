#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll r,c;
        cin>>r>>c;
        ll mat[r][c];
        vector<string> v(r);
        ll row[r]={0},col[c]={0},is_a=0,,is_p=0;
        for(ll i=0;i<r;i++)
        {
            cin>>v[i];
            for(ll j=0;j<c;j++)
            {
                if(v[i][j]=='A'){
                is_a=1;
                col[j]++;
                row[i]++;}
                else if(v[i][j]=='P')
                is_p=1;
            }
        }
        if(is_a==0)
        cout<<"MORTAL"<<endl;
        else if(is_p==0)
        cout<<"0"<<endl;
        else if(row[0]==c || row[r-1]==c || col[0]==r || col[c-1]==r)
        cout<<"1"<<endl;
        else if(v[0][0]=='A' || v[0][c-1]=='A' || v[r-1][0]=='A' || v[r-1][c-1]=='A')
        cout<<"2"<<endl;
        else 
        {
            ll chk=0;
            for(ll i=1;i<r-1;i++)
            {
                if(row[i]==c)
                {
                    chk=1;
                    cout<<"2"<<endl;
                    i=r;
                }
            }
            if(chk==0)
            {
                for(ll i=1;i<c-1;i++)
                {
                    if(col[i]==r)
                    {
                        chk=1;
                        cout<<"2"<<endl;
                        i=c;
                    }
                }
            }
            if(chk==0)
            {
                if(row[0]!=0 || row[r-1]!=0 || col[c-1]!=0 ||col[0]!=0)
                cout<<"3"<<endl;
                else 
                cout<<"4"<<endl;
            }
        }
    }
}