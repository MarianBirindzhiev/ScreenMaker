#include "catch2/catch_all.hpp"
#include "Factory.h"

#include <chrono>

TEST_CASE("LEDVideoWallAspects constructor creates correct object") 
{
    LEDVideoWallAspects videoWall(500, 500, 16, 9);
    
    REQUIRE(videoWall.getPanelWidth() == 500);
    REQUIRE(videoWall.getPanelHeight() == 500);
    REQUIRE(videoWall.getWallWidth() == 8000); 
    REQUIRE(videoWall.getWallHeight() == 4500); 
	REQUIRE(videoWall.getCols() == 16); 
    REQUIRE(videoWall.getRows() == 9); 
}

TEST_CASE("LEDVideoWallAspects constructor creates correct object with large panel size") 
{
    LEDVideoWallAspects videoWall(1000, 2000, 12, 8);
    
    REQUIRE(videoWall.getPanelWidth() == 1000);
    REQUIRE(videoWall.getPanelHeight() == 2000);
    REQUIRE(videoWall.getWallWidth() == 3000); 
    REQUIRE(videoWall.getWallHeight() == 4000); 
	REQUIRE(videoWall.getCols() == 3); 
    REQUIRE(videoWall.getRows() == 2); 
}

TEST_CASE("LEDVideoWallAspects constructor creates correct object with different panel and aspect ratio") 
{
    LEDVideoWallAspects videoWall(300, 600, 5, 3);
    
    REQUIRE(videoWall.getPanelWidth() == 300);
    REQUIRE(videoWall.getPanelHeight() == 600);
    REQUIRE(videoWall.getWallWidth() == 1500); 
    REQUIRE(videoWall.getWallHeight() == 1800); 
	REQUIRE(videoWall.getCols() == 5); 
    REQUIRE(videoWall.getRows() == 3); 
}

TEST_CASE("LEDVideoWallAspects throws exception for invalid aspect ratio dimensions") 
{
    REQUIRE_THROWS_AS(LEDVideoWallAspects(100, 200, 0, 0), std::invalid_argument);
    REQUIRE_THROWS_AS(LEDVideoWallAspects(100, 200, -4, 6), std::invalid_argument);
}

TEST_CASE("LEDVideoWallAspects throws exception for invalid panel dimensions (negative)") 
{
    REQUIRE_THROWS_AS(LEDVideoWallAspects(-100, 200, 4, 6), std::invalid_argument);
    REQUIRE_THROWS_AS(LEDVideoWallAspects(100, -200, 4, 6), std::invalid_argument);
    REQUIRE_THROWS_AS(LEDVideoWallAspects(100, 200, 4, -6), std::invalid_argument);
}

TEST_CASE("LEDVideoWallAspects throws exception for zero dimensions") 
{
    REQUIRE_THROWS_AS(LEDVideoWallAspects(0, 200, 4, 6), std::invalid_argument);
    REQUIRE_THROWS_AS(LEDVideoWallAspects(100, 0, 4, 6), std::invalid_argument);
    REQUIRE_THROWS_AS(LEDVideoWallAspects(100, 200, 0, 6), std::invalid_argument);
    REQUIRE_THROWS_AS(LEDVideoWallAspects(100, 200, 4, 0), std::invalid_argument);
}

TEST_CASE("LEDVideoWallAspects display method outputs correct string") 
{
    LEDVideoWallAspects videoWall(500, 500, 4, 6);
    
    std::stringstream ss;
    videoWall.display(ss);

    REQUIRE(ss.str() == "LED Video Wall:\n"
                        "Panel Size: 500mm x 500mm\n"
                        "Wall Size: 1000mm x 1500mm\n"
                        "Columns: 2, Rows: 3\n");
}

TEST_CASE("Create LEDVideoWallAspects using Factory and verify properties") 
{
    Factory& factory = Factory::getFactory();
    std::vector<int> params = {500, 500, 16, 9};
    
    Screen* screen = factory.createScreen("LEDVideoWallAspects", params);

    LEDVideoWallAspects* videoWall = dynamic_cast<LEDVideoWallAspects*>(screen);
    REQUIRE(videoWall != nullptr);  
    
    REQUIRE(videoWall->getPanelWidth() == 500);
    REQUIRE(videoWall->getPanelHeight() == 500);
    REQUIRE(videoWall->getWallWidth() == 8000);
    REQUIRE(videoWall->getWallHeight() == 4500);
    
    REQUIRE(videoWall->getCols() == 16); 
    REQUIRE(videoWall->getRows() == 9);
    
    std::stringstream ss;
    videoWall->display(ss);
    REQUIRE(ss.str() == "LED Video Wall:\n"
                        "Panel Size: 500mm x 500mm\n"
                        "Wall Size: 8000mm x 4500mm\n"
                        "Columns: 16, Rows: 9\n");

    delete screen;
}