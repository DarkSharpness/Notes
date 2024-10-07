# 自顶向下

## 第二章 - 应用层

### 网络架构

client-server 架构 和 p2p (去中心 peer to peer)

- client 发起请求，server 等待请求(随后处理)

socket 套接字: 进程与计算机网络之间的接口 (process <--(socket)-->  buffer (managed by OS) <--> internet)

> remark: 为什么翻译是套接字...

进程寻址:  1.主机地址 2. 主机上的哪个进程. 分别对应 (IP address和 port number)

Internet 传输层协议提供的服务:

- TCP: 可靠，无差错，按适当顺序交付，先握手。(TCP 的加密可以借助 TLS (Transport Layer Security)，某种应用层的加强)
- UDP: 无连接，不保证数据传输。没有拥塞控制机制。

应用层协议:

- 报文类型
- 报文类型的语法
- 字段的语义
- 一个进程何时、如何发送报文，如何响应

### Web & HTTP

使用 TCP，采用无状态连接，有持续和非持续连接。

RTT(Round-trip Time): 往返时间。

- 非持续: 首先建立 TCP 连接，然后请求一个文件，server 发送完成后关闭 TCP 连接。总响应时间 = RTT * 2 + 文件传输时间

#### 请求报文

```
GET /somedir/page.html HTTP/1.1
Host: www.someschool.edu
Connection: close
User-agent: Mozilla/5.0
Accept-language: fr

```

换行是 `cr` `lf` ，空格不能省。最后一行结束后有空行 (`crlf`)。再后面是实体。

首部行:

- `Host`: 高速缓存
- `Connection`: 持续/非持续
- `User-agent`: 浏览器类型
- `Accept-language`: 语言版本？

> Remark: 后面一小段来自 GPT

- `GET`：通常用于请求数据，主要用于从服务器获取资源。它是安全的，幂等的（多次请求同一资源不会改变其状态）。
- `POST`：用于向服务器发送数据，通常用于提交表单或上传文件。它可能会改变服务器上的状态。

当然，请求的数据如果少，也可以放在 URL 内部 (example.com/page?name=value)

#### 响应报文

```
HTTP/1.1 200 OK
Connection: close
Date: Tue, 18 Aug 2015 15:44:04 GMT
Server: Apache/2.2.3 (CentOS)
Last-Modified: Tue, 18 Aug 2015 15:11:03 GMT
Content-Length: 6821
Content-type: text/html

```

第一行是状态行，含 **状态**，**响应码**

#### Cookie

类似服务器缓存。服务器响应中 `Set-cookie` 可以告诉用户 cookie 是什么，用户可以 `Cookie` 指定。可以为无状态的 HTTP 网络添加状态。

#### Web 缓存

代理服务器。降低访问远端的平均延迟(前提是你得 cache hit)。CDN(?)

由于 cache 可能过期，用户可以条件 get，指定 `If-modified-since` 保证数据不会太老。

### 邮件 Mail

主要由: **用户代理**，**邮件服务器**，**简单的邮件传输协议(Simple Mail Transfer Protocol, SMP)** 构成

SMTP 只能推送，不能索取。(对比: HTTP 是一个可以拉的协议)

### DNS

DNS 是：

1. 一个由分层的 DNS 服务器实现的分布式数据库
2. 一个使得主机能够查群分布式数据库的应用层协议

在用户访问某个网站的时候，需要先获取目标的 IP 地址，这需要向写定的 DNS 服务器发送查询请求。

DNS 可以实现主机别名 (网站 a 实际地址是 b, 但是 a 比 b 更容易记忆，在人们访问 a 的时候，请求 a 的 IP, 实际会返回 b)

DNS 基于 UDP

> Remark: 猜测是因为要求低延迟，TCP 握手太慢啦

DNS 采用分层，可拓展的架构

1. 根 DNS 服务器
2. 顶级域 DNS 服务器 (**TLD**) (com, net, org)
3. 权威 DNS 服务器 (可能由学校管理，比如 sjtu.edu.cn)

在查询的时候，是自顶向下，一点点的细化。(先查 root, root 告诉你你要找哪个顶级服务器，再一级一级往下)

> Remark: system 都喜欢 hierarchy + cache, "divide and conquer" is the answer to this world!

一般来说，本地还会有本地 DNS 服务器 (例如，在连上 WIFI 的时候，ISP 会提供一个主机的 IP 地址，通常距离主机非常近，比如就在居民区附近)，它起到代理的作用，把请求转发给 DNS 服务器的层次结构 。

迭代查询(本地 DNS 服务器一步步地向 root -> TLD -> ...，每次请求都是本地服务器发起) / 递归查询 (在本地服务器发往 root 以后，root 向下去查询)。

DNS 报文: (Name, Value, Type, TTL) 4 元组

TTL: 该记录的生存时间，决定了资源记录什么时候从缓存中删除。

- Type = A。Name 是主机名，Value 是对应的 IP 地址。
- Type = NS。Name 是域 (如foo.com)，Value 是一个知道如何解析 Name 的 DNS 服务器
- Type = CNAME。Name 是一个别名。Value 是规范主机名。
- Type = MX。同上，但是 Value 必须是邮件服务器的规范主机名。

 ```
 12 Byte Header | Questions | Answers | ...
 ```

### P2P

TODO.

