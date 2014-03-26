#include <stdio.h>

int test(a, b)
int a;
int b;
<%
return a + b;
%>

main()
<%
printf("%d\n", test(1, 2));
%>
