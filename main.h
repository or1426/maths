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
        comp operator * (vect);
        vect operator / (vect);
        vect operator * (comp);
        bool operator = (vect);

        //functions
        string toString();
};

class matrix{
    public:
        list<vect> vList;

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
        matrix operator * (comp);
        vect operator * (vect);
        matrix operator ++(); //transpose
        bool operator = (matrix);

        //functions
        string toString();
};

class object{
    public:
        string name;
        matrix matrix_data;
        vect vect_data;
        comp comp_data;
        bool isMatrix;
        bool isVect;
        bool isComp;
        bool isVar;

        object(){};
        object(string str);
        object(string str,const object &obj);
        object(comp com);
        object(vect vec);
        object(matrix mat);
        object(const object &obj);
        ~object(){};

        bool operator = (object param);

        void value(matrix &m);
        void value(vect &v);
        void value(comp &c);
        string toString();
};

class op{
    public:
        op(){};
        op(string opS,void (*exe)(list<object> &stack));
        string opCode;
        string toString(){return opCode;};
        void (*execute)(list<object> &stack);
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
        bool isValid();
        bool isDefined();

        //return what the string contains
        object value();
        op toOp();
};

list<myString> split(string input);

void eval(list<myString> input);

void add(list<object> &stack);
void sub(list<object> &stack);
void mul(list<object> &stack);
void div(list<object> &stack);
void makeVect(list<object> &stack);
void trans(list<object> &stack);
void makeMatrix(list<object> &stack);
void define(list<object> &stack);
void help(list<object> &stack);

extern list<op> opList;
extern list<object> varList;
