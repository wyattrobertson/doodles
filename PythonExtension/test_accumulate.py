import numpy
import accumulate

if __name__ == "__main__":
    numpy_array = numpy.array([-1,-2])
    a = [1,2,4,6]
    result = accumulate.accumulate(a)
    print(result)
