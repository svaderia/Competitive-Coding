#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
#define int lli
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<lli> vli;
typedef vector<pii> vii;

const int MOD   = 1e9 + 7;
const double PI = acos(-1.0);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const int INF   = 1e18;

#define fastio            ios_base::sync_with_stdio(false);cin.tie(0)
#define sz(a) int((a).size())
#define rsz resize
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define f first
#define s second
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define endl "\n"
#define spc " "
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }

vvi g;
vi visited;
bool can = true;

void dfs(int root, int p){
    visited[root] = 1 - visited[p];
    for(auto child : g[root]){
        if(child != p){
            if(visited[child] == -1){
                dfs(child, root);
            }else if(visited[child] == visited[root]){
                can = false;
            }
        }
    }
}

void solve(){

    int n, m;
    cin >> n >> m;

    g.rsz(n);
    visited.rsz(n, -1);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    rep(i, n){
        if(visited[i] == -1){
            visited[i] = 0;
            dfs(i, i);
        }
    }

    if(can){
        for(auto x : visited) cout << x + 1 << spc;
    } else{
        cout << "IMPOSSIBLE" << endl;
    }

}

signed main(){
    fastio;

    solve();

    return 0;
}
