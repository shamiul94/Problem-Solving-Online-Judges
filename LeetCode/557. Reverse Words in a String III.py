####### attempt - 1 ######

s = "Let's take LeetCode contest"


f = " ".join(reversed(("".join(reversed(s))).split(" ")))
print(f)

#####attempt 2#########

class Solution:
    def reverseWords(self, s: str) -> str:
        ans = ''
        for x in s.split(" "):
            # a = str(x)
            ans += x[::-1]
            ans += " "
        return str(ans.strip())
