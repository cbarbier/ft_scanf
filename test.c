#include <stdio.h>
#include "includes/libft.h"
#include <locale.h>

int		main(void)
{
	int n;

	setlocale(LC_ALL, "");
	ft_printf("%C\n\n\n\n", 8364);
	ft_printf("%C\n\n\n\n", L'€');
//	printf("{%f}{%F}", -1444565444646.6465424242242454654, -1444565444646.6465424242242454654);
	ft_printf("{%ls %d %u %x %c %s %b %p %lc}\n", L"test", 10, 100, 1000, 42, "42", 123, 13546546i, 945);
	n = printf("\033[1m%c\033[0m\n", 'z');
	printf("%d\n", ft_strlen(EOC));
	ft_printf("{red}cedric{no}barbier{blu}blue{grn}green{no}white{yel}yellow{no}.\n");
	ft_printf("{% 10f}\n\n", 1444565444646.6465424242242);
	ft_printf("{% 10.10f}\n\n", 1444565444646.6465424242242);
//	ft_printf("{%10f}\n\n", 1.23);
//	ft_printf("{%010f}\n\n", -1.23);
/*	printf("%d\n", (int)10.5368);
	printf("%hhld\n", "128");
	printf("%E\n", 200.450);
	printf("%e\n", 1.450);
	printf("{%.10f}\n", 1.450);
	printf("{%f}\n", 112314.45017897);
	printf("{%15.3e}\n", 912314.45017897);
	printf("{%F}\n", 1.450);
	printf("{%5f}\n", 1.450);
	printf("{%5F}\n", 1.450);
	printf("{%10f}\n", 1.450);
	printf("{%10F}\n", 1.450);
	printf("{%010.5f}\n", 1.450);
	printf("{%10.5F}\n", 1.450);
	printf("{%.5f}\n", 1.450);
	printf("{%.5F}\n", 1.450);
	printf("{%.0f}\n", 1.450);
	printf("{%.0F}\n", 1.450);
	printf("%F\n", 1.450);
	printf("%g\n", 1.450);
	printf("%G\n", 1.450);
	printf("%a\n", 1.450);
	printf("%A\n", 300.451);
	printf("%A\n", 0.01);
	printf("%A\n", 0.02);
	printf("%A\n", 0.03);
	printf("%A\n", 0.04);
	printf("%A\n", 0.05);
	printf("%A\n", 0.11);
	printf("%#+10.2E\n", 5.0 / 3);
	printf("%#+10.2e\n", 5.0 / 3);
	printf("|%-10.0f|\n", 0.0);
	printf("%10f\n", 1.02);
	*/
//	printf("%d\n", printf("%d%dblabla13215454%C\n",4, 888,  0xfffffff));

	return 0;
}
