capitalC
========

Shims for common C functions that suicide your program (which is usually what you want) on error.
They are static inline wrapper functions.

We include a lot of header files. This may pollute your namespace but you shouldn't be calling your
functions Malloc or accept4 anyways.

By defining __NDEBUG__ (-DNDEBUG) you can compile a release version that does not do
error checking. This can be helpful for producing optimized 'release' versions.

This header is expected to be helpful for both C and C++.

The project is unlicensed public domain so please use and abuse it and don't
worry about crediting whomever.

Contributions are welcome. Send a pull request to this github.

For an alphabetized list of shims, see include/capitalC.h
