#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define LT "dict"
#define maxn 500005
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
int check = 0;

struct note
{
    int d[30];
    int f;
    string s;
};
note a[maxn];

void taonut() { ++nnote; }
void taocay( string s )
{
    string sres = s;
    s = " " + s; n = s.size() - 1;
    int tam = 1;
    For( i , 1 , n )
    {
        int res = s[i] - 'a' + 1;
        if( a[tam].d[res] == 0 )
        {
            taonut();
            a[tam].d[res] = nnote;
        }
        tam = a[tam].d[res];
    }
    a[tam].f++;
    a[tam].s = sres;
}

void nhap()
{
    taonut();
    cin >> m;
    For( i , 1 , m )
    {
        cin >> s;
        taocay(s);
    }
}

int FIND( string s )
{
    int tam = 1;
    s = " " + s;
    For( i , 1 , s.size() - 1 )
    {
        int res = s[i] - 'a' + 1;
        if( a[tam].d[res] == 0 ) return -1;
        tam = a[tam].d[res];
    }
    return tam;
}

void dfs( int u , int p )
{
    if( u != p && a[u].f )
    {
        cout << a[u].s << endl;
        check = 1;
    }

    For( i , 1 , 26 )
    {
        int v = a[u].d[i];
        if( v == 0 ) continue;
        dfs( v , p );
    }
}

void xuli()
{
    int q; cin >> q;
    For( z , 1 , q )
    {
        cout << "Case #" << z << ":\n";
        cin >> s;
        int tam = FIND(s);
        if( tam == -1 )
        {
            cout << "No match.\n";
            continue;
        }
        check = 0;
        dfs( tam , tam );
        if( check == 0 ) cout << "No match.\n";
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
