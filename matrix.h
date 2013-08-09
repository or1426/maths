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
