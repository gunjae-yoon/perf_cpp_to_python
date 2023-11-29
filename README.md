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

## Performance Test result
In my case, cpp method invocation overheads were measured as follows.
```bash
test number [0] ---------------------------
performance of PyBind11
	elapsed time: 2,620,486,285 ns
	elapsed time per access:  262.0  ns

performance of Cython
	elapsed time: 148,105,032 ns
	elapsed time per access:  14.0  ns


test number [1] ---------------------------
performance of PyBind11
	elapsed time: 2,617,789,897 ns
	elapsed time per access:  261.0  ns

performance of Cython
	elapsed time: 146,747,205 ns
	elapsed time per access:  14.0  ns


test number [2] ---------------------------
performance of PyBind11
	elapsed time: 2,614,058,689 ns
	elapsed time per access:  261.0  ns

performance of Cython
	elapsed time: 148,590,119 ns
	elapsed time per access:  14.0  ns


test number [3] ---------------------------
performance of PyBind11
	elapsed time: 2,620,532,346 ns
	elapsed time per access:  262.0  ns

performance of Cython
	elapsed time: 147,454,826 ns
	elapsed time per access:  14.0  ns


test number [4] ---------------------------
performance of PyBind11
	elapsed time: 2,613,329,643 ns
	elapsed time per access:  261.0  ns

performance of Cython
	elapsed time: 148,957,527 ns
	elapsed time per access:  14.0  ns


test number [5] ---------------------------
performance of PyBind11
	elapsed time: 2,617,007,623 ns
	elapsed time per access:  261.0  ns

performance of Cython
	elapsed time: 147,080,893 ns
	elapsed time per access:  14.0  ns


test number [6] ---------------------------
performance of PyBind11
	elapsed time: 2,612,930,471 ns
	elapsed time per access:  261.0  ns

performance of Cython
	elapsed time: 147,523,787 ns
	elapsed time per access:  14.0  ns


test number [7] ---------------------------
performance of PyBind11
	elapsed time: 2,618,963,342 ns
	elapsed time per access:  261.0  ns

performance of Cython
	elapsed time: 148,078,074 ns
	elapsed time per access:  14.0  ns


test number [8] ---------------------------
performance of PyBind11
	elapsed time: 2,615,682,951 ns
	elapsed time per access:  261.0  ns

performance of Cython
	elapsed time: 148,429,581 ns
	elapsed time per access:  14.0  ns


test number [9] ---------------------------
performance of PyBind11
	elapsed time: 2,615,501,880 ns
	elapsed time per access:  261.0  ns

performance of Cython
	elapsed time: 147,625,569 ns
	elapsed time per access:  14.0  ns
```
