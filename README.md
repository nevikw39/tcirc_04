# 一中電研 37 屆下學期 C++ 班 社課 Ⅳ
# https://github.com/nevikw39/tcirc_04

## 快速連結

> **[上課簡報]()**
> [社團ＯＪ](https://judge.tcirc.tw)
> [社團網站](https://tcirc.tw)
> [Telegram 討論區](https://t.me/joinchat/KUNytVBKySskb35M4TdOig)
> [Python 班講義](https://hackmd.io/@RucKuo/Circ-Python)

> 特別感謝「*[星城數位科技](http://xincastle.com/)*」

> [表單](https://s.bentley.taipei/form)

由於疫情關係，電腦教室鍵盤暫停使用，請同學改用螢幕小鍵盤或 Remote Mouse

### 電腦端

1. [下載](https://www.remotemouse.net/downloads/RemoteMouse.exe)
2. 安裝（管理員密碼：*sova*）
3. 查看 IP`(210.60.35.*)`

### 手機端

1. 安裝
    - [Android](https://play.google.com/store/apps/details?id=com.hungrybolo.remotemouseandroid)
    - [iOS](https://itunes.apple.com/app/id385894596?mt=8)
2. 輸入 IP`(210.60.35.*)`

請注意，「Remote Mouse」是中囯軟體喔．

## 回憶

[上週講義](https://github.com/nevikw39/tcirc_03)

### set

- 無序性：元素預設由小到大
- 互異性：元素不重複

### map

又稱關聯式陣列，一種 `key-value` 對映關係。可視為模仿陣列下標操作的推廣。`set` 或被認為是只有 `key` 而 `value` 為 `null` 的特例。

## Container Adaptors 容器適配器 / 配接器

*STL* 中有些資料結構並沒有直接被實作，而是提供一組特定的介面可以由其他容器實作。這類 __ADT__ *(Abstract Data Structure)* 包含：`stack`, `queue`, `priority_queue` *(heap)*。其中，`stack`, `queue` 預設以 `deque` 為內部依賴容器，`priority_queue` 則使用 `vector` 及 __<algorithm>__ 中的 *make_heap*, *push_heap*, *pop_heap* 等相關函式維護之。

我們用 `push` 方法將元素送入容器、`pop` 方法將元素移出容器。注意 `pop` 回傳型態是為 *void*，__stack__ 必須由 `top` 方法取得疊頂的元素、__queue__, *priority_queue* 由 `front` 方法取得列首的元素。

## Stack 堆疊

是一個遵守 __LIFO__ *(Last In, First Out)* 原則的 `ADT`。

如同在桌上堆東西，越後疊上去的越先被取出。

即時演練：[模板題](https://judge.tcirc.tw/ShowProblem?problemid=b039)

### 應用

*Stack* 的應用十分廣泛，像是 __DFS__ *(Depth-first Search)* 等等。

#### 鐵軌道岔

火車的車廂在調度時通常有個中繼站，藉此重組順序。中繼站遵守 LIFO 原則，因此是個堆疊。

- [TCIRC Judge - b040](https://judge.tcirc.tw/ShowProblem?problemid=b040)
- [UVA 514](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=455)

#### 括弧配對

觀察合法括弧字串，可以發現越早出現的左括弧，與之配對之右括弧即越早出現。也就是說，檢驗括弧字串的合法性可以利用先進後出的堆疊。

每當讀到左括弧就壓入堆疊，而遇到右括弧時檢查堆疊頂端的左括弧是否能與之配對，注意確認堆疊內是否有元素。

- [TCIRC Judge - b041](https://judge.tcirc.tw/ShowProblem?problemid=b041)
- [GreenJudge d033](http://www.tcgs.tc.edu.tw:1218/ShowProblem?problemid=d033)
- [UVA 673](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=8&page=show_problem&problem=614)

#### 運算式解析

日常生活中，一般人類使用的運算式表示法如 `A + B` 稱為「中序運算式 *(Infix Expression)*」，即運算子在兩運算元中間。可是這種表示法對電腦而言並不好懂，遂有人陸續提出前序、後序表示法。

後序運算式 *(postfix Expression)*，顧名思義，就是運算子在兩運算元中間之後的表示法。也就是說， `A + B` 會變成 `A B +`。這種表示法的好處是不必理會運算子優先順序（先乘除後加減）也省去了繁複的括弧，例如 `A + (B + C) * D - E` 會變成 `B C + D * A + E -`。

更深入一點探討電腦如何計算運算式吧。組合語言太難懂惹，茲以 *Java Bytecode* 為例。在 *Java* 中，假若你宣告兩個變數 `int a = 87, b = 69;` 並計算 `int c = a + b;`，則實際上會被編譯為八行位元組碼：`iconst_1`、`istore_1`、`iconst_2`、`istore_2`、`iload_1`、`iload_2`、`iadd`、`istore_3`。其中，前四個指令初始化 `a, b `，`iload_1`、`iload_2` 將 `a, b ` 分別 __push__ 入堆疊，`iadd` 將堆疊頂端兩個數 __pop__ 出後相加再把結果 __push__ 入堆疊，`istore_3` 才把堆疊頂端的結果存入 `c` 中。

而如果我們要把中序式轉為後序式同樣可以借助堆疊。對於中序式的每個元素，若是 `(` 就入堆疊，`)` 就不斷輸出堆疊頂端元素直到遇到 `(`；若是運算子則不斷輸出堆疊頂端元素直到頂端運算子的優先權小於當前運算子；若是運算元則直接輸出。

### 軼事

`stack` 是非常實用重要的資料結構，現代電腦非常依賴之。比如一般程式語言中的函式呼叫，絕大多數都是基於 `stack` 的。因此遞迴崩潰時，就叫做 *stack overflow*，這也是國外知名程式論壇 [stackoverflow.com](https://stackoverflow.com/) 的命名緣由。

如果問一個 Programmer __push__ 的相反，他會回答 __pop__。（`git` 的 *pull* 其實是 *fetch* + *merge* 喔 XDD）

## Queue 佇列

是一個遵守 __FIFO__ *(First In, First Out)* 原則的 `ADT`。

如同播放軟題的機制，越先被加入的越先播放。

即時演練：[模板題](https://judge.tcirc.tw/ShowProblem?problemid=b043)

### 應用

*Queue* 的應用也很廣泛，像是 __BFS__ *(Breadth-first Search)*、排程管理等等。

#### 約瑟夫問題

## Priority Queue 優先權佇列與 Heap 堆積

*Priority Queue* 不是 *Queue*，就跟科氏力不是力一樣，原因是作業系統排程時，有些比較晚加入的工作比較急迫要插隊，所以才提出這種資料結構。總而言之，*Priority Queue* 是這樣的 `ADT`: 優先權越大的元素越早離開。

*Priority Queue* 是抽象的，通常以 *Heap* 實作。*Heap* 是一種特殊的樹，對於任意節點其值必小於等於（或大於等於）其父節點。

__STL__ `priority_queue` 則使用 `vector` 及 __<algorithm>__ 中的 *make_heap*, *push_heap*, *pop_heap* 等相關函式維護之。__PBDS__ 提供的 `priority_queue` 所使用的 *Heap* 有多種選擇，包括：`Binary Heap`, `Pairing Heap`, `Binomial Heap`, `Thin Heap` (Fibonacci Heap 的改良)。

### 應用

*Priority Queue* 在 __Prim Algorithm__, __Dijkstra Algorithm__ 中皆相當重要。

#### Huffman Encoding 霍夫曼編碼

##### Add All

##### 編碼長度