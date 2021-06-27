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
    template <class InputIt>
    InputIt copy(InputIt first, InputIt last, InputIt d_first)
    {
        int size = last - first;

        for (int i = 0; i < size; i++)
        {
            *(d_first + i) = *(first + i);
        }

        return d_first + 1;
    }

}
#endif
