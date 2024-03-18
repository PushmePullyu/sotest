#include <stdio.h>
#include <string.h>
#include "testclass.h"


TestClass::TestClass(const char *context) {
        strncpy(_context, context, 1024);
        _context[1023] = '\0';
		CPRINT("TestClass ctor: context: %s, this=%p", _context, this);
	}

TestClass::~TestClass() {
		CPRINT("TestClass dtor: context: %s, this=%p", _context, this);
	}
