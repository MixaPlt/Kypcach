#include <set>
#include <functional>
#include <memory>
#include <assert.h>

class delegate_container
{
public:
    virtual void call()
    {

    }
};

template< class T, class M > class container_void : public delegate_container {};

template< class T >
class container_void< T, void (T::*)(void) > : public delegate_container
{
private:
    T *object;
    void (T::*method)();
public:
    container_void(T *_object, void (T::*_method)()) : object(_object), method(_method) {}
    void call()
    {
        (object->*method)();
    }
};

class delegate_void
{
private:
    delegate_container *container;
public:
    template< class T, class U >  delegate_void( T* object, U method )
    {
        container = new container_void<T, U>(object, method);
    }
    void call() const
    {
        container->call();
    }
    ~delegate_void()
    {
        delete(container);
    }
};

struct event
{
private:
    std::set< delegate_void* > poll;
public:
    template< class T, class U > void add( T* object, U method )
    {
        poll.insert(new delegate_void (object, method));
    }
    void call()
    {
        for(std::set< delegate_void* >::iterator i = poll.begin(); i != poll.end(); i++)
        {
            (*i)->call();
        }
    }
};


