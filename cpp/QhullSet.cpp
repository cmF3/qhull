/****************************************************************************
**
** Copyright (C) 2008-2010 C. Bradford Barber. All rights reserved.
** $Id: //product/qhull/main/rel/cpp/QhullSet.cpp#16 $$Change: 1137 $
** $DateTime: 2010/01/02 21:58:11 $$Author: bbarber $
**
****************************************************************************/

#//! QhullSet -- Qhull's facet structure, facetT, as a C++ class

#include "QhullError.h"
#include "QhullSet.h"

#ifdef _MSC_VER  // Microsoft Visual C++ -- warning level 4 
#endif

namespace orgQhull {

#//static members

setT QhullSetBase::
s_empty_set;

// Same code for qh_setsize [qset.c] and QhullSetBase::count
int QhullSetBase::count(const setT *set) 
{
    int size;
    const int *sizep;

    if (!set)
        return(0);
    sizep= SETsizeaddr_(set);
    if ((size= *sizep)) {
        size--;
        if (size > set->maxsize) {
            throw QhullError(10032, "QhullSet internal error: current set size %d is greater than maximum size %d\n",
                size, set->maxsize);
            // FIXUP -- qh_setprint(qhmem.ferr, "set: ", set);
        }
    }else
        size= set->maxsize;
    return size;
}


}//namespace orgQhull
