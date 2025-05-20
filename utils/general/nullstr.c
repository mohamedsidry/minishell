#include "../../include/header.h"




void nullstr(char **strptr)
{
	if (!strptr || !(*strptr))
		return ;
	free(*strptr);
	*strptr = NULL;
}
