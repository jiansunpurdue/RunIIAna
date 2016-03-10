#include "anaDntuple.cc"

//decaychannel 2 is D0

void run_anaDntuple(int startFile = 0, int endFile = 1, string filelist = "test_pp.lis", bool isPbPb = false)
{
    anaDntuple *a = new anaDntuple;

    a->LoopOverFile(startFile, endFile, filelist, isPbPb);

    delete a; 
}
