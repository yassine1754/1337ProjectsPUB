/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:28:16 by yadib             #+#    #+#             */
/*   Updated: 2024/11/21 01:22:20 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef enum e_data_convert
{
	NOT_FIND = -1,
	CHARACTER = 0,
	STRING = 1,
	ADDRESS = 2,
	DECIMALS = 3,
	INTEGERS = 4,
	UNSIGNED_DEC = 5,
	LOWER_HEX = 6,
	UPPER_HEX = 7,
	PERCENT_SIGN = 8
}	t_data_conv;

void		ft_check_types(char check, size_t *index);
void		handle_casses_b2(const char *array,
				va_list args, size_t *index, size_t *length);
char		*ft_strchr(const char *s, int c);
void		ft_bzero(void *s, size_t n);
size_t		ft_convert_to_hex(unsigned int degits, short type_data);
size_t		ft_print_address(void *arr);
int			ft_printf(const char *string, ...);
size_t		ft_putstr_fd(char *s, int fd);
size_t		ft_putchar_fd(char c, int fd);
size_t		ft_putnbr_fd(unsigned int n, short type_data);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
#endif
