#ifndef WEZEL_H
#define WEZEL_H

#include <iostream>
#include <memory>

using namespace std;

class Wezel
{
public:
    Wezel();
    shared_ptr<Wezel> next;
    ~Wezel();
};

#endif