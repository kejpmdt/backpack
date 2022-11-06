#include<bits/stdc++.h>
#define random(a,b) (rand()%(b-a)+a)
using namespace std;
int main(){
    int man=0,ans=0,n,x1=100,x2=100,g1,g2=10,j=0;
    srand((int)time(0));
    while(j==0&&x1>0&&x2>0){
        cout<<"丁真xp:"<<x1<<"技能:我测你码(1)(扣血10 10%的几率3倍伤害)  吸电子烟(2)(自生扣血10,对方扣血20) "<<"       "<<"梦泪xp:"<<x2<<"技能:国士无双(扣血"<<g2<<") 梦泪在偷塔(攻击力+10) 被动:名刀司令"<<endl;
        cin>>n;
        man=random(1,6);
        ans=random(1,3);
        if(n==1){
            g1=10;
            if(man==5){
                g1=30;
            }

            x2=x2-g1;
            cout<<"丁真使用我测你码"<<endl; 
        }
        if(n==2){
            g1=20;
            x1=x1-10; 
            x2=x2-g1;
            cout<<"丁真使用吸电子烟"<<endl; 
        }
        if(ans==1){
            x1=x1-g2;
            cout<<"梦泪使用国士无双"<<endl; 
        } 
        if(ans==2){
            g2=g2+10;
            cout<<"梦泪在偷塔"<<endl; 
        } 
        if(x2<=0){
            if(j==0){
                x2=x2+g1;
                j=1;
                cout<<"梦泪在偷塔!!!"<<endl<<"能偷掉吗!!!"<<endl<<"不!!!"<<endl<<"他出了个名刀司令!!!"<<endl; 
            }
        }
    } 
    if(x1>0){
        while(x1>0&&x2>0){
        cout<<"丁真xp:"<<x1<<"技能:我测你码(1)(扣血10 10%的几率3倍伤害)  吸电子烟(2)(自生扣血10,对方扣血20) "<<"       "<<"梦泪xp:"<<x2<<"技能:国士无双(扣血"<<g2<<") 梦泪在偷塔(攻击力+10) 被动:名刀司令"<<endl;
        cin>>n;
        man=random(1,6);
        ans=random(1,3);
        if(n==1){
            g1=10;
            if(man==5){
                g1=30;
            }

            x2=x2-g1;
            cout<<"丁真使用我测你码"<<endl; 
        }
        if(n==2){
            g1=20;
            x1=x1-10; 
            x2=x2-g1;
            cout<<"丁真使用吸电子烟"<<endl; 
        }
        if(ans==1){
            x1=x1-g2;
            cout<<"梦泪使用国士无双"<<endl; 
        } 
        if(ans==2){
            g2=g2+10;
            cout<<"梦泪在偷塔"<<endl; 
        } 
    }
    }
    if(x1<=0) x1=0;
    if(x2<=0) x2=0;
    cout<<"丁真xp:"<<x1<<"技能:我测你码(1)(扣血10)  吸电子烟(2)(自生扣血10,对方扣血20)"<<"       "<<"梦泪xp:"<<x2<<"技能:国士无双(扣血"<<g2<<") 梦泪在偷塔(攻击力+5) 被动:名刀司令"<<endl;
    if(x1==0&&x2==0){
        cout<<"平局"; 
    }else if(x2==0){
        cout<<"丁真获胜"<<endl; 
        for(int i=1;i<=10;i++) cout<<"我测你码!!!"<<endl; 
    }else if(x1==0){
        cout<<"丁真获胜"<<endl; 
        for(int i=1;i<=10;i++) cout<<"我测你码!!!"<<endl; 
    } 

    return 0;
}