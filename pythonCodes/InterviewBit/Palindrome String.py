import re


class Solution:
    # @param A : string
    # @return an integer
    def isPalindrome(self, A):
        A = re.sub(r'[^a-zA-Z0-9]', '', A)
        AA = A[::-1]
        return int(A.lower() == AA.lower())


p = Solution()
print(p.isPalindrome("A man, a plan, a canal: Panama"))
