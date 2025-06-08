#include "../../include/header.h"

size_t skip_space(char *line, size_t *pos)
{
	size_t idx;

	idx = 0;
	while (line[idx] && ft_isspace(line[idx]))
		idx++;
	*pos += idx;
	return (SUCCESS);
}