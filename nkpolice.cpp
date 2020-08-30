
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 100005
#define LT "policija"
#define FR freopen
#define pb push_back
#define For(i,a) for(int i=1;i<=a;i++)
#define FOr(i,a,b) for(int i=a;i<=b;i++)
int i,j,n,k,m,t,deepmax=-1,maxx=-1,res;
int h[maxn],cha[maxn],f[maxn][20],fi[maxn];
int low[maxn],cnt=0,num[maxn];
vector <int> a[maxn];
void nhap()
{
    scanf("%d %d",&n,&m);
    int x,y;
    For(i,m)
    {
        scanf("%d %d",&x,&y);
        a[x].pb(y);
        a[y].pb(x);
    }
}
int get(int k)
{
    return (1<<k);
}
void deep(int u)
{
    cnt++;
    num[u]=cnt;
    low[u]=cnt;
    deepmax=max(deepmax,h[u]);
    for(int i=0;i<a[u].size();i++)
    {
        int v=a[u][i];
        if(v!=cha[u])
        {
            if(cha[v]==0)
            {
                cha[v]=u;
                h[v]=h[u]+1;
                deep(v);
                low[u]=min(low[u],low[v]);
            }
            else low[u]=min(low[u],num[v]);
        }
    }
    fi[u]=cnt;
}
void khoitao()
{
    For(i,n)
    {
        f[i][0]=cha[i];
    }
    for(int j=1;j<=log2(deepmax);j++)
    {
        For(i,n)
        {
            f[i][j]=f[f[i][j-1]][j-1];
        }
    }
}
void process()
{
    deepmax=-1;
    cnt=0;
    For(i,n)
    {
        if(cha[i]==0)
        {
            cha[i]=i;
            deep(i);
        }
    }
}
int jump(int u,int kc)
{
    for(int i=log2(kc);i>=0;i--)
    {
        if( (kc ^ get(i)) < kc )
        {
            u=f[u][i];
        }
    }
    return u;
}
int ktcon(int v,int u)
{
    if(num[u]<=num[v] && fi[u]>=fi[v]) return 1;
    return 0;
}
void solve1()
{
    int x,y,u,v;
    scanf("%d %d %d %d",&x,&y,&u,&v);
    if(ktcon(u,v)==1) swap(u,v);
    if(u!=cha[v]) // cÃ³ Ã­t nháº¥t 2 con ÄÆ°á»ng tá»i u
    {
        printf("yes\n");
        return;
    }
    // v cháº¯c cháº¯n lÃ  con cá»§a u
    if(low[v]<num[v]) // u,v khÃ´ng pháº£i lÃ  cáº§u
    {
        printf("yes\n");
        return;
    }
    if( ktcon(x,v) == ktcon(y,v) ) //x vÃ  y lÃ  con cá»§a v hoáº·c lÃ  x vÃ  y Äá»u khÃ´ng pháº£i lÃ  con cá»§a v
    {
        printf("yes\n");
        return;
    }
    printf("no\n");
    return;
}
void solve2()
{
    int x,y,u;
    scanf("%d %d %d",&x,&y,&u);
    if(ktcon(x,u)==0 && ktcon(y,u)==0)
    {
        printf("yes\n");
        return;
    }
    if(ktcon(x,u)==1 && ktcon(y,u)==1)
    {
        int kc1,kc2;
        kc1=h[x]-h[u]-1;
        kc2=h[y]-h[u]-1;
        int a=jump(x,kc1);
        int b=jump(y,kc2);
        if(a==b)
        {
            printf("yes\n");
            return;
        }
        if( low[a]<num[u] && low[b]<num[u] ) //cÃ³ thá» thÃ´ng qua 2 Äá»nh khÃ¡c u Äá» tá»i x vÃ  y
        {
            printf("yes\n");
            return;
        }
        printf("no\n");
        return;
    }
    if(ktcon(y,u)==1) swap(x,y);
    int kc=h[x]-h[u]-1;
    int a=jump(x,kc);
    if(low[a]<num[u]) // cÃ³ Ã­t nháº¥t 1 con ÄÆ°á»ng tá»i a mÃ  khÃ´ng Äi qua u
    {
        printf("yes\n");
        return;
    }
    printf("no\n");
    return;
}
int main()
{
    nhap();
    process();
    khoitao();
    scanf("%d",&t);
    int loai;
    For(z,t)
    {
        scanf("%d",&loai);
        if(loai==1)
        {
            solve1();
        }
        else solve2();
    }
}
