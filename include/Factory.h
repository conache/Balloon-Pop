#ifndef FACTORY_H
#define FACTORY_H


class Factory
{
    public:
        Factory();
        virtual ~Factory();
        virtual SceneObject* newItem()=0;
    protected:

    private:
};

#endif // FACTORY_H
