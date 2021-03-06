#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// using namespace __gnu_pbds;
using namespace std;

typedef long long int lli;
#define int lli
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<lli> vli;
typedef vector<pii> vii;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> OrderedSet;

const int MOD	= 1e9 + 7;
const double PI = acos(-1.0);

#define fastio			ios_base::sync_with_stdio(0);cin.tie(0)
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
#define error(x) cerr << #x << " = " << (x) << endl
#define errorp(p) cerr << #p << " = " << (p.first) << ", " << (p.second) << endl

template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }

signed main(){
    // #ifdef DEBUG
	// 	freopen("test", "r", stdin);
	// #endif
    fastio;
    
    int T;
    cin >> T;

    while(T-- > 0){
        int n, m, k;
        cin >> n >> m >> k;
        int max_cards = n / k;
        if(m <= max_cards){
            cout << m << endl;
        }else{
            int mx = max_cards;
            int rj = m - mx;
            int mn = int(ceil((double)rj / (k - 1)));
            // error(mx);
            // error(mn);
            cout << mx - mn << endl;
        }
    }

    return 0;
}
