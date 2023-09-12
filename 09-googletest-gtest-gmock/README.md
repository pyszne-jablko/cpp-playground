# Info

GoogleTests. Minimum C++ standard is C++14. Here is set to C++17.

# Build

```
cmake . -B build
cd build
cmake --build .
```

# How to use it

After build, you have executable file. Simply run it. This will run all tests
in this file.

You can list available tests in executable file. Type
'hello_test.exe --gtest_list_tests'.

You can run one test or only test from pattern. Type
'hello_test.exe --gtest_filter=Hello*'
