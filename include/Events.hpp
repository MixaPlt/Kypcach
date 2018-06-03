#pragma once
#include <set>
#include <functional>
#include <memory>
#include <assert.h>
#include "Resources.hpp"
#include <queue>
#include <iostream>
#include <typeinfo>

struct delegate_container
{
public:
    virtual void call()
    {

    }
};

template< class T, class M > class container_void : public delegate_container {};

template< class T >
struct container_void< T, void (T::*)(void) > : public delegate_container
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

struct delegate_void
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
    template< class T, class U > delegate_void* add( T* object, U method )
    {
        delegate_void *dv = new delegate_void (object, method);
        poll.insert(dv);
        return dv;
    }
    void call()
    {
        for(std::set< delegate_void* >::iterator i = poll.begin(); i != poll.end(); i++)
        {
            (*i)->call();
        }
    }
    void remove(delegate_void* dv)
    {
        std::set< delegate_void* >::iterator i = poll.find(dv);
        if(i != poll.end())
            poll.erase(i);
    }
};



//!--------------------------------------------------------------------------------------------
//!############################################################################################
//!--------------------------------------------------------------------------------------------

template <class S>
struct delegate_sender_container
{
public:
    virtual void call(S sender)
    {

    }
};

template< class T, class M, class S > struct container_sender : public delegate_sender_container<S> {};

template< class T, class S >
struct container_sender< T, void (T::*)(S), S > : public delegate_sender_container<S>
{
private:
    T *object;
    void (T::*method)(S);
public:
    container_sender(T *_object, void (T::*_method)(S)) : object(_object), method(_method) {}
    void call(S sender)
    {
        (object->*method)(sender);
    }
};

template<class S>
struct delegate_sender
{
private:
    delegate_sender_container<S> *container;
public:
    template< class T, class U >  delegate_sender( T* object, U method )
    {
        container = new container_sender<T, U, S>(object, method);
    }
    void call(S sender) const
    {
        container->call(sender);
    }
    ~delegate_sender()
    {
        delete(container);
    }
};

template<class S>
struct event_sender
{
private:
    std::vector< delegate_sender<S>* > poll;
public:
    template< class T, class U > delegate_sender<S>* add( T* object, U method )
    {
        delegate_sender<S> *dv = new delegate_sender<S> (object, method);
        poll.push_back(dv);
        return dv;
    }
    void call(S sender)
    {
        for(int i = 0; i != poll.size(); i++)
        {
            (poll[i])->call(sender);
        }
    }
};

//!-----------------------------------------------------------------------------------------------------------
//############################################################################################################
//!-----------------------------------------------------------------------------------------------------------

struct delete_container
{
public:
    virtual void call()
    {

    }
};

template <class T>
struct d_container : public delete_container
{
private:
    T* object;
public:
    void call()
    {
        delete(object);
        std::cout << typeid(object).name() << "\t deleted\t ( " << object <<" )\n";
    }
    d_container(T* _object) : object(_object)
    {

    }
};


struct DeleteSet
{
private:
    std::queue<delete_container*> qu;
public:
    template <class T> void add(T* object)
    {
        qu.push(new d_container<T>(object));
    }
    void call()
    {
        while(!qu.empty())
        {
            qu.front()->call();
            qu.pop();

        }
    }
};


