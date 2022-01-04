# Anaconda 简介
anaconda 是一款便捷的 python 包管理工具，不仅可以对 python 不同版本环境进行管理，而且还可以安装管理其他 python 相关的工具包，比如说 pytorch、numpy...
(pytorch 官网有 conda 安装命令，直接在 python 相应环境中执行安装命令即可。)

# Anaconda 使用
打开 Anaconda Prompt
## 创建环境
conda create -n py38 python=3.8

## 删除环境
conda remove -n py38 --all

## 激活环境
conda activate py38

## 退出环境
conda deactivate

## 查看环境中已经安装了的软件包
conda list

## 查看当前存在的 python 环境
conda env list

## 检查更新当前的conda版本
conda update conda

## 下载安装包
conda install package_name(包名)

## 卸载安装包
conda uninstall package_name(包名)

## conda 安装 pytorch 踩坑
根据官网 https://pytorch.org/ 安装命令极有可能失败，主要原因是网络不稳定，因此我们需要换源，参考 https://blog.csdn.net/han_hhh/article/details/116001650 该文列举了多种方法。

## vscode PowerShell 使用 conda
1. conda命令未找到，是没有设置环境变量所致。
2. conda activate [CommandNotFoundError], 参考了博客https://www.codenong.com/cs108900830/ 但还未完全解决，每次重启都需要配置。