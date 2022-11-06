#include<bits/stdc++.h>
using namespace std;
int main(int filenum,char **filename){
    string filenames[5];
    --filenum;
    for(int i=0;i<filenum;++i)filenames[i]=filename[i+1];
    freopen("outt.txt","w",stdout);
    freopen("err.txt","w",stderr);
    string runnername;string outputfile;string inputfile;string buildername;string runnerpath;string builderpath;
    //cout<<filenum<<endl;
    //for(int i=0;i<filenum;++i)cout<<filenames[i]<<endl;
    if(filenum!=4){
        cerr<<"Wrong Input.There's must 4 files:\n";
        cerr<<"1.build.exe           #builder\n";
        cerr<<"2.xxx.exe             #runner\n";
        cerr<<"3.xxx.in              #input file\n";
        cerr<<"4.xxx.out             #output file\n";
        return 0;
    }
    else{
        int buildernum;
        for(int i=0;i<4;++i)
            if(filenames[i].substr(filenames[i].size()-9)=="build.exe"){
                buildername="build.exe",buildernum=i;
                builderpath=filenames[i].substr(0,filenames[i].find_last_of("\\")+1);
            }
        for(int i=0;i<4;++i)
            if(i!=buildernum&&filenames[i][filenames[i].size()-1]=='e'){
                runnername=filenames[i].substr(filenames[i].find_last_of("\\")+1,filenames[i].size()-5-filenames[i].find_last_of("\\"));
                runnerpath=filenames[i].substr(0,filenames[i].find_last_of("\\")+1);
            }
        for(int i=0;i<4;++i)
            if(filenames[i][filenames[i].size()-1]=='n')inputfile=filenames[i].substr(filenames[i].find_last_of("\\")+1,filenames[i].size()-4-filenames[i].find_last_of("\\"));
        for(int i=0;i<4;++i)
            if(filenames[i][filenames[i].size()-1]=='t')outputfile=filenames[i].substr(filenames[i].find_last_of("\\")+1,filenames[i].size()-5-filenames[i].find_last_of("\\"));
    }
    cout<<runnerpath<<"|||"<<runnername<<endl;
    cout<<builderpath<<"|||"<<buildername<<endl;
    cout<<inputfile<<" "<<outputfile<<endl;
    string x="md "+runnername+"\n";
    system(x.c_str());
    int n;
    cerr<<"输入数据组数"<<endl;
    int time1,time2;
    cin>>n;
    cerr<<"输入数据构造限时(/ms)"<<endl;
    cin>>time1;
    cerr<<"输入程序运行限时(/ms)#炸了就开大点"<<endl;
    cin>>time2;
    for(int i=1;i<=n;++i){
        x=builderpath+buildername+'\n';
        //system(x.c_str());
        cout<<x.c_str();
        x="cp "+builderpath+inputfile+".in "+runnerpath+inputfile+".in\n";
        //system(x.c_str());
        cout<<x.c_str();
        _sleep(100);
        x=runnerpath+runnername+'\n';
        //system(x.c_str());
        cout<<x.c_str();
        _sleep(1500);
        x="cp "+builderpath+outputfile+".out .\\"+runnername+"\\"+outputfile+(char)(i+48)+".ans\n";
        //system(x.c_str());
        cout<<x.c_str();
        //system(x.c_str());
        cout<<x.c_str();
        x="cp "+builderpath+inputfile+".in .\\"+runnername+"\\"+inputfile+(char)(i+48)+".in\n";
    }
}


        