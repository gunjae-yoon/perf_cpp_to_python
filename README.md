# perf_cpp_to_python

## Usage
### Step 1. clone project
```bash
git clone https://github.com/gunjae-yoon/perf_cpp_to_python --depth 1
```

### Step 2-1. create a library by PyBind11
```bash
cd perf_cpp_to_python
mkdir build
cd build
cmake ..
```

### Step 2-2. create a library by Cython
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

## Performance Test result
In my case, cpp method invocation overheads were measured as follows.
```bash
TEST [0] ==============================================
    PyBind11 --------------------------------------
        elapsed time: 2,580,502,161 ns
        elapsed time per access: 258.0 ns
    Cython ----------------------------------------
        elapsed time: 149,258,307 ns
        elapsed time per access: 14.0 ns
    Ctypes ----------------------------------------
        elapsed time: 768,678,743 ns
        elapsed time per access: 76.0 ns

TEST [1] ==============================================
    PyBind11 --------------------------------------
        elapsed time: 2,581,704,217 ns
        elapsed time per access: 258.0 ns
    Cython ----------------------------------------
        elapsed time: 151,069,042 ns
        elapsed time per access: 15.0 ns
    Ctypes ----------------------------------------
        elapsed time: 761,508,787 ns
        elapsed time per access: 76.0 ns

TEST [2] ==============================================
    PyBind11 --------------------------------------
        elapsed time: 2,591,430,548 ns
        elapsed time per access: 259.0 ns
    Cython ----------------------------------------
        elapsed time: 150,667,565 ns
        elapsed time per access: 15.0 ns
    Ctypes ----------------------------------------
        elapsed time: 758,385,484 ns
        elapsed time per access: 75.0 ns

TEST [3] ==============================================
    PyBind11 --------------------------------------
        elapsed time: 2,586,683,432 ns
        elapsed time per access: 258.0 ns
    Cython ----------------------------------------
        elapsed time: 149,375,078 ns
        elapsed time per access: 14.0 ns
    Ctypes ----------------------------------------
        elapsed time: 757,957,571 ns
        elapsed time per access: 75.0 ns

TEST [4] ==============================================
    PyBind11 --------------------------------------
        elapsed time: 2,579,945,236 ns
        elapsed time per access: 257.0 ns
    Cython ----------------------------------------
        elapsed time: 153,395,069 ns
        elapsed time per access: 15.0 ns
    Ctypes ----------------------------------------
        elapsed time: 757,959,054 ns
        elapsed time per access: 75.0 ns

TEST [5] ==============================================
    PyBind11 --------------------------------------
        elapsed time: 2,586,719,720 ns
        elapsed time per access: 258.0 ns
    Cython ----------------------------------------
        elapsed time: 149,326,175 ns
        elapsed time per access: 14.0 ns
    Ctypes ----------------------------------------
        elapsed time: 756,688,190 ns
        elapsed time per access: 75.0 ns

TEST [6] ==============================================
    PyBind11 --------------------------------------
        elapsed time: 2,579,728,890 ns
        elapsed time per access: 257.0 ns
    Cython ----------------------------------------
        elapsed time: 149,130,149 ns
        elapsed time per access: 14.0 ns
    Ctypes ----------------------------------------
        elapsed time: 757,357,412 ns
        elapsed time per access: 75.0 ns

TEST [7] ==============================================
    PyBind11 --------------------------------------
        elapsed time: 2,577,545,474 ns
        elapsed time per access: 257.0 ns
    Cython ----------------------------------------
        elapsed time: 150,014,187 ns
        elapsed time per access: 15.0 ns
    Ctypes ----------------------------------------
        elapsed time: 754,910,679 ns
        elapsed time per access: 75.0 ns

TEST [8] ==============================================
    PyBind11 --------------------------------------
        elapsed time: 2,583,221,843 ns
        elapsed time per access: 258.0 ns
    Cython ----------------------------------------
        elapsed time: 149,549,267 ns
        elapsed time per access: 14.0 ns
    Ctypes ----------------------------------------
        elapsed time: 759,118,573 ns
        elapsed time per access: 75.0 ns

TEST [9] ==============================================
    PyBind11 --------------------------------------
        elapsed time: 2,587,141,625 ns
        elapsed time per access: 258.0 ns
    Cython ----------------------------------------
        elapsed time: 148,873,666 ns
        elapsed time per access: 14.0 ns
    Ctypes ----------------------------------------
        elapsed time: 758,521,687 ns
        elapsed time per access: 75.0 ns
```
