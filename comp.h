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
