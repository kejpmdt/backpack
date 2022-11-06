#include<bits/stdc++.h>
using namespace std;
bool setblocked[20][20][25];
signed char freeze[20][20];
signed char n;
signed char Hm;
signed char Hr,Hc,Hx,Hy;
signed short m;
signed short num;
signed char Dx[8]={-1,-1,0,1,1,1,0,-1};
signed char Dy[8]={0,-1,-1,-1,0,1,1,1};
bool pd[20][20][25];
struct block{
    int x,y,z;
};
template<typename T>
void read(T&ans)
{
    ans=0;
    char us=getchar();
    bool f=false;
    while(us<48||us>57){
        f|=(us==45);
        us=getchar();
    }
    while(us>47&&us<58){
        ans=(ans<<1)+(ans<<3)+(us^48);
        us=getchar();
    }
    ans*=f?-1:1;
    return;
}
template<typename T,typename ...O>
void read(T&x,O&...oth)
{
    read(x);
    read(oth...);
}
void ICE_BARRAGE(void){
    signed char R,C,D,S;
    read(R,C,D,S);
    signed ans=0;
    for(signed char i=0;i<=S;++i){
        if(R+Dx[D]*i<0)break;
        if(C+Dy[D]*i<0)break;
        if(R+Dx[D]*i>=n)break;
        if(C+Dy[D]*i>=n)break;
        if(setblocked[R+Dx[D]*i][C+Dy[D]*i][0])break;
        if(freeze[R+Dx[D]*i][C+Dy[D]*i]<=3)++ans,++freeze[R+Dx[D]*i][C+Dy[D]*i];
    }
    printf("CIRNO FREEZED %d BLOCK(S)\12",ans);
    return;
}
void MAKE_ICE_BLOCK(void){
    unsigned short add=0;
    for(signed char i=0;i<n;++i)
        for(signed char j=0;j<n;++j)
            if(freeze[i][j]==4)
                ++add,++num,freeze[i][j]=0;
    printf("CIRNO MADE %d ICE BLOCK(S),NOW SHE HAS %d ICE BLOCK(S)\12",add,num);
    return;
}
void PUT_ICE_BLOCK(void){
    signed char R,C,H;
    read(R,C,H);
    if(num==0){
        printf("CIRNO HAS NO ICE_BLOCK\12");
        return;
    }
    if(setblocked[R][C][H]){
        printf("BAKA CIRNO,CAN'T PUT HERE\12");
        return;
    }
    if(H>0)
        if(!setblocked[R][C][H-1]&&!setblocked[R-1][C][H]&&!setblocked[R][C-1][H]&&!setblocked[R+1][C][H]&&!setblocked[R][C+1][H]){
            printf("BAKA CIRNO,CAN'T PUT HERE\12");
            return;
        }
    --num;
    if(H==0)
        freeze[R][C]=0;
    setblocked[R][C][H]=true;
    if(R<Hr||C<Hc||R>=Hr+Hx||C>=Hc+Hy)
        printf("CIRNO MISSED THE PLACE\12");
    else if(Hr<R&&Hr+Hx-1>R&&Hc<C&&Hc+Hy-1>C)
        printf("CIRNO PUT AN ICE_BLOCK INSIDE THE HOUSE\12");
    else 
        printf("CIRNO SUCCESSFULLY PUT AN ICE_BLOCK,NOW SHE HAS %d ICE_BLOCK(S)\12",num);
    return;
}
void REMOVE_ICE_BLOCK(void){
    signed char R,C,H;
    read(R,C,H);
    if(!setblocked[R][C][H])
        printf("BAKA CIRNO,THERE IS NO ICE_BLOCK\12");
    else {
        memset(pd,0x00,sizeof pd);
        deque<block>q;
        setblocked[R][C][H]=false;
        for(signed char i=0;i<n;++i){
            for(signed char j=0;j<n;++j){
                if(setblocked[i][j][0]){
                    pd[i][j][0]=true;
                    q.push_back({i,j,0});
                }
            }
        }
        while(!q.empty()){
            if((q.front().x!=0)&&(setblocked[q.front().x-1][q.front().y][q.front().z])&&(!pd[q.front().x-1][q.front().y][q.front().z])){
                pd[q.front().x-1][q.front().y][q.front().z]=true;
                q.push_back({q.front().x-1,q.front().y,q.front().z});
            }
            if((q.front().y!=0)&&(setblocked[q.front().x][q.front().y-1][q.front().z])&&(!pd[q.front().x][q.front().y-1][q.front().z])){
                pd[q.front().x][q.front().y-1][q.front().z]=true;
                q.push_back({q.front().x,q.front().y-1,q.front().z});
            }
            if((q.front().x!=n-1)&&(setblocked[q.front().x+1][q.front().y][q.front().z])&&(!pd[q.front().x+1][q.front().y][q.front().z])){
                pd[q.front().x+1][q.front().y][q.front().z]=true;
                q.push_back({q.front().x+1,q.front().y,q.front().z});
            }
            if((q.front().y!=n-1)&&(setblocked[q.front().x][q.front().y+1][q.front().z])&&(!pd[q.front().x][q.front().y+1][q.front().z])){
                pd[q.front().x][q.front().y+1][q.front().z]=true;
                q.push_back({q.front().x,q.front().y+1,q.front().z});
            }
            if(setblocked[q.front().x][q.front().y][q.front().z+1]){
                pd[q.front().x][q.front().y][q.front().z+1]=true;
                q.push_back({q.front().x,q.front().y,q.front().z+1});
            }
            q.pop_front();
        }
        ++num;
        unsigned short ans=0;
        for(signed char i=0;i<n;++i){
            for(signed char j=0;j<n;++j){
                for(signed char k=0;k<=Hm+1;++k)
                if(setblocked[i][j][k]&&!pd[i][j][k]){
                    setblocked[i][j][k]=false;
                    ++ans;
                }
            }
        }
        if(ans!=0)
            printf("CIRNO REMOVED AN ICE_BLOCK,AND %d BLOCK(S) ARE BROKEN\12",ans);
        else 
            printf("CIRNO REMOVED AN ICE_BLOCK\12");
    }
    return;
}
void MAKE_ROOF(void){
    signed char h=-1;
    for(signed char i=0;i<Hx;++i)
        for(signed char j=Hm;j>h;--j)
            if(setblocked[Hr+i][Hc][j]||setblocked[Hr+i][Hc+Hy-1][j])
                h=j;
    for(signed char i=0;i<Hy;++i)
        for(signed char j=Hm;j>h;--j)
            if(setblocked[Hr][Hc+i][j]||setblocked[Hr+Hx-1][Hc+i][j])
                h=j;
    ++h;
    unsigned short ans=0;
    for(signed char i=0;i<Hx;++i)
        for(signed char j=0;j<Hy;++j)
            if(!setblocked[Hr+i][Hc+j][h])
                ++ans,--num,setblocked[Hr+i][Hc+j][h]=true;
    if(num<0){
        printf("SORRY CIRNO,NOT ENOUGH ICE_BLOCK(S) TO MAKE ROOF\12");
        return;
    }
    if(h<=1||Hx<=2||Hy<=2){
        printf("SORRY CIRNO,HOUSE IS TOO SMALL\12");
        return;
    }
    unsigned short k1=0,k2=0;
    for(signed char i=0;i<n;++i)
        for(signed char j=0;j<n;++j)
            for(signed char k=0;k<=Hm;++k)
                if(setblocked[i][j][k]&&(k>h||i<Hr||j<Hc||i>=Hr+Hx||j>=Hc+Hy))
                    ++k2,setblocked[i][j][k]=false,++num;
    for(signed char i=0;i<n;++i)
        for(signed char j=0;j<n;++j)
            for(signed char k=0;k<=Hm;++k)
                if(setblocked[i][j][k]&&(i>=Hr+1&&i<Hr+Hx-1&&j>=Hc+1&&j<Hc+Hy-1&&k<h))
                    ++k1,setblocked[i][j][k]=false,++num;
    printf("%d ICE_BLOCK(S) INSIDE THE HOUSE NEED TO BE REMOVED\12",k1);
    printf("%d ICE_BLOCK(S) OUTSIDE THE HOUSE NEED TO BE REMOVED\12",k2);
    deque<block>q;
    memset(pd,0x00,sizeof pd);
    for(signed char i=0;i<n;++i)
        for(signed char j=0;j<n;++j)
            if(setblocked[i][j][0])
                q.push_back({i,j,0}),pd[i][j][0]=true;
    while(!q.empty()){
        if((q.front().x!=0)&&(setblocked[q.front().x-1][q.front().y][q.front().z])&&(!pd[q.front().x-1][q.front().y][q.front().z])){
            pd[q.front().x-1][q.front().y][q.front().z]=true;
            q.push_back({q.front().x-1,q.front().y,q.front().z});
        }
        if((q.front().y!=0)&&(setblocked[q.front().x][q.front().y-1][q.front().z])&&(!pd[q.front().x][q.front().y-1][q.front().z])){
            pd[q.front().x][q.front().y-1][q.front().z]=true;
            q.push_back({q.front().x,q.front().y-1,q.front().z});
        }
        if((q.front().x!=n-1)&&(setblocked[q.front().x+1][q.front().y][q.front().z])&&(!pd[q.front().x+1][q.front().y][q.front().z])){
            pd[q.front().x+1][q.front().y][q.front().z]=true;
            q.push_back({q.front().x+1,q.front().y,q.front().z});
        }
        if((q.front().y!=n-1)&&(setblocked[q.front().x][q.front().y+1][q.front().z])&&(!pd[q.front().x][q.front().y+1][q.front().z])){
            pd[q.front().x][q.front().y+1][q.front().z]=true;
            q.push_back({q.front().x,q.front().y+1,q.front().z});
        }
        if(setblocked[q.front().x][q.front().y][q.front().z+1]){
            pd[q.front().x][q.front().y][q.front().z+1]=true;
            q.push_back({q.front().x,q.front().y,q.front().z+1});
        }
        q.pop_front();
    }
    for(signed char i=0;i<n;++i)
        for(signed char j=0;j<n;++j)
            for(signed char k=0;k<=Hm;++k)
                if(setblocked[i][j][k]&&!pd[i][j][k])
                    if(k==h){
                        printf("SORRY CIRNO,HOUSE IS BROKEN WHEN REMOVING BLOCKS\12");
                        return;
                    }
                    else
                        setblocked[i][j][k]=false,++num;
    signed char state=0;
    signed char nwstate;
    bool center;
    bool nwcenter;
    signed char doorx=Hr,doory=Hc;
    ans=0;
    unsigned char fixadd=0;
    unsigned char nwfixneed;
    for(signed char i=1;i<Hx-1;++i)
        for(signed char j=h;j>=0;--j){
            if(!setblocked[Hr+i][Hc][j])
                ++ans;
            if(!setblocked[Hr+i][Hc+Hy-1][j])
                ++ans;
        }
    for(signed char i=1;i<Hy-1;++i)
        for(signed char j=h;j>=0;--j){
            if(!setblocked[Hr][Hc+i][j])
                ++ans;
            if(!setblocked[Hr+Hx-1][Hc+i][j])
                ++ans;
        }
    for(signed char i=1;i<Hx-1;++i){
        nwfixneed=0;
        if(i==1){
            if(!setblocked[Hr][Hc][0]&&!setblocked[Hr+i][Hc][0])
                ++nwfixneed;
            if(!setblocked[Hr][Hc][1]&&!setblocked[Hr+i][Hc][1])
                ++nwfixneed;
        }
        if(i==Hx-2){
            if(!setblocked[Hr+Hx-1][Hc][0]&&!setblocked[Hr+i][Hc][0])
                ++nwfixneed;
            if(!setblocked[Hr+Hx-1][Hc][1]&&!setblocked[Hr+i][Hc][1])
                ++nwfixneed;
        }
        nwcenter=false;
        if(Hx%2==0&&(i==Hx/2||i==Hx/2-1))
            nwcenter=true;
        if(Hx%2!=0&&i==Hx/2)
            nwcenter=true;
        nwstate=0;
        if(!setblocked[Hr+i][Hc][0])
            ++nwstate;
        if(!setblocked[Hr+i][Hc][1])
            ++nwstate;
        if(nwstate>state){
            doorx=Hr+i;
            doory=Hc;
            state=nwstate;
            center=nwcenter;
            fixadd=nwfixneed;
        }
        else if(nwstate==state)
            if(nwfixneed<fixadd){
                doorx=Hr+i;
                doory=Hc;
                state=nwstate;
                center=nwcenter;
                fixadd=nwfixneed;
            }
    }
    
    for(signed char i=1;i<Hx-1;++i){
        nwfixneed=0;
        if(i==1){
            if(!setblocked[Hr][Hc+Hy-1][0]&&!setblocked[Hr+i][Hc+Hy-1][0])
                ++nwfixneed;
            if(!setblocked[Hr][Hc+Hy-1][1]&&!setblocked[Hr+i][Hc+Hy-1][1])
                ++nwfixneed;
        }
        if(i==Hx-2){
            if(!setblocked[Hr+Hx-1][Hc+Hy-1][0]&&!setblocked[Hr+i][Hc+Hy-1][0])
                ++nwfixneed;
            if(!setblocked[Hr+Hx-1][Hc+Hy-1][1]&&!setblocked[Hr+i][Hc+Hy-1][1])
                ++nwfixneed;
        }
        nwcenter=false;
        if(Hx%2==0&&(i==Hx/2||i==Hx/2-1))
            nwcenter=true;
        if(Hx%2!=0&&i==Hx/2)
            nwcenter=true;
        nwstate=0;
        if(!setblocked[Hr+i][Hc+Hy-1][0])
            ++nwstate;
        if(!setblocked[Hr+i][Hc+Hy-1][1])
            ++nwstate;
        if(nwstate>state){
            doorx=Hr+i;
            doory=Hc+Hy-1;
            state=nwstate;
            center=nwcenter;
            fixadd=nwfixneed;
        }
        else if(nwstate==state)
            if(nwfixneed<fixadd){
                doorx=Hr+i;
                doory=Hc+Hy-1;
                state=nwstate;
                center=nwcenter;
                fixadd=nwfixneed;
            }
    }
    for(signed char i=1;i<Hy-1;++i){
        nwfixneed=0;
        if(i==1){
            if(!setblocked[Hr][Hc][0]&&!setblocked[Hr][Hc+i][0])
                ++nwfixneed;
            if(!setblocked[Hr][Hc][1]&&!setblocked[Hr][Hc+i][1])
                ++nwfixneed;
        }
        if(i==Hy-2){
            if(!setblocked[Hr][Hc+Hy-1][0]&&!setblocked[Hr][Hc+i][0])
                ++nwfixneed;
            if(!setblocked[Hr][Hc+Hy-1][1]&&!setblocked[Hr][Hc+i][1])
                ++nwfixneed;
        }
        nwcenter=false;
        if(Hy%2==0&&(i==Hy/2||i==Hy/2-1))
            nwcenter=true;
        if(Hy%2!=0&&i==Hy/2)
            nwcenter=true;
        nwstate=0;
        if(!setblocked[Hr][Hc+i][0])
            ++nwstate;
        if(!setblocked[Hr][Hc+i][1])
            ++nwstate;
        if(nwstate>state){
            doorx=Hr;
            doory=Hc+i;
            state=nwstate;
            center=nwcenter;
            fixadd=nwfixneed;
        }
        else if(nwstate==state)
            if(nwfixneed<fixadd){
                doorx=Hr;
                doory=Hc+i;
                state=nwstate;
                center=nwcenter;
                fixadd=nwfixneed;
            }
    }
    for(signed char i=1;i<Hy-1;++i){
        nwfixneed=0;
        if(i==1){
            if(!setblocked[Hr+Hx-1][Hc][0]&&!setblocked[Hr+Hx-1][Hc+i][0])
                ++nwfixneed;
            if(!setblocked[Hr+Hx-1][Hc][1]&&!setblocked[Hr+Hx-1][Hc+i][1])
                ++nwfixneed;
        }
        if(i==Hy-2){
            if(!setblocked[Hr+Hx-1][Hc+Hy-1][0]&&!setblocked[Hr+Hx-1][Hc+i][0])
                ++nwfixneed;
            if(!setblocked[Hr+Hx-1][Hc+Hy-1][1]&&!setblocked[Hr+Hx-1][Hc+i][1])
                ++nwfixneed;
        }
        nwcenter=false;
        if(Hy%2==0&&(i==Hy/2||i==Hy/2-1))
            nwcenter=true;
        if(Hy%2!=0&&i==Hy/2)
            nwcenter=true;
        nwstate=0;
        if(!setblocked[Hr+Hx-1][Hc+i][0])
            ++nwstate;
        if(!setblocked[Hr+Hx-1][Hc+i][1])
            ++nwstate;
        if(nwstate>state){
            doorx=Hr+Hx-1;
            doory=Hc+i;
            state=nwstate;
            center=nwcenter;
            fixadd=nwfixneed;
        }
        else if(nwstate==state)
            if(nwfixneed<fixadd){
                doorx=Hr+Hx-1;
                doory=Hc+i;
                state=nwstate;
                center=nwcenter;
                fixadd=nwfixneed;
            }
    }
    ans-=state;
    ans+=fixadd;
    num-=ans;
    if(abs(Hr-doorx)+abs(Hc-doory)==1){
        setblocked[Hr][Hc][0]|=!setblocked[doorx][doory][0];
        setblocked[Hr][Hc][1]|=!setblocked[doorx][doory][1];
    }
    if(abs(Hr+Hx-1-doorx)+abs(Hc-doory)==1){
        setblocked[Hr+Hx-1][Hc][0]|=!setblocked[doorx][doory][0];
        setblocked[Hr+Hx-1][Hc][1]|=!setblocked[doorx][doory][1];
    }
    if(abs(Hr-doorx)+abs(Hc+Hy-1-doory)==1){
        setblocked[Hr][Hc+Hy-1][0]|=!setblocked[doorx][doory][0];
        setblocked[Hr][Hc+Hy-1][1]|=!setblocked[doorx][doory][1];
    }
    if(abs(Hr+Hx-1-doorx)+abs(Hc+Hy-1-doory)==1){
        setblocked[Hr+Hx-1][Hc+Hy-1][0]|=!setblocked[doorx][doory][0];
        setblocked[Hr+Hx-1][Hc+Hy-1][1]|=!setblocked[doorx][doory][1];
    }
    signed char finalstate=0;
    if(num<0){
        printf("SORRY CIRNO,NOT ENOUGH ICE_BLOCKS TO FIX THE WALL\12");
        return;
    }
    printf("GOOD JOB CIRNO,SUCCESSFULLY BUILT THE HOUSE\12");
    if(state==2){
        printf("DOOR IS OK\12");
        ++finalstate;
    }
    else{
        printf("HOUSE HAS NO DOOR\12");
        num-=state;
        num+=2;
        setblocked[doorx][doory][0]=false;
        setblocked[doorx][doory][1]=false;
    }
    if(ans!=0){
        printf("WALL NEED TO BE FIXED\12");
    }
    else{
        printf("WALL IS OK\12");
        ++finalstate;
    }
    ans=0;
    for(signed char i=0;i<=h;++i){
        if(!setblocked[Hr][Hc][i])
            ++ans,--num;
        if(!setblocked[Hr+Hx-1][Hc][i])
            ++ans,--num;
        if(!setblocked[Hr][Hc+Hy-1][i])
            ++ans,--num;
        if(!setblocked[Hr+Hx-1][Hc+Hy-1][i])
            ++ans,--num;
    }
    if(ans==0){
        printf("CORNER IS OK\12");
        ++finalstate;
    }
    else
        printf("CORNER NEED TO BE FIXED\12");
    if(num<0)
        num=0;
    printf("CIRNO FINALLY HAS %d ICE_BLOCK(S)\12",num);
    if(finalstate==3&&k1==0&&k2==0&&center)
        printf("CIRNO IS PERFECT!\12");
}

        

int main(){
    string s;
#ifndef ONLINE_JUDGE
    freopen("out.txt","w",stdout);
#endif
    read(n,Hm,Hr,Hc,Hx,Hy,m);
    while(m--){
        cin>>s;
        if(s=="ICE_BARRAGE")
            ICE_BARRAGE();
        if(s=="MAKE_ICE_BLOCK")
            MAKE_ICE_BLOCK();
        if(s=="PUT_ICE_BLOCK")
            PUT_ICE_BLOCK();
        if(s=="REMOVE_ICE_BLOCK")
            REMOVE_ICE_BLOCK();
        if(s=="MAKE_ROOF")
            MAKE_ROOF();
    }
}