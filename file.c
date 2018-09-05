adb shell screenrecord --time-limit=180 --bit-rate=500000 --size=800x480 --output-format=h264 - | gst-launch fdsrc fd=0  ! h264parse ! omx_h264dec  !autovideosink
