#include "libft.h"
#include "ft_printf.h"

t_printf	*ft_print_percent(t_printf *data)
{
	if (data->zero_flag == 1 && data->precision == -1)
	{
		data->precision = data->width;
		data->width = 0;
	}
	if (data->minus_flag == 0)
		ft_display(data, ' ', data->width - 1, 1);
	ft_display(data, '0', data->precision - 1, 1);
	write(1, "%", 1);
	data->length++;
	if (data->minus_flag == 1)
		ft_display(data, ' ', data->width - 1, 1);
	return (data);
}
