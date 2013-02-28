#include <iostream>
#include <string>
#include <list>
#include <locale>
#include <sstream>

#include <cstring>
#include <cstdlib>


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
};

class vect{
    public:
        list<comp> elList;

        //Constructors
        vect(){};
        vect(list<comp> inList);
        vect(const vect &param);
        vect(const comp &param);
        //Destructor
        ~vect(){};

        //Operators
        vect operator + (vect);
        vect operator - (vect);
        vect operator * (vect);
        vect operator / (vect);
        bool operator = (vect);

        //functions
        string toString();
};

class matrix{
    public:
        list<vect> vList;
        bool isVector;
        bool isComplex;
        //Constructors
        matrix();
        matrix(const matrix &param);
        matrix(const vect &param);
        matrix(const comp &param);

        //Destructor
        ~matrix(){};

        matrix operator + (matrix);
        matrix operator - (matrix);
        matrix operator * (matrix);
        matrix operator / (matrix);
        matrix operator ++(); //transpose
        bool operator = (matrix);

        //functions
        string toString();
};

class op{
    public:
        op(){};
        op(string opS,void (*exe)(list<matrix> &stack));
        string opCode;
        string toString(){return opCode;};
        void (*execute)(list<matrix> &stack);
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
        matrix value();
        op toOp();
};

list<myString> split(string input);

void eval(list<myString> input);

void add(list<matrix> &stack);
void sub(list<matrix> &stack);
void mul(list<matrix> &stack);
void div(list<matrix> &stack);
void makeVect(list<matrix> &stack);
void trans(list<matrix> &stack);
void makeMatrix(list<matrix> &stack);
void help(list<matrix> &stack);
extern list<op> opList;
