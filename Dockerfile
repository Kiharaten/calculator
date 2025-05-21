# ディストリビュージョン選択
FROM debian:bullseye

# タイムゾーンなど無視してOKなら noninteractive に
ENV DEBIAN_FRONTEND=noninteractive

# パッケージ更新＆基本ツール＋開発環境インストール
RUN apt-get update && apt-get install -y \
    bash \
    vim \
    gcc \
    make \
    man \
    nano \
    sudo \
    curl \
    git \
    python3 \
    python3-pip \
    build-essential \
    strace \
    libglib2.0-dev \
    net-tools \
    iputils-ping \
 && apt-get clean && rm -rf /var/lib/apt/lists/*

# 開発用ユーザーの作成
RUN useradd -m Tenda

# 作業ディレクトリを作成して権限付与
RUN mkdir -p /home/Tenda/work && chown -R Tenda:Tenda /home/Tenda/work

# ワーキングディレクトリを設定
WORKDIR /home/Tenda/work

# 開発者ユーザーで動作
USER Tenda

# 起動時のシェル
CMD ["/bin/bash"]
