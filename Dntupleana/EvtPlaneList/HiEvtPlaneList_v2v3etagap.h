#ifndef __HiEvtPlaneList__
#define __HiEvtPlaneList__
/*
Index     Name   Detector Order hmin1 hmax1 hmin2 hmax2 minpt maxpt nsub mcw    rmate1    rmate2
    0      HFm2        HF     2 -5.00 -3.00  0.00  0.00  0.01 30.00 3sub  no      HFp2 trackmid2
    1      HFp2        HF     2  3.00  5.00  0.00  0.00  0.01 30.00 3sub  no      HFm2 trackmid2
    2 trackmid2   Tracker     2 -0.75  0.75  0.00  0.00  0.30  3.00 3sub  no      HFm2      HFp2
    3   trackm2   Tracker     2 -0.50  0.00  0.00  0.00  0.30  3.00 3sub  no      HFp2      HFm2
    4   trackp2   Tracker     2  0.00  0.50  0.00  0.00  0.30  3.00 3sub  no      HFp2      HFm2
    5     HFm2a        HF     2 -5.00 -2.00  0.00  0.00  0.01 30.00 3sub  no      HFp2   trackp2
    6     HFm2b        HF     2 -5.00 -2.50  0.00  0.00  0.01 30.00 3sub  no      HFp2   trackp2
    7     HFm2c        HF     2 -5.00 -3.00  0.00  0.00  0.01 30.00 3sub  no      HFp2   trackp2
    8     HFm2d        HF     2 -5.00 -3.50  0.00  0.00  0.01 30.00 3sub  no      HFp2   trackp2
    9     HFm2e        HF     2 -5.00 -4.00  0.00  0.00  0.01 30.00 3sub  no      HFp2   trackp2
   10     HFm2f        HF     2 -5.00 -4.50  0.00  0.00  0.01 30.00 3sub  no      HFp2   trackp2
   11     HFp2a        HF     2  2.00  5.00  0.00  0.00  0.01 30.00 3sub  no      HFm2   trackm2
   12     HFp2b        HF     2  2.50  5.00  0.00  0.00  0.01 30.00 3sub  no      HFm2   trackm2
   13     HFp2c        HF     2  3.00  5.00  0.00  0.00  0.01 30.00 3sub  no      HFm2   trackm2
   14     HFp2d        HF     2  3.50  5.00  0.00  0.00  0.01 30.00 3sub  no      HFm2   trackm2
   15     HFp2e        HF     2  4.00  5.00  0.00  0.00  0.01 30.00 3sub  no      HFm2   trackm2
   16     HFp2f        HF     2  4.50  5.00  0.00  0.00  0.01 30.00 3sub  no      HFm2   trackm2
   17      HFm3        HF     3 -5.00 -3.00  0.00  0.00  0.01 30.00 3sub  no      HFp3 trackmid3
   18      HFp3        HF     3  3.00  5.00  0.00  0.00  0.01 30.00 3sub  no      HFm3 trackmid3
   19 trackmid3   Tracker     3 -0.75  0.75  0.00  0.00  0.30  3.00 3sub  no      HFm3      HFp3
   20   trackm3   Tracker     3 -0.50  0.00  0.00  0.00  0.30  3.00 3sub  no      HFp3      HFm3
   21   trackp3   Tracker     3  0.00  0.50  0.00  0.00  0.30  3.00 3sub  no      HFp3      HFm3
   22     HFm3a        HF     3 -5.00 -2.00  0.00  0.00  0.01 30.00 3sub  no      HFp3   trackp3
   23     HFm3b        HF     3 -5.00 -2.50  0.00  0.00  0.01 30.00 3sub  no      HFp3   trackp3
   24     HFm3c        HF     3 -5.00 -3.00  0.00  0.00  0.01 30.00 3sub  no      HFp3   trackp3
   25     HFm3d        HF     3 -5.00 -3.50  0.00  0.00  0.01 30.00 3sub  no      HFp3   trackp3
   26     HFm3e        HF     3 -5.00 -4.00  0.00  0.00  0.01 30.00 3sub  no      HFp3   trackp3
   27     HFm3f        HF     3 -5.00 -4.50  0.00  0.00  0.01 30.00 3sub  no      HFp3   trackp3
   28     HFp3a        HF     3  2.00  5.00  0.00  0.00  0.01 30.00 3sub  no      HFm3   trackm3
   29     HFp3b        HF     3  2.50  5.00  0.00  0.00  0.01 30.00 3sub  no      HFm3   trackm3
   30     HFp3c        HF     3  3.00  5.00  0.00  0.00  0.01 30.00 3sub  no      HFm3   trackm3
   31     HFp3d        HF     3  3.50  5.00  0.00  0.00  0.01 30.00 3sub  no      HFm3   trackm3
   32     HFp3e        HF     3  4.00  5.00  0.00  0.00  0.01 30.00 3sub  no      HFm3   trackm3
   33     HFp3f        HF     3  4.50  5.00  0.00  0.00  0.01 30.00 3sub  no      HFm3   trackm3
*/
#include <string>
using namespace std;
namespace hi{

