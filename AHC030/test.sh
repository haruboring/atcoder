#!/bin/bash

source_file=$1

# コンパイル
g++-13 -std=c++17 -I.. tools/a.out

# 0000.txtから0100.txtまで繰り返し実行
for i in $(seq -f "%04g" 0 99); do
    input_file_name="${i}.txt"
    echo "input_file_name: ${input_file_name}"
    # cargo runを実行し、標準エラー出力から数値を抽出してsumに加算
    error_output=$(cd tools && cargo run -r --bin tester ./a.out < in/${input_file_name} > out16/${input_file_name})
done

# input_file_name: 0087.txt
#     Finished release [optimized] target(s) in 0.02s
#      Running `target/aarch64-apple-darwin/release/tester ./a.out`
# "ようこそ": ようこそ