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

void solve(){
    int n, k;
    cin >> n >> k;
    pii a, b;
    cin >> a.f >> a.s >> b.f >> b.s;
    if(a.f > b.f) swap(a, b);

    int curr = 0;
    int dist = b.f - a.s;  
    int scope = max(a.s, b.s) - a.f;
    int inter = 0;
    if(b.f < a.s){
        inter = (min(b.s, a.s) - b.f);
        curr += n * inter;
        dist = 0;
        scope -= inter;
    }

    int ans = 1e18;
    if(curr >= k) {
        ans = 0;
        cout << ans << endl;
        return;
    }
    repA(seg, 1, n){
        int need = k - curr;
        int moves = seg * dist;
        int domove = min(need, scope * seg);
        moves += domove;
        need -= domove;
        moves += need * 2;
        ans = min(ans, moves);
    }
    cout << ans << endl;
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
