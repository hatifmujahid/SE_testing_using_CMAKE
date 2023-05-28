cmake -S . -B build -G "MinGW Makefiles"
cmake --build build
cd build
./eda.exe