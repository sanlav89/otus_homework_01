# otus_homework_01

Первый проект с CMake, CI/CD

# Build & Run
cd <otus_homework_01_dir>  
cmake . -DPATCH_VERSION=123  
cmake --build .  
cmake --build . --target test  
cmake --build . --target package  
./helloworld_cli  

# Output:
Version: 123  
Hello, World!
