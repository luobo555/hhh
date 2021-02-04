'''
Find the greatest common divisor of two given numbers.

Args:
  A and B: two given numbers.

Returns:
  the greatest common divisor of A and B.

For example:
  ```python
  A=4
  B=12
  GCD_Euclidean(A, B)
  ```

  would produce:

  ```python
  4
  ```
'''


def GCD_Euclidean(A, B):
    if A is 0 or B is 0:
        return max(A, B)

    else:
        if A < B:
            A, B = B, A

        while (A % B):
            temp = A % B
            A = B
            B = temp

        return B


if __name__ == "__main__":
    A, B = map(int, input().split())
    res = GCD_Euclidean(A, B)
    print(res)
