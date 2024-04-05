# "Cracked" Stack W/ Increment Operation 😎

This is the design of a stack with an `increment(x, v)` function. 
The function takes 2 arguments: `x`&`v` to increment the top `x` elements of the stack by the value `v`.


## Brute-force implementation `O(n)` 👎
- Iterate over the top `x` elements, and if possible increment them by `v`.


## Optimized implementation `O(1)` ⚡️🔥
- Store a variable `top_increment` for the increment value of the top element
- Store a vector `v_increment` for the last index from the end of the stack when the increment applies to it
- No matter what the value of `x` is we will always increment the top-element by `v`  

      top_increment += v;
      v_increment[idx] += v;

- We just need to know when we need to undo an increment every time we pop from the stack

        top_increment -= v_increment.back();
        v_increment.pop_back();
        elements.pop_back();
        return stack_top + temp;
