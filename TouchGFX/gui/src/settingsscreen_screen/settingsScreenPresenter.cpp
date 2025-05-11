#include <gui/settingsscreen_screen/settingsScreenView.hpp>
#include <gui/settingsscreen_screen/settingsScreenPresenter.hpp>

settingsScreenPresenter::settingsScreenPresenter(settingsScreenView& v)
    : view(v)
{

}

void settingsScreenPresenter::activate()
{

}

void settingsScreenPresenter::deactivate()
{

}

void settingsScreenPresenter::setModelColors()
{
	model->setColors(colorToSet[0],colorToSet[1],colorToSet[2]);
}


void settingsScreenPresenter::getModelColors()
{
	model->getColors(colorToSet[0], colorToSet[1],colorToSet[2]);
}

