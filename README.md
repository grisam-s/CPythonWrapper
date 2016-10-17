# CPythonWrapper
Taking a C/C++ library and embedding it into Python

The approach of this project is fairly straightforward. Given a C or C++ library, I want to be able to use each function in that library in Python. Effectively, I want to create a C/C++ dll file that extends C++ into Python. To do this, I would essentially use a blackbox model, creating a PyObject function for each corresponding C function, where the PyObject function would take in the same arguments (and return the same output) as the C function, and call the C function to actually execute the code.

That is, if I am trying to add two numbers:

    int add(int x, int y)
    {
        return x+y;
    }

In the dll file, I would essentially create a function that goes like:

    static PyObject *add(PyObject *self, PyObject *args) {
        int a;
        int b;

        if (!PyArg_ParseTuple(args, "ii", &a, &b)) {
            return NULL;
        }
        
        int c = add(a,b);
        return Py_BuildValue("i", a+b);
    }

The end goal is to get the same inputs and outputs, but use the underlying C/C++ library to fill the blackbox. 
