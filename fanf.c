#include <stdio.h>
#include "printf.h"
#include <locale.h>
int main()
{
	int i;
	unsigned long long int j;
	char *str;
	unsigned long l;
	setlocale(LC_ALL, "");
	ft_printf("%lc\n",L'±');
	printf("%lc\n",L'±');
	printf("%c\n",200);
	//ft_printf("%lc\n",);
	//    printf("%s\n",ft_itoa_base(L'難', 2));
	//        printf("%s\n",ft_itoa_base(L'Δ', 2));
	//            printf("%s\n",ft_itoa_base('a', 2));
	//                printf("%s\n",ft_itoa_base('b', 2));
	return (1);
}
