// SrcFile   : DataPacket.cpp
//
// Create on : 2016-5-11    
//
// Author    : Gaoriyao
//
// Modify By  :
//
// Modify Time:
#ifndef TIME_H_
#define TIME_H_

int ShowCurTime();

int TimeStart(struct timeval &tm_start);

int TimeEnd(struct timeval &tm_end);

void TimeCost(struct timeval &tm_start, struct timeval &tm_end);

#endif
