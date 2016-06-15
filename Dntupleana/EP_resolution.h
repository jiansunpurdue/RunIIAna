#ifndef EP_resolution_H
#define EP_resolution_H

//for MC default EP list, no calibration
#define NCentbin_MC 9
int centbins_MC[NCentbin_MC+1] = { 0, 5, 15, 35, 40, 50, 60, 70, 90, 100};

double EPm_resolution_v2_MC[NCentbin_MC] = { 0.784277, 0.930973, 0.932909, 0.905139, 0.868241, 0.781579, 0.632768, 0.336767, 0.084966};
double EPp_resolution_v2_MC[NCentbin_MC] = { 0.789622, 0.930651, 0.93282, 0.903751, 0.868913, 0.782272, 0.635515, 0.334797, 0.120175};
double EPm_resolution_v3_MC[NCentbin_MC] = { 0.733322, 0.780641, 0.713051, 0.612896, 0.554029, 0.453339, 0.323571, 0.14654, 99999.};
double EPp_resolution_v3_MC[NCentbin_MC] = { 0.729355, 0.776133, 0.712883, 0.633601, 0.556134, 0.430348, 0.32254, 0.16158, 99999.};

double SP_EPm_resolution_v2_MC[NCentbin_MC] = { 95.7606, 126.183, 96.865, 61.6211, 44.9339, 26.3757, 13.338, 3.96807, 0.339162};
double SP_EPp_resolution_v2_MC[NCentbin_MC] = { 96.4375, 126.475, 96.9675, 61.7006, 45.068, 26.4305, 13.3437, 3.97825, 0.498504};
double SP_EPm_resolution_v3_MC[NCentbin_MC] = { 70.7116, 67.2383, 43.7007, 25.6119, 18.8044, 10.9497, 5.43308, 1.5248, 0.0353239};
double SP_EPp_resolution_v3_MC[NCentbin_MC] = { 70.7568, 66.5684, 43.6427, 26.5294, 18.6348, 10.548, 5.36539, 1.5913, 1.00892};

//for data
#define NCentbin 6

int centbins[NCentbin+1] = { 0, 10, 30, 50, 70, 90, 100};

//for default EP list
double EPm_resolution_v1[NCentbin] = { 0.18244, 0.17418, 0.16040, 0.14045, 0.175546, 0.166938};
double EPp_resolution_v1[NCentbin] = { 0.18397, 0.17183, 0.15899, 0.13923, 0.175546, 0.166938};
double EPm_resolution_v2[NCentbin] = { 0.685727, 0.859672, 0.805478, 0.56692, 0.211365, 0.030237};
double EPp_resolution_v2[NCentbin] = { 0.68588, 0.859855, 0.805752, 0.567143, 0.210699, 0.0333565};
double EPm_resolution_v3[NCentbin] = { 0.526721, 0.493559, 0.37117, 0.182181, 0.0348828, 0.0470742};
double EPp_resolution_v3[NCentbin] = { 0.528248, 0.495846, 0.373716, 0.183726, 0.0315059, 0.0470742};
double EPm_resolution_v4[NCentbin] = { 0.33524, 0.30516, 0.21898, 0.09603, 0.0223367, 0.0575957};
double EPp_resolution_v4[NCentbin] = { 0.33135, 0.30910, 0.22230, 0.09918, 0.0223367, 0.0575957};

double SP_EPm_resolution_v2[NCentbin] = { 2.22816, 4.55138, 5.44081, 3.8803, 1.16357, 0.122025};
double SP_EPp_resolution_v2[NCentbin] = { 2.22641, 4.55193, 5.44447, 3.86791, 1.14987, 0.122898};
double SP_EPm_resolution_v3[NCentbin] = { 1.19763, 1.45449, 1.44094, 0.885659, 0.164674, 99999.};
double SP_EPp_resolution_v3[NCentbin] = { 1.19816, 1.45979, 1.44864, 0.888863, 0.164725, 99999.};

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

int Decide_centbin_for_EPresolution( int centlow, int centhigh, bool isMC = false)
{
	int icentbin = -99;

	if( !isMC )
	{
		for( int ibin = 0; ibin < NCentbin; ibin++ )
		{
			if( centlow == centbins[ibin] && centhigh == centbins[ibin+1] )
			{
				icentbin = ibin;
				break;
			}
		}
	}
	else
	{
		for( int ibin = 0; ibin < NCentbin_MC; ibin++ )
		{
			if( centlow == centbins_MC[ibin] && centhigh == centbins_MC[ibin+1] )
			{
				icentbin = ibin;
				break;
			}
		}
	}

	return icentbin;
}

#endif //  EP_resolution_H
