import sys
sys.path.append('.')

from exam_lib import Calculator

calculator = Calculator()

choice = input("Choose an operation: \n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n")
a = float(input("Enter the first number: "))
b = float(input("Enter the second number: "))



if choice == '1':
    print(calculator.add(a, b))
elif choice == '2':
    print(calculator.subtract(a, b))
elif choice == '3':
    print(calculator.multiply(a, b))
elif choice == '4':
    print(calculator.divide(a, b))
else:
    print("Invalid choice")

