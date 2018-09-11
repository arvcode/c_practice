video:
adb shell screenrecord --time-limit=180 --bit-rate=500000 --size=800x480 --output-format=h264 - | gst-launch fdsrc fd=0  ! h264parse ! omx_h264dec  !autovideosink
audio:
gst-launch-0.10 alsasrc device=hw:5 !queue min-threshold-bytes=10000 min-threshold-time= 10000000 ! queue2 ring-buffer-max-size= 10000000  ! capsfilter caps=\"audio/x-raw-int, width=16, depth=16, endianness=1234, channels=2, rate=44100, signed=true\" ! alsasink device=hw:0 sync=false


#su root & adb start-server
adb devices
LD_PRELOAD#
