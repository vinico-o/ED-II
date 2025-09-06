#include "arvoreDigitalBusca.h"

//Encontrando o kesimo bit da chave numero
unsigned int bit(unsigned numero, int k)
{
    //Para deixar o kesimo bit como o menos significativo precisamos de
    //NBITS - k - 1 rotacoes para direita, o "1" indica o bit menos significativo
    return (numero >> NBITS - k - 1) & 1;
}
