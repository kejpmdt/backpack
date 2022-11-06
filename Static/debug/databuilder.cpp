#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int main(int filenum,char **filename){
    string filenames[5];--filenum;
    for(int i=0;i<filenum;++i)filenames[i]=filename[i+1];
    if(filenum!=4){
        freopen("err.txt","w",stderr);
        cerr<<"Wrong Input.There's must 4 files:\n";
        cerr<<"1.build.exe           #builder\n";
        cerr<<"2.xxx.exe             #runner\n";
        cerr<<"3.xxx.in              #input file\n";
        cerr<<"4.xxx.out             #output file\n";
        return 0;
    }
    int n;
    bool pd=false;
    char c;
    cout<<"输入数据组数"<<endl;
    cin>>n;
    cout<<"是否手动(Y/N)"<<endl;
    cin>>c;
    cout<<"输出文件扩展名？"<<endl;
    string outext;
    cin>>outext;
    if(c=='Y'||c=='y')pd=true;
    string runnername;string outputfile;string inputfile;string buildername;string runnerpath;string builderpath;
    string inputpath,outputpath;
    int buildernum=0;
    for(int i=0;i<4;++i)if(filenames[i].substr(filenames[i].size()-9)=="build.exe")buildername="build.exe",buildernum=i,builderpath=filenames[i].substr(0,filenames[i].find_last_of("\\")+1);
    for(int i=0;i<4;++i)if(i!=buildernum&&filenames[i][filenames[i].size()-1]=='e')runnername=filenames[i].substr(filenames[i].find_last_of("\\")+1,filenames[i].size()-5-filenames[i].find_last_of("\\")),runnerpath=filenames[i].substr(0,filenames[i].find_last_of("\\")+1);
    for(int i=0;i<4;++i)if(filenames[i][filenames[i].size()-1]=='n')inputfile=filenames[i].substr(filenames[i].find_last_of("\\")+1,filenames[i].size()-4-filenames[i].find_last_of("\\")),inputpath=filenames[i].substr(0,filenames[i].find_last_of("\\")+1);
    for(int i=0;i<4;++i)if(filenames[i][filenames[i].size()-1]=='t')outputfile=filenames[i].substr(filenames[i].find_last_of("\\")+1,filenames[i].size()-5-filenames[i].find_last_of("\\")),outputpath=filenames[i].substr(0,filenames[i].find_last_of("\\")+1);
    string x="md "+inputpath+inputfile+"\n";
    system(x.c_str());
    x="md "+outputpath+outputfile+"\n";
    system(x.c_str());
    system("cls");
    cout<<"0/"<<n<<'\n';
    for(int i=1;i<=n;++i){
        x=builderpath+buildername+'\n';
        system(x.c_str());
        x="copy "+builderpath+inputfile+".in /Y "+runnerpath+inputfile+".in\n";
        system(x.c_str());
        system("cls");
        printf("%d.5/%d\n",i-1,n);
        if(pd){
            system("pause");
        }
        x=runnerpath+runnername+'\n';
        system(x.c_str());
        x="copy "+runnerpath+outputfile+".out /Y "+inputpath+inputfile+"\\"+outputfile+to_string(i)+"."+outext+"\n";
        system(x.c_str());
        x="copy "+builderpath+inputfile+".in /Y "+outputpath+inputfile+"\\"+inputfile+to_string(i)+".in\n";
        system(x.c_str());
        system("cls");
        printf("%d/%d\n",i,n);
        if(pd){
            system("pause");
        }
    }
}