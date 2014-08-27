#ifndef GDCORE_VERSION_H
#define GDCORE_VERSION_H

namespace AutoVersion{

	//Date Version Types
	static const char GDCore_DATE[] = "24";
	static const char GDCore_MONTH[] = "08";
	static const char GDCore_YEAR[] = "2014";

	//Software Status
	static const char GDCore_STATUS[] = "Release";
	static const char GDCore_STATUS_SHORT[] = "r";

	//Standard Version Type
	static const long GDCore_MAJOR = 3;
	static const long GDCore_MINOR = 4;
	static const long GDCore_BUILD = 73;
	static const long GDCore_REVISION = 0;

	//Miscellaneous Version Types
	#define GDCore_RC_FILEVERSION 3,4,73,0
	#define GDCore_RC_FILEVERSION_STRING "3, 4, 73, 0\0"
	static const char GDCore_FULLVERSION_STRING[] = "3.4.73.0";

	//These values are to keep track of your versioning state, don't modify them.
	static const long GDCore_BUILD_HISTORY = 0;


}
#endif //GDCORE_VERSION_H
