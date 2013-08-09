
class op{
    public:
        op(){};
        op(string opS,void (*exe)(list<matrix> &stack));
        string opCode;
        string toString(){return opCode;};
        void (*execute)(list<matrix> &stack);
};
