#include "main.h"
//using namespace std;

int main()
{
    //Sort out basic operations in opList //yuck! function pointers in c++;
    op(string("+"),&add); //for vectors elementwise
    op(string("-"),&sub); //for vectors dot product
    op(string("*"),&mul);//for vectors elementwise
    op(string("/"),&div); //for vectors elementwise
    op(string(")"),&makeVect);
    op(string("}"),&makeMatrix);
    op(string("t"),&trans);
    op(string("-help"),&help);

    char inp[256];
    string input;
    list<myString> paramList;
    cout <<"Enter -help for help"<< endl;
    while(true){
        cout << "\n>";
        cin.getline(inp,256,'\n');

        input = string(inp);
        paramList = split(input);
        eval(paramList);
}

    return 0;
}
