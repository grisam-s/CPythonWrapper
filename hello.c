#include <Python.h>
#include "add.h"

static PyObject* helloworld(PyObject* self)
{
    char *j = my();
    return Py_BuildValue("s", j);
}

static char helloworld_docs[] =
    "helloworld( ): Any message you want to put here!!\n";

static PyMethodDef helloworld_funcs[] = {
    {"helloworld", (PyCFunction)helloworld, 
     METH_NOARGS, helloworld_docs},
    {NULL}
};

void inithelloworld(void)
{
    Py_InitModule3("helloworld", helloworld_funcs,
                   "Extension module example!");
}

/*static PyObject *add(PyObject *self, PyObject *args) {
   int a;
   int b;

   if (!PyArg_ParseTuple(args, "ii", &a, &b)) {
      return NULL;
   }
   //int c = add(a,b);
   return Py_BuildValue("i", a+b);
}

static PyMethodDef add_methods[] = { { "add", (PyCFunction)add, METH_VARARGS, NULL }, { "add", add, METH_VARARGS, NULL }, { NULL, NULL, 0, NULL } };

void initadd(void)
{
    Py_InitModule3("add", add_methods,
                   "Extension module example!");
}*/