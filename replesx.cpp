#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define maxn 400005
#define db double
#define LT "replesx"
#define endl "\n"
#define For( i , a , b ) for( int i = int(a) ; i <= int(b) ; i ++ )
#define FOr( i , a , b ) for( int i = int(a) ; i >= int(b) ; i -- )
#define fi first
#define se second
#define mp make_pair

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
int X , p;
int a[maxn];

void nhap()
{
    cin >> n >> X >> p >> k;
    For( i , 1 , n ) cin >> a[i];
    sort( a + 1 , a + n + 1 );
}

void xuli()
{
    /// Nếu ban đầu đã giống nhau thì không cần thay đổi
    if( a[p] == X ) { cout << 0 << endl; return; }

    /// Nếu p >= k thì chỉ có thể tăng a[p] lên
    /// Nếu muốn a[p] == X thì ta chỉ cần loại bỏ những thằng nhỏ hơn X nằm sau vị trí p
    /// Đương nhiên cách bỏ dễ dàng nhất là cứ chèn số lớn nhất để nó chạy về cuối

    if( p >= k && a[p] <= X )
    {
        int ans = 0;
        For( i , p , n ) ans += ( a[i] < X );
        cout << ans << endl;
        return;
    }

    /// Nếu p <= k thì chỉ có thể giảm a[p]
    /// Nếu muốn a[p] == X thì cần bỏ những thằng lớn hơn X từ 1 -> p
    /// vì ta chỉ cần thay đổi những giá trị này. Và đương nhiên để dễ dàng thì cứ thay đổi
    /// từ những bài nhỏ nhất

    if( p <= k && a[p] >= X )
    {
        int ans = 0;
        For( i , 1 , p ) ans += ( a[i] > X );
        cout << ans << endl;
        return;
    }

    cout << - 1 << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen(LT".inp","r",stdin);
//    freopen(LT".out","w",stdout);
    int t; cin >> t;
    while( t-- )
    {
        nhap();
        xuli();
    }
}
