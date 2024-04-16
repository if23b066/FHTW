#include <iostream>

#include "Reiskocher.h"
#include "Reis.h"
#include "Sushireis.h"
#include "Wildreis.h"

int main()
{
    Reiskocher cooker;
    cooker.cookRice();
    cooker.chooseRice();
    cooker.chooseRice();
    cooker.cookRice();
    return 0;
}