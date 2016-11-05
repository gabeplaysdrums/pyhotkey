// pyhotkey.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "pyhotkey.h"


// This is an example of an exported variable
PYHOTKEY_API int npyhotkey=0;

// This is an example of an exported function.
PYHOTKEY_API int fnpyhotkey(void)
{
    return 42;
}

// This is the constructor of a class that has been exported.
// see pyhotkey.h for the class definition
Cpyhotkey::Cpyhotkey()
{
    return;
}
