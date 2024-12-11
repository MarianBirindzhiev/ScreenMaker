#include "catch2/catch_all.hpp"
#include "Factory.h"

TEST_CASE("LEDVideoWallFreeform constructor creates correct object") 
{
    LEDVideoWallFreeform videoWall(100, 200, 400, 600);
    
    REQUIRE(videoWall.getPanelWidth() == 100);
    REQUIRE(videoWall.getPanelHeight() == 200);
    REQUIRE(videoWall.getWallWidth() == 400); 
    REQUIRE(videoWall.getWallHeight() == 600); 
	REQUIRE(videoWall.getCols() == 4); 
    REQUIRE(videoWall.getRows() == 3); 
}

TEST_CASE("Create LEDVideoWallFreeform with adjusted wall height") 
{
    LEDVideoWallFreeform videoWall(500, 500, 2000, 1750);
    
    REQUIRE(videoWall.getPanelWidth() == 500);
    REQUIRE(videoWall.getPanelHeight() == 500);
    REQUIRE(videoWall.getWallWidth() == 2000); 
    REQUIRE(videoWall.getWallHeight() == 1500); 
	REQUIRE(videoWall.getCols() == 4); 
    REQUIRE(videoWall.getRows() == 3); 
}

TEST_CASE("Create LEDVideoWallFreeform with adjusted wall width") 
{
    LEDVideoWallFreeform videoWall(250, 500, 1800, 2000);
    
    REQUIRE(videoWall.getPanelWidth() == 250);
    REQUIRE(videoWall.getPanelHeight() == 500);
    REQUIRE(videoWall.getWallWidth() == 1750); 
    REQUIRE(videoWall.getWallHeight() == 2000); 
	REQUIRE(videoWall.getCols() == 7); 
    REQUIRE(videoWall.getRows() == 4); 
}

TEST_CASE("LEDVideoWallFreeform throws exception for invalid panel dimensions") 
{
    REQUIRE_THROWS_AS(LEDVideoWallFreeform(100, 200, 50, 50), std::invalid_argument);
}

TEST_CASE("LEDVideoWallFreeform throws exception for invalid panel dimensions (negative)") 
{
    REQUIRE_THROWS_AS(LEDVideoWallFreeform(-100, 200, 400, 600), std::invalid_argument);
    REQUIRE_THROWS_AS(LEDVideoWallFreeform(100, -200, 400, 600), std::invalid_argument);
    REQUIRE_THROWS_AS(LEDVideoWallFreeform(100, 200, -400, 600), std::invalid_argument);
    REQUIRE_THROWS_AS(LEDVideoWallFreeform(100, 200, 400, -600), std::invalid_argument);
}

TEST_CASE("LEDVideoWallFreeform throws exception for zero dimensions") 
{
    REQUIRE_THROWS_AS(LEDVideoWallFreeform(0, 200, 400, 600), std::invalid_argument);
    REQUIRE_THROWS_AS(LEDVideoWallFreeform(100, 0, 400, 600), std::invalid_argument);
    REQUIRE_THROWS_AS(LEDVideoWallFreeform(100, 200, 0, 600), std::invalid_argument);
    REQUIRE_THROWS_AS(LEDVideoWallFreeform(100, 200, 400, 0), std::invalid_argument);
}

TEST_CASE("LEDVideoWallFreeform display method outputs correct string") 
{
    LEDVideoWallFreeform videoWall(500, 500, 2000, 1750);
    
    std::stringstream ss;
    videoWall.display(ss);

    REQUIRE(ss.str() == "LED Video Wall:\n"
                        "Panel Size: 500mm x 500mm\n"
                        "Wall Size: 2000mm x 1500mm\n"
                        "Columns: 4, Rows: 3\n");
}

TEST_CASE("Create LEDVideoWallFreeform using Factory and verify properties") 
{
    Factory& factory = Factory::getFactory();
    std::vector<int> params = {100, 200, 400, 600};
    
    Screen* screen = factory.createScreen("LEDVideoWallFreeform", params);

    LEDVideoWallFreeform* videoWall = dynamic_cast<LEDVideoWallFreeform*>(screen);
    REQUIRE(videoWall != nullptr);  
    
    REQUIRE(videoWall->getPanelWidth() == 100);
    REQUIRE(videoWall->getPanelHeight() == 200);
    REQUIRE(videoWall->getWallWidth() == 400);
    REQUIRE(videoWall->getWallHeight() == 600);
    
    REQUIRE(videoWall->getCols() == 4); 
    REQUIRE(videoWall->getRows() == 3);
    
    std::stringstream ss;
    videoWall->display(ss);
    REQUIRE(ss.str() == "LED Video Wall:\n"
                        "Panel Size: 100mm x 200mm\n"
                        "Wall Size: 400mm x 600mm\n"
                        "Columns: 4, Rows: 3\n");

    delete screen;
}