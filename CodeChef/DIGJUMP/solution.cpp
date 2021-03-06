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
    string s;
    cin >> s;
    vvi whereto(10);
    int n = sz(s);

    rep(i, n){
        whereto[s[i] - '0'].pb(i);
    }

    vi visited(n, -1);
    vb vs(10);
    queue<pii> q;
    q.push(mp(0, 0));
    visited[0] = 0;
    while(!q.empty()){
        int d =  q.front().f;
        int i = q.front().s;
        q.pop();
        if(i - 1 > 0 && visited[i - 1] == -1){
            q.push(mp(d + 1, i - 1));
            visited[i - 1] = d + 1;
        }
        if(i + 1 < n && visited[i + 1] == -1){
            q.push(mp(d + 1, i + 1));
            visited[i + 1] = d + 1;
        }
        if(!vs[s[i] - '0']){
            vs[s[i] - '0'] = true;
            for(auto x : whereto[s[i] - '0']){
                if(visited[x] == -1){
                    q.push(mp(d + 1, x));
                    visited[x] = d + 1;
                }
            }
        }
    }
    cout << visited[n - 1] << endl;

}

signed main(){
    fastio;

    solve();

    return 0;
}
