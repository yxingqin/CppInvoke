#ifndef OBJECT_H
#define OBJECT_H

#include <unordered_map>

#define STRING(X) (#X)
#define INVOKE_MAP_ITEM(FUN_NAME)             \
    {                                         \
        STRING(FUN_NAME), &Object::##FUN_NAME \
    }

//注册要反射的方法
#define INVOKE_MAP Object::InvokeMap const Object::invoke_map = { \
                       INVOKE_MAP_ITEM(invokeTest),               \
};

#include <string>
class Object
{
    using FunPtr = void (Object::*)(void);
    using InvokeMap = std::unordered_map<std::string, FunPtr>;
    static const InvokeMap invoke_map; //方法名到函数入口地址的映射
public:
    static void invoke(Object *object, const char *funName); //调用反射机制方法
    Object() = default;
    virtual ~Object() = default;
    void invokeTest();
};

#endif
