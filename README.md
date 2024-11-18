# Push_swap

## Descripción

**Push_swap** es un proyecto cuyo objetivo es implementar un programa para ordenar números utilizando dos stacks (`a` y `b`) y un conjunto limitado de operaciones. El objetivo es hacerlo de forma eficiente.

## Reglas del proyecto

1. **Stack inicial**:
   - `a` contiene una lista de números (positivos y/o negativos) únicos.
   - `b` comienza vacío.

2. **Objetivo**:
   - Ordenar el stack `a` en orden ascendente utilizando únicamente las operaciones permitidas.

3. **Operaciones disponibles**:
   - **Swap**:
     - `sa`: Intercambia los dos primeros elementos en `a`.
     - `sb`: Intercambia los dos primeros elementos en `b`.
     - `ss`: Realiza `sa` y `sb` simultáneamente.
   - **Push**:
     - `pa`: Mueve el primer elemento de `b` al tope de `a`.
     - `pb`: Mueve el primer elemento de `a` al tope de `b`.
   - **Rotate**:
     - `ra`: Desplaza todos los elementos de `a` hacia arriba; el primero se mueve al final.
     - `rb`: Desplaza todos los elementos de `b` hacia arriba; el primero se mueve al final.
     - `rr`: Realiza `ra` y `rb` simultáneamente.
   - **Reverse Rotate**:
     - `rra`: Desplaza todos los elementos de `a` hacia abajo; el último se mueve al principio.
     - `rrb`: Desplaza todos los elementos de `b` hacia abajo; el último se mueve al principio.
     - `rrr`: Realiza `rra` y `rrb` simultáneamente.

---

## Implementación

### Algoritmo: **Radix Sort**

1. Representar los números en su forma binaria.
2. Ordenar los números bit a bit, comenzando por el bit menos significativo.
3. Reorganizar los números en función de sus bits.

