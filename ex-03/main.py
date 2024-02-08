import sys
sys.path.append('.')

from exam_lib import DataProcessor
from exam_lib import compute_correlation

def main():
    input1 = [2.43, -0.86, 7.19, 4.57, 1.68, 9.32, 5.75]
    input2 = [0.73, -0.45, 0.12, 0.88, -0.67, 0.34, -0.92]

    dp1 = DataProcessor(input1, 7)
    dp2 = dp1

    dp3 = DataProcessor(input2, 7)
    dp3 = dp1

    print(dp1)
    print(dp2)
    print(dp3)
    print(dp1.n_elements())
    print(dp2.n_elements())
    print(dp3.n_elements())

    print(dp1.minimum())
    print(dp1.maximum())
    print(dp1.mean())
    print(dp1.standard_deviation())

    dp4 = DataProcessor(input2, 7)
    print(dp4)

    dp5 = dp1 + dp4
    print(dp5)
    print(dp5.minimum())
    print(dp5.maximum())
   
    print(dp5[3])
    dp5[3] = 0.0
    print(dp5[3])

    print(DataProcessor.get_n_instances())
    print(compute_correlation(dp1, dp4))


main()