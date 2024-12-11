#include "LEDVideoWall.h"

///
/// LEDVideoWall
///

void LEDVideoWall::display(std::ostream& out) const 
{
    out << "LED Video Wall:\n"
        << "Panel Size: " << panelWidth << "mm x " << panelHeight << "mm\n"
        << "Wall Size: " << wallWidth << "mm x " << wallHeight << "mm\n"
        << "Columns: " << wallWidth / panelWidth << ", Rows: " << wallHeight / panelHeight<<'\n';
}

void LEDVideoWall::setPanelWidth(int width) 
{
    if(width <= 0)
        throw std::invalid_argument("The panel width must be greater than 0!");
    this->panelWidth = width;
}

void LEDVideoWall::setPanelHeight(int height) 
{
    if(height <= 0)
        throw std::invalid_argument("The panel height must be greater than 0!");
     this->panelHeight = height;
}

void LEDVideoWall::setWallWidth(int width) 
{
    if(width <= 0)
        throw std::invalid_argument("The wall width must be greater than 0!");
    this->wallWidth = width;
}

void LEDVideoWall::setWallHeight(int height) 
{
    if(height <= 0)
        throw std::invalid_argument("The wall height must be greater than 0!");
    this->wallHeight = height;
}

///
/// LEDVideoWallFreefrom
///

LEDVideoWallFreeform::LEDVideoWallFreeform(int _panelWidth, int _panelHeight, int _wallWidth, int _wallHeight)
{
    if(_wallWidth < _panelWidth || _wallHeight < _panelHeight)
        throw std::invalid_argument("Wall dimensions must be at least as large as the panel dimensions!");
        
    setPanelWidth(_panelWidth);
    setPanelHeight(_panelHeight);

    int cols = _wallWidth / getPanelWidth();
    int rows = _wallHeight / getPanelHeight();

    setWallWidth(cols * getPanelWidth());
    setWallHeight(rows * getPanelHeight());
}

///
/// LEDVideoWallAspects
///

LEDVideoWallAspects::LEDVideoWallAspects(int _panelWidth, int _panelHeight, int _aspectWidth, int _aspectHeight)
{
    if(_aspectHeight == 0 || _aspectWidth == 0)
        throw std::invalid_argument("Aspect ratio dimensions must be greater than 0!");

    int gcd = HelperFunctions::gcd(_aspectHeight, _aspectWidth);
    int cols = _aspectWidth / gcd;
    int rows = _aspectHeight / gcd;

    setPanelWidth(_panelWidth);
    setPanelHeight(_panelHeight);

    setWallWidth(cols * getPanelWidth());
    setWallHeight(rows * getPanelHeight());
}