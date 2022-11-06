#ifndef _HEAD_H
#define _HEAD_H

#ifndef mx2
#define mx2(a, b) ((a) > (b) ? (a) : (b))
#endif

#ifndef mi2
#define mi2(a, b) ((a) < (b) ? (a) : (b))
#endif

#ifndef MAX_SIGNED_LONG_LONG
#define MAX_SIGNED_LONG_LONG 0x7fffffffffffffffll
#endif 

#ifndef _READ
#define _READ
template<typename T>void read(T&ans){
    ans=0;char us=getchar();bool f=false;
    while(us!=EOF&&(us<48||us>57)){f|=(us==45);us=getchar();}
    while(us>47&&us<58){ans=(ans<<1)+(ans<<3)+(T)(us^48);us=getchar();}
    ans=f?-ans:ans;
}
template<typename T,typename ...O>void read(T&x,O&...oth){read(x);read(oth...);}
template<typename T=signed int>T read(void){T x;read(x);return x;}
#endif


#endif