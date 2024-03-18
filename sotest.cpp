#include <stdio.h>

#define SDL_MAIN_HANDLED
#include "SDL.h"

#include "testclass.h"

#define SONAME "./libfoo.so"

using MyFuncPtr = auto (*)(void) -> void;

union MySdlFuncPtr {
	void* voidPtr;
	MyFuncPtr funcPtr;
};

static void fail() {
	CPRINT("error: %s", SDL_GetError());
	exit(1);
}

static void cleanup() {
	CPRINT("This is cleanup()");
}

static void localFuncWithStatic() {
	CPRINT("This is localFuncWithStatic()");
	static TestClass someObj("sotest");
}

int main() {
	void *soHandle = nullptr;
	MySdlFuncPtr sdlFuncPtr;

	CPRINT("Registering cleanup function");
	if(atexit(cleanup)) {
		CPRINT("Registration failed");
		exit(1);
	}

	SDL_Init(SDL_INIT_EVERYTHING);

	CPRINT("Loading SO");
	soHandle = SDL_LoadObject(SONAME);
	if (!soHandle)
		fail();

	CPRINT("Getting function pointer from SO");
	sdlFuncPtr.voidPtr = SDL_LoadFunction(soHandle, "someSOFunc");
	if(!sdlFuncPtr.voidPtr)
		fail();

	CPRINT("Calling SO function");
	(*sdlFuncPtr.funcPtr)();

	CPRINT("Calling local function");
	localFuncWithStatic();

	CPRINT("Unloading SO");
	SDL_UnloadObject(soHandle);

	CPRINT("Calling SDL_Quit");
	SDL_Quit();

	CPRINT("Returning from main");
	return 0;
}
