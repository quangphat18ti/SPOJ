#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define LT "chain2"
#define maxn 250005
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
int f[maxn] , ans = 0;

struct note
{
    int d[30];
    int f;
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
        int res = s[i] - 'a' + 1;
        if( a[tam].d[res] == 0 )
        {
            taonut();
            a[tam].d[res] = nnote;
        }
        tam = a[tam].d[res];
    }
    a[tam].f ++;
}

void nhap()
{
    taonut();
    cin >> n;
    For( i , 1 , n )
    {
        cin >> s ;
        taocay(s);
    }
}

void dfs( int u )
{
    For( i , 1 , 26 )
    {
        int v = a[u].d[i];
        if( v == 0 ) continue;
        dfs(v);
    }

    f[u] = 0;
    For( i , 1 , 26 )
    {
        int v = a[u].d[i];
        if( v == 0 ) continue;
        f[u] = max ( f[u] , f[v] );
    }
    f[u] += a[u].f;
}

void xuli()
{
    dfs(1);
    cout << f[1] << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen(LT".inp","r",stdin);
//    freopen(LT".out","w",stdout);
    nhap();
    xuli();
}
