
#include <unistd.h>
#include <stdarg.h>

int ft_putchar(char c)
{
	write(1,&c,1);
	return(1);
}

int ft_putstr(char *s)
{
	int i = 0 ;
	if(!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while(*s)
	{
		i += ft_putchar(*s);
		s++;
	}
	return (i);
}

void ft_putnbr(int nbr, int *i)
{
	if(nbr == -2147483648)
	{
		write(1, "-2147483648",11);
		*i+=11;
		return ;
	}
	if(nbr >= 0 && nbr <= 9)
	{
		(*i)++;
		ft_putchar(nbr + '0');
	}
	else if(nbr < 0)
	{
		(*i)++;
		ft_putchar('-');
		ft_putnbr(nbr * (-1),i);
	}
	else
	{
		ft_putnbr(nbr/10, i);
		ft_putnbr(nbr%10, i);
	}
}

void ft_puthex(unsigned int nbr, int *i)
{
	char *base="0123456789abcdef";
	if(nbr >= 0 && nbr <= 15)
	{
		(*i)++;
		ft_putchar(base[nbr]);
	}
		else
	{
		ft_puthex(nbr/16, i);
		ft_puthex(nbr%16, i);
	}
}

int condition(va_list args, char s)
{
	int count = 0;
	if(s == 's')
	{
		count += ft_putstr(va_arg(args, char *));
	}
	else if (s == 'd')
	{
		ft_putnbr(va_arg(args, int), &count);
	}
	else if (s == 'x')
	{
		ft_puthex(va_arg(args, unsigned int), &count);
	}
	return count;
}

int ft_printf(const char *s, ...)
{
	va_list(args);
	int count = 0;
	va_start(args,s);
	while(*s)
	{
		if(*s == '%')
		{
			s++;
			count += condition(args, *s);
		}
		else
		{
			count += ft_putchar(*s);
		}
		s++;
	}
	va_end(args);
	return(count);

}
/*
#include <limits.h>
#include <stdio.h>
int main()
{
	int len;
	len = 0;
	len = ft_printf("%d\n",5454545454123);
	printf("len = %d\n ", len);	
	len = ft_printf("%d\n",123);
	printf("%d\n ", len);	
}*/
