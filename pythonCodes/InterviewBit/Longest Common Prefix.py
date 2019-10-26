class Solution:
    # @param A : list of strings
    # @return a strings
    def longestCommonPrefix(self, A):
        A.sort()
        minLen = min(len(A[0]), len(A[len(A) - 1]))
        prefix = ''
        for i in range(minLen):
            if A[0][i] == A[len(A) - 1][i]:
                prefix += A[0][i]
            else:
                break

        return str(prefix)


print(Solution().longestCommonPrefix(A=["abcdefgh", "aefghijk", "abcefgh"]))
