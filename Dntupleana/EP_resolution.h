#ifndef EP_resolution_H
#define EP_resolution_H
#include <array>

//for MC default EP list, no calibration
//#define NCentbin_MC 9
//int centbins_MC[NCentbin_MC+1] = { 0, 5, 15, 35, 40, 50, 60, 70, 90, 100};
//
//double EPm_resolution_v2_MC[NCentbin_MC] = { 0.784277, 0.930973, 0.932909, 0.905139, 0.868241, 0.781579, 0.632768, 0.336767, 0.084966};
//double EPp_resolution_v2_MC[NCentbin_MC] = { 0.789622, 0.930651, 0.93282, 0.903751, 0.868913, 0.782272, 0.635515, 0.334797, 0.120175};
//double EPm_resolution_v3_MC[NCentbin_MC] = { 0.733322, 0.780641, 0.713051, 0.612896, 0.554029, 0.453339, 0.323571, 0.14654, 99999.};
//double EPp_resolution_v3_MC[NCentbin_MC] = { 0.729355, 0.776133, 0.712883, 0.633601, 0.556134, 0.430348, 0.32254, 0.16158, 99999.};
//
//double SP_EPm_resolution_v2_MC[NCentbin_MC] = { 95.7606, 126.183, 96.865, 61.6211, 44.9339, 26.3757, 13.338, 3.96807, 0.339162};
//double SP_EPp_resolution_v2_MC[NCentbin_MC] = { 96.4375, 126.475, 96.9675, 61.7006, 45.068, 26.4305, 13.3437, 3.97825, 0.498504};
//double SP_EPm_resolution_v3_MC[NCentbin_MC] = { 70.7116, 67.2383, 43.7007, 25.6119, 18.8044, 10.9497, 5.43308, 1.5248, 0.0353239};
//double SP_EPp_resolution_v3_MC[NCentbin_MC] = { 70.7568, 66.5684, 43.6427, 26.5294, 18.6348, 10.548, 5.36539, 1.5913, 1.00892};

#define NCentbin_MC 6
int centbins_MC[NCentbin_MC+1] = { 0, 5, 20, 40, 60, 80, 100};

//pthatweight
double EPm_resolution_v2_MC[NCentbin_MC] = { 0.780564, 0.935042, 0.927511, 0.840199, 0.592185, 0.24612};
double EPp_resolution_v2_MC[NCentbin_MC] = { 0.792049, 0.935415, 0.926704, 0.844018, 0.592548, 0.251614};
double EPm_resolution_v3_MC[NCentbin_MC] = { 0.729103, 0.77431, 0.686449, 0.523215, 0.291367, 0.0955829};
double EPp_resolution_v3_MC[NCentbin_MC] = { 0.733793, 0.767867, 0.68886, 0.508867, 0.296772, 0.123554};

double SP_EPm_resolution_v2_MC[NCentbin_MC] = { 95.4735, 122.887, 83.6028, 37.3283, 10.7024, 1.71673};
double SP_EPp_resolution_v2_MC[NCentbin_MC] = { 95.9358, 123.001, 83.9414, 37.5968, 10.673, 1.71067};
double SP_EPm_resolution_v3_MC[NCentbin_MC] = { 70.4551, 63.2733, 36.9853, 15.704, 4.34821, 0.603327};
double SP_EPp_resolution_v3_MC[NCentbin_MC] = { 71.055, 62.5361, 36.5589, 15.3159, 4.25297, 0.678117};

