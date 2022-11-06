#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <fstream>
using namespace std;
string infiles[2]={"userdata1.dat","userdata2.dat"};
string outfiles[2]={"userres1.dat","userres2.dat"};
int main()
{
   int userdata;
   scanf("%d", &userdata);
   fstream datain;
   fstream dataout;
   string usin;
   while(1){
      datain.open(infiles[userdata],ios::in);
      datain>>usin;
      if(usin=="ready?"){
         dataout.open(outfiles[userdata],ios::out);
         dataout<<"ready!";
         dataout.close();
         break;
      }
      datain.close();
   }
   while(1){
      datain.open(infiles[userdata],ios::in);
      datain>>usin;
      if(usin=="start"){
         break;
      }

}
