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
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
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
struct solver_2SAT {
    struct util {
        util()
            : index{ MIN }
            , lowlink{ MIN }
            , id{ -1 }
            , on_stack{ false }
        {
        }
        int index, lowlink, id;
        bool on_stack;
        std::vector<int> edges;
    };

    solver_2SAT(std::unordered_map<int, util> adj_lst_graph, int num_of_vars)
        : n{ num_of_vars }
        , graph{ std::move(adj_lst_graph) }
        , sol{ std::vector<bool>(n, false) }
    {
    }

    void process_vertex(int v)
    {
        auto& utl = graph[v];

        utl.lowlink = utl.index = t++;
        utl.on_stack = true;
        stk.push(v);

        for (auto w : utl.edges) {
            if (graph[w].index == MIN) {
                process_vertex(w);
                utl.lowlink = std::min(utl.lowlink, graph[w].lowlink);
            }
            else if (graph[w].on_stack) {
                utl.lowlink = std::min(utl.lowlink, graph[w].index);
            }
        }

        if (utl.lowlink == utl.index) {
            do {
                w = stk.top();
                stk.pop();

                if (id == graph[-w].id) {
                    sat = false;
                    return;
                }

                auto& w_utl = graph[w];
                w_utl.on_stack = false;
                w_utl.id = id;

                sol[abs(w) - 1] = w < 0 ? true : false;

            } while (w != v);
            ++id;
        }
    }

    void solve()
    {
        for (int i = -n; i <= n; ++i) {
            if (graph[i].index == MIN && i != 0) {
                process_vertex(i);
            }
        }
    }

    void print_solution() const noexcept
    {
        if (!sat) {
            printf("%s\n", "UNSATISFIABLE\0");
            return;
        }

        printf("%s\n", "SATISFIABLE\0");
        for (unsigned int i = 0, s = sol.size(); i < s; ++i) {
            printf("%d ", (sol[i] ? i + 1 : -(i + 1)));
        }

        printf("\n");
    }

    int t{ 0 }, id{ 0 }, w{ 0 }, n{ 0 };

    std::unordered_map<int, util> graph;
    std::vector<bool> sol;
    std::stack<int> stk;

    bool sat{ true };

    static constexpr int MIN = std::numeric_limits<int>::min();
};

int main()
{
    std::ios::sync_with_stdio(false);

    int n, m;
    std::cin >> n >> m;

    std::unordered_map<int, solver_2SAT::util> adj_lst_graph(n * 2);

    for (int i = 0, x, y; i < m; ++i) {
        std::cin >> x >> y;
        adj_lst_graph[-x].edges.emplace_back(y);
        adj_lst_graph[-y].edges.emplace_back(x);
    }

    solver_2SAT solver(std::move(adj_lst_graph), n);
    solver.solve();
    solver.print_solution();
}