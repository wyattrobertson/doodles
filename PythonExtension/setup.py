from distutils.core import setup, Extension
from sysconfig import get_paths
import numpy
import sys

def main():

    numpy_dir = numpy.get_include()
    sys.path.append(numpy_dir)
    python_include_path = get_paths().get('include', "usr/include/python3.8")
    sys.path.append(get_paths)
    sys.path.append(python_include_path)
    extension = Extension(name="accumulate",
                          sources=["accumulate.cpp"],
                          language="c++",
                          include_dirs=sys.path,
                          headers=["accumulate.hpp"])

    setup(name="accumulate",
          version="1.0.0",
          description="Python interface for an implementation of C++'s accumulate function",
          author="Wyatt Robertson",
          ext_modules=[extension])

if __name__ == "__main__":
    main()