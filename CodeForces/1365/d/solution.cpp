//https://codeforces.com/contest/1365/problem/D
#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
#define int lli
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<lli> vli;
typedef vector<pii> vii;

const int MOD	= 1e9 + 7;
const double PI = acos(-1.0);

#define fastio			ios_base::sync_with_stdio(false);cin.tie(0)
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define all(c) (c).begin(),(c).end()
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define endl "\n"
#define error_old(x) cerr << #x << " = " << (x) << endl
#define errorp(p) cerr << #p << " = " << (p.first) << ", " << (p.second) << endl
#ifdef DEBUG
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {it++; cout << endl;}
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << " [ "<< *it << " : " << a << " ] "; err(++it, args...); }
#else
#define error(args...)
#endif
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void solve(){
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i, n){
        cin >> s[i];
    }

    rep(x, n){
        rep(y, m){
            if(s[x][y] == 'B'){
                rep(dir, 4){
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                        if(s[nx][ny] == '.'){
                            s[nx][ny] = '#';
                        }
                    }
                }
                
            }
        }
    }

    vector<vector<bool> > dp2(n, vector<bool>(m, false));

    dp2[n - 1][m - 1] = (s[n - 1][m - 1] == '.' ? true : false);
    queue<pii> q;
    if(dp2[n - 1][m - 1]){
        q.push({n - 1, m - 1});
    }

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        error(x, y);

        rep(dir, 4){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !dp2[nx][ny] && s[nx][ny] != '#'){
                dp2[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    int ans = true;
    rep(x, n){
        rep(y, m){
            if((s[x][y] == 'G' && !dp2[x][y]) || (s[x][y] == 'B' && dp2[x][y])){
                ans = false;
            }
        }
    }


    cout << (ans ? "Yes" : "No") << endl;

}

signed main(){
    #ifdef DEBUG
		freopen("test", "r", stdin);
	#endif
    fastio;
    
    int T;
    cin >> T;

    while(T-- > 0){
        solve();
    }

    return 0;
}
