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

void print_python_list(PyObject *p)
{
        PyListObject *list = (PyListObject *)p;

        printf("[*] Python list info\n");
        printf("[*] Size of the Python List = %ld\n", list->ob_base.ob_size);
        printf("[*] Allocated = %ld\n", list->allocated);

        for (Py_ssize_t i = 0; i < list->ob_base.ob_size; i++)
        {
                printf("Element %ld: %s\n", i, list->ob_item[i]->ob_type->tp_name);

                if (PyBytes_Check(list->ob_item[i]))
                {
                        print_python_bytes(list->ob_item[i]);
                }
        }
}