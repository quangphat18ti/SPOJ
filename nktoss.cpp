/// ý tưởng : Xây dựng mảng f[i] là số dãy thỏa xét đến kí tự thứ i.
/// Ta nhận thấy rằng : f[i-1] thỏa thì thêm 0 hay 1 vào vẫn sẽ thỏa.
/// => f[i] = f[i-1] * 2;
/// Nhận xét 2 : Nếu mà xét tới thằng i mới xuất hiện dãy với độ dài k
/// => f[i] += lt[i - k - 1]. Bởi thằng thứ  i - k phải là 0.Nó không thể là 1
/// Và đương nhiên trường hợp này sẽ bị trùng với các đoạn thỏa với độ dài
/// f[ i - k - 1 ]

/// Công thức truy hồi cuối cùng : f[i] = 2*f[i-1] + lt[i - k - 1] - f[i - k - 1]


#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define pb push_back
#define db double
#define LT "nktoss"
#define fi first
#define se second
#define mp make_pair
#define maxn 10005
#define For( i , a , b ) for( int i = int(a) ; i <= int(b) ; i++ )
#define FOr( i , a , b ) for( int i = int(a) ; i >= int(b) ; i-- )

typedef vector<int> vi;
typedef pair<int,int> pii;

int i , j , n , m , k;
vi f[maxn];
vi lt[maxn];
int mod = 1e9;

void Push ( vi &a , int b ) { a.pb(b); }

vi operator + ( vi a , vi b )
{
    vi ans;

    int n = a.size() - 1 , m = b.size() - 1;
    ll carry = 0;

    For( i , 0 , max(  n , m ) )
    {
        if( i <= n ) carry += a[i];
        if( i <= m ) carry += b[i];
        ans.pb( carry % mod );
        carry /= mod;
    }

    if( carry ) ans.pb( carry );

    return ans;
}

vi operator - ( vi a , vi b )
{
    int n = a.size() - 1 , m = b.size() - 1;
    vi ans;

    ll carry = 0;
    For( i , 0 , n )
    {
        carry += a[i];
        if( i <= m ) carry -= b[i];
        if( carry < 0 ) a[i+1]-- , carry += mod ;
        ans.pb( carry % mod );
        carry /= mod;
    }

    while( ans.size() > 1 && ans.back() == 0 ) ans.pop_back();

    return ans;
}

vi operator * ( vi a , vi b )
{
    int n = a.size() - 1 , m = b.size() - 1;
    vi ans( n + m + 2 , 0 );

    For( i , 0 , n )
    {
        ll carry = 0;
        For( j , 0 , m )
        {
            carry += ans[i + j] + 1ll * a[i] * b[j];
            ans[i + j] = carry % mod;
            carry /= mod;
        }

        if( carry > 0 ) ans[ i + m + 1 ] += carry;
    }

    while( ans.size() > 1 && ans.back() == 0 ) ans.pop_back();

    return ans;
}

void xuat( vi a )
{
    printf("%d",a.back());
    FOr( i , a.size() - 2 , 0 ) printf("%0.9d" , a[i]);
    printf( "\n" );
}

void nhap()
{
    cin >> n >> k;
}

void process()
{
    Push( lt[0] , 1 );
    For( i , 1 , n )
    {
        vi b; Push (  b , 2 );
        lt[i] = lt[i-1] * b;
    }
}

void xuli()
{
    process();

    For( i , 0 , k - 1 ) Push( f[i] , 0 );
    Push( f[k] , 1 );

    For( i , k + 1 , n )
    {
        vi tam; Push( tam , 2 );
        f[i] = f[i-1] * tam;
        f[i] = f[i] + lt[i - k - 1];
        f[i] = f[i] - f[i - k - 1];
    }

    xuat( f[n] );
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen(LT".inp","r",stdin);
//    freopen(LT".out","w",stdout);
    nhap();
    xuli();
}
