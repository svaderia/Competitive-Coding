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

int n, r1, r2, r3, d;
vi a;

void solve(){

    cin >> n >> r1 >> r2 >> r3 >> d;
    a.rsz(n);
    rep(i, n){
        cin >> a[i];
    }

    int ans = 0;
    int dp0 = 0, dp1 = INF;
    rep(i, n){
        int cost1 = a[i] * r1 + r3;
        int cost2 = min({cost1, a[i] * r1 + r1 + r1, r2 + r1});
        int ndp0 = INF;
        int ndp1 = INF;
        ndp0 = min({ndp0, dp0 + cost1, dp1 + cost2 + d});
        ndp1 = min({ndp1, dp0 + cost2 + d});
        if(i == n - 1){
            ndp0 = min(ndp0, dp1 + cost1);
        }
        dp0 = ndp0;
        dp1 = ndp1;
    }

    ans = min(dp0, dp1 + d) + (n - 1) * d;

    cout << ans << endl;





}

signed main(){
    fastio;

    solve();

    return 0;
}
