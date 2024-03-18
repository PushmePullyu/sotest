#include <stdio.h>
#include "testclass.h"
#include "libfoo.h"

static void someSOFuncWithStatic() {
	CPRINT("This is someSOFuncWithStatic()");
	static TestClass testObj("libfoo");
}

extern "C" void someSOFunc(void) {
	CPRINT("This is someSOFunc()");
	someSOFuncWithStatic();
}
