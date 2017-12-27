#include <Python.h>

// https://docs.python.org/2/extending/extending.html
static PyObject *SpamError; // used for python error state

static PyObject* spam_system(PyObject *self, PyObject *args)
{
    const char *command;
    int sts;

    if (!PyArg_ParseTuple(args, "s", &command))
        return NULL;
    // this just sends the commands to the unix System
    sts = system(command);
    if (sts < 0) {
        PyErr_SetString(SpamError, "System command failed");
        return NULL;
    }
    return PyLong_FromLong(sts);
}

static PyMethodDef SpamMethods[] = {
    {"system",  spam_system, METH_VARARGS /*" It should normally always be METH_VARARGS or METH_VARARGS | METH_KEYWORDS; "*/,
     "Execute a shell command."},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};


PyMODINIT_FUNC initspam(void)
{
    PyObject *m;

    m = Py_InitModule("spam", SpamMethods);
    if (m == NULL)
        return;

    char name[] = "spam.error";
    PyObject* base = NULL;
    PyObject* dict = NULL;
    SpamError = PyErr_NewException(name, base, dict);
    Py_INCREF(SpamError);
    PyModule_AddObject(m, "error", SpamError);
}

int main(int argc, char *argv[])
{
    /* Pass argv[0] to the Python interpreter */
    Py_SetProgramName(argv[0]);

    /* Initialize the Python interpreter.  Required. */
    Py_Initialize();

    /* Add a static module */
    initspam();

    // run the file
    FILE* file = fopen(argv[1], "r");
    PyRun_SimpleFile(file, argv[1]);
    fclose(file);

    Py_Finalize();
}
