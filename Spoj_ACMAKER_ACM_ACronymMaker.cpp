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
vector<int> months = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

map<string , bool> forb;
int dp[155][155][155][2];
vector<string> v;
int sz;
string abb;
int solve(int iab , int strID , int id , int flg = 0){
    if(strID == (int)v.size())
        return iab == sz;
    if(iab == sz){
        if(strID == (int)v.size() - 1)
            return flg;
        return 0;
    }
    int &res = dp[iab][strID][id][flg];
    if(res != -1)
        return res;
    res = 0;
    int nxt = id + 1;
    int add = 0;
    if(nxt == (int)v[strID].size()){
        nxt = 0;
        add = 1;
    }
    if(nxt || flg)
        res += solve(iab , strID + add , nxt , (add)? 0 : flg);
    if(abb[iab] == v[strID][id])
        res += solve(iab + 1 , strID + add , nxt , 1 - add);
    return res;
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    while(1){
        int n;
        sc(n);
        if(!n)
            break;
        forb.clear();
        for(int i = 0 ; i < n ; ++i){
            string s;
            cin>>s;
            forb[s] = true;
        }
        string plapla;
        getline(cin , plapla);
        while(1){
            string line;
            line.clear();
            getline(cin , line);
            if(line == "LAST CASE")
                break;
            istringstream iss(line);
            iss>>abb;
            sz = abb.size();
            for(int i = 0 ; i < sz ; ++i)
                abb[i] = tolower(abb[i]);
            string temp;
            v.clear();
            while(iss>>temp){
                if(!forb[temp])
                    v.pb(temp);
                temp.clear();
            }
            mem(dp,-1);
            int ans = solve(0 , 0 , 0);
            for(int i = 0 ; i < sz ; ++i)
                abb[i] = toupper(abb[i]);
            printf("%s " , abb.c_str());
            if(ans){
                printf("can be formed in %d ways"  , ans);
            }
            else{
                printf("is not a valid abbreviation");
            }
            blank;
        }

    }



return 0;
}
