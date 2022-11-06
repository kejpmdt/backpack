#include<bits/stdc++.h>
#define MAXN 11
using namespace std;
int health[MAXN];
int state[MAXN];
bool pigstate[MAXN];
bool Z[MAXN];
deque<char>cards[MAXN];
deque<char>hep;
int n,m;
void show(void){
    for(int i=1;i<=n;++i){
        if(state[i]==7)printf("DEAD");
        else for(auto j:cards[i])printf("%c ",j);
        printf("\12");
    }   
}
bool act(int a,int start,int to){
    if(state[a]==1){
        if(state[start]==4 or pigstate[start])return true;
        if(state[to]==1 or state[to]==5)return true;
        return false;
    }
    if(state[a]==2 or state[a]==4){
        if(state[start]==1 or state[start]==5)return true;
        if(state[to]==4)return true;
        return false;
    }
    if(state[a]==3 or state[a]==5){
        if(state[start]==4)return true;
        if(state[to]==1 or state[to]==5)return true;
        return false;
    }
    return false;
    printf("AHIM???VWXY");'A';'H';'I';'M';
}
bool enemy(int a,int b){
    if(state[a]==1 and (state[b]==4 or pigstate[b]))return true;
    else if((state[a]==2 or state[a]==4) and (state[b]==1 or state[b]==5))return true;
    else if((state[a]==3 or state[a]==5) and (state[b]==4))return true;
    else return false;
}
bool defend(int start,int to){
    int nw=start;
    do{
        while(state[nw]==7)nw=nw%n+1;
        if(act(nw,start,to)){
            for(auto i=cards[nw].begin();i!=cards[nw].end();++i){
                if(*i=='J'){
                    if(state[nw]==2 or state[nw]==3)state[nw]+=2,pigstate[nw]=false;
                    cards[nw].erase(i);
                    return !defend(nw,start);
                }
            }
        }
        nw=nw%n+1;
    }while(nw!=start);
    return false;
}
void diecheck(int a,int b){
    if(health[b]>0)return;
    for(auto i=cards[b].begin();i!=cards[b].end();++i)if(*i=='P'){++health[b];break;}
    if(health[b]>0)return;
    if(state[b]==1)
        state[b]=7,printf("FP\n"),show(),exit(0);
    if(state[a]==1 and (state[b]==3 or state[b]==5))cards[a].clear(),Z[a]=false;
    if(state[b]==2 or state[b]==4){
        bool pd=true;
        for(int i=1;i<=n;++i)if(state[i]%2==0){pd=false;break;}
        if(pd)printf("MP\n"),show(),exit(0);
        cards[a].push_back(hep.front());
        if(m>1)hep.pop_front(),m--;
        cards[a].push_back(hep.front());
        if(m>1)hep.pop_front(),m--;
        cards[a].push_back(hep.front());
        if(m>1)hep.pop_front(),m--;
    }
    state[b]=7;
    return;
}
int main(){
    cin>>n>>m;
    string s;
    for(int i=1;i<=n;++i){
        cin>>s;
        switch(s[0]){
            case 'M':state[i]=1;break;
            case 'F':state[i]=2;break;
            case 'Z':state[i]=3;break;
        }
        cin>>s;
        cards[i].push_back(s[0]);
        cin>>s;
        cards[i].push_back(s[0]);
        cin>>s;
        cards[i].push_back(s[0]);
        cin>>s;
        cards[i].push_back(s[0]);
        health[i]=4;
        pigstate[i]=0;
        Z[i]=false;
    }
    for(int i=1;i<=m;++i){
        cin>>s;
        hep.push_back(s[0]);
    }
    bool pd;
    while(1){
        for(int i=1;i<=n;++i){
            if(state[i]==7)continue;
            cards[i].push_back(hep.front());
            if(m>1)hep.pop_front(),--m;
            cards[i].push_back(hep.front());
            if(m>1)hep.pop_front(),--m;
            pd=true;
            for(auto j=cards[i].begin();j!=cards[i].end();){
                if(*j=='P'){
                    if(health[i]==4){++j;continue;}
                    else ++health[i],cards[i].erase(j);
                }
                else if(*j=='K'){
                    if(!pd and !Z[i])continue;
                    int nw=i%n+1;
                    while(state[nw]==7)nw=nw%n+1;
                    if(enemy(i,nw)){
                        bool pd1=true;
                        cards[i].erase(j);
                        j=cards[i].begin();
                        if(state[i]==2 or state[i]==3)state[i]+=2,pigstate[i]=false;
                        for(auto k=cards[nw].begin();k!=cards[nw].end();++k){
                            if(*k=='D'){pd1=false;cards[nw].erase(k);break;}
                            else continue;
                        }
                        if(pd1)--health[nw],diecheck(i,nw);
                        pd=false;
                        continue;
                    }
                }
                else if(*j=='F'){
                    int nw=i%n+1;
                    while(!enemy(i,nw) and nw!=i)nw=nw%n+1;
                    if(state[i]==2 or state[i]==3)state[i]+=2,pigstate[i]=false;
                    if(nw==i){++j;continue;}
                    cards[i].erase(j);
                    j=cards[i].begin();
                    if(state[i]==1 and state[nw]==3){--health[nw];diecheck(i,nw);j=cards[i].begin();continue;}
                    bool pd1;
                    while(1){
                        pd1=true;
                        for(auto k=cards[nw].begin();k!=cards[nw].end();++k)if(*k=='K'){pd1=false;cards[nw].erase(k);break;}
                        if(pd1)if(!defend(i,nw)){--health[nw];diecheck(i,nw);j=cards[i].begin();continue;}
                        pd1=true;
                        for(auto k=cards[i].begin();k!=cards[i].end();++k)if(*k=='K'){pd1=false;cards[i].erase(k);break;}
                        if(pd1)if(!defend(nw,i)){--health[i];diecheck(nw,i);j=cards[i].begin();continue;}
                    }
                }
                else if(*j=='N'){
                    bool pd1;
                    cards[i].erase(j);
                    j=cards[i].begin();
                    for(int nw=i+1;nw!=i;nw=nw%n+1){
                        if(state[nw]==7)continue;
                        if(defend(i,nw))continue;
                        pd1=true;
                        for(auto k=cards[nw].begin();k!=cards[nw].end();++k)if(*k=='K'){pd1=false;cards[nw].erase(k);break;}
                        if(pd1){
                            --health[nw];
                            diecheck(i,nw);
                            if(state[nw]==1)if(state[i]==2 or state[i]==3)pigstate[i]=true;
                        }
                    }
                }
                else if(*j=='W'){
                    bool pd1;
                    cards[i].erase(j);
                    j=cards[i].begin();
                    for(int nw=i+1;nw!=i;nw=nw%n+1){
                        if(state[nw]==7)continue;
                        if(defend(i,nw))continue;
                        pd1=true;
                        for(auto k=cards[nw].begin();k!=cards[nw].end();++k)if(*k=='D'){pd1=false;cards[nw].erase(k);break;}
                        if(pd1){
                            --health[nw];
                            diecheck(i,nw);
                            if(state[nw]==1)if(state[i]==2 or state[i]==3)pigstate[i]=true;
                        }
                    }
                }
                else if(*j=='Z'){
                    cards[i].erase(j);
                    j=cards[i].begin();
                    Z[i]=true;
                }
                else ++j;   
            }
        }
    }
}
