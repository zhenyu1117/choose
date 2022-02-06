#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

int get()
{
    int f=1,sum=0;
    char q;
    for(q=getchar();(q>'9'||q<'0')&&q!='-';q=getchar());
    if(q=='-')
    {
        f=-1;
        q=getchar();
    }
    for(;q>='0'&&q<='9';q=getchar())
        sum=(sum<<3)+(sum<<1)+q-48;
    return sum*f;
}

const int maxn=1000; 
int n,p,k,x,y,sum[maxn],color[maxn],ans;

int main()
{
    freopen("choose.in","r",stdin);
    freopen("choose.out","w",stdout);

    n=getint();
	k=getint();
	p=getint();
    for(int i=1;i<=n;++i)
    {
        x=getint();
		y=getint();
        color[x]++;
        if(y<=p)
        {
            for(int j=0;j<=k-1;++j)
            {
                sum[j]+=color[j];
                color[j]=0;
            }

            ans=ans-1;
        }
        ans=ans+sum[x];
    }

    cout<<ans<<endl;
    return 0;
}
