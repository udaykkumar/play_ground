### Keep Calm and Push LCs to Git
###### install dependencies, I'm on ubuntu 18 and I do 
            sudo apt install libboost-all-dev  git cmake  -y
###### Build, with cmake and ninja its a piece of cake and fast
            mkdir -p build && cd build && cmake -G"Ninja" .. && ninja && ./lc && ./lc-bm 

