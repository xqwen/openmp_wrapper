OpenMP Wrapper: Parallel Execution of Tasks in Multi-Core Environment
==============

OpenMP Wrapper enables parallel executions of multiple tasks in a single multi-core computer. The tasks can be specified by any excutable scripts (Perl, Python, Shell, R, etc) or binaries. 

**Turn your multi-core desktop into a mini grid egine, and enjoy!**

## Compilation

To compile, it is required that the [OpenMP library](http://openmp.org) and GNU c++ compiler are properly installed. Simply run "make" to compile the source code.


## Usage

The command line syntax of OpenMP wrapper is 

```{shell}
openmp_wrapper -d cmd_script  -t thread_number
```
Sepcially, "cmd_script" provides a list of computational tasks to be executed in parallel and "thread_number" specifies number of threads to be run in parallel. Note thread_number should be determined based on the number of CPU cores available on the running machine.

Example cmd_script
```
sh command 1
sh command 2
sh command 3
```

Be mindful that different thread may be competing critical resources (file etc.).

