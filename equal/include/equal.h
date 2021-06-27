#ifndef GRAAL_H
#define GRAAL_H

#include <utility>
using std::pair;
#include <iterator>
using std::distance;
#include <algorithm>
using std::sort;

namespace graal
{

    /*! 
 * TODO: documentação no estilo doxygen
 */

    template <class InputIt1, class InputIt2, class Equal>
    bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, Equal eq)
    {
        int size = last1 - first1;

        for (int i = 0; i < size; i++)
        {
            if (!(eq(*(first1 + i), *(first2 + i))))
                return false;
        }

        return true;
    }

    template <class InputIt1, class InputIt2, class Equal>
    bool equal(InputIt1 first1, InputIt1 last1,
               InputIt2 first2, InputIt2 last2,
               Equal eq)
    {
        int size1 = last1 - first1;
        int size2 = last2 - first2;

        if (size1 != size2)
            return false;

        for (int i = 0; i < size1; i++)
        {
            if (!(eq(*(first1 + i), *(first2 + i))))
                return false;
        }
        return true;
    }

}
#endif
