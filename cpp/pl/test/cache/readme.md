## 缓存工作机制

### 浮点加法的计算量

[示例代码](02.cpp)

- 并行给浮点数组每个元素作一次加法反而更慢
- 因为一次浮点加法的计算量和访存的超高延迟相比实在太少了
- 计算太简单，数据量又大，并行只带来了多线程调度的额外开销
- 经验公式：1次浮点读写 ≈ 8次浮点加法
- 如果矢量化成功(SSE)：1次浮点读写 ≈ 32次浮点加法
- 如果CPU有4个核且矢量化成功：1次浮点读写 ≈ 128次浮点加法

所以上述的示例代码中，并行反而比串行要慢一些

---

那么多少计算量才算多呢？

[示例代码](03.cpp)