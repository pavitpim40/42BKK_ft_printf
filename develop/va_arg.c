   #include <stdarg.h>
   #include <stdio.h>

 void foo(char *fmt, ...)
{
	va_list ap, ap2;
	int d;
	char c, *s;

	va_start(ap, fmt);
	va_copy(ap2, ap);
	while (*fmt)
	{
		switch(*fmt++) {
			case 's':                       /* string */
				s = va_arg(ap, char *);
				printf("string %s\n", s);
				break;
			case 'd':                       /* int */
				d = va_arg(ap, int);
				printf("int %d\n", d);
				break;
			case 'c':                       /* char */
				c = va_arg(ap, int);
				printf("char %c\n", c);
				break;
			}
	}
    va_end(ap);
    va_end(ap2);
}

int main () 
{
	int num = 42;
	char *text = "42BKK";
	foo("Hello %d %s",num,text);
	return (0);
}