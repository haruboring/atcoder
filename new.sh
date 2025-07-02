#!/bin/sh

# 1から500までのループ
for i in $(seq 1 500)
do
  # 数字を3桁のゼロ埋め形式にフォーマット (例: 1 -> 001)
  number=$(printf "%03d" $i)

  # コマンドを組み立てて実行
  echo "実行中: acc new abc${number}"
  acc new abc${number}
done

echo "すべての処理が完了しました。"