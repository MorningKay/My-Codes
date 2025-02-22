#include "GenList.h"

int main()
{
    GenList gl;
    InitGenList(gl);

    char *ga = "(1,2,3)";
    char *gb = "(1,(2,3))";
    char *gc = "(1,(2),3)";
    char *gd = "((1,2),3)";
    char *ge = "((1,2,3))";
    char *gf = "()";
    char *gg = "(1,(2,(3,4)),5)";

    int i, j = 2, *p = &i;
    *p = j;
    *p = *&j;

    CreateGenList(gl, gg);
    ShowGenList(gl);
    printf("\n");
    int length = GenListLength(gl);
    printf("length = %d\n", length);

    int depth = GenListDepth(gl);
    printf("depth = %d\n", depth);
}