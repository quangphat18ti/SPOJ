#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define db double
#define maxn 30005
#define LT "area"
#define For(i , a , b) for(int i = int(a) ; i <= int(b) ; i++)
#define FOr(i , a , b) for(int i = int(a) ; i >= int(b) ; i--)
#define fi first
#define se second

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;

struct rect
{
    int x1 , y1; /// trái dưới
    int x2 , y2; /// phải trên
};
rect a[maxn];

struct canh
{
    int x , y1 , y2 , loai;

    bool operator < (canh a)
    {
        return x < a.x || ( x == a.x && loai < a.loai );
        /// sort theo tọa độ x. Nếu x bằng nhau thì ưu tiên cạnh đóng trước.
    }
};
vector<canh> b;

pii IT[maxn * 4];
/// IT[i].fi là số lượng cạnh phủ lên toàn đoạn từ l -> r
/// IT[i].se là số lượng đoạn từ l -> r được phủ.

void nhap()
{
    cin >> n;
    For( i , 1 , n )
    {
        int x1 , y1 , x2 , y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a[i] = { x1 , y1 , x2 , y2 };
    }
}

void Build_canh()
{
    For( i , 1 , n )
    {
        b.pb( { a[i].x1 , a[i].y1 , a[i].y2 , 1 } ); /// cạnh mở
        b.pb( { a[i].x2 , a[i].y1 , a[i].y2 , -1 } ); /// cạnh đóng
    }
    sort( b.begin() , b.end() );
}

void update( int id , int l , int r , int u , int v , int gt )
{
    if( l > v || r < u ) return;
    if( l >= u && r <= v )
    {
        IT[id].fi += gt;
        if( IT[id].fi ) IT[id].se = r - l + 1;
        /// Nếu có ít nhất 1 cạnh phủ lên đoạn từ l -> r thì số lượng đoạn phủ là r - l + 1
        else
        {
            /// Nếu không còn nút con thì sẽ trả về 0.
            /// Nếu còn nút con thì sẽ trả về tổng của 2 nút con

            if( l == r ) IT[id].se = 0;
            else IT[id].se = IT[id*2].se + IT[id*2 + 1].se;
        }
        return;
    }

    int mid = (l + r) >> 1;
    update( id*2 , l , mid , u , v , gt );
    update( id*2 + 1 , mid+1 , r , u , v , gt );

    /// Nếu chưa có cạnh phủ qua và còn nút con thì sẽ update
    if( !IT[id].fi && l < r ) IT[id].se = IT[id*2].se + IT[id*2 + 1].se;
}

void xuli()
{
    ll ans = 0;
    For( i , 0 , b.size() - 1 )
    {
       /// IT[1].se là tổng số đoạn được phủ.
       if( i > 0 ) ans = ans + IT[1].se * ( b[i].x - b[i - 1].x );
       update( 1 , 0 , 30000 , b[i].y1 , b[i].y2 - 1 , b[i].loai );
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen(LT".inp","r",stdin);
//    freopen(LT".out","w",stdout);
    nhap();
    Build_canh();
    xuli();
}
