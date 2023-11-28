from distutils.core import setup
from distutils.extension import Extension
from Cython.Build import cythonize
from Cython.Distutils import build_ext

ext_modules = [
	Extension(
		name = 'ctopy',
		language = 'c++',
		extra_compile_args = ['-std=c++17'],
		include_dirs = ['../include', '../src'],
		sources = [
			'ctopy.pyx',
			'../src/ctopy/ctopy.cpp'
		],
		library_dirs = ['../build'],
		libraries = ['ctopy']
	)
]

setup(
	name = 'ctopy',
	cmdclass = {'build_ext': build_ext},
	ext_modules = cythonize(ext_modules)
)
