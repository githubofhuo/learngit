#include<stdio.h>
#include "C:\Program Files\eclipse\plugins\org.python.pydev_4.5.4.201601292234\pysrc\pydevd_attach_to_process\dll\python.h"
int main()
{
	Py_Initialize();
	PyRun_SimpleString("x= 'brave' + 'sir robin'");
	return 0;
} 
