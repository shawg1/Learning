###Ubuntu初始环境配置
####基本软件安装
```
#git curl wget
sudo apt install git curl wget
#vim配置
git clone https://github.com/chxuan/vimplus
cd vimplus
sudo ./install.sh
#npm nodejs react
sudo apt install npm#安装npm
sudo npm install -g n#安装nodejs版本管理n
n latest#安装最新的nodejs
n stable#安装稳定版->推荐这一个
#搜狗拼音自己去官网刚下载安装后要先重启
```
####github的ssh秘钥配置
```
git config --global user.name "your name"
git config --global user.email "your email"
#填写你的github账号信息
git config --lis
#查看是否配置成功
cd ~/.ssh
#如果有东西则删除
ssh-keygen -t rsa -C "your email"#就是上面那个email
#全部回车到结束
cd .ssh
ll
#看到几个文件
cat  id_rsa.pub
#复制显示的内容
#到你的github上去,进入setting,左侧ssh配置,new一个,把刚刚那个粘贴进去
#之后git就不要用http方式了
```

####laravel环境配置
本地服务配置
```
#打开软件更新器切换一下国内的源,清华或者阿里
sudo apt update
sudo apt install apache2
sudo apt install mysql-server mysql-client
sudo apt install php7.0 php7.0-.
#我在使用过程中发现总是会提示我php少了一些拓展,这里就直接把所有的装上了

php
#如果有一些cannot的报错信息的话
sudo apt remove php7.0-snmp
```
composer安装
```
sudo apt install composer
composer
#看到composer提示信息则表示安装成功
composer config -g repo.packagist composer https://packagist.phpcomposer.com
#切换到国内的源
```
laravel安装
```
composer global require "laravel/installer"
sudo vim /etc/profile
#在最后添加下面一句话
export PATH="$PATH:$HOME/.config/composer/vendor/bin
#注销后重新登录
echo $PATH
#看到最后一句就是刚刚添加的内容则添加成功
```