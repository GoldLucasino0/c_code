#ifndef _PROCESS_CLASS
#define _PROCESS_CLASS

#include <iostream>

/* the process class */

class Process { /* extend me! */
public:
  Process(){}
  int start(); /* throws ForkException */
  virtual void run() {
    /* override me! */
  }
};

/* and its exception */

class ForkException {
public:
  ForkException(int error);
  ~ForkException();
  char* getMessage();
  friend std::ostream& operator << (std::ostream& out,const ForkException& fe);
private:
  char* message;
};

#endif
