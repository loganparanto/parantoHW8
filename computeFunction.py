# computeFunction.py

"""
Description:
    Computes values for the function f(x) = x^2 + 2 for x = 0 to 9.
    Prints out the values for x and f(x).

Command Line Arguments:
    None

Example Invocation:
    python computeFunction.py
"""

# Function to compute f(x) = x^2 + 2
def compute_function(x):
    return x**2 + 2

# Loop from 0 to 9 and print x and f(x)
for x in range(10):
    result = compute_function(x)
    print(f"x: {x}, f(x): {result}")

