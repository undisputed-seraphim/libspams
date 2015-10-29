# libspams
Sparse Modeling Software for Visual Studio

This is a headers-only library of the SPArse Modeling Software written by these guys: http://spams-devel.gforge.inria.fr/

Note: I added cpp files to remove some linker errors in Visual Studio so it's no longer 'headers-only'.

I take no credit for any code written in there. The license of this code is the same as the license at the above-mentioned website (GPLv3).

I made this for use with Visual Studio 2013. The project file may work with earlier versions of Visual Studio, but I make no guarantees.

If you find and fix any errors feel free to make a pull request. I should respond in a day or two.

TODO: Refactor this code so it produces absolutely no errors.

Currently, linker errors result if you #include spams.h, due to some multiple redefinitions caused by global variables in misc.h.