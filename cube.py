# cube.py

"""
Description:
    Prints out the cube of odd numbers from 0 to 19 or the numbers themselves if they are even.

Command Line Arguments:
    None

Example Invocation:
    python cube.py
"""

# Loop from 0 to 19 and print the cube of odd numbers or the number itself if even
for num in range(20):
    if num % 2 == 1:
        cube = num ** 3
        print(cube)
    else:
        print(num)

