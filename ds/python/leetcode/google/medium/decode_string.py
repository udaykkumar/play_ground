"""
Created on Jun 3, 2021

@author: kumarkud
"""


class decode_string:
    """
    classdocs https://leetcode.com/problems/decode-string/
    """

    def __init__(self):
        """
        Constructor
        """

    def __parse_number(self, s, i):
        # so this logic should cover the way we identify the number
        start = i
        while s[start + 1] != "[":
            start += 1

        n = int(s[i : start + 1])
        i = start
        return start, i, n

    def decodeString(self, s: str) -> str:
        finalString = ""
        slen = len(s)
        i = 0
        while i < slen:

            # If its a number
            if s[i].isnumeric():

                start, i, n = self.__parse_number(s, i)

                # decode the string within  [ ]
                start = i + 1
                end = start
                while s[end] != "]":
                    end += 1
                end += 1
                decodedString = self.decodeString(s[start:end])

                # Repeat it with the numeric time
                for _ in range(n):
                    finalString += decodedString
                i = end
            # Skip Openings ??
            elif s[i] == "[":
                i += 1
                continue

            # this forms a base case for us
            elif s[i] == "]":
                return finalString

            # all others are just plain alphabets
            else:
                finalString += s[i]
                i += 1

        return finalString


# print( decode_string().decodeString(s = "3[a]2[bc]") == "aaabcbc")
# Output: "aaabcbc"

# print( decode_string().decodeString(s = "3[a2[c]]") == "accaccacc")
# "accaccacc"

# print( decode_string().decodeString(s = "2[abc]3[cd]ef") == "abcabccdcdcdef" )
# abcabccdcdcdef"

# print( decode_string().decodeString(s = "abc3[cd]xyz") == "abccdcdcdxyz")
# "abccdcdcdxyz"

# print( decode_string().decodeString("100[leetcode]") )
# print( decode_string().decodeString("3[z]2[2[y]pq4[2[jk]e1[f]]]ef") )
print(
    decode_string().decodeString("3[z]2[2[y]pq4[2[jk]e1[f]]]ef")
    == "zzzyypqjkjkefjkjkefjkjkefjkjkefyypqjkjkefjkjkefjkjkefjkjkefef"
)
# zzzyypqjkjkefjkjkefjkjkefjkjkefyypqjkjkefjkjkefjkjkefjkjkefef
# zzzyyyypqjkjkjkjkjkjkjkjkef
