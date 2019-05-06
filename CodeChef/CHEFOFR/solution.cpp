#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<lli> vli;
typedef vector<pii> vii;

const int MOD	= 1e9 + 7;
const double PI = acos(-1.0);

#define fastio			ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define fill(a)  memset(a, 0, sizeof (a))

double tick(){static clock_t oldt,newt=clock();double diff=1.0*(newt-oldt)/CLOCKS_PER_SEC;oldt=newt;return diff;}
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }
template<typename T>T power(T e, T n, T m){T x=1,p=e;while(n){if(n&1)x=mul(x,p,m);p=mul(p,p,m);n>>=1;}return x;}
int mod_neg(int a, int b, int c){int res;if(abs(a-b)<c)res=a-b;else res=(a-b)%c;return(res<0?res+c:res);}
template<typename T>T extended_euclid(T a, T b, T &x, T &y){T xx=0,yy=1;y=0;x=1;while(b){T q=a/b,t=b;b=a%b;a=t;\
t=xx;xx=x-q*xx;x=t;t=yy;yy=y-q*yy;y=t;}return a;}
template<typename T>T mod_inverse(T a, T n){T x,y,z=0;T d=extended_euclid(a,n,x,y);return(d>1?-1:mod_neg(x,z,n));}

vli dp[51][51];

vli get_part(const vli &arr, int N, int curr, int k){
    if(!dp[curr][k].empty()){
        return dp[curr][k];
    }
    if(k == 1){
        lli sm = 0;
        repA(i, curr, N-1){
            sm += arr[i];
        }
        dp[curr][k].push_back(sm);
        return dp[curr][k];
    }
    if(k > (N - curr)){
        vli temp;
        return temp;
    }


    lli sm = 0;
    repA(j, curr+1, N-1){
        vli tp = get_part(arr, N, j, k-1);
        sm += arr[j-1];
        set<lli> s;
        if(!tp.empty()){
            tr(tp, it){
                lli temp_ans = *it & sm;
                s.insert(temp_ans);
            }
        }
        dp[curr][k].insert(dp[curr][k].begin(), all(s));
    }

    return dp[curr][k];
}

int main(){
    #ifndef ONLINE_JUDGE
		freopen("test", "r", stdin);
	#endif
    fastio;
    
    int N;
    cin >> N;

    lli A[N];
    rep(i, N){
        cin >> A[i];
    }

    int Q;
    cin >> Q;

    while(Q-- > 0){
        int K;
        cin >> K;

        vli arr;
        lli temp;

        rep(i, N){
            cin >> temp;
            if(temp > 0){
                arr.push_back(temp*A[i]);   
            }
        }

        // tr(arr, it){
        //     cout << *it << " ";
        // }
        // cout << endl;

        int S = sz(arr);
        // cout << "S " << S << endl;
        // vli pref_arr;
        // temp = 0;
        // tr(arr, it){
        //     temp += *it;
        //     pref_arr.push_back(temp);
        // }


        lli ans = -1;
        if( K > S){
            ans = 0;
        }else{
            vli temp = get_part(arr, S, 0, K);
            tr(temp, it){
                ans = max(ans, *it);
            }
        }

        rep(i, S){
            rep(j, K+1){
                dp[i][j].clear();
            }
        }

        
        
        cout << ans << endl;
    }
    // cout<<"Execution time : "<<tick()<<"\n";
    return 0;
}
