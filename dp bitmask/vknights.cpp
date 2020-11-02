///  Cho 1 mảng 3 * n. Tìm số cách đặt nhiều quân mã không nằm trong những ô cấm
/// và không ăn lên nhau

/// Solve
/// Thay vì 1 hàng lưu trữ trạng thái 3 ô trên hàng đó thì ta có thể lưu 1 hàng là
/// trạng thái của 2 hàng liên tiếp. Và sau đó chỉ cần duyệt hàng i và i - 2.

#include<bits/stdc++.h>
using namespace std;
#define nhat "VKNIGHTS"
#define ll long long
#define db double
int n,re=0;
ll kq=0;
int a[4][105],c[3][4];
struct ii
{
    int gt;
    ll sl;
};ii f[105][64];
int dx[8]={1,1,2,2,-2,-2,-1,-1};
int dy[8]={2,-2,1,-1,1,-1,2,-2};
bool check()
{
    for(int i=0;i<3;i++)
        for(int j=0;j<4;j++)
            for(int z=0;z<8;z++)
            {
                int in=i+dx[z],jn=j+dy[z];
                if(in<0||jn<0||in>2||jn>3) continue;
                if(c[i][j]*c[in][jn]) return 1;
            }
    return 0;
}
int main()
{
//    freopen(nhat".inp","r",stdin);
//    freopen(nhat".out","w",stdout);
    scanf("%d",&n);
    a[1][0]=a[2][0]=a[3][0]=1;
    for(int i=1;i<=n;i++)
    {
        int x; scanf("%d",&x);
        if(x) a[x][i]=1;
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<64;j++)
        {
            int cc=0;
            for(int l=0;l<3;l++)
            {
                for(int r=0;r<2;r++)
                {
                    int tam=l*2+r;
                    int x=(j>>(tam))&1;
                    c[l][r+2]=x;
                    if(x*a[l+1][i-1+r]) {cc=1; break;}
                }
                if(cc) break;
            }
            if(cc) continue;
            if(i<=2)
            {
                if(check()) continue;
                int d=0;
                for(int l=0;l<3;l++)
                    for(int r=2;r<4;r++) d+=c[l][r];
                f[i][j]={d,1};
                re=max(re,d);
                continue;
            }
            for(int p=0;p<64;p++)
            {
                cc=0;
                for(int l=0;l<3;l++)
                {
                    for(int r=0;r<2;r++)
                    {
                        int tam=    l*2+r;
                        int x=(p>>(tam))&1;
                        c[l][r]=x;
                        if(x*a[l+1][i-3+r]) {cc=1; break;}
                    }
                    if(cc) break;
                }
                if(cc) continue;
                if(check()) continue;
                int d=0;
                for(int l=0;l<3;l++)
                    for(int r=2;r<4;r++) d+=c[l][r];
                if(f[i][j].gt<f[i-2][p].gt+d) f[i][j]={f[i-2][p].gt+d,f[i-2][p].sl};
                else if(f[i][j].gt==f[i-2][p].gt+d) f[i][j].sl+=f[i-2][p].sl;
                re=max(re,f[i][j].gt);
            }
        }
    for(int j=0;j<64;j++) if(f[n][j].gt==re) kq+=f[n][j].sl;
    printf("%d %lld",re,kq);
}
