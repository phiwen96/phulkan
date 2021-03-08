# phulkan


To configure:
	cmake -S . -B build
		Add -GNinja if you have Ninja.
To build:
	cmake --build build
To test (--target can be written as -t in CMake 3.15+):
	cmake --build build --target test
To build docs (requires Doxygen, output in build/docs/html):
	cmake --build build --target docs
To use an IDE, such as Xcode:
	cmake -S . -B xbuild -GXcode
	cmake --open xbuild

git submodule deinit -f toml++
 git rm toml++  
	