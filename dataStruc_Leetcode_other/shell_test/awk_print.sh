#!/bin/sh

row_value="wiscom,20,20001,zxx"
row_value_count=`echo $row_value | awk 'BEGIN{FS=","}{print NF}'`  #获取个数，分隔符再用逗号
echo $row_value_count

for((i=1; i<=row_value_count; i++))
do
    array[$i]=`echo $row_value | awk -v col_number="${i}" 'BEGIN {FS=","} {print $col_number}'`
    echo "array[$i]=${array[$i]}"
done

#PID=`pwd`/bin/xcloudd 
#runpath=`ps -ef | grep $PID | awk '{print $8}'`
#`awk '{print $8}'`

innerPort="9001"
sessionPort="9002"
paraMonitor="--flagfile=$xcloudDir/conf/ds.ini --daemonize=true --internalPort=$innerPort 
--sessionPort=$sessionPort"
echo $paraMonitor