////no pthatweight
//double EPm_resolution_v2_MC[NCentbin_MC] = { 0.784277, 0.934235, 0.923994, 0.825564, 0.528754, 0.203334};
//double EPp_resolution_v2_MC[NCentbin_MC] = { 0.789622, 0.933644, 0.923848, 0.826244, 0.529531, 0.205695};
//double EPm_resolution_v3_MC[NCentbin_MC] = { 0.733322, 0.771342, 0.67854, 0.505453, 0.259086, 0.0766994};
//double EPp_resolution_v3_MC[NCentbin_MC] = { 0.729355, 0.768982, 0.682528, 0.496532, 0.264215, 0.0970609};
//
//double SP_EPm_resolution_v2_MC[NCentbin_MC] = { 95.7606, 122.843, 83.4118, 36.7421, 9.85876, 1.47601};
//double SP_EPp_resolution_v2_MC[NCentbin_MC] = { 96.4375, 123.022, 83.5666, 36.843, 9.85664, 1.54997};
//double SP_EPm_resolution_v3_MC[NCentbin_MC] = { 70.7116, 63.1424, 36.5976, 15.3428, 3.98462, 0.496936};
//double SP_EPp_resolution_v3_MC[NCentbin_MC] = { 70.7568, 62.7981, 36.5228, 15.098, 3.96212, 0.622147};

//for data
#define NCentbin 6

int centbins[NCentbin+1] = { 0, 10, 30, 50, 70, 90, 100};

////golden data, D candidate Q vector recenter
double v2_meancosnphi[NCentbin] = { 0.00239109, 0.00428512, 0.00112981, 0.0128266, 0., 0.};
double v2_meansinnphi[NCentbin] = { 0.00294925, 0.00937768, 0.01653460, 0.0214646, 0., 0.};
double v3_meancosnphi[NCentbin] = { 0.00839557, 0.00429976, -0.0001893, -0.002187, 0., 0.};
double v3_meansinnphi[NCentbin] = { -0.0171459, -0.0159969, -0.0157925, -0.023782, 0., 0.};

////tracker+barrel data, D candidate Q vector recenter
//double v2_meancosnphi[NCentbin] = {  0.0075231, 0.00865529, 0.0120846, 0.0190262, 0., 0.};
//double v2_meansinnphi[NCentbin] = {  0.0093781, 0.01554140, 0.0189508, 0.0236537, 0., 0.};
//double v3_meancosnphi[NCentbin] = {  0.0106649, 0.00713216, 0.0120853, -0.001336, 0., 0.};
//double v3_meansinnphi[NCentbin] = {  -0.019160, -0.0184749, 0.0189516, -0.010818, 0., 0.};

//for default EP list
//errors are wrong
double EPm_resolution_v1[NCentbin] = { 0.18244, 0.17418, 0.16040, 0.14045, 0.175546, 0.166938};
double EPp_resolution_v1[NCentbin] = { 0.18397, 0.17183, 0.15899, 0.13923, 0.175546, 0.166938};
double EPm_resolution_v2[NCentbin] = { 0.685727, 0.859672, 0.805478, 0.56692, 0.211365, 0.030237};
double EPp_resolution_v2[NCentbin] = { 0.68588, 0.859855, 0.805752, 0.567143, 0.210699, 0.0333565};
double EPm_resolution_v3[NCentbin] = { 0.526721, 0.493559, 0.37117, 0.182181, 0.0348828, 0.0470742};
double EPp_resolution_v3[NCentbin] = { 0.528248, 0.495846, 0.373716, 0.183726, 0.0315059, 0.0470742};
double EPm_resolution_v4[NCentbin] = { 0.33524, 0.30516, 0.21898, 0.09603, 0.0223367, 0.0575957};
double EPp_resolution_v4[NCentbin] = { 0.33135, 0.30910, 0.22230, 0.09918, 0.0223367, 0.0575957};

double error_EPm_resolution_v2[NCentbin] = { 0.000179207, 6.76151e-05, 8.661e-05, 0.000163775, 0.000425099, 0.00310912};
double error_EPp_resolution_v2[NCentbin] = { 0.000179247, 6.76295e-05, 8.66394e-05, 0.00016384, 0.00042376, 0.00342988};
double error_EPm_resolution_v3[NCentbin] = { 0.000229879, 0.000172564, 0.000231558, 0.000458358, 0.00285484, 99999.};
double error_EPp_resolution_v3[NCentbin] = { 0.000230545, 0.000173364, 0.000233146, 0.000462246, 0.00257847, 99999.};

