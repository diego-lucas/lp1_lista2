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
    template <class ForwardIt, class UnaryPredicate>
    ForwardIt partition(ForwardIt first, ForwardIt last, UnaryPredicate p)
    {
        int size = last - first;

        // Quando as posicoes de first e last forem a mesma, eh porque
        // esta ordenado como queremos
        while (first != last)
        {
            // Encontra o primeiro elemento que NAO ATENDE ao predicato
            while (p(*first))
            {
                ++first;
                // Checa se chegou ao final
                if (first == last)
                {
                    return first;
                }
            }
            // Encontra o primeiro elemento na ordem inversa que ATENDE ao predicado
            do
            {
                --last;
                // Checa se chegou ao final
                if (first == last)
                {
                    return first;
                }
            } while (!p(*last));
            // Troca a posição dos dois elementos encontrados
            std::swap(*first, *last);
            // Avanca a posicao do first para a proxima checagem
            ++first;
        }

        // Depois de feitas as trocas nos valores, last sera o
        // primeiro elemento do range que NAO ATENDE ao predicato
        return last;
    }

}
#endif
