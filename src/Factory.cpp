#include "Factory.h"

Factory& Factory::getFactory()
{
	static Factory theFactory;
	return theFactory;
}

Screen* Factory::createScreen(const std::string& type, const std::vector<int>& params)
{

    Screen* screen = nullptr;

    if(type == "TV")
    {
        if(params.size() != 2)
            throw std::invalid_argument("TV creation requires 2 parameters (width and height)");

        screen = new TV(params[0], params[1]);
    }

    if(type == "LEDVideoWallFreeform")
    {
        if(params.size() != 4)
            throw std::invalid_argument("LEDVideoWallFreeform creation requires 4 parameters");

        screen = new LEDVideoWallFreeform(params[0], params[1], params[2], params[3]);
    }

    if(type == "LEDVideoWallAspects" && params.size() == 4)
    {
        if(params.size() != 4)
            throw std::invalid_argument("LEDVideoWallFreeform creation requires 4 parameters");

        screen = new LEDVideoWallAspects(params[0], params[1], params[2], params[3]);
    }

    if(screen == nullptr)
        throw std::invalid_argument("Unknow screen type" + type);
    
    return screen;
}