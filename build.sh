if [ ! -d "build" ]; then
    mkdir build
fi

cd build
cmake ..
make
./lets-go-phishing
