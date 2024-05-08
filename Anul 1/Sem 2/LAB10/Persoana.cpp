#pragma once
#include <iostream>
#include <string>
#include "Persoana.h"
using namespace std;

Persoana::Persoana(string nu):nume(nu) {}

void Persoana::afisare() const{
    cout << nume << " ";
}
