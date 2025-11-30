# Homework Assignment IV: Hash Function Design & Observation (C/C++ Version) 0

This assignment focuses on the design and observation of hash functions using C/C++. 
Students are expected to implement and analyze the behavior of hash functions, 
evaluate their efficiency, and understand their applications in computer science.

Developer: [Yan-Xi Lee]  
Email: [leesteve0312@gmail.com]  

## My Hash Function
### Integer Keys 
- Formula / pseudocode:
  ```text
  I used the Multiplication Method for hashing integers.
  The formula is:
  h(k)=⌊m⋅frac(k⋅A)⌋
  where frac(x)=x−⌊x⌋
  Pseudocode (corresponds to my C/C++ code):
  function myHashInt(key, m):
  A = 0.7 // C version
  OR
  A = 0.35 // C++ version
  prod = key * A
  frac = prod - floor(prod)
  index = floor(frac * m)
  return index
  Note:
  I intentionally used different A values (0.7 in C and 0.35 in C++) to compare distribution behavior.
  Both values satisfy 0 < A < 1, so they work correctly in the multiplication method.
  ```
- Rationale:[
I chose the multiplication hashing method because:
1. More uniform than using key % m
Modulo hashing tends to create clustering when input keys follow patterns (e.g., consecutive integers).
The multiplication method introduces a non-integer multiplier A, which adds useful randomness.
2. Independent of table size
This method works well whether m is prime or not.
So it works consistently for m = 10, 11, and 37.
3. Best distribution appeared when m = 11 and m = 37
Especially when m = 37 (a prime), the results formed a nearly linear and uniform sequence.
]

### Non-integer Keys
- Formula / pseudocode:
  ```text
  I used the Polynomial Rolling Hash method.
  hash = ( hash ⋅ base + 𝑐 ) mod 𝑚
  Pseudocode:
  function myHashString(str, m):
  hash = 0 base = 31 // C version
  OR
  base = 97 // C++ version
  for each character c in str:
  hash = (hash * base + ASCII(c)) % m
  return hash
  I used base = 31 for C and base = 97 for C++ to compare different multiplier effects.
  ```
- Rationale: [
1. Polynomial hashing is widely used and effective
It accumulates characters using multiplication, which reduces patterns and clusters.
2. Base = 31 (C)
A common choice in competitive programming and standard libraries.
3. Base = 97 (C++)
A larger base amplifies ASCII differences and reduces collisions for small datasets.
]

## Experimental Setup
- Table sizes tested (m): 10, 11, 37
- Test dataset:
  - Integers: 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60
  - Strings: "cat", "dog", "bat", "cow", "ant", "owl", "bee", "hen", "pig", "fox"
- Compiler: GCC and G++
- Standard: C23 and C++23

## Results
Integer Keys
| Table Size (m) | Index Sequence         | Observation              |
|----------------|------------------------|--------------------------|
| 10             | 1, 2, 3, 4, ...        | Pattern repeats every 10 |
| 11             | 10, 0, 1, 2, ...       | More uniform             |
| 37             | 20, 21, 22, 23, ...    | Near-uniform             |

## Compilation, Build, Execution, and Output

### Compilation
- The project uses a comprehensive Makefile that builds both C and C++ versions with proper flags:
  ```bash
  # Build both C and C++ versions
  make all
  
  # Build only C version
  make c
  
  # Build only C++ version
  make cxx
  ```

### Manual Compilation (if needed)
- Command for C:
  ```bash
  gcc -std=c23 -Wall -Wextra -Wpedantic -g -o C/hash_function C/main.c C/hash_fn.c
  ```
- Command for C++:
  ```bash
  g++ -std=c++23 -Wall -Wextra -Wpedantic -g -o CXX/hash_function_cpp CXX/main.cpp CXX/hash_fn.cpp
  ```

### Clean Build Files
- Remove all compiled files:
  ```bash
  make clean
  ```

### Execution
- Run the compiled binary:
  ```bash
  ./hash_function
  ```
  or
  ```bash
  ./hash_function_cpp
  ```

### Result Snapshot
<img width="611" height="674" alt="image" src="https://github.com/user-attachments/assets/073087e0-5f0a-44d2-881a-457ccf9929be" />

  ```
  
- Example output for integers:
  ```
  Hash table (m=10): [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
  Hash table (m=11): [10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
  Hash table (m=37): [20, 21, 22, 23, 24, 25, 26, 27, 28, 29, ...]
  ```
- Example output for strings:
  ```
  Hash table (m=10): ["cat", "dog", "bat", "cow", "ant", ...]
  Hash table (m=11): ["fox", "cat", "dog", "bat", "cow", ...]
  Hash table (m=37): ["bee", "hen", "pig", "fox", "cat", ...]
  ```
- Observations: For both integer and string hashing, the results produced by my program align with the expected theoretical behavior.
In particular:
The multiplication-method hash for integers generates more uniform results when the table size m is prime (especially 11 and 37).
The polynomial rolling hash for strings shows fewer collisions with larger bases (base = 31 in C and base = 97 in C++).
When m = 10, the distribution tends to form small repeating patterns, while m = 11 and m = 37 spread values more evenly.
Using different constants (A = 0.7 for C, A = 0.35 for C++) produces slightly different shift patterns, which helps compare distribution quality.
Overall, the observed outputs matched the expectations from multiplication hashing and polynomial hashing theory.

## Analysis
- Prime vs non-prime `m`: Prime table sizes (11, 37) consistently provide better distribution and fewer collisions for both integer and string hashing.
- Patterns or collisions: m = 10 produces noticeable patterns, especially for integer hashing.
Polynomial hashing reduces patterns more effectively when the base and modulus are relatively large.
- Improvements: Use a prime table size whenever possible.
Choose a base that fits the dataset size (larger base for strings when collisions matter).
Multiplication hashing works well when 0 < A < 1 and is especially effective when combined with a prime table size.

## Reflection
1. This assignment showed that even simple hash functions behave differently depending on parameter choices such as the table size, multiplier A, and polynomial base.
2. Prime table sizes consistently produced smoother and more uniform distributions, reducing collisions for both integer and string datasets.
3. The comparison between C and C++ versions (different A and base values) revealed how small parameter changes can shift the entire hash distribution.
4. Overall, designing an effective hash function requires balancing algorithm simplicity with careful tuning of constants to achieve good distribution performance.
