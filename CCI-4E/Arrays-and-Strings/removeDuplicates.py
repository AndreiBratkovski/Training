"""
1.3 Design an algorithm and write code to
remove the duplicate characters in a string
without using any additional buffer. NOTE: One
or two additional variables are fine. An
extra copy of the array is not.

1. For each character, check if it is a duplicate
of already found characters.
2. Skip duplicate characters and update the non duplicate
characters
"""
from collections import OrderedDict


def remove_duplicates(input_str):
    return "".join(OrderedDict.fromkeys(input_str))


my_str = "Annddreeeei"
print(remove_duplicates(my_str))
