# Lab 1

`lab1.c` reads an integer upper limit and calculates a finite sum using double-precision floating-point arithmetic.

## What the program computes

For the entered integer `n`, it evaluates

```text
(-1)^n * sum(i^2 / (i^4 + 1), i = 1..n)
```

The loop adds the positive terms `i^2 / (i^4 + 1)` for `i` from 1 through `n`. Afterward, the result is negated when `n` is odd. This makes the sign depend on the parity of the upper limit; it does not alternate the sign of each individual term.

## Input and output

The program prompts for the upper limit and reads it as a signed `long long int`. It prints the result with 10 digits after the decimal point. If it cannot read an integer, it writes an error to standard error and exits with status 1.

For `n <= 0`, the loop does not run and the result is zero (for a negative odd `n`, the program may print negative zero).

## Implementation notes

- The calculation takes O(n) time for positive `n` and O(1) additional space.
- Terms and the running total use `double`, so the printed result is an approximation and very large limits can also be impractical to compute.
- The positive partial sums tend toward a finite limit because the terms behave like `1/i^2`. However, negating the whole sum for odd `n` makes the program's signed result alternate between positive and negative values as `n` increases.
