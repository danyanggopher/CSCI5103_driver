NITEMS is the third argument for the driver in installation time. The default value is set to be 20.

To install the driver:
cd scullpipe
make
sudo ./scull_load
sudo chmod 777 /dev/scull*

To run producer process:
cd producer
make
./producer [number of items]

To run consumer process:
cd consumer
make
./consumer [number of items]
