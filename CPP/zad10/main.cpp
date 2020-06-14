#include"ONP.h"

using namespace std;
int main()
{
  string polecenie, arg1, arg2;
  while(true)
  {
    cin>>polecenie;
    cin.ignore();
    if(polecenie.compare("print")==0)
    {
      getline(cin, arg1);
      onp::print(arg1);
    }
    else if(polecenie.compare("assign")==0)
    {
      getline(cin, arg1);
      getline(cin, arg2);
      onp::assign(arg1, arg2);
    }
    else if(polecenie.compare("clear")==0)
    {
      onp::clear();
    }
    else if(polecenie.compare("exit")==0)
    {
      break;
    }
    else
    {
      cout<<"Nieznane polecenie"<<endl;
      continue;
    }
  }

  return 0;
}
