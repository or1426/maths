#include "main.h"
//using namespace std;

int main()
{
    //Sort out basic operations in opList //yuck! function pointers in c++;
    op(string("+"),&add);
    op(string("-"),&sub);
    op(string("*"),&mul);
    op(string("/"),&div);
    op(string("-help"),&help);

    char inp[256];
    string input;
    list<myString> paramList;
    cout <<"Enter -help for help"<< endl;
    while(true){
        cout << ">";
        cin.getline(inp,256,'\n');

        input = string(inp);
        paramList = split(input);
        eval(paramList);
}

    return 0;
}
