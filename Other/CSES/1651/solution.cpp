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

struct node{
    int data;
    node(int val) : data(val) {}
    node() {}
}typedef node;

struct SegTree{
    typedef node T;

    T unit = T(-INF);

    T merge(T a, T b) {
        return T(max(a.data, b.data));
    } // any associatinve function

    int n;
    vi lo, hi, delta;
    vector<T> seg;

    void update(int idx){
        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

    void propagate(int idx){
        if(lo[idx] == hi[idx]){
            seg[idx].data += delta[idx];
            delta[idx] = 0;
            return;
        }

        delta[2 * idx] += delta[idx];
        delta[2 * idx + 1] += delta[idx];
        delta[idx] = 0;
    }

    SegTree(int nn, T def) : n(nn), lo(4 * n), hi(4 * n), delta(4 * n), seg(4 * n, def) { build(1, 0, n - 1); }
    SegTree(int nn) : n(nn), lo(4 * n), hi(4 * n), delta(4 * n), seg(4 * n)  { build(1, 0, n - 1); }
    SegTree(int nn, vi &arr) : n(nn), lo(4 * n), hi(4 * n), delta(4 * n), seg(4 * n)  { build(1, 0, n - 1, arr); }

    void build(int id, int l, int r){
        lo[id] = l, hi[id] = r;
        if(l == r) return;
        int mid = (l + r) / 2;
        build(2 * id, l, mid);
        build(2 * id, mid + 1, r);
    }

    void build(int id, int l, int r, vi &arr){
        lo[id] = l, hi[id] = r;
        if(l == r){
            seg[id] = T(arr[l]);
            return;
        }
        int mid = (l + r) / 2;
        build(2 * id, l, mid, arr);
        build(2 * id + 1, mid + 1, r, arr);
        update(id);
    }

    T query(int l, int r, int id = 1){
        // outside
        if(lo[id] > r || hi[id] < l)
            return unit;

        propagate(id);

        if(l <= lo[id] && hi[id] <= r)
            return seg[id];

        T leftQuery = query(l, r, 2 * id);
        T rightQuery = query(l, r, 2 * id + 1);
        update(id);

        return  merge(leftQuery, rightQuery);
    }

    void increase(int l, int r, int val, int id = 1){
        // outside
        if(lo[id] > r || hi[id] < l) return;

        if(l <= lo[id] && hi[id] <= r){
            delta[id] += val;
            return;
        }

        propagate(id);
        increase(l, r, val, 2 * id);
        increase(l, r, val, 2 * id + 1);
        update(id);
    }

    void change(int p, int val, int id = 1){
        // No overlap
        if(p < lo[id] || p > hi[id])
            return;

        if(lo[id] == hi[id]){
            seg[id] = val;
            return;
        }

        propagate(id);
        change(p, val, 2 * id);
        change(p, val, 2 * id + 1);
        update(id);
    }

};

void solve(){
    int n, q;
    cin >> n >> q;

    vi arr(n);
    rep(i, n){
        cin >> arr[i];
    }

    SegTree seg(n, arr);

    rep(i, q){
        int type;
        cin >> type;
        if(type == 2){
            int k; cin >> k; k--;
            cout << seg.query(k, k).data << endl;
        }else{
            int x, y, val;
            cin >> x >> y >> val;
            x--; y--;
            seg.increase(x, y, val);
        }
    }

}

signed main(){
    fastio;

    solve();

    return 0;
}
