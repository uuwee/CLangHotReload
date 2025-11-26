cmake -B out -G "Ninja" -DCMAKE_EXPORT_COMPILE_COMMANDS=ON 
copy .\out\compile_commands.json .\compile_commands.json
cmake --build out
