#include "ft_printf.h"

int	unsig_numlen(unsigned long num)
{
	int	len;

	len = 0;
	if (num == 0)
		len ++;
	while (n)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

char	*ft_unsig_itoa(unsigned int num)
{
	char			*str;
	int				len;
	unsigned long	nb;

	nb = num;
	len = unsig_numlen(nb);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
		str[len--] = '\0';
	str[0] = '0';
	str[len] = '\0';
	if (nb < 0)
		nb = nb * -1;
	while (nb > 0)
	{
		str[len] = nb % 10 + 48;
		nb = nb / 10;
		len--;
	}
	return (str);
}
/*
int main() {
    unsigned int num = 12345;
    char *str = ft_unsig_itoa(num);

    if (str != NULL) {
        printf("Número: %u\n", num);
        printf("Representación en cadena: %s\n", str);
        free(str);
    } else {
        printf("No se pudo asignar memoria para la cadena.\n");
    }

    return 0;
}
*/