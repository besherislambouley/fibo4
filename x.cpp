/*
 * https://github.com/thecodingwizard/competitive-programming/blob/master/Infoarena/fibo4.cpp 
*/
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 400
//#define mp make_pair
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
#define all(x) x.begin(), x.end()
#define gc getchar_unlocked
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll inf=1e18;
const ll mod=666013;
const ld pai=acos(-1);
void setupIO(const string &PROB = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (PROB.length() != 0) {
        ifstream infile(PROB + ".in");
        if (infile.good()) {
            freopen((PROB + ".in").c_str(), "r", stdin);
            freopen((PROB + ".out").c_str(), "w", stdout);
        }
    }
}
ll n , q , sz = inf ;
ll a [1000009] , dp [2000009] ;
ll fib ( ll x ) {
	if ( x > sz ) return fib ( x % sz ) ;
	ll &ret = dp [x] ;
	if ( ret != -1 ) return ret ;
	if ( x <= 1 ) ret = 1 ;
	else ret = fib ( x - 1 ) + fib ( x - 2 ) ;
	ret %= mod ;
	return ret ; 
}
int main () {
	setupIO("fibo4") ;
	mem ( dp , -1 ) ;
	cin >> n >> q ;
	for ( int i = 2 ; i <= 2000000 ; i ++ ) {
		if ( fib ( i ) == 1 && fib ( i + 1 ) == 1 ) {
			sz = i ;
			break ;
		}
	}
	while ( q -- ) {
		ll l , r , k ;
		cin >> l >> r >> k ;
		l -- , r -- , k -- ;
		a [l] += fib ( k ) ;
		a [l+1] += fib ( k + 1 ) - fib ( k ) ;
		a [r+1] -= fib ( k + ( r - l ) + 1 ) ;
		a [r+2] -= fib ( k + ( r - l ) ) ;
		a [l] %= mod ;
		a [l+1] %= mod ;
		a [r] %= mod ;
		a [r+1] %= mod ;
	}
	for ( int i = 0 ; i < n ; i ++ ) {
		a [i] = a [i] + ( i > 0 ? a [i-1] : 0 ) + ( i > 1 ? a [i-2] : 0 ) ;
		a [i] %= mod ;
		if ( a [i] < 0 ) a [i] += mod ;
	}
	for ( int i = 0 ; i < n ; i ++ ) cout << a [i] << " " ;
	cout << endl ;
}
