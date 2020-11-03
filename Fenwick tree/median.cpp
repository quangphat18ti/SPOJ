/// Cho 1 dãy có n phần tử và 1 số k. Tìm tổng các trung vị của các đoạn có độ dài k

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
#define LT "median"
#define maxn 250005

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
int a[maxn];
int st , mul , add , mod = 65536;

multiset<int> Ma , Mi;

ll ans = 0;

void nhap()
{
    cin >> st >> mul >> add >> n >> k;
    a[1] = st;
    For( i , 2 , n )
    {
        a[i] = (1ll * a[i - 1] * mul + add) % mod;
    }
}

void process()
{
    ans = 0;
    Ma.clear();
    Mi.clear();
}

int canbang()
{
    while( Ma.size() > Mi.size() )
    {
        int tam = *Ma.begin();
        Ma.erase( Ma.begin() );
        Mi.insert( -tam );
    }

    while( true )
    {
        int gt1 = *Ma.begin(); gt1 = -gt1;
        int gt2 = *Mi.begin();
        if( gt1 > gt2 )
        {
            Ma.erase( Ma.begin() );
            Mi.erase( Mi.begin() );
            Mi.insert( gt1 );
            Ma.insert( -gt2 );
        }
        else break;
    }

    if( k % 2 ) return *Mi.begin();
    else return -*Ma.begin();
}

void xuli()
{
    ans = 0;
    For( i , 1 , k ) Ma.insert( -a[i] );
    ans += canbang();

    For( i , k + 1 , n )
    {
        Ma.insert( -a[i] );
        if( Mi.find( a[i - k] ) == Mi.end() )
        {
            Ma.erase( Ma.find( -a[i - k] ) );
        }
        else Mi.erase( Mi.find( a[i - k] ) );

        ans += canbang();
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen(LT".inp","r",stdin);
//    freopen(LT".out","w",stdout);
    int t = 1;
    cin >> t;
    For( z , 1 , t )
    {
        cout << "Case #" << z <<": ";
        nhap();
        process();
        xuli();
    }
}
