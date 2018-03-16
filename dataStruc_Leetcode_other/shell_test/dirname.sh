#!/bin/sh

filepath=$(cd "$(dirname "$0")"; pwd)
echo "$0"
echo $(dirname "$0")  #dirname的作用是给出当前文件所在的相对目录，这里就是 "."
echo $filepath

#echo '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>' > ./rcode
#echo "<logs>" >> ./rcode
#echo '<logs>' >> ./rcode

echo $?

# add by gyr mkdir xcloud_innerPort_sessionPort first.
innerPort="$1"
sessionPort="$2"

echo $innerPort
echo $sessionPort

 xcloud="xcloud"
 
 xcloudDir=${xcloud}"_"$innerPort"_"$sessionPort
 echo $xcloudDir
 
 mkdir $xcloudDir

rcode=$xcloudDir"/""rcode"
echo "111"
echo $rcode

testdir=$xcloudDir/$xcloudDir/rcode
echo $testdir

function write_rcode() {
echo "22"
echo $xcloudDir
echo "33"
echo $rcode
echo '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>' > ./$rcode
}

write_rcode
