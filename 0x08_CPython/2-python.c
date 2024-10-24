#include <Python.h>

void print_python_list(PyObject *py_list)
{
        if (!PyList_Check(py_list))
        {
                printf("Invalid List Object\n");
                return;
        }

        Py_ssize_t size = PyList_Size(py_list);
        Py_ssize_t allocated = ((PyListObject *)py_list)->allocated;

        printf("[*] Python list info\n");
        printf("[*] Size of the Python List = %zd\n", size);
        printf("[*] Allocated = %zd\n", allocated);

        for (Py_ssize_t i = 0; i < size; i++)
        {
                PyObject *item = PyList_GetItem(py_list, i);
                printf("Element %zd: %s\n", i, item->ob_type->tp_name);
        }
}

void print_python_bytes(PyObject *p)
{
        PyBytesObject *bytes = (PyBytesObject *)p;
        Py_ssize_t size = 0;

        printf("[.] bytes object info\n");
        if (!PyBytes_Check(p))
        {
                printf("  [ERROR] Invalid Bytes Object\n");
                return;
        }

        size = PyBytes_Size(p);
        printf("  size: %zd\n", size);
        printf("  trying string: %s\n", bytes->ob_sval);
        if (size < 10)
                printf("  first %zd bytes: ", size + 1);
        else
                printf("  first 10 bytes: ");
        for (Py_ssize_t i = 0; i < size + 1 && i < 10; i++)
        {
                printf("%02hhx", bytes->ob_sval[i]);
                if (i + 1 < size + 1 && i + 1 < 10)
                        printf(" ");
        }
        printf("\n");
}