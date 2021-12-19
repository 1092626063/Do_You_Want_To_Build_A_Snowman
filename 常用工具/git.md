# Git
接触 git 也有很多年了，之前在学校里只有自己一个人提交，不会出现什么问题。但是当在工作中与团队成员共同开发时，时常遇到一些问题，也一直靠着 google 蒙混过关，并不清楚他的原理，有时还会由于操作失误浪费很多时间，更别说巧妙得利用他。由此，需要系统学习一下，利用它更清晰得辅助我们的版本管理。

# SSH 配置
ssh，全称（Secure Shell），工作在客户端认证过程中。

配置：
- 使用 ssh-keygen 命令来创建密钥对， 默认保存路径为~/.ssh/， 一般id_rsa为私钥，id_rsa.pub为公钥。
- 使用cat ~/.ssh/id_rsa.pub命令获取公钥，然后拷贝到托管网页上， 一般是setting(设置)—>SSH Keys里面添加

原理：
- 当 client 需要登录远程主机时，本地主机向远程主机发送一个登录请求，远程收到消息后，返回一个随机生成的字符串，本地拿到该字符串，用存放在本地的私钥进行加密，再次发送到远程，远程用之前存放在远程的公钥对本地发送过来加密过的字符串进行解密，如果解密后与源字符串等同，则认证成功。

# 常用命令
## git reset HEAD^
- 退回一个 commit 提交，将与上一个版本的所有差异放到工作目录。
- 用于合并 commit 结点（开发新功能时，可能频繁得 commit）。
- 其中 “HEAD^” 可以替换为任意版本。
- --hard、--soft、--mixed 的区别参照网上。
- 似乎这种方式只有对本地有效果，如果已经 push 到远程的 commit 记录似乎不会更改。//TODO 待验证

## 创建本地新分支
- get checkout -b dev 创建本地 dev 新分支并自动切换到新分支。

## 拉取远程分支并创建本地分支
- git checkout -b 本地分支名x origin/远程分支名x
1. 自动切换到本地分支x
2. 会和远程分支建立映射关系。

- git fetch origin 远程分支名x:本地分支名x
1. 不会自动切换到该本地分支x，需要手动checkout。
2. 不会和远程分支建立映射关系。


## 建立与远程分支的映射关系
- git branch --set-upstream-to origin/远程分支名
- 设置了当前分支与远程分支的映射关系后，只需要使用 git pull / git push 简单的命令即可实现拉取/推送。

- 撤销映射关系： git branch --unset-upstream

## git branch -vv
查看本地分支与远程分支的映射关系。

## git commit 规范
commit message格式: 
```
<type>(<scope>): <subject>
```

### type(必须)
用于说明git commit的类别，只允许使用下面的标识。
- feat：新功能（feature）
- fix/to：修复bug，可以是QA发现的BUG，也可以是研发自己发现的BUG。
1. fix：产生diff并自动修复此问题。适合于一次提交直接修复问题
2. to：只产生diff不自动修复此问题。适合于多次提交。最终修复问题提交时使用fix
- docs：文档（documentation）
- style：格式（不影响代码运行的变动）
- refactor：重构（即不是新增功能，也不是修改bug的代码变动）
- perf：优化相关，比如提升性能、体验。
- test：增加测试。
- chore：构建过程或辅助工具的变动。
- revert：回滚到上一个版本。
- merge：代码合并。
- sync：同步主线或分支的Bug。

### scope(可选)
scope 用于说明 commit 影响的范围，比如数据层、控制层、视图层等等，视项目不同而不同。

例如在Angular，可以是location，browser，compile，compile，rootScope， ngHref，ngClick，ngView等。如果你的修改影响了不止一个scope，你可以使用*代替。

### subject(必须)
- subject 是 commit 目的的简短描述，不超过50个字符。
- 结尾不加句号或其他标点符号。

### 例子
- fix(DAO):用户查询缺少username属性
- feat(Controller):用户查询接口开发
