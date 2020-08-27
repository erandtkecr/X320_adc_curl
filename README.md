# X320_adc_curl
simple example of how to read the digital io from the X320

# install
git clone https://github.com/erandtkecr/X320_adc_curl
cd X320_adc_curl
git submodule update --init --recursive --remote

mkdir build
cd build
cmake ..
make -j9

# example test code
cd build/state_thingy/test
./
