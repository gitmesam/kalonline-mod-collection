#include "OnSend.h"
#include "Interface.h"
#include "Hooks.h"
#include "Tools.h"

CREATE_INTERFACE(IOnSend)

unsigned long IOnSend::Patches[] =
{
    0x004022E4, 0x004023A3, 0x00413A66, 0x00413A9C, 0x00413B69, 0x00413B9C, 0x00414761, 0x004147E5, 0x004148C3, 0x00414946,
    0x004149CA, 0x0041602E, 0x0041623F, 0x00417660, 0x00417ABC, 0x00417D71, 0x00417FFB, 0x0041802F, 0x004180B0, 0x00418167,
    0x004181D9, 0x004185B2, 0x0041861F, 0x004187B5, 0x00418871, 0x0041889C, 0x004188B2, 0x00419ED4, 0x0041A128, 0x0041A42F,
    0x0043F01E, 0x0047650C, 0x004BA549, 0x0052B7F1, 0x0052F753, 0x0052F777, 0x0052F79B, 0x0052F7BF, 0x0052F7E3, 0x0052F807,
    0x0052F82B, 0x0052F84F, 0x0052F870, 0x0052F891, 0x0052F8B2, 0x0053077D, 0x005307A4, 0x005307CB, 0x005307F2, 0x00530819,
    0x00530840, 0x00530864, 0x00530888, 0x005308AC, 0x005308EA, 0x00530928, 0x005309D5, 0x005309FC, 0x00530A23, 0x00530A4A,
    0x00530A71, 0x00530A98, 0x00530ABC, 0x00530AE0, 0x00530B04, 0x00530B4D, 0x00530B93, 0x00531DBC, 0x0053377F, 0x00533DDF,
    0x005372F8, 0x00537ABA, 0x00537B03, 0x00537F69, 0x00538047, 0x00538090, 0x005384CF, 0x005388EB, 0x00539503, 0x005396D3,
    0x00539715, 0x00539954, 0x00539AF2, 0x0053A634, 0x0053A8E6, 0x0053AC6E, 0x0053ADA1, 0x0053B087, 0x0053B83D, 0x0053C6BF,
    0x0053C702, 0x0053C745, 0x0053C783, 0x0053C808, 0x0053C984, 0x0053CBFC, 0x0053CCBB, 0x0053CCFD, 0x0053DABB, 0x0053DB37,
    0x0053DBA9, 0x0053FEC3, 0x0053FF03, 0x0054185A, 0x005450D4, 0x00545379, 0x0054620B, 0x005470EB, 0x005480D5, 0x00548193,
    0x0054B102, 0x0054B20A, 0x0054B264, 0x0054DE15, 0x0054F065, 0x0054F1EB, 0x0055B573, 0x0055B8D0, 0x005605DA, 0x005611EE,
    0x00561402, 0x00561500, 0x005616C8, 0x0056394B, 0x00564195, 0x005647C0, 0x00564B11, 0x005654FD, 0x00565536, 0x0056559F,
    0x005655D6, 0x00565601, 0x0056565E, 0x005656D6, 0x005656FA, 0x00565771, 0x005657C6, 0x00565D5E, 0x00565D87, 0x00565DC9,
    0x00565DF9, 0x0056C6CB, 0x0056C717, 0x0056EA49, 0x0057164F, 0x00574477, 0x00574DEC, 0x00575852, 0x00578288, 0x00578304,
    0x005783A7, 0x0057844A, 0x0057984C, 0x0057986C, 0x0057988C, 0x005798AC, 0x005798C9, 0x00579944, 0x00579964, 0x00579999,
    0x005799CE, 0x00579E2E, 0x00579EB6, 0x00579EE2, 0x00579F3C, 0x0057A91A, 0x0057CB76, 0x0057CD4F, 0x0057CF81, 0x00580B48,
    0x00583D41, 0x00583E51, 0x00586BF5, 0x0058760E, 0x00587627, 0x005892BD, 0x005892E4, 0x0058B444, 0x0058BA62, 0x0058BB34,
    0x0058BB7C, 0x0058C5AD, 0x0058C5E6, 0x0058D106, 0x0058D692, 0x0058D8EE, 0x0058DD1C, 0x0058E14A, 0x0058EB8F, 0x0058EC63,
    0x0058F7E1, 0x00590874, 0x00591673, 0x00593223, 0x0059464C, 0x00595747, 0x00595777, 0x005957AA, 0x005957D7, 0x00595807,
    0x00595912, 0x0059594F, 0x0059599C, 0x00595A18, 0x00595FAF, 0x00595FE6, 0x00596105, 0x00596141, 0x0059617A, 0x005961B3,
    0x005961EC, 0x00596228, 0x00596261, 0x0059629A, 0x005962D6, 0x0059630F, 0x0059634A, 0x00596383, 0x00596AAC, 0x00596B76,
    0x00596BAF, 0x00596C8D, 0x00596D52, 0x00596E17, 0x00596F09, 0x0059709F, 0x005973AA, 0x00597419, 0x0059781A, 0x00597A33,
    0x00597BFB, 0x00597C8F, 0x00597EF5, 0x00597F23, 0x00597F51, 0x00597F7F, 0x00597FAD, 0x00597FDB, 0x00598009, 0x00598037,
    0x00598065, 0x00598093, 0x005980C1, 0x005980EF, 0x0059811D, 0x0059814B, 0x00598179, 0x005981F2, 0x0059821C, 0x0059826F,
    0x00598386, 0x00598431, 0x0059846D, 0x005984B3, 0x005984CF, 0x0059E634, 0x0059E694, 0x0059E6D3, 0x0059E712, 0x0059E74E,
    0x0059E78A, 0x0059EC0C, 0x0059F086, 0x005AF720, 0x005AF748, 0x005AF7E7, 0x005B0A97, 0x005B0D8E, 0x005B0DA2, 0x005B3112,
    0x005B31FC, 0x005B326C, 0x005B3EFE, 0x005B3F71, 0x005B4513, 0x005B452E, 0x005B46C3, 0x005B6C65, 0x005B7AAC, 0x005B7CEC,
    0x005B7F66, 0x005B7FA3, 0x005B8016, 0x005B8335, 0x005B88CC, 0x005B8C27, 0x005B8C9F, 0x005B9CE3, 0x005B9E9A, 0x005BAE0C,
    0x005BB64D, 0x005BD201, 0x005BD443, 0x005C1989, 0x005C1ABE, 0x005C1BF9, 0x005C1D54, 0x005C1DB4, 0x005C1E11, 0x005C1F91,
    0x005C1FC7, 0x005C2004, 0x005C203E, 0x005C2391, 0x005C24AA, 0x005C2516, 0x005C25F1, 0x005C277A, 0x005C293B, 0x005C2A81,
    0x005C2DA5, 0x005C3256, 0x005C3BFC, 0x005C3C54, 0x005C3DE3, 0x005C3ED4, 0x005C45AC, 0x005C4741, 0x005C4DB3, 0x005C5051,
    0x005C5646, 0x005C56ED, 0x005C625F, 0x005C626E, 0x005C6618, 0x005C6627, 0x005C6AA3, 0x005C6AB2, 0x005C6B67, 0x005C6B76,
    0x005C7484, 0x005D1E75, 0x005D2EB6, 0x005D3924, 0x005D51BC, 0x005D550E, 0x005D558A, 0x005D5624, 0x005D56A0, 0x005D573A,
    0x005D57B6, 0x005D5951, 0x005D5974, 0x005D5997, 0x005D6510, 0x005D67CA, 0x005DA7FE, 0x005DCDCA, 0x005E02BD, 0x005E02DC,
    0x005E0585, 0x005E0E39, 0x005E0E6B, 0x005E0ED1, 0x005E0EE9, 0x005E0F45, 0x005E0F85, 0x005E3B47, 0x005E3B80, 0x005E3BA1,
    0x005E6342, 0x005F35A6, 0x005F8F47, 0x005FAC7C, 0x005FB62A, 0x005FB850, 0x005FCB4D, 0x005FCC17, 0x005FD0E0, 0x005FD685,
    0x005FE2AC, 0x005FE71F, 0x005FE789, 0x005FECB0, 0x0060B2A5, 0x0060CA16, 0x0060CA66, 0x006107BA, 0x00610831, 0x00610ABE,
    0x00610B39, 0x00610C60, 0x00610CB8, 0x00610D4A, 0x00614754, 0x006171CD, 0x006173A6, 0x006175BC, 0x0061BBEF, 0x0061D0F1,
    0x006211EE, 0x006214B0, 0x00622653, 0x00622F9F, 0x0062325C, 0x0062651C, 0x00626E65, 0x0062728B, 0x00632AB4, 0x0063CC1E,
    0x006480C5, 0x0064ADD4, 0x0064AE88, 0x0064EC4C, 0x0064F9D7, 0x0064FA00, 0x0064FA29, 0x0064FA7E, 0x0064FB32, 0x00650610,
    0x00651CBB, 0x00651CD4, 0x00651CED, 0x00651FC8, 0x00652141, 0x00652C24, 0x00653567, 0x00653E3B, 0x00653E54, 0x00653E6D,
    0x006541A1, 0x006543C3, 0x00654851, 0x006561C6, 0x006562AA, 0x0065637C, 0x00656440, 0x00656467, 0x006564BF, 0x00657113,
    0x00667146, 0x00680A56, 0x00683048, 0x00683DEF, 0x00683E21, 0x00683E52, 0x006845BB, 0x006845EF, 0x006846B4, 0x006846E8,
    0x00684AE6, 0x00684B4F, 0x00684BB7, 0x00684C1F, 0x00684C4B, 0x006856C0, 0x00685948, 0x00685BD0, 0x00685D23, 0x00685FC2,
    0x006860F9, 0x00686180, 0x0068624C, 0x00686270, 0x00686291, 0x006862B1, 0x006862D2, 0x00686305, 0x00686339, 0x00686372,
    0x006863AA, 0x006863E3, 0x0068641C, 0x00686454, 0x0068648D, 0x00686520, 0x00686554, 0x00686587, 0x006865BB, 0x00686609,
    0x0068663D, 0x0068669D, 0x006867B3, 0x00686924, 0x006869B5, 0x00686B26, 0x00686BBA, 0x00686CB3, 0x00686DAE, 0x00686DE1,
    0x00686E15, 0x00686EDF, 0x00686F00, 0x00686F20, 0x00686F41, 0x00686F62, 0x00686F82, 0x00686FA0, 0x00686FBE, 0x00686FDB,
    0x00686FF9, 0x00687459, 0x00688495, 0x006884BE, 0x006884E7, 0x006885E8, 0x00688706, 0x00688758, 0x0068896C, 0x006889BC,
    0x006889EA, 0x00688A6D, 0x00688AB4, 0x00688C46, 0x00688CC2, 0x00688D2D, 0x006915B3, 0x006916A5, 0x006928DC, 0x006929CE,
    0x00692C21, 0x00692CAF, 0x00692CCA, 0x00692D1A, 0x00692F30, 0x006933F6, 0x00693802, 0x00693C1F, 0x00693C42, 0x00693F25,
    0x00694250, 0x006943DE, 0x00694A4D, 0x00694B06, 0x00694B17, 0x00695105, 0x00695625, 0x006956FA, 0x00697CC2, 0x0069863A,
    0x0069E3D8, 0x006A0AF6, 0x006A3AE0, 0x006A3E40, 0x006A4C6B, 0x006A4EDD, 0x006A51CB, 0x006B0A11, 0x006B15D3, 0x006B165D,
    0x006B16E7, 0x006B1724, 0x006B17E5, 0x006B195B, 0x006B1E08, 0x006B2676, 0x006B28C7, 0x006B29E3, 0x006B3B3D, 0x006B3D79,
    0x006B6614, 0x006B8920, 0x006BC642, 0x006BC655, 0x006BC668, 0x00700354, 0x00700434, 0x007027D3, 0x0070299F, 0x007046B5,
    0x00705267, 0x00705322, 0x00705B33, 0x00705B5B, 0x00730C44, 0x00731449, 0x00749A64, 0x00795CD2, 0x00552F3E, 0x00553030,
    0x005532B0, 0x0055345F, 0x00553491, 0x005534DF, 0x00553511, 0x005536AA, 0x00557880, 0x005578A1, 0x005578C2, 0x005578E3,
    0x00557901, 0x0055791F, 0x0055793D, 0x0055795B, 0x0055799F, 0x005579C0, 0x005579E1, 0x00557A02, 0x00557A20, 0x00557A3E,
    0x00557A5C, 0x00557A7A, 0x00557ABE, 0x00557ADF, 0x00557B00, 0x00557B21, 0x00557B3F, 0x00557B5D, 0x00557B7B, 0x00557B99,
    0x00557BDD, 0x00557BFE, 0x00557C1F, 0x00557C40, 0x00557C5E, 0x00557C7C, 0x00557C9A, 0x00557CB8, 0x00557CFC, 0x00557D1D,
    0x00557D3E, 0x00557D5F, 0x00557D7D, 0x00557D9B, 0x00557DB9, 0x00557DD7, 0x00557E1B, 0x00557E3C, 0x00557E5A, 0x00557E78,
    0x00557E96, 0x00557EB4, 0x00557EEB, 0x00557F22, 0x00569847, 0x0059756D, 0x005975B9, 0x005C1E6C, 0x005C20A0, 0x005E7E5D,
    0x005EBCC2, 0x005ECD92, 0x005ECE47, 0x00683075, 0x006830A2, 0x006830CF, 0x006830FC, 0x00683129, 0x00683156, 0x00683183,
    0x006831B0, 0x006831DD, 0x0068320A, 0x00683237, 0x00683264, 0x00683291, 0x006832BE, 0x006832EB, 0x00683318, 0x00683345,
    0x00683372, 0x0068339F, 0x006833CC, 0x006833F9, 0x0068496D, 0x00684A18, 0x00684A49, 0x00698305, 0x0069AC58, 0x0069B39C,
    0x0069B418, 0x00700465, 0x00700490, 0x007004BD, 0x007004EA, 0x00700515, 0x00700542
};

void IOnSend::Hook()
{
    Interface<ITools> Tools;

    for(size_t i=0; i < sizeof this->Patches / sizeof(unsigned long); i++)
        Tools->Intercept(ITools::_I_CALL, (void*)IOnSend::Patches[i], Hooks::KSocket::WritePacketAutoCrc, 5);
}