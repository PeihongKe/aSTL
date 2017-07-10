#ifndef _ANOTHERSTL_FUNDAMENTAL_
#define _ANOTHERSTL_FUNDAMENTAL_

namespace anotherSTL
{
	typedef int ptrdiff_t;
	struct _true_type {};
	struct _false_type {};

	bool isTrueType(_true_type)
	{
		return true;
	}

	bool isFalseType(_false_type)
	{
		return false;
	}
}



#endif