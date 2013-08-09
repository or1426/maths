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