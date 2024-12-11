#include "catch2/catch_all.hpp"
#include "Factory.h"
#include <sstream>

TEST_CASE("TV object creation with valid width and height") 
{
    TV tv(1920, 1080);
    
    REQUIRE(tv.getWidth() == 1920);
    REQUIRE(tv.getHeight() == 1080);
}

TEST_CASE("TV display method outputs correct string") {
    TV tv(1920, 1080);
    std::stringstream ss;
    
    tv.display(ss);

    REQUIRE(ss.str() == "TV: \nTV dimensions: 1920mm x 1080mm\n");
}


TEST_CASE("TV object creation with invalid width or height") 
{
    REQUIRE_THROWS_AS(TV(0, 1080), std::invalid_argument);  
    REQUIRE_THROWS_AS(TV(1920, 0), std::invalid_argument);  
    REQUIRE_THROWS_AS(TV(-1920, 1080), std::invalid_argument); 
    REQUIRE_THROWS_AS(TV(1920, -1080), std::invalid_argument);  
}

TEST_CASE("Create TV using Factory and verify properties") 
{
    Factory& factory = Factory::getFactory();
    
    std::vector<int> tvParams = {1920, 1080};
    Screen* tv = factory.createScreen("TV", tvParams);

    REQUIRE(tv != nullptr);
    
    TV* concreteTV = dynamic_cast<TV*>(tv); 
    REQUIRE(concreteTV != nullptr); 
    REQUIRE(concreteTV->getWidth() == 1920);
    REQUIRE(concreteTV->getHeight() == 1080);
    
    std::stringstream ss;
    concreteTV->display(ss);
	REQUIRE(ss.str() == "TV: \nTV dimensions: 1920mm x 1080mm\n");

    delete tv;
}
