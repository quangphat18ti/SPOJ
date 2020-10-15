#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pb push_back
#define maxn 505
#define endl "\n"
#define LT "c11beau"
#define fi first
#define se second
#define mp make_pair
#define For( i , a , b ) for( int i = int(a) ; i <= int(b) ; i++ )
#define FOr( i , a , b ) for( int i = int(a) ; i >= int(b) ; i-- )

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;


int i , j , n , m , k;
ll maxxA , maxxB , countA , countB;

void nhap()
{
    cin >> countA >> countB >> maxxA >> maxxB;
}

void xuli()
{
    if( maxxA == 0 ) countA = 0;
    if( maxxB == 0 ) countB = 0;

    if( countA > countB )
    {
        swap ( countA , countB );
        swap ( maxxA , maxxB );
    }

    cout << countA + min( countB , (countA + 1) * maxxB ) << endl;
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
