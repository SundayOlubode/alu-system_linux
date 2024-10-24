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
        printf("[.] bytes object info\n");
        if (!PyBytes_Check(p))
        {
                printf("  [ERROR] Invalid Bytes Object\n");
                return;
        }

        Py_ssize_t size = PyBytes_Size(p);
        char *string = PyBytes_AsString(p);

        printf("  size: %zd\n", size);
        printf("  trying string: %s\n", string);

        printf("  first %zd bytes:", size < 10 ? size + 1 : 10);
        for (Py_ssize_t i = 0; i < size && i < 10; i++)
        {
                printf(" %02x", (unsigned char)string[i]);
        }
        printf("\n");
}
