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
    template <class ForwardIt, class Comparison>
    void sort(ForwardIt first, ForwardIt last, Comparison cmp)
    {
        int size = last - first;
        int temp;

        for (int i = 0; i < size; i++)
        {
            for (int j = i; j < size; j++)
            {
                if (cmp(*(first + j), *(first + i)))
                {
                    temp = *(first + i);
                    *(first + i) = *(first + j);
                    *(first + j) = temp;
                }
            }
        }
    }

}
#endif
