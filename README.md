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

#### 鐵軌道岔

#### 括弧配對

#### 運算式解析

### 軼事

`stack` 是非常實用重要的資料結構，現代電腦非常依賴之。比如一般程式語言中的函式呼叫，絕大多數都是基於 `stack` 的。因此遞迴崩潰時，就叫做 *stack overflow*，這也是國外知名程式論壇 [stackoverflow.com](https://stackoverflow.com/) 的命名緣由。

如果問一個 Programmer __push__ 的相反，他會回答 __pop__。（`git` 的 *pull* 其實是 *fetch* + *merge* 喔 XDD）

## Queue 佇列

是一個遵守 __FIFO__ *(First In, First Out)* 原則的 `ADT`。

如同播放軟題的機制，越先被加入的越先播放。

即時演練：[模板題](https://judge.tcirc.tw/ShowProblem?problemid=b043)

### 約瑟夫問題

## Priority Queue 優先權佇列（又稱 Heap 堆積）