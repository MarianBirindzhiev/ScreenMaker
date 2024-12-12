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

    setPanelWidth(_panelWidth);
    setPanelHeight(_panelHeight);

    int panels_lcm = HelperFunctions::lcm(_panelWidth, _panelHeight);
    
    int cols = (panels_lcm / _panelWidth) * _aspectWidth;
    int rows = (panels_lcm / _panelHeight) * _aspectHeight;

    int aspects_gcd = HelperFunctions::gcd(cols, rows);
    cols /= aspects_gcd;
    rows /= aspects_gcd;

    setWallWidth(cols * _panelWidth);
    setWallHeight(rows * _panelHeight);
}