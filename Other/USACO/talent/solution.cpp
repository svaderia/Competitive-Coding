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
const lli INF   = 1e18;

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

void solve(){
    int n, W;
    cin >> n >> W;

    vi w(n), t(n);
    rep(i, n){
        cin >> w[i] >> t[i];
        t[i] *= 1000;
    }

    auto ok = [&](int y) -> bool {
        vi dp(W + 1,  -INF);
        dp[0] = 0;
        rep(i, n){
            vi sdp(W + 1, -INF);
            int cost = t[i] - y * w[i];
            rep(x, W + 1){
                int id = min(W, x + w[i]);
                sdp[id] = max(sdp[id], dp[x] + cost);
            }
            rep(x, W + 1)
                dp[x] = max(dp[x], sdp[x]);
        }
        return dp[W] >= 0;
    };

    int z = 5e5;
    int id = -1;
    for(; z > 0; z /= 2){
        while(ok(id + z)) id += z;
    }

    cout << id << endl;

}

signed main(){
#ifndef DEBUG
    freopen("talent.in", "r", stdin);
    freopen("talent.out", "w", stdout);
#endif

    fastio;

    solve();

    return 0;
}
