#include <iostream>
#include <string>
#include <list>
#include <locale>
#include <sstream>

#include <cstring>
#include <cstdlib>

#define co 0;

using namespace std;

class comp{
    public:
        //Values
        double re;
        double im;

        //Constructors
        comp();
        comp(double real_bit,double imaginary_bit);
        //Destructor
        ~comp();

        //Operators
        comp operator + (comp);
        comp operator - (comp);
        comp operator * (comp);
        comp operator / (comp);
        bool operator = (comp);

        //functions
        string toString();
        int isA(){return co;}
};

class op{
    public:
        op(){};
        op(string opS,void (*exe)(list<comp> &stack));
        string opCode;
        string toString(){return opCode;};
        void (*execute)(list<comp> &stack);
};

class myString{
    public:
        string str;

        //constructors
        myString():str(""){};
        myString(const string & s):str(s){};
        myString(const char * s):str(s){};
        myString(const myString & s):str(s.str){};

        //destructor
        ~myString(){};

        //work out wtf the string contains
        bool isReal();
        bool isImag();
        bool isOp();

        //return what the string contains
        comp value();
        op toOp();
};

list<myString> split(string input);

void eval(list<myString> input);

void add(list<comp> &stack);
void sub(list<comp> &stack);
void mul(list<comp> &stack);
void div(list<comp> &stack);
void help(list<comp> &stack);
extern list<op> opList;
