#include "TV.h"

TV::TV(int _width, int _height )
{
    if(_width <= 0 || _height <= 0)
        throw std::invalid_argument("TV dimensions must be greater than 0");

    width = _width;
    height = _height;
}

void TV::display(std::ostream& out) const 
{
    out << "TV: \n"
        << "TV dimensions: "<< width <<"mm x " << height <<"mm\n";
}