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
        PyBytesObject *pb = (PyBytesObject *)p;

        printf("[.] bytes object info\n");
        if (PyBytes_Check(p))
        {
                printf("  size: %ld\n", pb->ob_base.ob_size);
                printf("  trying string: %s\n", pb->ob_sval);
                if (pb->ob_base.ob_size < 10)
                        printf("  first %ld bytes:", pb->ob_base.ob_size + 1);
                else
                        printf("  first 10 bytes:");

                for (int i = 0; i <= pb->ob_base.ob_size && i < 10; ++i)

                {
                        printf(" %02hhx", pb->ob_sval[i]);
                }
                printf("\n");
        }
        else
        {
                printf("  [ERROR] Invalid Bytes Object\n");
        }
}