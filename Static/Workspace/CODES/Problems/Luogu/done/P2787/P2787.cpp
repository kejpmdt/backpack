#include<bits/stdc++.h>
#define mi2(a,b) (a<b?a:b)
#define mx2(a,b) (a>b?a:b)
#define belong(x) (((x)-1)/sqrtn+1)
#define begin(x) (((x)-1)*sqrtn+1)
#define end(x) ((x)*sqrtn)
using namespace std;
template<typename T>void read(T&ans){
    ans=0;char us=getchar();bool f=false;
    while(us!=EOF&&(us<48||us>57)){f|=(us==45);us=getchar();}
    while(us>47&&us<58){ans=(ans<<1)+(ans<<3)+(us^48);us=getchar();}
    ans=f?-ans:ans;
}
template<typename T,typename ...O>void read(T&x,O&...oth){read(x);read(oth...);}
template<typename T=signed int>T read(void){T x;read(x);return x;}
#define MAXN 55000
unsigned char ori[MAXN],sot[MAXN],chg[300];
unsigned short num[100];
int main()
{
    unsigned short n,m,l,r,ans;
    register unsigned short i;
    register unsigned char j;
    unsigned char opt,c,sqrtn;
    read(n,m);
    sqrtn=sqrt(n);
    do{c=getchar();}while((c<65||c>90)&&(c<97||c>122));
    if(c>90)c-=32;
    for(i=1;i<=n;++i){
        ori[i]=c;
        sot[i]=ori[i];
        c=getchar();
        if(c>90)c-=32;
    }
    for(j=1;begin(j)<=n;++j)sort(sot+begin(j),sot+mi2(mi2(n,end(j)),n)+1);
    while(m--){
        read(opt,l,r);
        if(opt==1){
            c=getchar();
            if(c>90)c-=32;
            ans=0;
            if(belong(l)==belong(r)){
                if(chg[belong(l)]){
                    for(i=begin(belong(l));i<=end(belong(l));++i)ori[i]=sot[i]=chg[belong(l)];
                    chg[belong(l)]=0;
                }
                for(i = l; i <= r; ++i)if (ori[i] == c)++ans;
            }
            else
            {
                if (chg[belong(l)])
                {
                    for (i = begin(belong(l)); i <= end(belong(l)); ++i)ori[i] = sot[i] = chg[belong(l)];
                    chg[belong(l)] = 0;
                }
                if (chg[belong(r)])
                {
                    for (i = begin(belong(r)); i <= end(belong(r)); ++i)ori[i] = sot[i] = chg[belong(r)];
                    chg[belong(r)] = 0;
                }
                for (i = l; i <= end(belong(l)); ++i)if (ori[i] == c)++ans;
                for (j = belong(l) + 1; j < belong(r); ++j)
                    if (chg[j])if (chg[j] == c)ans += (mi2(n, end(j)) - begin(j) + 1);
                    else ans += upper_bound(sot + begin(j), sot + mi2(n, end(j)) + 1, c) - lower_bound(sot + begin(j), sot + mi2(n, end(j)) + 1, c);
                for (i = begin(belong(r)); i <= r; ++i)if (ori[i] == c)++ans;
            }
            printf("%d\n", ans);
        }
        if (opt == 2)
        {
            c = getchar();
            if (c > 90)c -= 32;
            if (belong(l) == belong(r))
            {
                if (chg[belong(l)])
                {
                    for (i = begin(belong(l)); i <= end(belong(l)); ++i)ori[i] = sot[i] = chg[belong(l)];
                    chg[belong(l)] = 0;
                }
                for (i = l; i <= r; ++i)ori[i] = c;
                for (i = begin(belong(l)); i <= end(belong(l)); ++i)sot[i] = ori[i];
                sort(sot + begin(belong(l)), sot + mi2(end(belong(l)), n) + 1);
            }
            else
            {
                if (chg[belong(l)])
                {
                    for (i = begin(belong(l)); i <= end(belong(l)); ++i)ori[i] = sot[i] = chg[belong(l)];
                    chg[belong(l)] = 0;
                }
                if (chg[belong(r)])
                {
                    for (i = begin(belong(r)); i <= end(belong(r)); ++i)ori[i] = sot[i] = chg[belong(r)];
                    chg[belong(r)] = 0;
                }
                for (i = l; i <= end(belong(l)); ++i)ori[i] = c;
                for (j = belong(l) + 1; j < belong(r); ++j)chg[j] = c;
                for (i = begin(belong(r)); i <= r; ++i)ori[i] = c;
                for (i = begin(belong(l)); i <= end(belong(l)); ++i)sot[i] = ori[i];
                sort(sot + begin(belong(l)), sot + mi2(end(belong(l)), n) + 1);
                for (i = begin(belong(r)); i <= end(belong(r)); ++i)sot[i] = ori[i];
                sort(sot + begin(belong(r)), sot + mi2(end(belong(r)), n) + 1);
            }
        }
        if (opt == 3)
        {
            if (belong(l) == belong(r))
            {
                if (chg[belong(l)])
                {
                    for (i = begin(belong(l)); i <= end(belong(l)); ++i)ori[i] = sot[i] = chg[belong(l)];
                    chg[belong(l)] = 0;
                }
                sort(ori + l, ori + r + 1);
            }
            else
            {
                memset(num, 0x00, sizeof num);
                if (chg[belong(l)])
                {
                    for (i = begin(belong(l)); i <= end(belong(l)); ++i)ori[i] = sot[i] = chg[belong(l)];
                    chg[belong(l)] = 0;
                }
                if (chg[belong(r)])
                {
                    for (i = begin(belong(r)); i <= end(belong(r)); ++i)ori[i] = sot[i] = chg[belong(r)];
                    chg[belong(r)] = 0;
                }
                for (i = l; i <= end(belong(l)); ++i)++num[ori[i]];
                for (j = belong(l) + 1; j < belong(r); ++j)
                    if (chg[j])num[chg[j]] += mi2(n, end(j)) - begin(j) + 1;
                    else for (c = 65; c < 91; ++c)num[c] += upper_bound(sot + begin(j), sot + mi2(n, mi2(n, end(j))) + 1, c) - lower_bound(sot + begin(j), sot + mi2(n, end(j)) + 1, c);
                for (i = begin(belong(r)); i <= r; ++i)++num[ori[i]];
                c = 65;
                for (i = l; i <= end(belong(l)); ++i)
                {
                    while (num[c] == 0)++c;
                    ori[i] = c,--num[c];
                }
                for (j = belong(l) + 1; j < belong(r); ++j)
                {
                    while (num[c] == 0)++c;
                    if (num[c] >= mi2(n, end(j)) - begin(j) + 1)chg[j] = c,num[c] -= mi2(n, end(j)) - begin(j) + 1;
                    else
                    {
                        chg[j] = 0;
                        for (i = begin(j); i <= mi2(n, end(j)); ++i)
                        {
                            while (num[c] == 0)++c;
                            ori[i] = sot[i] = c,--num[c];
                        }
                    }
                }
                for (i = begin(belong(r)); i <= r; ++i)
                {
                    while (num[c] == 0)++c;
                    ori[i] = c,--num[c];
                }
                for (i = begin(belong(l)); i <= end(belong(l)); ++i)sot[i] = ori[i];
                sort(sot + begin(belong(l)), sot + mi2(end(belong(l)), n) + 1);
                for (i = begin(belong(r)); i <= end(belong(r)); ++i)sot[i] = ori[i];
                sort(sot + begin(belong(r)), sot + mi2(end(belong(r)), n) + 1);
            }
        }
    }
    return 0;
}