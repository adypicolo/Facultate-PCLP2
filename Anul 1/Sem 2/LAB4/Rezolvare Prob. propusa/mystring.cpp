#include "mystring.h"
#include <iostream>
#include <string.h>
using namespace std;

MyString::MyString(){
    buf = NULL;
    l = 0;
}

MyString::MyString(char *p){
    if (buf != NULL){
        buf = new char[strlen(p)+1];
        strcpy(buf, p);
    }
}

MyString::MyString(const MyString &v){
    delete []v.buf;
    if (v.buf != NULL){
    buf = new char[strlen(v.buf)+1];
    strcpy(buf, v.buf);
    }
    else buf = NULL;
    l = v.l;
}

MyString::~MyString(){
    delete []buf;
}

ostream& operator<<(ostream &dev, const MyString &v){
    if (v.buf != NULL)
        dev << "Buf: " << v.buf << endl;
    else dev << "Buf: ";
    dev << v.l;

    return dev;
}

istream& operator>>(istream &dev, MyString &v){
    char aux[100];
    delete []v.buf;
    cout << "Marca= "; dev >> aux;
    v.buf = new char [strlen(aux)+1];
    strcpy(v.buf, aux);

    cout << "l= "; dev >> v.l;

    return dev;
}

const MyString operator+(const MyString &a, const MyString &b){
    return strcat(a.buf, b.buf);
}

MyString& operator+=(const MyString &a, const MyString &b){
    MyString aux(a);
    s
}

