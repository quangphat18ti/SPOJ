#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define LT "phonelst"
#define maxn 100005
#define endl "\n"
#define pb push_back
#define For( i , a , b ) for( int i = int(a) ; i <= int(b) ; i++ )
#define FOr( i , a , b ) for( int i = int(a) ; i >= int(b) ; i-- )
#define fi first
#define se second
#define mp make_pair
typedef pair<int,int> pii;
typedef vector<int> vi;

int i , j , n , m , k;
string s[10005];
int nnote = 0;

struct note
{
    int d[10];
    int f;
};
note a[maxn];

void taonut()
{
    ++nnote;
    For( i , 0 , 9 ) a[nnote].d[i] = 0;
    a[nnote].f = 0;
}

int taocay( string s )
{
    s = " " + s;
    int tam = 1;
    For( i , 1 , s.size()-1 )
    {
        int res = s[i] - '0';
        if( a[tam].d[res] == 0 )
        {
            taonut();
            a[tam].d[res] = nnote;
        }
        tam = a[tam].d[res];
        if( a[tam].f ) return -1;
    }
    a[tam].f = 1;
    return 1;
}

bool ss( string A , string B )
{
    return A.size() < B.size();
}

void nhap()
{
    nnote = 0;
    taonut();
    cin >> n;
    For( i , 1 , n ) cin >> s[i];
    sort( s+1 , s+n+1 , ss );
}

void xuli()
{
    For( i , 1 , n )
    {
        int tam = taocay( s[i] );
        if( tam == -1 )
        {
            cout << "NO\n"; return;
        }
    }
    cout << "YES\n";
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
