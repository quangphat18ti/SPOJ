/// Đếm số cặp số a,b sao cho a+b - gcd(a,b) = n

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pb push_back
#define For( i , a , b ) for(int i = int(a) ; i <= int(b) ; i++)
#define FOr( i , a , b ) for(int i = int(a) ; i >= int(b) ; i--)
#define fi first
#define se second
#define mp make_pair
#define LT "squares"
#define maxn

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
int ans = 0;

void nhap()
{
    cin >> n;
}

int Count( int s )
{
    int ans = 0;
    For( i , 1 , s / 2 )
    {
        int j = s - i;
        if( __gcd( i , j ) == 1 ) ans++;
    }
    return ans;
}

void xuli()
{
    For( i , 1 , n )
    {
        int m = n + i;
        if( m % i != 0 ) continue;
        m /= i;
        ans += Count( m );
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen(LT".inp","r",stdin);
//    freopen(LT".out","w",stdout);
    int t = 1;
//    cin >> t;
    while( t-- )
    {
        nhap();
        xuli();
    }
}
