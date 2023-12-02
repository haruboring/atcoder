#!/bin/bash

# 引数チェック
if [ "$#" -ne 1 ]; then
    echo "使用方法: $0 [ファイル名]"
    exit 1
fi

source_file=$1

sum=0

# コンパイル
g++-13 -std=c++17 -I../.. $source_file -o tools/a.out

# 0000.txtから0100.txtまで繰り返し実行
for i in $(seq -f "%04g" 0 99); do
    input_file_name="${i}.txt"
    echo ""
    echo "Processing file: ${input_file_name}"

    # プログラムを実行
    ./tools/a.out "${input_file_name}"

    # cargo run コマンドの出力を取得し、echo する
    output=$(cd tools && cargo run -r --bin vis in/${input_file_name} out/${input_file_name})
    echo "Output for ${input_file_name}: $output"

    # 数値のみを抽出して足し合わせる
    num=$(echo $output | grep -o '[0-9]\+')
    sum=$((sum + num))
    echo "Current Total: $sum"
done

# 最終合計を sum_score.txt に追加
echo "$source_file: $sum" >> sum_score.txt
