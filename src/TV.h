#ifndef TV_H
#define TV_H

#include "Screen.h"

class TV : public Screen
{
public:

    TV(int _width, int _height );

    void display(std::ostream& out) const override;

    int getWidth() const {return this->width;}
    int getHeight() const {return this->height;}

private:

    int width;
    int height;

};

#endif // TV_H