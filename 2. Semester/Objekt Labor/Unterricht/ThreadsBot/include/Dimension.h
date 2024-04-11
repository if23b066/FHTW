#ifndef DIMENSION_H
#define DIMENSION_H

#include <vector>

class Dimension
{
public:
    Dimension();
    virtual ~Dimension();

    void printDimension();
    int getLength() { return length; }
    int getWidth() { return width; }

private:
    std::vector<std::vector<int>> dimension;
    int length = 100;
    int width = 10;
};

#endif // DIMENSION_H
