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
    template <class InputIt, class UnaryPredicate>
    InputIt find_if(InputIt first, InputIt last, UnaryPredicate p)
    {
        int size = last - first;
        for (int i = 0; i < size; i++)
        {
            if (p(*(first + i)))
                return first + i;
        }
        return last;
    }

}
#endif
