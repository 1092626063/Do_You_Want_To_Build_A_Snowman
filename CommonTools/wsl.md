# wsl
windows 下的 linux 子系统，简称 wsl。
为了使得远程连接电脑上的 linux 子系统，需要做如下配置。

# linux ubuntu 启动 ssh
cd /etc/ssh
sudo service ssh restart
ifconfig//查看linux ip，端口转发需要用到

# windows 配置端口转发
配置端口转发规则：其中 connectaddress 为 linux ip
netsh interface portproxy add v4tov4 listenaddress=0.0.0.0 listenport=2222 connectaddress=172.18.194.52 connectport=2222

查看端口转发规则：
netsh interface portproxy show all

清除端口转发规则：
netsh interface portproxy reset
