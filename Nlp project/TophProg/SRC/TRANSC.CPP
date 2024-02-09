
#pragma hdrstop
#include <condefs.h>


//---------------------------------------------------------------------------
USEUNIT("extrai.cpp");
USEUNIT("gerbou.cpp");
USEUNIT("init.cpp");
USEUNIT("cherch.cpp");
USEUNIT("imprim.cpp");
USEUNIT("lire.cpp");
USEUNIT("main.cpp");
USEUNIT("trace.cpp");
USEUNIT("trans.cpp");
//---------------------------------------------------------------------------
#pragma argsused
#include <iostream.h>
#include <fstream.h>
int main()
{
extern void main_trans();
ifstream f("ammar.txt");
int x;
if(!f.is_open())
 {cout<<"jjhjkhkj"<<endl;
  cin>>x;
  }

f>>x;
main_trans();
}
