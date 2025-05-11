#ifndef BACKGROUNDCONTAINER_HPP
#define BACKGROUNDCONTAINER_HPP

#include <gui_generated/containers/backgroundContainerBase.hpp>

class backgroundContainer : public backgroundContainerBase
{
public:
    backgroundContainer();
    virtual ~backgroundContainer() {}

    virtual void initialize();
	virtual void setBGColor(uint8_t red, uint8_t green, uint8_t blue);
protected:
};

#endif // BACKGROUNDCONTAINER_HPP
