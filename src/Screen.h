#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <exception>

class Screen
{
public:

    virtual void display(std::ostream& out) const = 0;
    virtual ~Screen() = default;

    friend std::ostream& operator<<(std::ostream& out, const Screen& screen)
    {
        screen.display(out);
        return out;
    }
};

#endif //SCREEN_H