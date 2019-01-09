test_driver: test_driver.o test.o
        c++ -o test_driver test_driver.o test.o
test_driver.o: test_driver.cpp test.h
        c++ -c test_driver.cpp
test.o: test.cpp test.h
        c++ -c test.cpp
