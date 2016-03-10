#define NCentbin 6

int centbins[NCentbin+1] = { 0, 10, 30, 50, 70, 90, 100};
double EPm_resolution_v1[NCentbin] = { 0.18244, 0.17418, 0.16040, 0.14045, 0.175546, 0.166938};
double EPp_resolution_v1[NCentbin] = { 0.18397, 0.17183, 0.15899, 0.13923, 0.175546, 0.166938};
double EPm_resolution_v2[NCentbin] = { 0.68322, 0.85910, 0.80485, 0.56705, 0.219526, 0.0282894};
double EPp_resolution_v2[NCentbin] = { 0.68719, 0.86025, 0.80644, 0.56821, 0.219526, 0.0282894};
double EPm_resolution_v3[NCentbin] = { 0.52818, 0.49360, 0.36989, 0.18616, 0.0320431, 0.0470742};
double EPp_resolution_v3[NCentbin] = { 0.52724, 0.49611, 0.37458, 0.18412, 0.0320431, 0.0470742};
double EPm_resolution_v4[NCentbin] = { 0.33524, 0.30516, 0.21898, 0.09603, 0.0223367, 0.0575957};
double EPp_resolution_v4[NCentbin] = { 0.33135, 0.30910, 0.22230, 0.09918, 0.0223367, 0.0575957};

double SP_EPm_resolution_v2[NCentbin] = { 60.2798, 68.9037, 37.2794, 11.199, 1.5478, 0.0676852};
double SP_EPp_resolution_v2[NCentbin] = { 59.0384, 68.7826, 37.3237, 11.2098, 1.54055, 0.0706194};
double SP_EPm_resolution_v3[NCentbin] = { 33.8804, 23.1012, 10.0544, 2.63191, 0.2058, 0.16317};
double SP_EPp_resolution_v3[NCentbin] = { 32.2514, 22.6223, 9.95982, 2.61081, 0.265497, 0.0343396};

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
