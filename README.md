# Ethash WinBuild

The binary outputs of the Visual Studio project files have been reconfigured to follow the pattern common all winbuild repositories. The Visual Studio project files can be found under the `/windows` directory.

1. Output goes to:
`$(SolutionDir)..\..\..\..\\build_<tool>_<platform>\<configuration>\[lib|bin|include]`

2. Output library targets are named: `$(ProjectName)lib.lib` , `$(ProjectName)dll.dll`, and the import library is named `$(ProjectName)dll.lib`

3. Executables (`.exe`) and dynamic link libraries (`.dll`) go to `bin/`, static and import libraries go to `lib/`, and public header files (.h) go to `include/`.


This library opionally depends on the [cryptopp](https://github.com/winbuilds/cryptopp) library. 

####Conditional Compilation Manifest Constants

**`WITH_CRYPTOPP`** - Defined by default.   

- If defined, the implementations of functions `SHA3_256()` and `SHA3_512()` are taken from the `cryptopp` library.
- If not defined, the internal versions are used.



# Ethash

Ethash is the planned Proof-of-Work mining algorithm for Ethereum 1.0.  For details on the `ethash algorithm`, please see the [Ethereum wiki](https://github.com/ethereum/wiki/wiki/Ethash).

