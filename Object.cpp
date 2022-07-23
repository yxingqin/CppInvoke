#include"Object.h"
#include<cassert>


INVOKE_MAP


#include<iostream>
void Object::invoke(Object* object, const char* funName)
{
	auto it = invoke_map.find(funName);
	assert(it != invoke_map.end());
	(object->*(it->second))();
}

void Object::invokeTest()
{
	std::cout << "invokeTest\n";
}
