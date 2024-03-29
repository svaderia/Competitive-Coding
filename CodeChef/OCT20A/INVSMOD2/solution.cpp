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

const int MOD   = 2;
const double PI = acos(-1.0);
const int xd[4] = {1, 0, -1, 0}, yd[4] = {0, 1, 0, -1};
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

void solve(){

    int n, k;
    cin >> n >> k;

    int f[2][k + 1];
    f[0][0] = 1; /// base case f[n][0] = 1
    for (int i = 1; i <= k; ++i) f[0][i] = 0; /// base case f[0][k] = 0
    for (int i = 1; i <= n; ++i)
    {
        bool cur = i & 1; /// current
        bool pre = !cur;  /// previous

        f[cur][0] = 1; /// base case f[n][0] = 1
        for (int j = 1; j <= k; ++j)
        {
            f[cur][j] = (f[cur][j - 1] + f[pre][j]) % MOD;
            if (j >= i)
                f[cur][j] = (f[cur][j] - f[pre][j - i] + MOD) % MOD;
        }
    }

    assert(f[n & 1][k] == (((n - k) & k) == 0));
    /* cout << f[n & 1][k] << endl; */
}

signed main(){
    fastio;

    int T;
    cin >> T;

    repA(tc, 1, T){
        solve();
    }

    return 0;
}
