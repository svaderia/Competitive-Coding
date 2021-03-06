#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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

typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> OrderedSet; // order_of_key find_by_order

void solve(){

    int n, k;
    cin >> n >> k;

    vi arr(n);
    rep(i, n){
        cin >> arr[i];
    }

    int t = 0;
    OrderedSet st;
    rep(i, k){
        st.insert({arr[i], t++});
    }

    repA(i, k, n){
        if(k % 2 == 0){
            cout << (*st.find_by_order(k/2 - 1)).f << spc;
        }else{
            cout << (*st.find_by_order(k/2)).f << spc;
        }
        if(i != n){
            st.erase(st.lower_bound({arr[i - k], 0}));
            st.insert({arr[i], t++});
        }
    }

}

signed main(){
    fastio;

    solve();

    return 0;
}
