#pragma once

#define CPRINT(...) {printf("%s:%i: %s", __FILE__, __LINE__, __PRETTY_FUNCTION__); __VA_OPT__(printf(": "); printf(__VA_ARGS__);) printf("\n"); fflush(nullptr);}

class TestClass {
public:
    char _context[1024];

	TestClass(const char *context);

	~TestClass();
};
