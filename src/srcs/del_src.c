//
// Created by youpaw on 17.03.2020.
//

#include <stdlib.h>
#include "srcs.h"

void	del_src(t_src **src)
{
	free(*src);
	*src = NULL;
}
