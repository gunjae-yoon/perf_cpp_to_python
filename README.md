# perf_cpp_to_python

## Usage
### Step 1. clone project
```bash
git clone https://github.com/gunjae-yoon/perf_cpp_to_python --depth 1
```

### Step 2-1. create a library using PyBinder11
```bash
cd perf_cpp_to_python
mkdir build
cd build
cmake ..
```

### Step 2-2. create a library using Cython
```bash
cd perf_cpp_to_python/cython
python3 setup.py build_ext --inplace
```

### Step 3. move libraries into tester path
```bash
cd ..
cd python
mv ../build/*.so ./
mv ../cython/*.so ./
```

### Step 4. run performance test
```bash
python3 perf_pybind.py
```
