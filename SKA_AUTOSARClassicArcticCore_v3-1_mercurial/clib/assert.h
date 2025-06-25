/*-------------------------------- Arctic Core ------------------------------
 * Copyright (C) 2013, ArcCore AB, Sweden, www.arccore.com.
 * Contact: <contact@arccore.com>
 * 
 * You may ONLY use this file:
 * 1)if you have a valid commercial ArcCore license and then in accordance with  
 * the terms contained in the written license agreement between you and ArcCore, 
 * or alternatively
 * 2)if you follow the terms found in GNU General Public License version 2 as 
 * published by the Free Software Foundation and appearing in the file 
 * LICENSE.GPL included in the packaging of this file or here 
 * <http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt>
 *-------------------------------- Arctic Core -----------------------------*/

#ifndef ASSERT_H_
#define ASSERT_H_

#include <stdio.h>
#include <stdlib.h>

#if defined(NDEBUG)
#define assert(_x)
#else
#define assert(_x)  if (!(_x)) { \
/*	                  printf("%s %s %s\n",#_x,__FILE__,__LINE__); */ \
                      while(1){}; \
                     }
#endif

#endif /* ASSERT_H_ */
