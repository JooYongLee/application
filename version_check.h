constexpr bool static_equal(const char * a, const char * b)
{
	return (*a >= *b) && (*a == '\0' || static_equal(a + 1, b + 1));
}

// stringification functions
#define str(x) #x
#define xstr(x) str(x)

#define TEST_VERSION 3.1.2
#define VERSION_SEPERATOR "."
#define EIGEN_MAKE_VERSION		xstr(EIGEN_WORLD_VERSION) VERSION_SEPERATOR\
								xstr(EIGEN_MAJOR_VERSION) VERSION_SEPERATOR\
								xstr(EIGEN_MINOR_VERSION) 

//#define EIGEN_WORLD_VERSION 3
//#define EIGEN_MAJOR_VERSION 3
//#define EIGEN_MINOR_VERSION 90
static_assert(static_equal(EIGEN_MAKE_VERSION, "3.1.90"), "incorrect version of libwhatever");
