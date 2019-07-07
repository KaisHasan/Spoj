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

/*
you can solve it using game theory. It has got two states: winning and losing.
For n=1, it can be clearly seen that player_1 is the winner.
For n>1, let us assume player_1 to be the loser. Hence after player_1 plays his move,
it will lead to a winning state. Take for eg. for n>1 , player_1 picks up 1,
then player_2 picks up x. Since, we have assumed that player_2 is the winner,
we can say that the move made by player_2 leads to losing state.
But if player_1 picks up x in the first move, player_2 will be in the losing state.This is a contradiction.
Hence the first player always wins.
*/


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);


    int t;
    sc(t);
    while(t--){
        int n;
        sc(n);
        int player;
        sc(player);
        if(player == 0)
            printf("Airborne wins.");
        else
            printf("Pagfloyd wins.");
        blank;
    }


return 0;
}
