# syntax=docker/dockerfile:1
FROM ubuntu:latest

# インタラクティブモードにならないようにする
ARG DEBIAN_FRONTEND=noninteractive

# タイムゾーンを日本に設定
ENV TZ=Asia/Tokyo

WORKDIR /app

# パッケージリストの更新と必要なパッケージのインストール
RUN apt-get update && apt-get install -y \
    time \
    tzdata \
    tree \
    git \
    curl \
    gcc-12 \
    g++-12 \
    gdb \
    python3 \
    python3-pip \
    nodejs \
    npm

# C++でAtCoder Library(ACL)を使えるようにする
RUN git clone https://github.com/atcoder/ac-library.git /lib/ac-library
ENV CPLUS_INCLUDE_PATH /lib/ac-library

# atcoder-cliのインストール
RUN npm install -g atcoder-cli@2.2.0

# コンテスト補助アプリケーションをインストール
RUN pip install online-judge-tools==11.5.1