double SP_EPm_resolution_v2[NCentbin] = { 2.22816, 4.55138, 5.44081, 3.8803, 1.16357, 0.122025};
double SP_EPp_resolution_v2[NCentbin] = { 2.22641, 4.55193, 5.44447, 3.86791, 1.14987, 0.122898};
double SP_EPm_resolution_v3[NCentbin] = { 1.19763, 1.45449, 1.44094, 0.885659, 0.164674, 99999.};
double SP_EPp_resolution_v3[NCentbin] = { 1.19816, 1.45979, 1.44864, 0.888863, 0.164725, 99999.};

double error_SP_EPm_resolution_v2[NCentbin] = { 0.000644391, 0.000586142, 0.000810683, 0.00108307, 0.00167915, 0.00865894};
double error_SP_EPp_resolution_v2[NCentbin] = { 0.000643886, 0.000586213, 0.000811228, 0.00107961, 0.00165938, 0.00872088};
double error_SP_EPm_resolution_v3[NCentbin] = { 0.00048173, 0.000459859, 0.000760835, 0.00176677, 0.00875007, 99999.};
double error_SP_EPp_resolution_v3[NCentbin] = { 0.00048194, 0.000461537, 0.000764897, 0.00177316, 0.00875278, 99999.};

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

//for v2, v3 eta gap study EP list
//default, a, b, c, d, e, f
//errors are wrong
typedef std::array<double, NCentbin> Row;

std::array<Row, 7> EPm_resolution_v2_etagap;
std::array<Row, 7> EPp_resolution_v2_etagap;
std::array<Row, 7> EPm_resolution_v3_etagap;
std::array<Row, 7> EPp_resolution_v3_etagap;

std::array<Row, 7> error_EPm_resolution_v2_etagap;
std::array<Row, 7> error_EPp_resolution_v2_etagap;
std::array<Row, 7> error_EPm_resolution_v3_etagap;
std::array<Row, 7> error_EPp_resolution_v3_etagap;

std::array<Row, 7> SP_EPm_resolution_v2_etagap;
std::array<Row, 7> SP_EPp_resolution_v2_etagap;
std::array<Row, 7> SP_EPm_resolution_v3_etagap;
std::array<Row, 7> SP_EPp_resolution_v3_etagap;

std::array<Row, 7> error_SP_EPm_resolution_v2_etagap;
std::array<Row, 7> error_SP_EPp_resolution_v2_etagap;
std::array<Row, 7> error_SP_EPm_resolution_v3_etagap;
std::array<Row, 7> error_SP_EPp_resolution_v3_etagap;

