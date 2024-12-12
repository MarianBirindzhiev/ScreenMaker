#ifndef LEDVIDEOWALL_H
#define LEDVIDEOWALL_H

#include "Screen.h"
#include "Helper.h"

class LEDVideoWall : public Screen
{

public:

    void display(std::ostream& out) const override;

    int getPanelWidth() const {return this->panelWidth;}
    int getPanelHeight() const {return this->panelHeight;}
    long getWallWidth() const {return this->wallWidth;}
    long getWallHeight() const {return this->wallHeight;}
    int getRows() const {return this->wallHeight / this->panelHeight;}
    int getCols() const {return this->wallWidth / this->panelWidth;}

protected:

    LEDVideoWall() = default;

    void setPanelWidth(int width); 
    void setPanelHeight(int height); 
    void setWallWidth(int width); 
    void setWallHeight(int height); 
    
private:

    int panelWidth;
    int panelHeight;
    int wallWidth;
    int wallHeight;

};

class LEDVideoWallFreeform : public LEDVideoWall
{
public:

    LEDVideoWallFreeform(int _panelWidth, int _panelHeight, int _wallWidth, int _wallHeight);
};

class LEDVideoWallAspects : public LEDVideoWall
{
public:

    LEDVideoWallAspects(int _panelWidth, int _panelHeight, int _aspectWidth, int _aspectHeight);
};

#endif // LEDVIDEOWALL_H