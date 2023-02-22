//
// Created by Olimi on 2023/1/29.
//

#ifndef PURECPPINCMAKE_REFLECTIONIMPL_H
#define PURECPPINCMAKE_REFLECTIONIMPL_H

#include <iostream>
#include "string"
#include "map"
using namespace std;

typedef void *(*PTRCreateObj)(void);

class RegisterFactory
{
public:
    static RegisterFactory* getInstance();

    void* getClassObjByName(string className);
    void registerClass(string className, PTRCreateObj createFunc);

private:
    map<string, PTRCreateObj> m_classCreatorMap;
    RegisterFactory()= default;;
};

void *RegisterFactory::getClassObjByName(string className) {
    auto iter = m_classCreatorMap.find(className);
    if(iter != m_classCreatorMap.end())
        return iter->second();
    return nullptr;
}

void RegisterFactory::registerClass(string className, PTRCreateObj createFunc) {
    m_classCreatorMap.insert(pair(className, createFunc));
}

RegisterFactory *RegisterFactory::getInstance() {
    static RegisterFactory instance;
    return &instance;
}

class RegisterAction
{
public:
    RegisterAction(string name, PTRCreateObj func){
        RegisterFactory::getInstance()->registerClass(name, func);
    }
};

#define REGISTER(className) \
    className* createTest##className() \
    { \
    return new className; \
    }                       \
    RegisterAction g_creatorRegister##className(#className, (PTRCreateObj)createTest##className);

// here is example
class TestClassA
{
public:
    void print(){ cout << "TestClassA"<<endl;}
};
REGISTER(TestClassA)

//auto classA = (TestClassA*)RegisterFactory::getInstance()->getClassObjByName("TestClassA");
//classA->print();

#endif //PURECPPINCMAKE_REFLECTIONIMPL_H
