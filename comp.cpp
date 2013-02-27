#include "main.h"

comp::comp(double real_bit, double imaginary_bit){
    re = real_bit;
    im = imaginary_bit;
}

comp::comp(){
    re = 0;
    im = 0;
}

comp::~comp(){
}

bool comp::operator = (comp param){

    re = param.re;
    im = param.im;
    return 0;
}

comp comp::operator + (comp param){
    comp temp;
    temp.re = (double)re + (double)param.re;
    temp.im = im + param.im;
    return temp;
}

comp comp::operator - (comp param){
    comp temp;
    temp.re = re - param.re;
    temp.im = im - param.im;
    return temp;
}

comp comp::operator * (comp param){
    comp temp;
    cout << re << " " << im << "i " << param.re << " " << param.im << "i" <<endl;
    temp.re = re*param.re - im*param.im;
    temp.im = re*param.im + im*param.re;
    return temp;
}

comp comp::operator / (comp param){

    comp temp;
    temp.re = (re * param.re + im * param.im)/(param.re * param.re + param.im * param.im);
    temp.im = (im * param.re - re * param.im)/(param.re * param.re + param.im * param.im);

    return temp;
}
string comp::toString(){
    stringstream temp;

    temp << re << " + " << im << "i\n";
    return temp.str();
}