  enum EPNamesInd {
          HFm2,        HFp2,   trackmid2,     trackm2,     trackp2,
         HFm2a,       HFm2b,       HFm2c,       HFm2d,       HFm2e,
         HFm2f,       HFp2a,       HFp2b,       HFp2c,       HFp2d,
         HFp2e,       HFp2f,        HFm3,        HFp3,   trackmid3,
       trackm3,     trackp3,       HFm3a,       HFm3b,       HFm3c,
         HFm3d,       HFm3e,       HFm3f,       HFp3a,       HFp3b,
         HFp3c,       HFp3d,       HFp3e,       HFp3f,   EPBLANK
  };

  const std::string  EPNames[]  = {
        "HFm2",      "HFp2", "trackmid2",   "trackm2",   "trackp2",
       "HFm2a",     "HFm2b",     "HFm2c",     "HFm2d",     "HFm2e",
       "HFm2f",     "HFp2a",     "HFp2b",     "HFp2c",     "HFp2d",
       "HFp2e",     "HFp2f",      "HFm3",      "HFp3", "trackmid3",
     "trackm3",   "trackp3",     "HFm3a",     "HFm3b",     "HFm3c",
       "HFm3d",     "HFm3e",     "HFm3f",     "HFp3a",     "HFp3b",
       "HFp3c",     "HFp3d",     "HFp3e",     "HFp3f" 
  };

  enum Detectors {Tracker, HF, Castor};

  const int  EPDet[]  = {
          HF,        HF,   Tracker,   Tracker,   Tracker,
          HF,        HF,        HF,        HF,        HF,
          HF,        HF,        HF,        HF,        HF,
          HF,        HF,        HF,        HF,   Tracker,
     Tracker,   Tracker,        HF,        HF,        HF,
          HF,        HF,        HF,        HF,        HF,
          HF,        HF,        HF,        HF 
  };

  const int  EPOrder[]  = {
             2,           2,           2,           2,           2,
             2,           2,           2,           2,           2,
             2,           2,           2,           2,           2,
             2,           2,           3,           3,           3,
             3,           3,           3,           3,           3,
             3,           3,           3,           3,           3,
             3,           3,           3,           3 
  };

  const double  EPEtaMin1[]  = {
         -5.00,        3.00,       -0.75,       -0.50,        0.00,
         -5.00,       -5.00,       -5.00,       -5.00,       -5.00,
         -5.00,        2.00,        2.50,        3.00,        3.50,
          4.00,        4.50,       -5.00,        3.00,       -0.75,
         -0.50,        0.00,       -5.00,       -5.00,       -5.00,
         -5.00,       -5.00,       -5.00,        2.00,        2.50,
          3.00,        3.50,        4.00,        4.50 
  };

