/// Cho n xâu. gọi s' là xâu ngược của s
/// 2 xâu được gọi là được biệt nếu a < b && a' > b'
/// Đếm số lượng xâu được biệt

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
#define LT "mchaos"
#define maxn 200005

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
string S[maxn] , S1[maxn];
pii a[maxn];
map <string,int> dd;
set <string> st;

int Fen[maxn];

string Rev( string s )
{
    string ans = "";
    FOr( i , s.size() - 1 , 0 ) ans += s[i];
    return ans;
}

void nhap()
{
    cin >> n;
    For( i , 1 , n ) cin >> S[i] , S1[i] = Rev(S[i]);
    For( i , 1 , n ) st.insert( S[i] ) , st.insert( S1[i] );

    m = 0;
    for( string tam : st )
    {
        m++;
        dd[tam] = m;
    }

    For( i , 1 , n ) a[i].fi = dd[S[i]] , a[i].se = dd[S1[i]];
}

bool ss( pii a , pii b )
{
    return a.fi > b.fi;
}

void update( int i , int gt )
{
    while( i <= m )
    {
        Fen[i] += gt;
        i += i & -i;
    }
}

int get( int i )
{
    int ans = 0;
    while( i >= 1 )
    {
        ans += Fen[i];
        i -= i & -i;
    }
    return ans;
}

void xuli()
{
    sort( a + 1 , a + n + 1 , ss );

    ll ans = 0;
    For( i , 1 , n )
    {
        int j =  i;
        while( i <= n && a[i].fi == a[j].fi ) i++; i--;

        For( ires , j , i ) ans += get( a[ires].se - 1 );
        For( ires , j , i ) update( a[ires].se , 1 );
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
