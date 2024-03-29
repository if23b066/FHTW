#include "Stock.h"

Stock::Stock()
{
    //ctor
}

Stock::Stock(std::string name, std::string wkn, std::string acronym)
{
    this->name = name;
    this->wkn = wkn;
    this->acronym = acronym;
}

Stock::~Stock()
{
    //dtor
}
