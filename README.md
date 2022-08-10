# Learn the Embedded Template Library (ETL)
Examples to help learn how and why to use the Embedded Template Library

# Motivation

[Here's what the C++ Core Guidelines say about libraries versus 'handcrafted code'](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#es1-prefer-the-standard-library-to-other-libraries-and-to-handcrafted-code)
> **ES.1:** Prefer the standard library to other libraries and to “handcrafted code”
> 
> **Reason** - Code using a library can be much easier to write than code working directly with language features, much shorter, tend to be of a higher level of abstraction, and the library code is presumably already tested. The ISO C++ Standard Library is among the most widely known and best tested libraries. It is available as part of all C++ implementations.
> 
> **Exception** -  Large parts of the standard library rely on **dynamic allocation** (free store). These parts, notably the containers but not the algorithms, are unsuitable for some hard-real-time and **embedded applications**. In such cases, consider providing/using similar facilities, e.g., a standard-library-style container implemented using a pool allocator.

The C++ standard library provides [containers](https://en.cppreference.com/w/cpp/container) and [algorithms](https://en.cppreference.com/w/cpp/algorithm)
