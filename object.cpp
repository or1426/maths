#include "main.h"
list<object> varList;
object::object(string str){
    name = str;
    isComp = false;
    isVect = false;
    isMatrix = false;
    isVar = true;

}

object::object(string str,const object &obj){
    name = str;
    matrix_data = obj.matrix_data;
    vect_data = obj.vect_data;
    comp_data = obj.comp_data;

    isMatrix = obj.isMatrix;
    isVect = obj.isVect;
    isComp = obj.isComp;
    isVar = true;

    varList.push_back(*this);
}

object::object(comp com){
    name = "";
    comp_data = com;
    isComp = true;
    isVect = false;
    isMatrix = false;
    isVar = false;
}

object::object(vect vec){
    name = "";
    vect_data = vec;
    isComp = false;
    isVect = true;
    isMatrix = false;
    isVar = false;
}

object::object(matrix mat){
    name = "";
    matrix_data = mat;
    isComp = false;
    isVect = false;
    isMatrix = true;
    isVar = false;
}

object::object(const object &obj){
    name = obj.name;
    matrix_data = obj.matrix_data;
    vect_data = obj.vect_data;
    comp_data = obj.comp_data;

    isMatrix = obj.isMatrix;
    isVect = obj.isVect;
    isComp = obj.isComp;
    isVar = obj.isVar;

}

bool object::operator = (object param){
    name = param.name;
    matrix_data = param.matrix_data;
    vect_data = param.vect_data;
    comp_data = param.comp_data;

    isMatrix = param.isMatrix;
    isVect = param.isVect;
    isComp = param.isComp;
    isVar = param.isVar;
    return 0;
}

void object::value(matrix &m){
    m = matrix_data;
}
void object::value(vect &v){
    v = vect_data;
}
void object::value(comp &c){
    c = comp_data;
}

string object::toString(){
    if(isMatrix){
        return matrix_data.toString();
    }else if(isVect){
        return vect_data.toString();
    }else if(isComp){
        return comp_data.toString();
    }

    return string("");
}

