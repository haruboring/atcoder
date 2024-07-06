#!/bin/bash

# コンパイル
cd src && g++-14 -std=c++17 -I../.. 0518-3.cpp -o ../a.out && cd ..

# 0000.txtから0100.txtまで繰り返し実行
for i in $(seq -f "%04g" 0 99); do
    input_file_name="tools/in/${i}.txt"
    output_file_name="tools/out/${i}.txt"
    ./a.out < $input_file_name > $output_file_name
done

