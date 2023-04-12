#ifndef TEMPLATE_TEST_H
#define TEMPLATE_TEST_H

#include <boost/shared_ptr.hpp>
#include <cstdlib>
#include <string>
#include <ctime>

class TopicHandle
{
public:
    TopicHandle()
    {
        srand(time(NULL));
        name = "unregistered handle" + std::to_string(rand() % 100000);
        is_register = false;
    }

    bool operator<(const TopicHandle &handle) const { return this->name < handle.name; }

    bool operator==(const TopicHandle &handle) const { return this->name == handle.name; }

public:
    bool is_register;
    std::string name;
};

class BaseTopic
{
public:
    virtual ~BaseTopic() {}
};

#define TSInterObjectPtr boost::shared_ptr<BaseTopic>
// typedef boost::shared_ptr<BaseTopic> TSInterObjectPtr;

class TSTopicContext
{
public:
    virtual ~TSTopicContext() { ptr = nullptr; }
    TSTopicContext() {}
    TSTopicContext(const TopicHandle &_handle, TSInterObjectPtr _ptr)
    {
        handle = _handle;
        ptr = _ptr;
    }
    TSInterObjectPtr GetTopic() { return ptr; }
    const TopicHandle &GetTopicHandle() { return handle; }

public:
    TopicHandle handle;
    TSInterObjectPtr ptr;
};
typedef boost::shared_ptr<TSTopicContext> TSTopicContextPtr;
//#define TSTopicContextPtr boost::shared_ptr<TSTopicContext>

#endif // TEMPLATE_TEST_H
