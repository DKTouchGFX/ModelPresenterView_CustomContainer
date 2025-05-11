#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

volatile int color[3]={0,0,255};

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
	//modelListener->setBGColor(color[0], color[1], color[2]);	//update the GUI color
}

void Model::setColors(int r, int g, int b)
{
	color[0] = r;
	color[1] = g;
	color[2] = b;
}

void Model::getColors(int& r, int& g, int& b)
{
	r = color[0];
	g = color[1];
	b = color[2];
}
