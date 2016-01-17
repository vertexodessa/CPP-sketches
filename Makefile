
all: defer

defer: defer.h defer_test.cpp
	g++ defer_test.cpp -o defer