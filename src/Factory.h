#ifndef FACTORY_H
#define FACTORY_H

#include "TV.h"
#include "LEDVideoWall.h"
#include "vector"

class Factory
{
public:
    static Factory& getFactory();

	Screen* createScreen(const std::string& type, const std::vector<int>& params);

private:
	Factory(){}
	~Factory(){}
	Factory(const Factory&) = delete;
	Factory& operator=(const Factory&) = delete;
};

#endif // FACTORY_H