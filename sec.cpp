#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define LT "sec"
#define maxn 1000005
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
string s;
int nnote = 0;

struct note
{
    int d[2];
    int f , c;
};
note a[maxn];

void taonut()
{
    ++nnote;
}

void taocay( string s )
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
        a[tam].c ++;
    }
    a[tam].f ++;
}

void nhap()
{
    taonut();
    cin >> n >> m;
    For( i , 1 , n )
    {
        int sl; cin >> sl;
        s = "";
        For( j , 1 , sl )
        {
            char tam; cin >> tam;
            s += tam;
        }
        taocay(s);
    }
}

void solve( string s )
{
    int ans = 0;
    s = " " + s;
    int tam = 1;
    For( i , 1 , s.size()-1 )
    {
        int res = s[i] - '0';
        int v = a[tam].d[res];
        if( v == 0 )
        {
            cout << ans << endl;
            return;
        }
        tam = v;
        ans += a[tam].f;
    }
    ans = ans + a[tam].c - a[tam].f;
    cout << ans << endl;
}

void xuli()
{
    while( m-- )
    {
        s = "";
        int sl; cin >> sl;
        For( i , 1 , sl )
        {
            char tam; cin >> tam;
            s += tam;
        }

        solve(s);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen(LT".inp","r",stdin);
//    freopen(LT".out","w",stdout);
    nhap();
    xuli();
}
