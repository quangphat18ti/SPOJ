//Tóm tắt : Cho n điểm trên mặt phẳng tọa độ. Tìm 3 bộ điểm thằng hàng
/// Chú ý : phải nhớ là chia ở dạng số thực nếu không thì nó sẽ ra giá trị nguyên
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pb push_back
#define LT "qbpoint"
#define maxn 2005
#define For( i , a , b ) for( int i = int(a) ; i <= int(b) ; i++ )
#define FOr( i , a , b ) for( int i = int(a) ; i >= int(b) ; i-- )
#define fi first
#define se second
#define mp make_pair

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;

int i , j , n , m , k;

db vc = 1e15;

struct diem
{
    int x , y;
};
diem a[maxn];

void nhap()
{
    cin >> n;
    For( i , 1 , n ) cin >> a[i].x >> a[i].y;
}

int solve( vector<diem> &U )
{
    vector<db> a;
    for( diem tam : U )
    {
        if( tam.y == 0 ) a.pb( vc );
        else a.pb( 1.00 * tam.x / tam.y );
    }

    sort( a.begin() , a.end() );

    int ans = 0;

    int i = 0 , n = a.size() - 1;
    while( i <= n )
    {
        int j = i;
        while( i <= n && a[j] == a[i] ) i++;
        int kc = i - j;
        ans += kc * (kc - 1) / 2;
    }

    return ans;
}

void xuli()
{
    ll ans = 0;
    For( i , 3 , n )
    {
        vector<diem> U;
        For( j , 1 , i - 1 ) U.pb( { a[j].x - a[i].x , a[j].y - a[i].y } );
        ans += solve(U);
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen(LT".inp","r",stdin);
//    freopen(LT".out","w",stdout);
    int t = 1;
    //cin >> t;
    while( t-- )
    {
        nhap();
        xuli();
    }
}
