#include <bits/stdc++.h>
using namespace std;
int health[20];
int state[20];
bool pigstate[20];
bool Z[20];
int fpnum;
deque<char> cards[20];
deque<char> hep;
int n,m;
bool enemy(int a,int b){
    if(state[a]==1 and (state[b]==4 or pigstate[b]==true))return true;
    if(state[a]%2==0 and (state[b]==1 or state[b]==5))return true;
    return (state[a]==3 or state[a]==5) and state[b]==4;
}
bool partner(int a,int b){
    if((state[a]==1 or state[a]==3 or state[a]==5) and (state[b]==1 or state[b]==5))return true;
    return(state[a]==2 or state[a]==4) and state[b]==4;
}
bool act(int a,int start,int to){
    return partner(a,to) or enemy(a,start);
}
void getcard(int x){
    cards[x].push_back(hep.front());
    if(m>1)
        hep.pop_front(),m--;
}
void show(){
    for(int i=1;i<=n;++i){
        if(state[i]==7)
            printf("DEAD");
        else 
            for(auto j=cards[i].begin();j!=cards[i].end();++j)
                printf("%c ",*j);
        printf("\n");
    }
}
void diecheck(int a,int b){
    if(health[b]>0)return;
    for(auto j=cards[b].begin();j!=cards[b].end();)
        if(*j=='P'){
            cards[b].erase(j);
            j=cards[b].begin();
            ++health[b];
            if(health[b]>0)return;
        }
        else++j;
    cards[b].clear();pigstate[b]=false;
    if(state[a]==1 and (state[b]==3 or state[b]==5)){
        cards[a].clear();Z[a]=false;
        state[b]=7;return;
    }
    if(state[b]%2==0){
        --fpnum;state[b]=7;
        if(fpnum==0)printf("MP\n"),show(),exit(0);
        getcard(a),getcard(a),getcard(a);
    }
    if(state[b]==1)state[b]=7,printf("FP\n"),show(),exit(0);
    state[b]=7;
}
bool defend(int start,int to,bool J=false){
    int i=start;
    do{
        if((!J and partner(i,to)) or (J and enemy(i,start)))
            for(auto j=cards[i].begin();j!=cards[i].end();++j)
                if(*j=='J'){
                    cards[i].erase(j);
                    if(state[i]==2 or state[i]==3)state[i]+=2,pigstate[i]=false;
                    return !defend(i,start,true);
                }
        i=i%n+1;
    }while(i!=start);
    return false;
}
int main()
{
#ifndef ONLINE_JUDGE
//    freopen("in.txt","r",stdin);
#endif
    //freopen("txt.txt","w",stderr);
    scanf("%d%d", &n, &m);
    string s;
    for (int i = 1; i <= n; ++i){
        cin >> s;
        switch (s[0]){
            case 'M':state[i] = 1;break;
            case 'F':state[i] = 2;++fpnum;break;
            case 'Z':state[i] = 3;break;
        }
        cards[i].clear();
        cin >> s;cards[i].push_back(s[0]);
        cin >> s;cards[i].push_back(s[0]);
        cin >> s;cards[i].push_back(s[0]);
        cin >> s;cards[i].push_back(s[0]);
        health[i] = 4;
        pigstate[i] = false;
    }
    for (int i = 1; i <= m; ++i){
        cin >> s;
        hep.push_back(s[0]);
    }
    bool pd;
    bool pd1;
    int nw;
    while (1){
        for (int i = 1; i <= n; ++i){
            if(state[i]==7)continue;
            getcard(i),getcard(i);
            pd=true;
            for(auto j=cards[i].begin();j!=cards[i].end();){
                switch (*j){
                    case 'P':
                        if(health[i]<4){
                            cards[i].erase(j);
                            j=cards[i].begin();
                            cerr<<i<<" P"<<endl;
                            ++health[i];
                        }
                        else ++j;
                        break;
                    case 'K':
                        if(!pd and !Z[i]){
                            ++j;
                            break;
                        }
                        nw=i%n+1;
                        while(state[nw]==7)nw=nw%n+1;
                        if(nw==i){
                            ++j;break;
                        }
                        else if(enemy(i,nw)){
                                cards[i].erase(j);j=cards[i].begin();
                                --health[nw];
                                for(auto k=cards[nw].begin();k!=cards[nw].end();++k)
                                    if(*k=='D'){
                                        cards[nw].erase(k);
                                        ++health[nw];
                                        break;
                                    }
                                diecheck(i,nw);
                                if(state[i]==2 or state[i]==3)state[i]+=2,pigstate[i]=false;
                                pd=false;
                            }
                            else ++j;
                        break;
                    case 'F':
                        if(state[i]%2==0)nw=1;
                        else {
                            nw=i%n+1;
                            while(!enemy(i,nw) and nw!=i)nw=nw%n+1;
                            if(nw==i){
                                ++j;break;
                            }
                        }
                        cards[i].erase(j);j=cards[i].begin();
                        if(state[i]==2 or state[i]==3)state[i]+=2,pigstate[i]=false;
                        if(defend(i,nw))break;
                        if(state[i]==1 and state[nw]==3){
                            --health[nw];diecheck(i,nw);
                            break;
                        }
                        while(1){
                            pd1=true;
                            for(auto k=cards[nw].begin();k!=cards[nw].end();++k)
                                if(*k=='K'){
                                    cards[nw].erase(k);
                                    pd1=false;break;
                                }
                            if(pd1){
                                --health[nw];diecheck(i,nw);
                                break;
                            }
                            pd1=true;
                            for(auto k=cards[i].begin();k!=cards[i].end();++k)
                                if(*k=='K'){
                                    cards[i].erase(k);pd1=false;
                                    break;
                                }
                            if(pd1){
                                --health[i];diecheck(nw,i);
                                j=cards[i].begin();
                                break;
                            }
                        }
                        break;
                    case 'N':
                        cards[i].erase(j);j=cards[i].begin();
                        for(nw=i%n+1;nw!=i;nw=nw%n+1){
                            if(state[nw]==7 or defend(i,nw))continue;
                            pd1=true;
                            for(auto k=cards[nw].begin();k!=cards[nw].end();++k)
                                if(*k=='K'){
                                    cards[nw].erase(k);
                                    pd1=false;
                                    break;
                                }
                            if(pd1){
                                --health[nw];diecheck(i,nw);
                                if(state[nw]==1 and (state[i]==2 or state[i]==3))pigstate[i]=true;
                            }
                        }
                        break;
                    case 'W':
                        cards[i].erase(j);j=cards[i].begin();
                        for(nw=i%n+1;nw!=i;nw=nw%n+1){
                            if(state[nw]==7 or defend(i,nw))continue;
                            pd1=true;
                            for(auto k=cards[nw].begin();k!=cards[nw].end();++k)
                                if(*k=='D'){
                                    cards[nw].erase(k);pd1=false;
                                    break;
                                }
                            if(pd1){
                                --health[nw];diecheck(i,nw);
                                if(state[nw]==1 and (state[i]==2 or state[i]==3))pigstate[i]=true;
                            }
                        }
                        break;
                    case 'Z':
                        cards[i].erase(j);j=cards[i].begin();Z[i]=true;
                        break;
                    default:++j;break;
                }
            }
        }
    }
}