# encoding: utf-8

class Solution(object):
    def reverse(self, x):
        summary = 0
        if x == 0:
            return 0
        if x > 2147483647 or x < -2147483647:
            return 0

        sign = 1 if x > 0 else 0
        if sign == 0:
            x -= x*2

        digits = [int(i) for i in str(x)]
        it = 0
        for i in digits:
            summary += i*10**it
            it += 1

        if sign == 0:
            summary -= summary*2

        if summary > 2147483647 or summary < -2147483647:
            return 0
        return summary

def main():
    rtn = Solution()
    print rtn.reverse(1534236469)

if __name__ == '__main__':
    main()

