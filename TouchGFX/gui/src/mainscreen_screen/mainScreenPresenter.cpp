#include <gui/mainscreen_screen/mainScreenView.hpp>
#include <gui/mainscreen_screen/mainScreenPresenter.hpp>

mainScreenPresenter::mainScreenPresenter(mainScreenView& v)
    : view(v)
{

}

void mainScreenPresenter::activate()
{
	
}

void mainScreenPresenter::deactivate()
{

}

void mainScreenPresenter::getModelColors()
{
	model->getColors(colorToSet[0], colorToSet[1],colorToSet[2]);
}
