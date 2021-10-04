# otus_homework_01 

Первый проект с CMake, CI/CD

# Build & Run
cd <otus_homework_01_dir>  
cmake . -DPATCH_VERSION=123  
cmake --build .  
cmake --build . --target test  
cmake --build . --target package  

# Первая часть  (release 3)
./helloworld_cli  
# Output:
Version: 123  
Hello, World!  

# Вторая часть  (release 6)
./ip_filter < <path-to-ip_filter.tsv>/ip_filter.tsv  
# Output
222.173.235.246  
222.130.177.64  
222.82.198.61  
222.42.146.225  
220.189.194.162  
220.180.121.6  
220.132.196.75  
...  
46.70.147.26  
46.70.113.73  
46.70.29.76  
46.55.46.98  
46.49.43.85  
39.46.86.85  
5.189.203.46  

# Доп. задание по 'auto', 'tuple' (release 7)
cd ./auto_tuple
