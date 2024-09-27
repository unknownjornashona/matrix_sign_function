# MatrixSignFunctionProject

## 概要
`MatrixSignFunctionProject` は、行列の符号関数を計算する C++ プロジェクトです。Eigenライブラリを使用しており、行列演算を効率的に実行します。このプロジェクトは、行列に対する数学的な処理を行いたい開発者や研究者に役立つことを目的としています。

## ディレクトリ構造
```
MatrixSignFunctionProject/
├── CMakeLists.txt      # CMakeビルド設定
├── docs/               # ドキュメント
├── include/            # ヘッダーファイル
│   └── MatrixSignFunction.h
├── scripts/            # 補助スクリプト
├── src/               # ソースコード
│   ├── MatrixSignFunction.cpp
│   └── main.cpp
└── tests/              # テストコード
```

## 必要なライブラリ
- [Eigen](https://eigen.tuxfamily.org/dox/GettingStarted.html)

## セットアップ手順

以下の手順に従ってプロジェクトをセットアップしてください。

1. **リポジトリをクローン**

   ```sh
   git clone <repository_url>
   cd MatrixSignFunctionProject
   ```

2. **ビルドディレクトリの作成**

   ```sh
   mkdir build
   cd build
   ```

3. **CMakeを使用してプロジェクトを構成**

   ```sh
   cmake ..
   ```

4. **プロジェクトをビルド**

   ```sh
   make
   ```

## 使用方法

ビルドが成功した後、生成された実行ファイルを実行して行列の符号関数を計算することができます。

```sh
./matrix_sign_function
```

実行すると、結果がコンソールに表示され、`sign_function.csv` というファイルに計算結果が保存されます。また、処理のログが `log.txt` に記録されます。

## テスト

テストコードは `tests` ディレクトリに含まれています。必要に応じてユニットテストを追加してください。

## ライセンス

このプロジェクトは [MIT License](LICENSE) のもとで提供されています。