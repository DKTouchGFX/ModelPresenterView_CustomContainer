#include <gui/settingsscreen_screen/settingsScreenView.hpp>

settingsScreenView::settingsScreenView()
{

}

void settingsScreenView::setupScreen()
{
    settingsScreenViewBase::setupScreen();
	presenter->getModelColors();	//get latest colors from the model
	sliderRed.setValue(presenter->colorToSet[0]);
    sliderGreen.setValue(presenter->colorToSet[1]);
    sliderBlue.setValue(presenter->colorToSet[2]);
}

void settingsScreenView::tearDownScreen()
{
    settingsScreenViewBase::tearDownScreen();
}

void settingsScreenView::sliderRedHandler(int value)
{
	presenter->colorToSet[0]=value;
	setBGColor(presenter->colorToSet[0], presenter->colorToSet[1], presenter->colorToSet[2]);	//update the current screen to reflect the changes
	presenter->setModelColors();	//send the colors to the player struct
}

void settingsScreenView::sliderGreenHandler(int value)
{
	presenter->colorToSet[1]=value;
	setBGColor(presenter->colorToSet[0], presenter->colorToSet[1], presenter->colorToSet[2]);	//update the current screen to reflect the changes
	presenter->setModelColors();	//send the colors to the player struct
}

void settingsScreenView::sliderBlueHandler(int value)
{
	presenter->colorToSet[2]=value;
	setBGColor(presenter->colorToSet[0], presenter->colorToSet[1], presenter->colorToSet[2]);	//update the current screen to reflect the changes
	presenter->setModelColors();	//send the colors to the player struct
}

void settingsScreenView::setBGColor(int red, int green, int blue)
{
	background.setBGColor(red, green, blue);
	background.invalidate();
	backButton.setColor(red, green, blue);
	backButton.invalidate();
}