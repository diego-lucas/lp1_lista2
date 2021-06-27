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
    template <class ForwardIt>
    ForwardIt rotate(ForwardIt first, ForwardIt n_first, ForwardIt last)
    {
        int size = last - first;
        int n_first_index = n_first - first;
        int posicao;
        int B[size];

        for (int i = 0; i < size; i++)
        {
            posicao = i - n_first_index;
            if (posicao < 0)
                posicao = posicao + size;
            B[posicao] = *(first + i);
        }

        for (int i = 0; i < size; i++)
        {
            *(first + i) = B[i];
        }

        return (first + (size - n_first_index));
    }

}
#endif
