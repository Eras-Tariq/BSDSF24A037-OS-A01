# Operating Systems Programming Assignment – 01

## Report

### Feature-2: Multi-file Project using Make Utility

#### Q1. Explain the linking rule in this part's Makefile: `$(TARGET): $(OBJECTS)`. How does it differ from a Makefile rule that links against a library?

The rule `$(TARGET): $(OBJECTS)` means that the final executable depends directly on all the object files. The object files are compiled first and then linked together to create the executable.

In library linking, the main program is linked with a library instead of directly listing all the function object files. For example, `-L../lib -lmyutils` tells the compiler where the library is and which library to use.

#### Q2. What is a git tag and why is it useful in a project? What is the difference between a simple tag and an annotated tag?

A Git tag is a name given to a specific commit. It is useful for marking important versions or stable points of a project.

A simple tag only points to a commit, while an annotated tag stores additional information such as the tag message, author, and date. In this assignment, annotated tags were used for the releases.

#### Q3. What is the purpose of creating a "Release" on GitHub? What is the significance of attaching binaries like your client executable to it?

A GitHub Release provides an official version of the project that users can download and use.

Attaching binaries such as the client executable allows users to download the already compiled program without compiling the source code themselves.

---

### Feature-3: Creating and Using Static Library

#### Q4. Compare the Makefile from Part 2 and Part 3. What are the key differences in the variables and rules that enable the creation of a static library?

In Part 2, the Makefile directly compiled and linked the object files to create the executable.

In Part 3, additional variables and rules were added for the static library. The object files were placed into `lib/libmyutils.a` using the `ar` command, and the final program was linked with this static library.

The static library allowed the utility functions to be bundled into one `.a` file.

#### Q5. What is the purpose of the `ar` command? Why is `ranlib` often used immediately after it?

The `ar` command is used to create and manage archive files. In this project, it was used to combine the object files into the static library `libmyutils.a`.

`ranlib` creates or updates the archive's symbol index. This helps the linker efficiently find the required functions inside the static library.

#### Q6. When you run `nm` on your `client_static` executable, are the symbols for functions like `mystrlen` present? What does this tell you about how static linking works?

Yes, functions such as `mystrlen` were present in the symbols of `client_static`.

This shows that the required function code from the static library was linked into the executable. Therefore, the executable contains the required library code instead of depending on a separate `.so` file at runtime.

---

### Feature-4: Creating and Using Dynamic Library

#### Q7. What is Position-Independent Code (`-fPIC`) and why is it a fundamental requirement for creating shared libraries?

Position-Independent Code is code that can execute correctly regardless of where it is loaded into memory.

The `-fPIC` option was used when compiling the object files for `libmyutils.so`. It is important for shared libraries because the operating system can load the library at an appropriate memory address without requiring the library code to be fixed to one specific address.

#### Q8. Explain the difference in file size between your static and dynamic clients. Why does this difference exist?

The static and dynamic clients had different file sizes because static linking copies the required library code into the executable.

With dynamic linking, the library code remains in `libmyutils.so` and the executable contains references to that shared library. Therefore, the dynamic executable can be smaller because the library code is not copied directly into it.

#### Q9. What is the `LD_LIBRARY_PATH` environment variable? Why was it necessary to set it for your program to run, and what does this tell you about the responsibilities of the operating system's dynamic loader?

`LD_LIBRARY_PATH` tells the Linux dynamic loader which additional directories should be searched for shared libraries.

It was necessary because `libmyutils.so` was stored in the project's `lib` directory, which was not automatically known to the loader. After setting `LD_LIBRARY_PATH`, the loader was able to find the shared library and run `client_dynamic`.

This shows that the dynamic loader is responsible for finding and loading the required shared libraries when a dynamically linked program starts.
