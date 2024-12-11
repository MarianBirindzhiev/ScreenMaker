#include <iostream>
#include <vector>
#include <stdexcept>
#include "Factory.h"

int main() 
{
    try 
    {
        std::string type;
        std::cout << "Enter the screen type (TV, LEDVideoWallFreeform, LEDVideoWallAspects): ";
        std::cin >> type;

        std::vector<int> params;
        int numParams = 0;

        if (type == "TV") 
        {
            numParams = 2;
            std::cout << "Enter TV width and height (separated by space): ";
        } 
        else if (type == "LEDVideoWallFreeform") 
        {
            numParams = 4;
            std::cout << "Enter LED Video Wall Freeform panel width, panel height, wall width, and wall height (separated by space): ";
        } 
        else if (type == "LEDVideoWallAspects") 
        {
            numParams = 4;
            std::cout << "Enter LED Video Wall Aspects panel width, panel height, aspect width, and aspect height (separated by space): ";
        } 
        else 
        {
            throw std::invalid_argument("Unknown screen type");
        }

        for (int i = 0; i < numParams; ++i) 
        {
            int param;
            std::cin >> param;
            params.push_back(param);
        }

        Factory& factory = Factory::getFactory();
        Screen* screen = factory.createScreen(type, params);

        screen->display(std::cout);

        delete screen;
    }
    catch (const std::exception& e) 
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
