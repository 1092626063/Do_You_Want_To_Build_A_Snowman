# Git
接触 git 也有很多年了，之前在学校里只有自己一个人提交，不会出现什么问题。但是当在工作中与团队成员共同开发时，时常遇到一些问题，也一直靠着 google 蒙混过关，并不清楚他的原理，有时还会由于操作失误浪费很多时间，更别说巧妙得利用它。由此，需要系统学习一下，利用它更清晰得辅助我们的版本管理。

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

## git stash
- git stash
保存当前所有未提交的修改（包括暂存的和非暂存的），保存至栈中
- git stash save "message..."
这是 git stash 的完整版
- git stash list
查看当前保存在栈中的进度列表
- git stash pop
恢复最新保存的工作进度，并将恢复的工作进度从栈中清除
- git stash clear
清除栈中所有工作进度

## 创建本地新分支
- get checkout -b dev 创建本地 dev 新分支并自动切换到新分支。

## 拉取远程分支并创建本地分支
- git checkout -b 本地分支名x origin/远程分支名x
1. 自动切换到本地分支x
2. 会和远程分支建立映射关系。
(其实上面那个命令没必要用，比较难记忆，可以使用下面的方法)
- git fetch origin & git checkout 远程分支名x
1. 首先更新所有分支，这样远程分支会在同步到本地 origin/分支名 中
2. 直接 checkout 想要关联的分支即可


- git fetch origin 远程分支名x:本地分支名x
1. 不会自动切换到该本地分支x，需要手动checkout。
2. 不会和远程分支建立映射关系。

## git fetch origin
将远程仓库中新的提交拉取到本地 origin/分支名 中

## git merge 与 git rebase 区别
- git merge xxx
1. 将当前分支与 xxx 分支合并
2. 若两个分支存在不同的 commit 记录，则会自动创建一个新的 merge commit
3. 优点：记录了真实的 commit 情况，包括每个分支的详情
4. 因为每次 merge 会自动生成一个 merge commit，当 commit 比较频繁时，看到的分支会比较杂乱

- git rebase xxx
1. 将当前分支变基到 xxx 分支
2. 合并之前的 commit 历史，使之成为线性历史树
3. 优点：得到更简洁的项目历史，省去了 merge commit
4. 缺点：如果合并出现代码问题不容易定位，因为历史记录已 re-write

## 建立与远程分支的映射关系
- git branch --set-upstream-to origin/远程分支名
- 设置了当前分支与远程分支的映射关系后，只需要使用 git pull / git push 简单的命令即可实现拉取/推送。

- 撤销映射关系： git branch --unset-upstream

## git branch [< options >]
    -vv  查看本地分支与远程分支的映射关系。
    -a   list both remote-tracking and local branches
    -d   delete fully merged branch

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
