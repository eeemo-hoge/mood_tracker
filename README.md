このプログラムはシンプルなムードトラッカーです。自分の身体状態を客観的に、また、平均や有意差なども見ることができます。
ログファイルは各々分かれており、catなどでも見ることができます。

C++言語,arch linux環境 下,vscodeで書かれました。
使用したコンパイラはGNUです。

医療的視点からのアドバイスはできかねます。
あくまで個人的内使用、心身の状態を客観視し、データに残し、分析するために作られました。

CUIに常駐させておき、ユーザーのデータ入力を常に受付け、数字の入力とともに動きます。
プログラムのファンクションで、4~5時間ごとの、それぞれの数値の平均値を出すことができます。
よって、この時間帯はいつもイライラしている。。。この時間帯はBPMが速い。。など、客観的に見ることができ、もしかすればいくつかの要因による相関関係を求められるかもしれません。
データファイル、統計ファイル、有意差ファイルそれぞれのcsvファイルをログファイルとして読み込み計算します。


アンドロイドでの実装も予定しています。


This program is a simple mood-tracker. 
It allows you to objectively assess your physical condition and view data such as averages and discrepancies between your actual state,
and your perceived state.

This was written in C++ using VS Code on an Arch Linux environment.
The compiler used was GNU.

I am unable to provide advice from a medical perspective.
This was created solely for personal use—to objectively assess one’s physical and mental state, record the data, and analyze it.

It runs in the command line interface (CLI) in the background, constantly accepting user input and responding as numbers are entered.
The program’s functions allow you to calculate the average of each value every 4 to 5 hours.
This enables you to view the data objectively—for example, “I’m always irritable during this time of day…” or “My BPM is faster during this time…”—and you may even be able to identify correlations between various factors.
The program reads and processes the CSV files for the data, statistics, and statistical significance as log files.

Translated with DeepL.com (free version)
I also plan to implement this on Android.
