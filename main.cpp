#include "main.h"
//using namespace std;

int main()
{
    //Sort out basic operations in opList //yuck! function pointers in c++;
    op(string("+"),&add); //for vectors, matrices elementwise
    op(string("-"),&sub); //for vectors, matrices elementwise
    op(string("*"),&mul);//for vectors dot product, for matrices works properly
    op(string("/"),&div); //for vectors, matrices elementwise
    op(string(")"),&makeVect);
    op(string("}"),&makeMatrix);
    op(string("t"),&trans); //matrix transpose and converts between row and column vectors
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
