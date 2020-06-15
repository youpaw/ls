//
// Created by youpaw on 18.03.2020.
//

#include <stdlib.h>
#include "flags.h"

void 	del_flags(t_flags **flags)
{
	free(*flags);
	*flags = NULL;
}
