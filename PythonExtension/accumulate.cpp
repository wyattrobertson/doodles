#include <Python.h>
#include "numpy/ndarraytypes.h"
#include "numpy/ufuncobject.h"
#include "numpy/npy_3kcompat.h"
#include "accumulate.hpp"
#include <vector>

static PyObject* method_accumulate(PyObject* self, PyObject* args)
{
    PyObject* python_object;
  
    if(!PyArg_ParseTuple(args, "O", &python_object))
    {
        return NULL;
    }
    if (!PyList_Check(python_object) && !PyArray_Check(python_object))
    {
        PyErr_Format(PyExc_TypeError, "The argument must be a list or numpy array");
        return NULL;
    }

    PyObject* numpy_object = PyArray_FROM_OTF(python_object, NPY_DOUBLE, NPY_IN_ARRAY);
    PyArrayObject* numpy_array_object = (PyArrayObject*)(numpy_object);

    int32_t number_of_elements = PyArray_SIZE(numpy_array_object);
    auto p = (npy_double*)PyArray_GETPTR1(numpy_object, 0);
    std::vector<double> double_array(p, p + number_of_elements);

    int64_t total = accumulate(std::begin(double_array), std::end(double_array), 0); 

    return PyLong_FromLong(total);
}

static PyMethodDef AccumulateMethods[] = {
    {"accumulate", method_accumulate, METH_VARARGS, "Python interface for an implementation of C++'s accumulate function"},
    {NULL, NULL, 0, NULL}
};


static struct PyModuleDef accumulatemodule = {
    PyModuleDef_HEAD_INIT,
    "accumulate",
    "Python interface for an implementation of C++'s accumulate function",
    -1,
    AccumulateMethods
};

PyMODINIT_FUNC PyInit_accumulate(void)
{
    auto mod = PyModule_Create(&accumulatemodule);
    import_array();
    return mod;
}