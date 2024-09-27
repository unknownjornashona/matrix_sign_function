# インストール手順

`MatrixSignFunctionProject` を正しくインストールするための手順を以下に示します。これに従うことで、依存関係を満たし、プロジェクトをビルドできるようになります。

## 必要条件

- C++ コンパイラ（GCC、Clang、または MSVC）
- CMake（バージョン 3.10 以上）
- [Eigen](https://eigen.tuxfamily.org/dox/GettingStarted.html)（Eigenをソースからビルドするか、パッケージマネージャを使用してインストールしてください）

## 手順

1. **依存ライブラリのインストール**

   ### Ubuntu/Linux

   ```sh
   sudo apt update
   sudo apt install build-essential cmake libeigen3-dev
   ```

   ### macOS

   ```sh
   brew update
   brew install eigen
   ```

   ### Windows

   1. [Eigenの公式サイト](https://eigen.tuxfamily.org/dox/GettingStarted.html)からEigenをダウンロードします。
   2. ダウンロードしたEigenを適切なディレクトリに解凍します（例: `C:\Eigen`）。

2. **リポジトリをクローン**

   ```sh
   git clone <repository_url>
   cd MatrixSignFunctionProject
   ```

3. **ビルドディレクトリの作成**

   ```sh
   mkdir build
   cd build
   ```

4. **CMakeを使用してプロジェクトを構成**

   インストールしたEigenのパスを指定する場合、以下のように `CMake` コマンドを使用します。

   ```sh
   cmake -DEIGEN3_INCLUDE_DIR=/path/to/eigen ..
   ```

   例（Ubuntu/LinuxのEigenの場合）:

   ```sh
   cmake ..
   ```

5. **プロジェクトをビルド**

   ```sh
   make
   ```

6. **ビルドが成功したか確認**

   ビルドプロセスが成功すると、実行可能ファイル `matrix_sign_function` が `build` ディレクトリ内に生成されます。

7. **実行**

   以下のコマンドで実行ファイルを実行します。

   ```sh
   ./matrix_sign_function
   ```

## 問題解決

インストール中に問題が発生した場合は、以下を確認してください：

- CMakeが正しくインストールされているか。
- Eigenのパスが正しいか。
- C++ コンパイラが正しくセットアップされているか。

さらに問題が続く場合は、[GitHub](https://github.com/your-repo/issues)でイシューを作成してください。