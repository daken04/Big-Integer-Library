# Big Integer Library

This library provides functionalities for handling arbitrarily large integers and performing basic mathematical operations. The implementation is designed to have specific time complexities for each operation to ensure efficient performance.

## Input Format

The input format depends on the type of operation to be performed. The first line contains an integer value that denotes the type of operation. The mapping of integer values to operations is as follows:

1. Addition, Subtraction, Multiplication & Division
2. Exponentiation
3. GCD
4. Factorial

The subsequent line(s) contain input according to the type of operation:

- For the 1st and 4th type of operation, there will be one string.
- For the 2nd & 3rd type of operation, there will be two space-separated strings.

## Expected Time Complexity

Let's denote s1 and s2 as two big integers with n and m digits in them. Let x be an integer < 2^63.

1. **Addition (s1 + s2):** O(n + m)
2. **Subtraction (s1 - s2):** O(n + m)
3. **Multiplication (s1 * s2):** O(n * m)
4. **Division (s1 / s2):** O(n * m)
5. **Exponentiation (s1^x):** O(n * n * log(x))
6. **GCD (s1, s2):** O(max(n, m))
7. **Factorial (s1):** O(n^3)

## Examples

### Example 1: Addition
```plaintext
1
123456789012345678901234567890 987654321098765432109876543210
```

### Example 2: Exponentiation
```plaintext
2
876543210987654321098765432109 3
```

### Example 3: GCD
```plaintext
3
123456789012345678901234567890 987654321098765432109876543210
```

### Example 4: Factorial
```plaintext
4
876543210987654321098765432109
```



