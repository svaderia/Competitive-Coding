#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<lli> vli;
typedef vector<pii> vii;

const int MOD   = 1e9 + 7;
const double PI = acos(-1.0);
const int xd[4] = {1, 0, -1, 0}, yd[4] = {0, 1, 0, -1};

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

mt19937 rnd(42);

const int K = 60;

typedef array<int, K> num;

num operator ^(const num &a, const num &b){
    num c;
    rep(i, K){
        c[i] = a[i] + b[i];
        c[i] %= 3;
    }
    return c;
}

void solve(){

    int n;
    cin >> n;

    vi a(n);
    rep(i, n){
        cin >> a[i];
        a[i]--;
    }

    vector<num> rands(n);

    rep(i, n) rep(j, K) rands[i][j] = rand() % 3;

    map<num, int> cnt;
    vector<num> xors(1);

    cnt[xors.back()] = 1;
    int curr = 0;

    vvi pos(n);

    lli ans = 0;

    rep(i, n){
        xors.pb(xors.back() ^ rands[a[i]]);
        pos[a[i]].pb(i);
        int len = sz(pos[a[i]]);
        if(len >= 4){
            while(curr <= pos[a[i]][len - 4]){
                --cnt[xors[curr]];
                curr++;
            }
        }
        ans += cnt[xors.back()];
        cnt[xors.back()]++;
    }

    cout << ans << endl;

}

signed main(){
    fastio;

    solve();

    return 0;
}
