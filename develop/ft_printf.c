#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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

// ##########################################
// ################# LIBFT ###################
// ##########################################
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}


void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count * size < count && count * size < size)
		return (NULL);
	ptr = malloc(count * size);
	if (ptr == 0)
		return (ptr);
	ft_bzero(ptr, count * size);
	return (ptr);
}



static int	ft_intlen(long nbr)
{
	int	size;

	size = 0;
	while (nbr >= 10)
	{
		nbr /= 10;
		++size;
	}
	return (size + 1);
}

static int	ft_power(int base, int power)
{
	int	i;
	int	result;

	i = 0;
	result = 1;
	while (i < power)
	{
		result = result * base;
		i++;
	}
	return (result);
}

static char	*ft_write(char *str, long nbr, int sign, int len)
{
	int	i;

	i = 0;
	if (sign < 0)
	{
		str[i++] = '-';
		len-- ;
	}
	while (len--)
	{
		str[i++] = (nbr / ft_power(10, len)) + '0';
		nbr = nbr % ft_power(10, len);
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;
	long	nbr;

	len = 0;
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		len = 1;
	}
	nbr = (long)n * (long)sign;
	len += ft_intlen (nbr);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	return (ft_write(str, nbr, sign, len));
}


int ft_printf(char *fmt,...)
{
	va_list ap;
	int len;
	char *s;
	char c;
	int num;

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
			} else if (*fmt == 'd' || *fmt == 'i')
			{
				num = va_arg(ap,int);
				s = ft_itoa(num);
				len+= write(1,s,ft_strlen(s));
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
	int num = 4242;
	// len = ft_printf("%s %%percent %c \n",text,c);
	len = ft_printf("%d",num);
	// len = ft_printf("Hello\n");
	printf("Len of String is %d", len);
	return (0);
}