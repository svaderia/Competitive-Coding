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
void err(istream_iterator<string> it) {it++;}
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << endl; err(++it, args...); }
#else
#define error(args...)
#endif
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }

const long long mod = 1000000007; 
#define ll lli

ll euclid(ll a, ll b, ll &x, ll &y) {
    if (b) { ll d = euclid(b, a % b, y, x);
        return y -= a/b * x, d; }
    return x = 1, y = 0, a;
}

struct modint{
    long long a;
 
    modint() : a(-1){}
    modint(long long t){
        a = t % mod;
        if(a < 0) a += mod;
    }
 
    operator long long() const{ return a; }
 
    bool operator==(const modint &x) const{ return a == x.a; }
    bool operator!=(const modint &x) const{ return a != x.a; }
 
    modint operator-() const{ return modint(a ? (mod - a) : 0); }
    modint operator~() const{ return invert(*this); }
 
    modint operator+(const modint &x) const{ return modint(*this) += x; }
    modint operator-(const modint &x) const{ return modint(*this) -= x; }
    modint operator*(const modint &x) const{ return modint(*this) *= x; }
    modint operator/(const modint &x) const{ return modint(*this) /= x; }
 
    modint &operator+=(const modint &x){
        a += x.a;
        if(a >= mod) a -= mod;
        return *this;
    }
    modint &operator-=(const modint &x){
        a -= x.a;
        if(a < 0) a += mod;
        return *this;
    }
    modint &operator*=(const modint &x){
        a = a * x.a % mod;
        return *this;
    }
    modint &operator/=(const modint &x){
        a = a * (~x).a % mod; 
        return *this;
    }
 
    friend ostream &operator<<(ostream &os,const modint &x){
        return os << x.a;
    }
    friend istream &operator>>(istream &is,modint &x){
        long long t;
        is >> t;
        x = modint(t);
        return is;
    }
 
    modint pow(long long x) const{
        modint ret = 1,tmp = a;
        for(;x;tmp *= tmp,x >>= 1){
            if(x & 1) ret *= tmp;
        }
        return ret;
    }

    modint invert(modint a) const{
        ll x, y, g = euclid(a.a, mod, x, y);
        assert(g == 1); return modint((x + mod) % mod);
    }
};

vector<vector<modint> > dp;
vector<vi> arr;
int n;

modint rec(int man, int wom){
    if(dp[man][wom].a != -1){
        return dp[man][wom];
    }
    dp[man][wom] = modint(0);
    if(man == 0){
        rep(i, n){
            if(arr[man][i] && (wom & (1 << i))){
                dp[man][wom] += modint(1);
            }
        }
    }else{
        rep(i, n){
            if(arr[man][i] && (wom & (1 << i)) ){
                dp[man][wom] += rec(man - 1, (wom ^ (1 << i)));
            }
        }
    }
    return dp[man][wom];
}

void solve(){
    cin >> n;
    arr.resize(n, vi(n));
    rep(i, n){
        rep(j, n){
            cin >> arr[i][j];
        }
    }

    int max_wom = (1 << (n));
    dp.resize(n, vector<modint>(max_wom));
    
    // Surely calculating something which are not required
    // rep(man, n){
    //     for(int wom = 0; wom < max_wom; wom++){
    //         if(man == 0){
    //             rep(i, n){
    //                 if(arr[man][i] && (wom & (1 << i))){
    //                     dp[man][wom] += 1;
    //                 }
    //                 // error(man, wom, i, arr[man][i], dp[man][wom]);
    //             }
    //         }else{
    //             rep(i, n){
    //                 if(arr[man][i] && (wom & (1 << i)) ){
    //                     dp[man][wom] += dp[man - 1][(wom ^ (1 << i))];
    //                     // error(wom, wom^(1<<i));
    //                 }
    //             }
    //         }
    //     }
    // }
    // cout << dp[n - 1][max_wom - 1] << endl;

    
    cout << rec(n - 1, max_wom - 1) << endl;
}

signed main(){
    #ifdef DEBUG
		freopen("test", "r", stdin);
	#endif
    fastio;
    
    solve();

    return 0;
}
