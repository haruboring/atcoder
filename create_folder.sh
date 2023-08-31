# 色々
rm */tempCodeRunnerFile.cpp

read -p "new folder name: " new_folder_name

# 新しいフォルダを作成
mkdir -p "${new_folder_name}"

# コピー元のフォルダ内の全てのファイル・ディレクトリを新しいフォルダにコピー
cp -R "template/." "${new_folder_name}/"