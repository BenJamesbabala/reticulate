#ifndef __RETICULATE_TYPES__
#define __RETICULATE_TYPES__

#include "libpython.h"
using namespace libpython;

#include <Rcpp.h>

inline void python_object_finalize(PyObject* object) {
  if (object != NULL)
    Py_DecRef(object);
}

typedef Rcpp::XPtr<PyObject, Rcpp::PreserveStorage, python_object_finalize>
                                                                  PyObjectXPtr;


#endif // __RETICULATE_TYPES__
