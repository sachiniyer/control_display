## Getting Started
- Development server
  ```bash
  touch data
  echo "something" > data
  echo "DATA=data" > .env
  npm run dev
  ```
- Production (docker)
  ```bash
  docker build . -t school-demo
  docker run --name <name of deployment> -it -d -e "DATA=/app/data" -p 5000:3000 school-demo
  ```
- Production (kubernetes)
  You have to change the ingresses and stuff probably. 
  ```bash
  kubectl apply -f deployment.yaml 
  ```
