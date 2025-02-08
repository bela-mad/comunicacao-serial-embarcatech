#include "animation.h"

// Matriz de animação dos números com intensidade de luz reduzida
const uint32_t numeros_low[10][25] = {
{
0x00000000, 0x3160300, 0x3160300, 0x3160300, 0x00000000, 
0x00000000, 0x3160300, 0x00000000, 0x3160300, 0x00000000, 
0x00000000, 0x3160300, 0x00000000, 0x3160300, 0x00000000, 
0x00000000, 0x3160300, 0x00000000, 0x3160300, 0x00000000, 
0x00000000, 0x3160300, 0x3160300, 0x3160300, 0x00000000
},
{
0x00000000, 0x00000000, 0x20d0200, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x20d0200, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x20d0200, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x20d0200, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x20d0200, 0x00000000, 0x00000000
},
{
0x00000000, 0x190e00, 0x190e00, 0x190e00, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x190e00, 0x00000000, 
0x00000000, 0x190e00, 0x190e00, 0x190e00, 0x00000000, 
0x00000000, 0x190e00, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x190e00, 0x190e00, 0x190e00, 0x00000000
},
{
0x00000000, 0x6191500, 0x6191500, 0x6191500, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x6191500, 0x00000000, 
0x00000000, 0x6191500, 0x6191500, 0x6191500, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x6191500, 0x00000000, 
0x00000000, 0x6191500, 0x6191500, 0x6191500, 0x00000000
},
{
0x00000000, 0x190000, 0x00000000, 0x190000, 0x00000000, 
0x00000000, 0x190000, 0x00000000, 0x190000, 0x00000000, 
0x00000000, 0x190000, 0x190000, 0x190000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x190000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x190000, 0x00000000
},
{
0x00000000, 0x71900, 0x71900, 0x71900, 0x00000000, 
0x00000000, 0x71900, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x71900, 0x71900, 0x71900, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x71900, 0x00000000, 
0x00000000, 0x71900, 0x71900, 0x71900, 0x00000000
},
{
0x00000000, 0xf020000, 0xf020000, 0xf020000, 0x00000000, 
0x00000000, 0xf020000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0xf020000, 0xf020000, 0xf020000, 0x00000000, 
0x00000000, 0xf020000, 0x00000000, 0xf020000, 0x00000000, 
0x00000000, 0xf020000, 0xf020000, 0xf020000, 0x00000000
},
{
0x00000000, 0xc190000, 0xc190000, 0xc190000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0xc190000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0xc190000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0xc190000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0xc190000, 0x00000000
},
{
0x00000000, 0xe190400, 0xe190400, 0xe190400, 0x00000000, 
0x00000000, 0xe190400, 0x00000000, 0xe190400, 0x00000000, 
0x00000000, 0xe190400, 0xe190400, 0xe190400, 0x00000000, 
0x00000000, 0xe190400, 0x00000000, 0xe190400, 0x00000000, 
0x00000000, 0xe190400, 0xe190400, 0xe190400, 0x00000000
},
{
0x00000000, 0x19191900, 0x19191900, 0x19191900, 0x00000000, 
0x00000000, 0x19191900, 0x00000000, 0x19191900, 0x00000000, 
0x00000000, 0x19191900, 0x19191900, 0x19191900, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x19191900, 0x00000000, 
0x00000000, 0x19191900, 0x19191900, 0x19191900, 0x00000000
}
};