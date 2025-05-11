#include <gui/mainscreen_screen/mainScreenView.hpp>

mainScreenView::mainScreenView()
{

}

void mainScreenView::setupScreen()
{
    mainScreenViewBase::setupScreen();
	presenter->getModelColors();	//get latest colors from the model
	setBGColor(presenter->colorToSet[0], presenter->colorToSet[1], presenter->colorToSet[2]);	//update the background color
	settingsButton.setButtonText("Settings\0");
	settingsButton.setColor(presenter->colorToSet[0], presenter->colorToSet[1], presenter->colorToSet[2]);
	backButton.setColor(presenter->colorToSet[0], presenter->colorToSet[1], presenter->colorToSet[2]);
}

void mainScreenView::tearDownScreen()
{
    mainScreenViewBase::tearDownScreen();
}

void mainScreenView::setBGColor(int red, int green, int blue)
{
	background.setBGColor(red, green, blue);
}
