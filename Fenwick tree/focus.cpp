/// Cho 3 truy vấn.
///Truy vấn 1 : Thêm 1 số vào hàng đợi
///Truy vấn 2 : Xóa 1 số khỏi hàng đợi
///Truy vấn 3 : Hỏi số lớn thứ k trong đoạn từ a -> b

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
#define LT "focus"
#define maxn 600005

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
string s;

struct query
{
    int loai;
    int a[5];
};
query a[maxn];

vi st;
map <int,int> dd;
int nhan[maxn];

int IT[maxn * 4];

void nhap()
{
    cin >> n;
    For( i , 1 , n )
    {
        char tam; cin >> tam;
        if( tam == '+' )
        {
            a[i].loai = 1;
            cin >> a[i].a[1];
            st.pb( a[i].a[1] );
        }
        else if( tam == '-' )
        {
            a[i].loai = 2;
            cin >> a[i].a[1];
            st.pb( a[i].a[1] );
        }
        else
        {
            a[i].loai = 3;
            For( j , 1 , 3 ) cin >> a[i].a[j] , st.pb( a[i].a[j] );
        }
    }
}

void nen()
{
    sort( st.begin() , st.end() );
    m = unique( st.begin() , st.end() ) - st.begin() - 1;
    For( i , 0 , m )
    {
        dd[st[i]] = i + 1;
        nhan[i + 1] = st[i];
    }
    m++;

    For( i , 1 , n )
    {
        if( a[i].loai == 3 )
        {
            For( j , 2 , 3 ) a[i].a[j] = dd[a[i].a[j]];
        }
        else a[i].a[1] = dd[a[i].a[1]];
    }
}

void update( int id , int l , int r , int vt , int gt )
{
    if( l > vt || r < vt ) return;
    if( l == r )
    {
        IT[id]+= gt;
        return;
    }

    int mid = (l + r) >> 1;
    update( id*2 , l , mid , vt , gt );
    update( id*2+1 , mid + 1 , r , vt , gt );
    IT[id] = IT[id*2] + IT[id*2 + 1];
}

int get( int id, int l, int r, int u , int v )
{
    if (u > v) return 0;
    if( l > v || r < u ) return 0;
    if( l >= u && r <= v ) return IT[id];
    int mid = (l+r) >> 1;
    return get( id * 2 , l , mid , u , v ) + get( id * 2 + 1 , mid + 1 , r , u , v );
}

void solve1( int t )
{
    int x = a[t].a[1];
    update( 1 , 1 , m , x , 1 );
}

void solve2( int t )
{
    int x = a[t].a[1];
    update( 1 , 1 , m , x , -1 );
}

int get_gt( int id , int l , int r ,  int gt )
{
    if( l == r ) return l;
    int mid = (l + r) >> 1;
    if (gt > IT[id * 2]) return get_gt(id * 2 + 1, mid + 1, r, gt - IT[id * 2]);
    else return get_gt(id * 2, l, mid, gt);
}

void solve3( int t )
{
     k = a[t].a[1];
     int l = a[t].a[2] , r = a[t].a[3];
     if( l > r || get( 1 , 1 , m , l , r ) < k ) { cout << 0 << endl; return; }
     cout << nhan[get_gt( 1 , 1 , m , k + get(1, 1, m, 1, l - 1))] << endl;
}

void xuli()
{
    For( i , 1 , n )
    {
        if( a[i].loai == 1 ) solve1(i);
        else if( a[i].loai == 2 ) solve2(i);
        else solve3(i);
    }
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
        nen();
        xuli();
    }
}

