/*
- Order of the tree (k or t)
        /         \ 
    min no.      max no. 
 of values       of values

- Min = t - 1
  Max = 2t - 1
- Root is the exception while considering min/max no. of values. 
- Always stay consistent with whether you're choosing the left or the right median to be pushed upward.
- No. of keys + 1 = No. of child nodes

Deletion: 
    1. If min key rule is not violated
    2. If min key rule is violated and sibling can offer a key
    3. If min key rule is violated and sibling cannot offer a key
*/

