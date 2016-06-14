#ifndef EP_resolution_H
#define EP_resolution_H

#define NCentbin 6

int centbins[NCentbin+1] = { 0, 10, 30, 50, 70, 90, 100};

//for default EP list
double EPm_resolution_v1[NCentbin] = { 0.18244, 0.17418, 0.16040, 0.14045, 0.175546, 0.166938};
double EPp_resolution_v1[NCentbin] = { 0.18397, 0.17183, 0.15899, 0.13923, 0.175546, 0.166938};
double EPm_resolution_v2[NCentbin] = { 0.685723, 0.859663, 0.805454, 0.566906, 0.211415, 0.0300765};
double EPp_resolution_v2[NCentbin] = { 0.685867, 0.859828, 0.805742, 0.567145, 0.210669, 0.0331533};
double EPm_resolution_v3[NCentbin] = { 0.526697, 0.493556, 0.371157, 0.182179, 0.0344609, 0.0470742};
double EPp_resolution_v3[NCentbin] = { 0.528234, 0.495824, 0.373692, 0.183663, 0.0314355, 0.0470742};
double EPm_resolution_v4[NCentbin] = { 0.33524, 0.30516, 0.21898, 0.09603, 0.0223367, 0.0575957};
double EPp_resolution_v4[NCentbin] = { 0.33135, 0.30910, 0.22230, 0.09918, 0.0223367, 0.0575957};

double SP_EPm_resolution_v2[NCentbin] = { 2.22815, 4.55128, 5.44069, 3.88015, 1.16372, 0.121632};
double SP_EPp_resolution_v2[NCentbin] = { 2.22631, 4.55176, 5.44434, 3.86785, 1.1498, 0.122138};
double SP_EPm_resolution_v3[NCentbin] = { 1.1976, 1.45446, 1.44092, 0.885596, 0.163693, 99999.};
double SP_EPp_resolution_v3[NCentbin] = { 1.19813, 1.45973, 1.44858, 0.888648, 0.164866, 99999.};

//for v2, v3 eta gap study EP list

//from steve for default EP list
//double EPm_resolution_v1[NCentbin] = { 0.18244, 0.17418, 0.16040, 0.14045, 0.175546, 0.166938};
//double EPp_resolution_v1[NCentbin] = { 0.18397, 0.17183, 0.15899, 0.13923, 0.175546, 0.166938};
//double EPm_resolution_v2[NCentbin] = { 0.68322, 0.85910, 0.80485, 0.56705, 0.219526, 0.0282894};
//double EPp_resolution_v2[NCentbin] = { 0.68719, 0.86025, 0.80644, 0.56821, 0.219526, 0.0282894};
//double EPm_resolution_v3[NCentbin] = { 0.52818, 0.49360, 0.36989, 0.18616, 0.0320431, 0.0470742};
//double EPp_resolution_v3[NCentbin] = { 0.52724, 0.49611, 0.37458, 0.18412, 0.0320431, 0.0470742};
//double EPm_resolution_v4[NCentbin] = { 0.33524, 0.30516, 0.21898, 0.09603, 0.0223367, 0.0575957};
//double EPp_resolution_v4[NCentbin] = { 0.33135, 0.30910, 0.22230, 0.09918, 0.0223367, 0.0575957};
//private calculation
//double EP_resolution_v1[NCentbin] = { 0.137765, 0.172671, 0.190468, 0.187673, 0.175546, 0.166938};
//double EP_resolution_v2[NCentbin] = { 0.677732, 0.856505, 0.807603, 0.574763, 0.219526, 0.0282894};
//double EP_resolution_v3[NCentbin] = { 0.517663, 0.491202, 0.37364, 0.186168, 0.0320431, 0.0470742};
//double EP_resolution_v4[NCentbin] = { 0.321251, 0.298758, 0.216105, 0.0942812, 0.0223367, 0.0575957};

int Decide_centbin_for_EPresolution( int centlow, int centhigh )
{
	int icentbin = -99;

	for( int ibin = 0; ibin < NCentbin; ibin++ )
	{
		if( centlow == centbins[ibin] && centhigh == centbins[ibin+1] )
		{
			icentbin = ibin;
			break;
		}
	}

	return icentbin;
}

#endif //  EP_resolution_H
