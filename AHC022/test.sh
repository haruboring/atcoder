echo 0 > tools/SumScore.txt
echo 0 > tools/SumWrong.txt



g++-13 -std=c++17 -I.. last.cpp -o tools/a.out

# 0000.txtから0100.txtまで繰り返し実行
for i in $(seq -f "%04g" 0 2); do
    input_file_name="${i}.txt"
    echo ""
    echo "Processing file: ${input_file_name}"
    cd tools && cargo run --release --bin tester ./a.out < in/"${input_file_name}" > "${i}out.txt" && cd ..
done


echo
echo
echo "Result:"
echo "123456789"
cat tools/SumScore.txt
echo
cat tools/SumWrong.txt
echo