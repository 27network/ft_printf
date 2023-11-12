/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:25:49 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/12 02:51:32 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <ft/io.h>
# include <ft/list.h>
# include <ft/macros.h>
# include <ft/mem.h>
# include <ft/string/parse.h>
# include <ft/string.h>

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef PF_FORMAT_SYMBOL
#  define PF_FORMAT_SYMBOL "%" 
# endif // PF_FORMAT_SYMBOL

# ifndef PF_FLAGS
#  define PF_FLAGS "-0 #+"
# endif // PF_FLAGS

# ifndef PF_SPECIFIERS
#  define PF_SPECIFIERS "cspdiuxX%"
# endif // PF_SPECIFIERS

# define PF_LEFT_JUSTIFY	1  // (1 << 0)
# define PF_ZERO_PAD		2  // (1 << 1)
# define PF_SPACE			4  // (1 << 2)
# define PF_HASH			8  // (1 << 3)
# define PF_PLUS			16 // (1 << 4)

typedef struct s_fmt_spec
{
	uint8_t	flags;
	int		width;
	int		precision;

	char	*length;
	char	specifier;

	char	*raw;
}	t_fmt_spec;

typedef char	*(*t_type_formatter)(t_fmt_spec *spec, va_list args);

/* Wrapper functions */

int			ft_printf(const char *format, ...);
int			ft_dprintf(int fd, const char *format, ...);
int			ft_vprintf(const char *format, va_list args);
int			ft_vdprintf(int fd, const char *format, va_list args);
int			ft_asprintf(char **str_ptr, const char *format, ...);
int			ft_vasprintf(char **str_ptr, const char *format, va_list args);

char		*ft_format(const char *format, ...);
char		*ft_vformat(const char *format, va_list args);

/* Parsing & formatting */

t_fmt_spec	*ft_new_spec(const char *fmt, int *i, va_list args);
t_fmt_spec	*ft_parse_spec(const char *format, va_list args);
char		*ft_format_spec(t_fmt_spec *spec, va_list args, int *len);
void		ft_free_spec(t_fmt_spec *spec);

/* Formatters */

char		*ft_format_char(t_fmt_spec *spec, va_list args);
char		*ft_format_hex(t_fmt_spec *spec, va_list args);
char		*ft_format_int(t_fmt_spec *spec, va_list args);
char		*ft_format_percent(t_fmt_spec *spec, va_list args);
char		*ft_format_pointer(t_fmt_spec *spec, va_list args);
char		*ft_format_string(t_fmt_spec *spec, va_list args);
char		*ft_format_uint(t_fmt_spec *spec, va_list args);

/* Flag mutators */

char		*ft_hash_mutator_prefix(t_fmt_spec *spec, char *str);

char		*ft_leftjustify_mutator(t_fmt_spec *spec, char *str);

char		*ft_padding_mutator(t_fmt_spec *spec, char *str);

char		*ft_precision_mutator_str(t_fmt_spec *spec, char *str);
char		*ft_precision_mutator_int(t_fmt_spec *spec, char *str);

/* String */

typedef struct s_str
{
	char	*inner;
	size_t	length;
}	t_str;

void		ft_str_init(t_str *self, char **str_target);
t_str		*ft_str_create(char *str, size_t length);
t_str		*ft_str_append(t_str *self, t_str *other);

/* Utils */

/**
 * @brief	Prepends a sign to a string based on the format flags.
 *
 * @param	spec	The format specifier.
 * @param	str		The string to prepend the sign to.
 * @param	neg		Whether the number is negative.
 *
 * @return	The string with the sign prepended.
 *
 * @note	The string `str` must be freed by the caller.
 */
char		*ft_prepend_sign(t_fmt_spec *spec, char *str, int neg);
char		*ft_strnjoin(char *s1, size_t n1, char *s2, size_t n2);
void		ft_append(char **dest, int dest_len, char *src, int src_len);

#endif // FT_PRINTF_H
