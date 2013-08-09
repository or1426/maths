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
