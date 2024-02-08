from newtonsolver import NewtonSolver, NewtonSolverComplex
import cmath

f = lambda x : x * x - 1.0
df = lambda x : 2.0 * x
print("f(x) = x * x - 1")
x0 = 0.5
solver_real = NewtonSolver(f, df, x0)
root = solver_real.solve()

try:
    root = solver_real.solve()
    print(f"Approximate root: {root}")
except RuntimeError as e:
    print("Error: ", str(e))


f =lambda x : x * x + 1.0
print("f(x) = x * x + 1")
z0 = complex(0.5, 0.5)
solver_comp = NewtonSolverComplex(f, df, z0)
root = solver_comp.solve()

try:
    root = solver_comp.solve()
    print(f"Approximate root: {root}")
except RuntimeError as e:
    print("Error: ", str(e))