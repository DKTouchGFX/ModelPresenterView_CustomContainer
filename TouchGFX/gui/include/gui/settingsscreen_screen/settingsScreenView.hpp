#ifndef SETTINGSSCREENVIEW_HPP
#define SETTINGSSCREENVIEW_HPP

#include <gui_generated/settingsscreen_screen/settingsScreenViewBase.hpp>
#include <gui/settingsscreen_screen/settingsScreenPresenter.hpp>

class settingsScreenView : public settingsScreenViewBase
{
public:
    settingsScreenView();
    virtual ~settingsScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
	
	void sliderRedHandler(int value);
	void sliderGreenHandler(int value);
	void sliderBlueHandler(int value);
	void setBGColor(int red, int green, int blue);
	
protected:
};

#endif // SETTINGSSCREENVIEW_HPP
