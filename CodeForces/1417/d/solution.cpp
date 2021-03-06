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

const int MX = 1e6 + 5;
vb mark(MX);
vvi prime(MX);

void preproc(){
    repA(p, 2, MX - 1){
        if(mark[p]) continue;
        for(int n = p; n < MX; n += p){
            int cnt = 0, tn = n;
            while(tn % p == 0){
                tn /= p;
                cnt++;
            }
            if(cnt % 2 == 1) prime[n].pb(p);
            mark[n] = true;
        }
    }
}

void solve(){
    int n;
    cin >> n;

    vi arr(n);
    map<vi, int> mp;
    rep(i, n){
        cin >> arr[i];
        mp[prime[arr[i]]]++;
    }

    int mx = 0, odd = 0, ones = 0;
    ones += mp[prime[1]];
    for(auto x : mp){
        mx = max(mx, x.s);
        if(sz(x.f) == 0) continue;
        if(x.s % 2 == 1) odd = max(odd, x.s);
        else ones += x.s;
    }

    int q;
    cin >> q;
    rep(i, q){
        int w;
        cin >> w;
        if(w == 0){
            cout << mx << endl;
        }else{
            cout << max(ones, odd) << endl;
        }
    }

}

signed main(){
    fastio;

    preproc();

    int T;
    cin >> T;

    repA(tc, 1, T){
        solve();
    }

    return 0;
}
