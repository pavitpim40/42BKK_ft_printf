#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>


// ap == argument to be process
int ft_printf(char *fmt,...)
{
	va_list ap;
	int len;

	va_start(ap,fmt);
	len = 0;
	while(*fmt)
	{
		len += (int)write(1,fmt,1);
		fmt++;
	}
	va_end(ap);
	return (len);
}


int main ()
{
	char *text = "42BKK";
	int len;
	len = ft_printf("Hello\n");
	printf("Len of String is %d", len);
	return (0);
}