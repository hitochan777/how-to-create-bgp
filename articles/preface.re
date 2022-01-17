= 前書き

インターネットを支えるルーティングプロトコルであるBGP(Border Gateway Protocol)をRFCからRustで実装する方法を解説します。小さなプログラムから始め、Update Messageを交換しルーティングテーブルの更新を行うまで、ステップバイステップで実装を追うことができるように解説します。

本PDFでは正常系のみ実装します。また可能な限り最小限の実装をします。

本書はWebでも公開しております。ブラウザで読みたい方は以下を参照ください。

 * ToDo: URLを追加！

また、本書で作成するサンプル実装・本PDFのソースコードは以下リポジトリに公開しております。

 * https://github.com/Miyoshi-Ryota/mrbgpdv2
 * https://github.com/Miyoshi-Ryota/how-to-create-bgp

GitHub Starをいただけたらとっても嬉しいです。

== 対象読者
読者に以下の前提知識を求めています。

 * ルーティングプロトコルは聞いたことがある。
 * スタティックルートとは何か分かる。
 * ルーティングテーブルを見て意味が分かる。
 * 何らかのプログラミング言語でのプログラミング経験
 * Rustを知っている。

以下の経験があるとよりわかりやすいかもしれません。

 * BGPの運用経験
 * Docker、docker-composeを用いた開発経験
 * wiresharkを用いてパケットキャプチャを行った経験
 
== 書いていないこと

本PDFには以下のことは書かれておりません。

 * BGPとは何かということについての詳細な説明
 ** ただし、参考になるWebページを紹介しています。そのためBGPについて知らなくても問題ありません。
 * Rustの文法解説
 * Rust / Docker / docker-compose / wiresharkなど本PDFに登場するツールのインストール方法

== 本書の動作環境
筆者は以下の環境で本PDFのサンプルプログラムの作成・動作環境を行っております。

 * Ubuntu 20.04 LTS / Pop!_OS 20.04 LTS
 * cargo 1.53.0-nightly (f3e13226d 2021-04-30)
 * rustc 1.54.0-nightly (676ee1472 2021-05-06)

cargo / rustcのバージョンは2018 Edition以降であれば何でも動作すると考えております。

ただしOSについては注意点があります。
ルーティングプロトコルを実装するため、ルーティングテーブルを読み書きする処理が存在します。ルーティングテーブルの読み書きの方法はOSによって異なります。そのため、本PDFの後半ではLinuxの環境が必要になります。仮想マシン等でも問題ありません。

