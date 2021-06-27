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
    template <class InputIt, class Equal>
    InputIt unique(InputIt first, InputIt last, Equal eq)
    {
        int size = last - first;
        int ocorrencias;

        for (int i = 0; i < size; i++)
        {
            ocorrencias = 0;
            InputIt atual = (first + i);
            for (int j = 0; j < size; j++)
            {
                if (eq(*(first + j), *atual))
                {
                    ocorrencias++;
                    if (ocorrencias > 1)
                    {
                        // "Remove" um elemento e diminui o tamanho do array
                        for (int k = j; k < size; k++)
                        {
                            *(first + k) = *(first + k + 1);
                        }
                        size--;
                    }
                }
            }
        }
        // Retorna o primeiro elemento + o tamanho do array
        // ou seja, o "novo" ultimo elemento
        return (first + size);
    }

}
#endif
