#include <gui/containers/buttonContainer.hpp>
#include <touchgfx/Color.hpp>

buttonContainer::buttonContainer()
{

}

void buttonContainer::initialize()
{
    buttonContainerBase::initialize();
}

void buttonContainer::setButtonText(const char* text)
{
	Unicode::strncpy(flexButton1Buffer, text, FLEXBUTTON1_SIZE);
	flexButton1.invalidate();
}

void buttonContainer::setColor(uint8_t red,uint8_t green,uint8_t blue)
{
	backgroundColor.setColor(touchgfx::Color::getColorFromRGB(red, green, blue));
	backgroundColor.invalidate();
	flexButton1.setWildcardTextColors(touchgfx::Color::getColorFromRGB(red, green, blue), touchgfx::Color::getColorFromRGB(red+20, green+20, blue+20));
	flexButton1.invalidate();
}
