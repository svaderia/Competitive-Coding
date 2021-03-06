#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds;
using namespace std;

typedef long long int lli;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<lli> vli;
typedef vector<pii> vii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> OrderedSet;

const int MOD	= 1e9 + 7;
const double PI = acos(-1.0);

#define fastio			ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(auto &i : c)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define fill(a)  memset(a, 0, sizeof (a))
#define error(x) cerr << #x << " = " << (x) <<endl

template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }
int mul(int a, int b, int c){lli res=(lli)a*b;return (int)(res>=c?res%c:res);}
template<typename T>T power(T e, T n, T m){T x=1,p=e;while(n){if(n&1)x=mul(x,p,m);p=mul(p,p,m);n>>=1;}return x;}
int mod_neg(int a, int b, int c){int res;if(abs(a-b)<c)res=a-b;else res=(a-b)%c;return(res<0?res+c:res);}
template<typename T>T extended_euclid(T a, T b, T &x, T &y){T xx=0,yy=1;y=0;x=1;while(b){T q=a/b,t=b;b=a%b;a=t;\
t=xx;xx=x-q*xx;x=t;t=yy;yy=y-q*yy;y=t;}return a;}
template<typename T>T mod_inverse(T a, T n){T x,y,z=0;T d=extended_euclid(a,n,x,y);return(d>1?-1:mod_neg(x,z,n));}
template <class T>  inline void smax(T &x,T y){ x = max((x), (y));}
template <class T>  inline void smin(T &x,T y){ x = min((x), (y));}

vi primes;
vector<vector<pii> > t;
vector<vector<pii> > presums;
int N;
vi arr;

void sieve(int n){
    primes.clear();

    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) { 
        if (prime[p] == true) { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
          primes.pb(p);
}

void prime_factors(int k, int id){
    int ps = 0;
    int cnt = 0;
    // error(id);
    int cp = (int) sqrt(k);
    // error(cp);
    tr(primes, it){
        if(it > cp){
            break;
        }

        cnt = 0;
        while(k % it == 0){
            cnt ++;
            k /= it;
        }

        if(cnt != 0){
            t[id].pb(mp(it, cnt));
            ps += cnt;
            presums[id].pb(mp(it, ps));
        }
    }

    if(k >= 2){
        t[id].pb(mp(k, 1));
        presums[id].pb(mp(k, ps+1));
    }
   
}

void merge_vec(int id, int left, int right){
    int n = sz(t[left]);
    int m = sz(t[right]);
    int p = 0, q = 0;
    int ps = 0;
    // error(id);
    // tr(t[id], it){
    //     error(it.first);
    //     error(it.second);
    // }
    // error(left);
    // tr(t[left], it){
    //     error(it.first);
    //     error(it.second);
    // }
    // error(right); 
    // tr(t[right], it){
    //     error(it.first);
    //     error(it.second);
    // }
    while(p < n && q < m){
        if(t[left][p].first < t[right][q].first){
            t[id].pb(t[left][p]);
            ps += t[left][p].second;
            presums[id].pb(mp(t[left][p].first, ps));
            p++;
        }else if(t[left][p].first > t[right][q].first){
            t[id].pb(t[right][q]);
            ps += t[right][q].second;
            presums[id].pb(mp(t[right][q].first, ps));
            q++;
        }else{
            t[id].pb(mp(t[left][p].first, t[left][p].second + t[right][q].second));
            ps += t[left][p].second + t[right][q].second;
            presums[id].pb(mp(t[left][p].first, ps));
            p++;
            q++;
        }
    }

    while(p < n){
        t[id].pb(t[left][p]);
        ps += t[left][p].second;
        presums[id].pb(mp(t[left][p].first, ps));
        p++;
    }

    while(q < m){
        t[id].pb(t[right][q]);
        ps += t[right][q].second;
        presums[id].pb(mp(t[right][q].first, ps));
        q++;
    }
}



void build(int id = 1, int l = 0, int r = N){
    if(r - l < 2){
        prime_factors(arr[l], id);
        return;
    }

    int mid = (l+r)/2;
    // error(id);
    build(2*id, l, mid);
    build(2*id + 1, mid, r);
    merge_vec(id, 2*id, 2*id+1);
}


int Greater_equal(vector<pii> &a, int B){
	int lo = 0;
	int hi = sz(a) - 1;
	
	int index = -1;
	while(lo<=hi){
		int mid = lo + (hi-lo)/2;
		
		if(a[mid].first < B){
			lo = mid + 1;
		}
		else{
			index = mid;
			hi = mid -1;
		}
	}
	return index;
}

int Lesser_equal(vector<pii> &a, int B){
	int lo = 0;
	int hi = sz(a) - 1;
	
	int index = -1;
	while(lo<=hi){
		int mid = lo + (hi-lo)/2;
		
		if(a[mid].first > B){
			hi  = mid - 1;
		}
		else{
			index = mid;
			lo = mid + 1;
		}
	}
	return index;
}

int cnt(int p1, int p2, int x, int y, int id = 1, int l = 0, int r = N){
    if(x >= r || y <= l){
        return 0;
    }

    if(x <= l && r <= y){
        int res = 0;
        int pl = Greater_equal(t[id], p1);
        int pr = Lesser_equal(t[id], p2);
        if(pl != -1 and pr != -1){
            if(pl-1>=0){
                res += (presums[id][pr].second - presums[id][pl-1].second);				
            }
            else{
                res += (presums[id][pr].second);
            }
        }
        return res;
    }

    int mid = (l+r)/2;
    return cnt(p1, p2, x, y, 2*id, l, mid) + cnt(p1, p2, x, y, 2*id+1, mid, r);
}

int main(){
    #ifndef ONLINE_JUDGE
		freopen("test", "r", stdin);
	#endif
    // fastio;
    
    // cin >> N;
    scanf("%d", &N);

    arr.resize(N);
    t.resize(4*(N+1));
    presums.resize(4*(N+1));
    sieve(1000005);

    rep(i, N){
        // cin >> arr[i];
        scanf("%d", &arr[i]);
    }

    build();

    int Q;
    // cin >> Q;
    scanf("%d", &Q);

    // repA(i, 1, 7){
    // error(i);
    // tr(presums[i], it){
    //     error(it.first);
    //     error(it.second);
    // }
    // }

    rep(i, Q){
        int l, r, x, y;
        // cin >> l >> r >> x >> y;
        scanf("%d%d%d%d", &l, &r, &x, &y);
        // error(l);
        // cout << cnt(x, y, l-1, r) << endl;
        printf("%d\n", cnt(x, y, l-1, r));
    }

    return 0;
}