  const double  EPEtaMax1[]  = {
         -3.00,        5.00,        0.75,        0.00,        0.50,
         -2.00,       -2.50,       -3.00,       -3.50,       -4.00,
         -4.50,        5.00,        5.00,        5.00,        5.00,
          5.00,        5.00,       -3.00,        5.00,        0.75,
          0.00,        0.50,       -2.00,       -2.50,       -3.00,
         -3.50,       -4.00,       -4.50,        5.00,        5.00,
          5.00,        5.00,        5.00,        5.00 
  };

  const double  EPEtaMin2[]  = {
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00 
  };

  const double  EPEtaMax2[]  = {
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00 
  };

  const double  minTransverse[]  = {
          0.01,        0.01,        0.30,        0.30,        0.30,
          0.01,        0.01,        0.01,        0.01,        0.01,
          0.01,        0.01,        0.01,        0.01,        0.01,
          0.01,        0.01,        0.01,        0.01,        0.30,
          0.30,        0.30,        0.01,        0.01,        0.01,
          0.01,        0.01,        0.01,        0.01,        0.01,
          0.01,        0.01,        0.01,        0.01 
  };

  const double  maxTransverse[]  = {
         30.00,       30.00,        3.00,        3.00,        3.00,
         30.00,       30.00,       30.00,       30.00,       30.00,
         30.00,       30.00,       30.00,       30.00,       30.00,
         30.00,       30.00,       30.00,       30.00,        3.00,
          3.00,        3.00,       30.00,       30.00,       30.00,
         30.00,       30.00,       30.00,       30.00,       30.00,
         30.00,       30.00,       30.00,       30.00 
  };

  const std::string  ResCalcType[]  = {
        "3sub",      "3sub",      "3sub",      "3sub",      "3sub",
        "3sub",      "3sub",      "3sub",      "3sub",      "3sub",
        "3sub",      "3sub",      "3sub",      "3sub",      "3sub",
        "3sub",      "3sub",      "3sub",      "3sub",      "3sub",
        "3sub",      "3sub",      "3sub",      "3sub",      "3sub",
        "3sub",      "3sub",      "3sub",      "3sub",      "3sub",
        "3sub",      "3sub",      "3sub",      "3sub" 
  };

  const std::string  MomConsWeight[]  = {
          "no",        "no",        "no",        "no",        "no",
          "no",        "no",        "no",        "no",        "no",
          "no",        "no",        "no",        "no",        "no",
          "no",        "no",        "no",        "no",        "no",
          "no",        "no",        "no",        "no",        "no",
          "no",        "no",        "no",        "no",        "no",
          "no",        "no",        "no",        "no" 
  };

  const int  RCMate1[]  = {
        HFp2,      HFm2,      HFm2,      HFp2,      HFp2,
        HFp2,      HFp2,      HFp2,      HFp2,      HFp2,
        HFp2,      HFm2,      HFm2,      HFm2,      HFm2,
        HFm2,      HFm2,      HFp3,      HFm3,      HFm3,
        HFp3,      HFp3,      HFp3,      HFp3,      HFp3,
        HFp3,      HFp3,      HFp3,      HFm3,      HFm3,
        HFm3,      HFm3,      HFm3,      HFm3 
  };

  const int  RCMate2[]  = {
   trackmid2, trackmid2,      HFp2,      HFm2,      HFm2,
     trackp2,   trackp2,   trackp2,   trackp2,   trackp2,
     trackp2,   trackm2,   trackm2,   trackm2,   trackm2,
     trackm2,   trackm2, trackmid3, trackmid3,      HFp3,
        HFm3,      HFm3,   trackp3,   trackp3,   trackp3,
     trackp3,   trackp3,   trackp3,   trackm3,   trackm3,
     trackm3,   trackm3,   trackm3,   trackm3 
  };

  static const int NumEPNames = 34;
}
#endif
