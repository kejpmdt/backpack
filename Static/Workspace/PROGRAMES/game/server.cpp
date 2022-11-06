#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <fstream>
using namespace std;
int main()
{
   fstream u1out;
   fstream u1in;
   fstream u2out;
   fstream u2in;
   u1out.open("userdata1.dat", ios::out);
   u2out.open("userdata2.dat", ios::out);
   u1out << "ready?";
   u2out << "ready?";
   u1out.close();
   u2out.close();
   string s1, s2;
   while (1)
   {
      u1in.open("userres1.dat", ios::in);
      u2in.open("userres2.dat", ios::in);
      u1in >> s1;
      u2in >> s2;
      if (s1 == "ready!" && s2 == "ready!")
      {
         u1out.open("userdata1.dat", ios::out);
         u2out.open("userdata2.dat", ios::out);
         u1out << "start";
         u2out << "start";
         u1out.close();
         u2out.close();
         break;
      }
   }
   while (1)
   {
   }
}