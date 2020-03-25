#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX = 1e4+5;
int id[MAX],nodes,edges;
pair<ll,pair<int,int> >p[MAX];

void intialize()
{
    for(int i=0;i<MAX ; i++)
    id[i]=i;
}

int root(int x)
{
    while(id[x]!=x)
    {
        id[x]=id[id[x]];
        x=id[x];
    }
    return x;
}

void union1(int x, int y)
{
    int p=root(x);
    int q=root(y);
    id[p]=id[q];
}

ll kruskal()
{
    int x,y;
    ll cost,minimumcost=0;
    for(int i=0;i<edges;i++)
    {
        //seclecting edges one by one in increasing order
        x=p[i].second.first;
        y=p[i].second.second;
        cost = p[i].first;
        if(root(x)!=root(y))
        {
            minimumcost+=cost;
            union1(x,y);
        }
    }
    return minimumcost;
}

int main()
{
    int x,y;
    ll weight , cost, minimumcost;
    intialize();
    cin>>nodes>>edges;
    for(int i=0;i<edges;i++)
    {
        cin>>x>>y>>weight;
        p[i]=make_pair(weight,make_pair(x,y));
    }
    //sort the edges in ascending order
    sort(p,p+edges);
    minimumcost=kruskal();
    cout<<minimumcost<<endl;
    return 0;
}