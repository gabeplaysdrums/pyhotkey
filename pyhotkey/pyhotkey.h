// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the PYHOTKEY_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// PYHOTKEY_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef PYHOTKEY_EXPORTS
#define PYHOTKEY_API __declspec(dllexport)
#else
#define PYHOTKEY_API __declspec(dllimport)
#endif

// This class is exported from the pyhotkey.dll
class PYHOTKEY_API Cpyhotkey {
public:
	Cpyhotkey(void);
	// TODO: add your methods here.
};

extern PYHOTKEY_API int npyhotkey;

PYHOTKEY_API int fnpyhotkey(void);
