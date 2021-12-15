#pragma once
#include <iostream>
using namespace std;
class Service
{
    virtual void add() = 0;
    virtual void update() = 0;
    virtual void remove() = 0;
    virtual void search() = 0;
    virtual void removeAll() = 0;
    virtual void display() = 0;
};