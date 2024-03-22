#include <cstdlib>
#include <dlfcn.h>
#include <cstdio>

#ifndef DSOFILE
#pragma message "DSOFILE not defined, using default"
#define DSOFILE "somelib.so"
#endif

#define info(MSG) { printf("%s\n", MSG); fflush(nullptr); }
#define fail(MSG) { printf("ERROR: %s\n", MSG); fflush(nullptr); exit(1); }
#define fail_if(MSG) { const char *msg = MSG; if (msg) fail(msg); }

int main() {
	void *soHandle;
	using FuncPtr = auto (*)(void) -> void;
	FuncPtr soFunc;

	info("Loading SO");
	dlerror();
	soHandle = dlopen(DSOFILE, RTLD_LAZY);
	fail_if(dlerror());

	info("Getting function pointer from SO");
	dlerror();
	soFunc = reinterpret_cast<FuncPtr>(dlsym(soHandle, "someSOFunc"));
	fail_if(dlerror());

	info("Calling SO function");
	if (!soFunc)
		fail("SO function is nullptr");
	soFunc();

	info("Unloading SO");
	dlerror();
	dlclose(soHandle);
	fail_if(dlerror());

	info("Returning from main");
	return 0;
}
