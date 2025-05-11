#ifndef MODEL_HPP
#define MODEL_HPP

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();
	void setColors(int r, int g, int b);
	void getColors(int& r, int& g, int& b);
protected:
    ModelListener* modelListener;
};

#endif // MODEL_HPP
