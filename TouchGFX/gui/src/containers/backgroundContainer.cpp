#include <gui/containers/backgroundContainer.hpp>
#include <touchgfx/Color.hpp>

backgroundContainer::backgroundContainer()
{

}

void backgroundContainer::initialize()
{
    backgroundContainerBase::initialize();
}

void backgroundContainer::setBGColor(uint8_t red, uint8_t green, uint8_t blue)
{
	backgroundColor.setColor(touchgfx::Color::getColorFromRGB(red, green, blue));
}
