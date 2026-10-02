class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        digits[-1] += 1

        digit = len(digits) - 1

        while digits[digit] == 10:
            digits[digit] = 0
            if digit == 0:
                return [1] + digits
            digits[digit-1] += 1
            digit -= 1
        return digits