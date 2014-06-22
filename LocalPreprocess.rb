#!/usr/bin/env ruby
#coding: utf-8

# 二重引用符で囲まれた#include命令のみを処理するスクリプト
# ライブラリのテスト時に使用する

require 'pathname'

main = Pathname.new(ARGV[0])
target_dir = main.parent

main.readlines.each do |line|
  if m = line.match(/^#include +"(.*)"/) 
    included_file = target_dir + Pathname.new(m.captures[0])
    puts included_file.read
  else
    puts line
  end
end

