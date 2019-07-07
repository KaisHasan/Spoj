#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int , int> pi;
typedef pair<double , int > dpi;
typedef pair<long long , long long> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef unsigned long long ull;
#define MP  make_pair
#define mem(a , v)  memset(a , v , sizeof(a))
#define all(v)	((v).begin()), ((v).end())
#define sc(a) scanf("%d",&a)
#define scl(a) scanf("%lld",&a)
#define scd(a) scanf("%lf" , &a)
#define sch(a) scanf("%c" , &a)
#define blank printf("\n")
#define pla printf("plapla\n")
#define pb push_back
#define INF 1e9
#define EPS 1e-9
vector<int> months = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

//seive
// O(n log log n)
ll SIZE;
bitset<2000010> isprime;
vi primes;
void seive(ll n){
    SIZE = n + 1;
    isprime.set();
    isprime[0] = isprime[1] = 0;
    for(ll i = 2 ; i <= SIZE ; ++i){
        if(isprime[i]){
            for(ll j = i * i ; j <= SIZE ; j += i)
                isprime[j] = 0;
            primes.pb((int)i);
        }
    }
}

// O(sqrt(n))
bool is_prime(ll n){
    if(n <= SIZE)
        return isprime[n];
    int id = 0;
    ll p = primes[0];
    while(p * p <= n){
        if(n % p == 0)
            return 0;
        p = primes[++id];
    }
    return 1;
}

int len;
int dp[10][MAX];

ll F(int dig , int sum){
    if(!dig)
        return is_prime(sum);
    int &res = dp[dig][sum];
    if(res != -1)
        return res;
    res = 0;
    for(int i =0 ; i < 10 ; ++i){
        res += F(dig - 1 , sum + i);
    }
    return res;
}

ll solve(int x){
    string s = to_string(x);
    int n = s.size();
    len = n;
    int sum = 0;
    ll ans = 0;
    mem(dp ,-1);
    for(int i = 0 ; i < len ;++i){
        --n;
        int d = s[i] - '0';
        for(int j = 0 ; j < d ; ++j){
            ans += F(n , sum + j);
        }
        sum += d;
    }
    return ans;
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    seive(1000);
    int t;sc(t);
    while(t--){
        int a , b;
        sc(a);sc(b);
        ll res = solve(b + 1) - solve(a);
        printf("%lld\n" , res);
    }


return 0;
}
