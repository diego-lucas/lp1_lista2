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
 * Exemplo de documentação seguindo o formato Doxygen
 *
 * @tparam Itr iterator para o range.
 * @tparam Compare o tipo de uma função bool(const T &a, const T &b)
 *
 * @param first Ponteiro para o primeiro elemento do range
 * @param last Ponteiro para a posição logo após o último elemento do range
 * @param cmp A função de comparação que retorna true quando o primeiro parâmetro é menor do que o segundo
 *
 * @return Um std::pair contendo o menor e maior elemento, nesta ordem
 *
 */
    template <typename Itr, typename Compare>
    std::pair<Itr, Itr> minmax(Itr first, Itr last, Compare cmp)
    {
        Itr min = first;
        Itr max = first;

        int size = last - first;

        for (int i = 0; i < size; i++)
        {
            Itr atual = first + i;
            if (cmp(*atual, *min))
            {
                min = atual;
            }
            else if (cmp(*max, *atual))
            {
                max = atual;
            }
        }

        // std::cout << "max: " << *max << std::endl;
        // std::cout << "min: " << *min << std::endl;

        return std::make_pair(min, max);
    }

}
#endif
