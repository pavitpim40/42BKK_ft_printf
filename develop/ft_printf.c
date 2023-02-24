#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

// void print()
// ap == argument to be process

typedef struct s_print
{
	va_list	args;
	int		width;
	int		precision;
	int		zero;
	int		point;
	int		dash;
	int		total_length;
	int		sign;
	int		is_zero;
	int		percent;
	int		space;
}	t_print;

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
				len += write(1,s,ft_strlen(s));
				fmt++;
			}
			else if (*fmt == 'c')
			{
				c = va_arg(ap,int);
				len += write(1,&c,1);
				fmt++;
			}
			else if(*fmt == '%')
			{
				// c = va_arg(ap,int);
				len += write(1,"%",1);
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
	char c = '-';
	int len;
	len = ft_printf("%s %%percent %c \n",text,c);
	// len = ft_printf("Hello\n");
	printf("Len of String is %d", len);
	return (0);
}