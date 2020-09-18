#ifndef  _PLOG_H_
#define  _PLOG_H_
#include <stdio.h>
#include <time.h>

inline void GetTime(char* pszTimebuf, int nBuflen)
{
    time_t tmTime;
    time(&tmTime);
    strftime(pszTimebuf, nBuflen, "%Y-%m-%d %H:%M:%S", localtime(&tmTime));
}

inline void GetTime_s(char* pszTimebuf, int nBuflen)
{
    time_t tmTime;
    time(&tmTime);
    strftime(pszTimebuf, nBuflen, "%Y%m%d%H%M%S", localtime(&tmTime));
}

inline void GetTime_h(char* pszTimebuf, int nBuflen)
{
    time_t tmTime;
    time(&tmTime);
    strftime(pszTimebuf, nBuflen, "%Y%m%d%H", localtime(&tmTime));
}

#define Plog(format, ...)\
    do{\
        char szTime[64];\
        GetTime(szTime, 64);\
        fprintf(stderr, "%s at %s %d %s : " format "\n", szTime, __FILE__, __LINE__, __PRETTY_FUNCTION__, ##__VA_ARGS__);\
    }while(0)

#endif