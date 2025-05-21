# calculator
calculator app

# Dockerイメージのビルド
docker build -t debian_periodic_processing .

# コンテナ起動（ログフォルダのマウント例付き）
docker run -it \
  --platform linux/arm/v7 \
  --name machine \
  -p 80:80
  -v ~/Docker/debian/log/:/var/log \
  debian_periodic_processing