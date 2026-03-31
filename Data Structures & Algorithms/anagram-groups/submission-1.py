class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        dic = {}
        for st in strs:
            freq = [0] * 26
            for ch in st:
                freq[ord(ch) - ord('a')]+=1
            if tuple(freq) not in dic:
                dic[tuple(freq)] = []
            dic[tuple(freq)].append(st)
        res = []
        for val, ans in dic.items():
            res.append(ans)
        return res