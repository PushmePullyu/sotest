#include <cstdio>

struct TestClass {
	TestClass() { printf("TestClass ctor, this=%p\n", static_cast<void*>(this)); }
	~TestClass() { printf("TestClass dtor, this=%p\n", static_cast<void*>(this)); }
};

extern "C" void someSOFunc(void) {
	printf("This is someSOFunc()\n");
	static TestClass testObj;
}
