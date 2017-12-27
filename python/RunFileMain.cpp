
#include <Python.h>

int main(int argc, char** argv)
{
    Py_SetProgramName(argv[0]);  /* optional but recommended */
    Py_Initialize();
    FILE* file = fopen(argv[1], "r");
    PyRun_SimpleFile(file, argv[1]);
    fclose(file);
    Py_Finalize();
    return 0;
}