void Initiate_EPSPresolution()
{
	EPm_resolution_v2_etagap[0] = { 0.685817, 0.859628, 0.805405, 0.56675, 0.211166, 0.0369004};
	EPp_resolution_v2_etagap[0] = { 0.686144, 0.859858, 0.805753, 0.567144, 0.210872, 0.0412922};
	EPm_resolution_v3_etagap[0] = { 0.52681, 0.493418, 0.371146, 0.182531, 0.0395432, 0.0074026};
	EPp_resolution_v3_etagap[0] = { 0.528266, 0.495583, 0.373695, 0.183742, 0.0354822, 0.0431808};

	SP_EPm_resolution_v2_etagap[0] = { 2.20396, 4.49691, 5.35371, 3.84252, 1.15754, 0.143096};
	SP_EPp_resolution_v2_etagap[0] = { 2.23117, 4.55791, 5.42984, 3.88098, 1.163, 0.148767};
	SP_EPm_resolution_v3_etagap[0] = { 1.18413, 1.43716, 1.41791, 0.877962, 0.179012, 0.0589739};
	SP_EPp_resolution_v3_etagap[0] = { 1.20041, 1.46178, 1.44465, 0.89159, 0.179256, 0.05101};

	error_EPm_resolution_v2_etagap[0] = { 0.000179193, 6.76088e-05, 8.66034e-05, 0.000163765, 0.000425169, 0.0031662};
	error_EPp_resolution_v2_etagap[0] = { 0.000179236, 6.76231e-05, 8.66325e-05, 0.000163828, 0.000423793, 0.00338732};
	error_EPm_resolution_v3_etagap[0] = { 0.000229861, 0.000172555, 0.000231543, 0.000458353, 0.00286344, 99999.};
	error_EPp_resolution_v3_etagap[0] = { 0.000230528, 0.000173358, 0.000233132, 0.000462204, 0.00261119, 99999.};

	error_SP_EPm_resolution_v2_etagap[0] = { 0.00063836, 0.000579849, 0.000799227, 0.00107445, 0.00167472, 0.00861163};
	error_SP_EPp_resolution_v2_etagap[0] = { 0.00064355, 0.000585072, 0.000806984, 0.00108054, 0.00166965, 0.00876173};
	error_SP_EPm_resolution_v3_etagap[0] = { 0.000477186, 0.000455253, 0.000750627, 0.00175877, 0.00872709, 99999.};
	error_SP_EPp_resolution_v3_etagap[0] = { 0.000481656, 0.000460977, 0.000761435, 0.00178082, 0.00879026, 99999.};

	EPm_resolution_v2_etagap[1] = { 0.752928, 0.90275, 0.855692, 0.629593, 0.250879, 0.0456747};
	EPp_resolution_v2_etagap[1] = { 0.753489, 0.903203, 0.856267, 0.630851, 0.251664, 0.0468623};
	EPm_resolution_v3_etagap[1] = { 0.613028, 0.584003, 0.45118, 0.223006, 0.0362468, 99999.};
	EPp_resolution_v3_etagap[1] = { 0.615076, 0.586947, 0.454671, 0.225106, 0.0337564, 99999.};

	SP_EPm_resolution_v2_etagap[1] = { 3.53874, 7.71875, 9.69137, 6.32682, 1.71158, 0.232112};
	SP_EPp_resolution_v2_etagap[1] = { 3.56678, 7.76379, 9.83035, 6.39338, 1.71385, 0.231368};
	SP_EPm_resolution_v3_etagap[1] = { 1.90122, 2.47866, 2.61671, 1.47807, 0.189433, 99999.};
	SP_EPp_resolution_v3_etagap[1] = { 1.91991, 2.50149, 2.6662, 1.50386, 0.195817, 99999.};

	error_EPm_resolution_v2_etagap[1] = { 0.000180907, 6.48609e-05, 8.4757e-05, 0.000167868, 0.000449565, 0.00334299};
	error_EPp_resolution_v2_etagap[1] = { 0.000180967, 6.48633e-05, 8.47767e-05, 0.000167995, 0.000448848, 0.00365318};
	error_EPm_resolution_v3_etagap[1] = { 0.000237577, 0.000179356, 0.000244302, 0.000484264, 0.00287134, 99999.};
	error_EPp_resolution_v3_etagap[1] = { 0.000238368, 0.000180291, 0.000246185, 0.000488746, 0.00265008, 99999.};

	error_SP_EPm_resolution_v2_etagap[1] = { 0.000984398, 0.000970546, 0.00139983, 0.00168068, 0.00219066, 0.0106849};
	error_SP_EPp_resolution_v2_etagap[1] = { 0.00099187, 0.000975911, 0.0014193, 0.00169807, 0.00218738, 0.0109904};
	error_SP_EPm_resolution_v3_etagap[1] = { 0.000703306, 0.000710264, 0.00120746, 0.00249106, 0.0101573, 99999.};
	error_SP_EPp_resolution_v3_etagap[1] = { 0.000710048, 0.000716649, 0.00123029, 0.00253082, 0.0102935, 99999.};

	EPm_resolution_v2_etagap[2] = { 0.730797, 0.889758, 0.842167, 0.608908, 0.235046, 0.0379066};
	EPp_resolution_v2_etagap[2] = { 0.73127, 0.889984, 0.842535, 0.609434, 0.234443, 0.0385502};
	EPm_resolution_v3_etagap[2] = { 0.585991, 0.554971, 0.427818, 0.20984, 0.0357679, 99999.};
	EPp_resolution_v3_etagap[2] = { 0.587825, 0.557392, 0.43095, 0.211805, 0.0344749, 99999.};

	SP_EPm_resolution_v2_etagap[2] = { 2.77033, 5.8007, 7.36411, 5.15729, 1.45234, 0.175914};
	SP_EPp_resolution_v2_etagap[2] = { 2.79012, 5.8407, 7.45671, 5.1969, 1.44851, 0.174839};
	SP_EPm_resolution_v3_etagap[2] = { 1.49955, 1.86976, 1.9805, 1.1997, 0.18919, 99999.};
	SP_EPp_resolution_v3_etagap[2] = { 1.51286, 1.88965, 2.01573, 1.21805, 0.194852, 99999.};

	error_EPm_resolution_v2_etagap[2] = { 0.000180312, 6.56724e-05, 8.524e-05, 0.00016647, 0.000439344, 0.00323384};
	error_EPp_resolution_v2_etagap[2] = { 0.000180369, 6.56859e-05, 8.52668e-05, 0.000166556, 0.000437966, 0.00361784};
	error_EPm_resolution_v3_etagap[2] = { 0.000235076, 0.000177101, 0.000240443, 0.0004756, 0.00285673, 99999.};
	error_EPp_resolution_v3_etagap[2] = { 0.000235814, 0.000177967, 0.000242224, 0.0004799, 0.00265821, 99999.};

	error_SP_EPm_resolution_v2_etagap[2] = { 0.000779216, 0.000732979, 0.00106947, 0.00138803, 0.00193844, 0.00949561};
	error_SP_EPp_resolution_v2_etagap[2] = { 0.000784629, 0.000737984, 0.0010827, 0.00139883, 0.00193236, 0.00980332};
	error_SP_EPm_resolution_v3_etagap[2] = { 0.000567887, 0.000550704, 0.000949124, 0.00213301, 0.00951771, 99999.};
	error_SP_EPp_resolution_v3_etagap[2] = { 0.00057288, 0.000556742, 0.000966247, 0.00216401, 0.00964096, 99999.};

	EPm_resolution_v2_etagap[3] = { 0.685732, 0.859684, 0.805492, 0.56693, 0.211378, 0.0307577};
	EPp_resolution_v2_etagap[3] = { 0.685895, 0.859866, 0.805762, 0.567147, 0.210694, 0.0329058};
	EPm_resolution_v3_etagap[3] = { 0.526727, 0.493562, 0.371182, 0.182194, 0.0346885, 99999.};
	EPp_resolution_v3_etagap[3] = { 0.528257, 0.495857, 0.373729, 0.183724, 0.0316327, 99999.};

	SP_EPm_resolution_v2_etagap[3] = { 2.20732, 4.50646, 5.36544, 3.85047, 1.16114, 0.121428};
	SP_EPp_resolution_v2_etagap[3] = { 2.22527, 4.54705, 5.41751, 3.87233, 1.15763, 0.123545};
	SP_EPm_resolution_v3_etagap[3] = { 1.1864, 1.44074, 1.42084, 0.878359, 0.164648, 99999.};
	SP_EPp_resolution_v3_etagap[3] = { 1.19751, 1.45886, 1.4413, 0.889368, 0.16584, 99999.};

	error_EPm_resolution_v2_etagap[3] = { 0.000179193, 6.76088e-05, 8.66034e-05, 0.000163765, 0.000425169, 0.0031662};
	error_EPp_resolution_v2_etagap[3] = { 0.000179236, 6.76231e-05, 8.66325e-05, 0.000163828, 0.000423793, 0.00338732};
	error_EPm_resolution_v3_etagap[3] = { 0.000229861, 0.000172555, 0.000231543, 0.000458353, 0.00286344, 99999.};
	error_EPp_resolution_v3_etagap[3] = { 0.000230528, 0.000173358, 0.000233132, 0.000462204, 0.00261119, 99999.};

	error_SP_EPm_resolution_v2_etagap[3] = { 0.00063836, 0.000579849, 0.000799227, 0.00107445, 0.00167472, 0.00861163};
	error_SP_EPp_resolution_v2_etagap[3] = { 0.00064355, 0.000585072, 0.000806984, 0.00108054, 0.00166965, 0.00876173};
	error_SP_EPm_resolution_v3_etagap[3] = { 0.000477186, 0.000455253, 0.000750627, 0.00175877, 0.00872709, 99999.};
	error_SP_EPp_resolution_v3_etagap[3] = { 0.000481656, 0.000460977, 0.000761435, 0.00178082, 0.00879026, 99999.};

	EPm_resolution_v2_etagap[4] = { 0.659543, 0.841398, 0.784147, 0.540073, 0.194847, 0.0218091};
	EPp_resolution_v2_etagap[4] = { 0.658225, 0.840563, 0.782983, 0.538682, 0.193499, 0.0260295};
	EPm_resolution_v3_etagap[4] = { 0.495953, 0.463159, 0.344591, 0.167976, 0.0354899, 99999.};
	EPp_resolution_v3_etagap[4] = { 0.495267, 0.463115, 0.345362, 0.168532, 0.0332784, 99999.};

	SP_EPm_resolution_v2_etagap[4] = { 1.42867, 2.92667, 3.52864, 2.65292, 0.820658, 0.0779545};
	SP_EPp_resolution_v2_etagap[4] = { 1.44035, 2.95554, 3.56831, 2.66648, 0.815939, 0.0835593};
	SP_EPm_resolution_v3_etagap[4] = { 0.75986, 0.922824, 0.919573, 0.596397, 0.118233, 99999.};
	SP_EPp_resolution_v3_etagap[4] = { 0.766501, 0.934496, 0.934474, 0.602894, 0.131535, 99999.};

	error_EPm_resolution_v2_etagap[4] = { 0.000178584, 6.87812e-05, 8.73996e-05, 0.000162124, 0.000415803, 0.00412248};
	error_EPp_resolution_v2_etagap[4] = { 0.000178576, 6.88528e-05, 8.74847e-05, 0.000162081, 0.000414086, 0.00349713};
	error_EPm_resolution_v3_etagap[4] = { 0.000227352, 0.000170492, 0.00022778, 0.000450488, 0.00292932, 99999.};
	error_EPp_resolution_v3_etagap[4] = { 0.000227808, 0.000171098, 0.000229024, 0.00045367, 0.00266446, 99999.};

	error_SP_EPm_resolution_v2_etagap[4] = { 0.000420675, 0.000381583, 0.00053389, 0.000761767, 0.00125601, 0.00702068};
	error_SP_EPp_resolution_v2_etagap[4] = { 0.000424592, 0.000385729, 0.000540514, 0.000767126, 0.00125481, 0.00665779};
	error_SP_EPm_resolution_v3_etagap[4] = { 0.00031702, 0.000304098, 0.000515126, 0.00128998, 0.00669404, 99999.};
	error_SP_EPp_resolution_v3_etagap[4] = { 0.000320645, 0.000308854, 0.000525068, 0.00131095, 0.00680245, 99999.};

	EPm_resolution_v2_etagap[5] = { 0.597093, 0.791815, 0.725799, 0.472507, 0.15888, 0.0061824};
	EPp_resolution_v2_etagap[5] = { 0.594871, 0.789879, 0.723551, 0.47013, 0.158007, 0.0195695};
	EPm_resolution_v3_etagap[5] = { 0.419687, 0.388673, 0.281144, 0.133445, 0.0300178, 99999.};
	EPp_resolution_v3_etagap[5] = { 0.417539, 0.387508, 0.281177, 0.133183, 0.0274541, 99999.};

	SP_EPm_resolution_v2_etagap[5] = { 0.68116, 1.40325, 1.69172, 1.29743, 0.412675, 0.0316884};
	SP_EPp_resolution_v2_etagap[5] = { 0.698776, 1.44154, 1.74274, 1.32917, 0.416875, 0.0392905};
	SP_EPm_resolution_v3_etagap[5] = { 0.351248, 0.426398, 0.423426, 0.2807, 0.0627105, 99999.};
	SP_EPp_resolution_v3_etagap[5] = { 0.360521, 0.439514, 0.438519, 0.289291, 0.0688332, 99999.};

	error_EPm_resolution_v2_etagap[5] = { 0.000177235, 7.19792e-05, 8.96026e-05, 0.000158328, 0.000397764, 0.00922549};
	error_EPp_resolution_v2_etagap[5] = { 0.000177218, 7.21304e-05, 8.97176e-05, 0.000158253, 0.000396375, 0.00282463};
	error_EPm_resolution_v3_etagap[5] = { 0.000221692, 0.000165893, 0.000219694, 0.000432644, 0.00278735, 99999.};
	error_EPp_resolution_v3_etagap[5] = { 0.000222008, 0.000166386, 0.000220666, 0.000435596, 0.00255551, 99999.};

	error_SP_EPm_resolution_v2_etagap[5] = { 0.000210899, 0.000190443, 0.000268995, 0.000406323, 0.000742514, 0.00501956};
	error_SP_EPp_resolution_v2_etagap[5] = { 0.000216817, 0.000196053, 0.000277756, 0.000417799, 0.000755149, 0.00413923};
	error_SP_EPm_resolution_v3_etagap[5] = { 0.000163682, 0.000159146, 0.000279729, 0.00074872, 0.00411803, 99999.};
	error_SP_EPp_resolution_v3_etagap[5] = { 0.000168947, 0.000164912, 0.000291328, 0.000777341, 0.00417328, 99999.};

	EPm_resolution_v2_etagap[6] = { 0.469561, 0.667235, 0.592241, 0.351661, 0.10756, 99999.};
	EPp_resolution_v2_etagap[6] = { 0.464016, 0.660606, 0.587015, 0.347536, 0.106386, 0.00519707};
	EPm_resolution_v3_etagap[6] = { 0.287427, 0.264383, 0.183981, 0.083509, 0.0191191, 99999.};
	EPp_resolution_v3_etagap[6] = { 0.282956, 0.259977, 0.182512, 0.0833685, 0.0180529, 99999.};

	SP_EPm_resolution_v2_etagap[6] = { 0.170227, 0.352775, 0.423568, 0.327732, 0.107442, 0.0081098};
	SP_EPp_resolution_v2_etagap[6] = { 0.169114, 0.350769, 0.423772, 0.326192, 0.105019, 0.00967511};
	SP_EPm_resolution_v3_etagap[6] = { 0.0835907, 0.101324, 0.0996704, 0.0663104, 0.017361, 99999.};
	SP_EPp_resolution_v3_etagap[6] = { 0.0831039, 0.100908, 0.100242, 0.0663349, 0.0163131, 99999.};

	error_EPm_resolution_v2_etagap[6] = { 0.00017497, 7.94783e-05, 9.43336e-05, 0.000152673, 0.000377838, 99999.};
	error_EPp_resolution_v2_etagap[6] = { 0.000174922, 7.98695e-05, 9.45288e-05, 0.000152553, 0.000376055, 0.0051668};
	error_EPm_resolution_v3_etagap[6] = { 0.00021387, 0.000159778, 0.000209977, 0.000413957, 0.00291551, 99999.};
	error_EPp_resolution_v3_etagap[6] = { 0.000214055, 0.000160101, 0.000210816, 0.000416352, 0.00242704, 99999.};

	error_SP_EPm_resolution_v2_etagap[6] = { 6.07715e-05, 5.40176e-05, 7.77674e-05, 0.000128433, 0.000273414, 0.0018988};
	error_SP_EPp_resolution_v2_etagap[6] = { 6.08789e-05, 5.41565e-05, 7.83628e-05, 0.000128867, 0.000269047, 0.00152962};
	error_SP_EPm_resolution_v3_etagap[6] = { 5.21382e-05, 5.16902e-05, 9.59026e-05, 0.000276103, 0.00165244, 99999.};
	error_SP_EPp_resolution_v3_etagap[6] = { 5.26447e-05, 5.24408e-05, 9.784e-05, 0.000279835, 0.0015265, 99999.};
}

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
