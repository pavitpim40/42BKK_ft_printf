#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

// void print()
// ap == argument to be process

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int ft_printf(char *fmt,...)
{
	va_list ap;
	int len;
	char *s;
	char c;

	va_start(ap,fmt);
	len = 0;
	while(*fmt)
	{
		c = *fmt;
		if(*fmt == '%')
		{
			fmt++;
			if(*fmt == 's') 
			{
				s = va_arg(ap, char *);
				write(1,s,ft_strlen(s));
				fmt++;
			}
				
		} else {
			write(1,fmt,1);
			len++;
			fmt++;
		}
		
			
	
	}
	va_end(ap);
	return (len);
}


int main ()
{
	char *text = "42BKK";
	int len;
	len = ft_printf("%s\n\n",text);
	// len = ft_printf("Hello\n");
	printf("Len of String is %d", len);
	return (0);
}