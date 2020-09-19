#To use run "make" to build all of these apps

build_all: build_test6 build_postfix build_delimiters

#run with "./test6"
build_test6: test6.cpp
	g++ -o test6 -std=c++11 -Wno-deprecated test6.cpp

#run with "./postfix"
build_postfix: postfix.cpp
	g++ -o postfix -std=c++11 -Wno-deprecated postfix.cpp

#run with "./delimiters"
build_delimiters: delimiters.cpp
	g++ -o delimiters -std=c++11 -Wno-deprecated delimiters.cpp
