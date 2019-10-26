class Solution:
    def findAndReplacePattern(self, words, pattern):
        ans = []
        length = len(pattern)
        for word in words:
            matches = True
            Dictionary = {}
            for i in range(length):
                if len(word) != len(pattern):
                    matches = False
                    break
                if pattern[i] in Dictionary:
                    if Dictionary[pattern[i]] != word[i]:
                        matches = False
                        break
                else:
                    if word[i] in Dictionary.values():
                        matches = False
                        break
                    else:
                        Dictionary[pattern[i]] = word[i]

            if matches:
                ans.append(word)
        return ans
