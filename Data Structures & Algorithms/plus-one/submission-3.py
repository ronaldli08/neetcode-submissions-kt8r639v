class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        num = ""
        for i in digits:
            num += str(i)
        num = int(num) + 1
        num = str(num)
        lst = []
        for i in num:
            lst.append(int(i))
        return lst