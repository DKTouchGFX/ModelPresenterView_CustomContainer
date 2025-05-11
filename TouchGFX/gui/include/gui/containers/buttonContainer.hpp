#ifndef BUTTONCONTAINER_HPP
#define BUTTONCONTAINER_HPP

#include <gui_generated/containers/buttonContainerBase.hpp>

class buttonContainer : public buttonContainerBase
{
public:
    buttonContainer();
    virtual ~buttonContainer() {}

    virtual void initialize();
	virtual void setColor(uint8_t red, uint8_t green, uint8_t blue);
	virtual void setButtonText(const char* text);
protected:
};

#endif // BUTTONCONTAINER_HPP
