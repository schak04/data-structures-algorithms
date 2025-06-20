/*
Hashing:
- Reduces time complexity
- Hash function -> h(k) where k is the value to be inserted, deleted or searched
    -> index = h(k)
    -> arr[index] = k
- Collision: occurs when we already have a value at an index where we're supposed to insert a new value
    -> How to avoid collision: 
        1. Linear Probing -> h(k)+i
        2. Quadratic Probing -> h(k)+(i*i)
        3. Double Hashing
- Often used for efficient data lookup and retrieval
- Transforms data into fixed sized values
- Types:
    1. Modulo Hash Functions
    2. Folding Hash Functions
*/
