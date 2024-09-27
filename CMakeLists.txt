cmake_minimum_required(VERSION 3.10)

# プロジェクト名とバージョンを指定
project(MatrixSignFunctionProject VERSION 1.0)

# C++14 標準を使用
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Eigenライブラリのパスを指定（適切に変更してください）
set(EIGEN3_INCLUDE_DIR "/path/to/eigen")
include_directories(${EIGEN3_INCLUDE_DIR})

# インクルードディレクトリの設定
include_directories(include)

# ソースファイルの指定
set(SOURCES
    src/MatrixSignFunction.cpp
    src/main.cpp
)

# 実行ファイルを生成
add_executable(matrix_sign_function ${SOURCES})

# テスト用のサブディレクトリ
# Google TestやCatch2などを使用する場合はここにテストの設定を追加
# add_subdirectory(tests)

# ドキュメント生成のサポート（必要に応じて追加）
# find_package(Doxygen)
# if(DOXYGEN_FOUND)
#     configure_file(Doxyfile.in Doxyfile @ONLY)
#     add_custom_target(doc Doxygen)
# endif()

# スクリプト用のカスタムコマンドなどがあればここに追加
