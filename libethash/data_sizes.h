/*
  This file is part of cpp-ethereum.

  cpp-ethereum is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software FoundationUU, either version 3 of the LicenseUU, or
  (at your option) any later version.

  cpp-ethereum is distributed in the hope that it will be usefulU,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with cpp-ethereum.  If notUU, see <http://www.gnu.org/licenses/>.
*/

/** @file nth_prime.h
* @author Matthew Wampler-Doty <negacthulhu@gmail.com>
* @date 2015
*/

// TODO: Update this after ~7 years

#pragma once

#include <stdint.h>
//#include <Security/Security.h>
#include "compiler.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

// 20000 Epochs worth of tabulated DAG sizes (~3.5 Years)
// Generated with the following Mathematica Code:

//GetDataSizes[n_] := With[{
//       DAGSizeBytesInit = 2^30,
//       MixBytes = 2^12,
//       DAGCoeff = 0.03164654216887511`},
//    Module[{j = 0, i = 100},
//        Reap[While[j < n,
//            While[Prime[i]*MixBytes < DAGSizeBytesInit*Exp[DAGCoeff*j], i++];
//            Sow[Prime[i - 1]*MixBytes]; j++]]]][[2]][[1]]

static const uint64_t dag_sizes[] = {
        1073721344U, 1108226048U, 1143885824U, 1180659712U, 1218596864U,
        1257795584U, 1298255872U, 1339936768U, 1383092224U, 1427402752U,
        1473458176U, 1520807936U, 1569673216U, 1620144128U, 1672278016U,
        1726042112U, 1781542912U, 1838804992U, 1897934848U, 1958998016U,
        2021961728U, 2086998016U, 2154057728U, 2223296512U, 2294779904U,
        2368581632U, 2444750848U, 2523344896U, 2604511232U, 2688249856U,
        2774577152U, 2863910912U, 2955931648U, 3050942464U, 3149049856U,
        3250393088U, 3354873856U, 3462705152U, 3574116352U, 3688951808U,
        3807588352U, 3930066944U, 4056395776U, 4186845184U, 4321439744U,
        4460376064U, 4603817984U, 4751814656U, 4904587264U, 5062283264U,
        5225107456U, 5393108992U, 5566435328U, 5745455104U, 5930217472U,
        6120894464U, 6317600768U, 6520754176U, 6730461184U, 6946820096U,
        7170248704U, 7400665088U, 7638716416U, 7884345344U, 8137854976U,
        8399417344U, 8669556736U, 8948322304U, 9235959808U, 9532960768U,
        9839448064U, 10155855872U, 10482405376U, 10819457024U, 11167338496U,
        11526311936U, 11896999936U, 12279476224U, 12674289664U, 13081759744U,
        13502451712U, 13936529408U, 14384705536U, 14847127552U, 15324565504U,
        15817142272U, 16325742592U, 16850776064U, 17392603136U, 17951731712U,
        18528980992U, 19124678656U, 19739537408U, 20374319104U, 21029343232U,
        21705601024U, 22403362816U, 23123750912U, 23867256832U, 24634658816U,
        25426694144U, 26244337664U, 27088154624U, 27959103488U, 28858068992U,
        29785862144U, 30743621632U, 31732092928U, 32752381952U, 33805438976U,
        34892345344U, 36014280704U, 37172006912U, 38367342592U, 39601033216U,
        40874233856U, 42188460032U, 43544932352U, 44945076224U, 46390145024U,
        47881662464U, 49421283328U, 51010260992U, 52650266624U, 54343241728U,
        56090497024U, 57894006784U, 59755409408U, 61676736512U, 63659511808U,
        65706610688U, 67819245568U, 69999824896U, 72250519552U, 74573484032U,
        76971298816U, 79446052864U, 82000531456U, 84637036544U, 87358369792U,
        90166980608U, 93066285056U, 96058585088U, 99146928128U, 102334885888U,
        105625317376U, 109021425664U, 112526741504U, 116144672768U, 119879143424U,
        123733594112U, 127711956992U, 131818123264U, 136056516608U, 140431028224U,
        144946270208U, 149606723584U, 154416951296U, 159381901312U, 164506415104U,
        169795760128U, 175255072768U, 180890046464U, 186706137088U, 192709193728U,
        198905311232U, 205300649984U, 211901517824U, 218714796032U, 225747021824U,
        233005371392U, 240497053696U, 248229711872U, 256210939904U, 264448864256U,
        272951578624U, 281727684608U, 290785980416U, 300135354368U, 309785612288U,
        319745953792U, 330026725376U, 340637888512U, 351590354944U, 362894921728U,
        374562910208U, 386606043136U, 399036362752U, 411866435584U, 425109090304U,
        438777516032U, 452885245952U, 467446829056U, 482476470272U, 497989357568U,
        514000949248U, 530527522816U, 547585273856U, 565191675904U, 583363907584U,
        602120753152U, 621480316928U, 641462669312U, 662087438336U, 683375218688U,
        705347547136U, 728026353664U, 751434305536U, 775594799104U, 800532262912U,
        826271510528U, 852838223872U, 880259182592U, 908561936384U, 937774575616U,
        967926444032U, 999047794688U, 1031169691648U, 1064324599808U,
        1098545475584U, 1133866594304U, 1170323329024U, 1207952257024U,
        1246791102464U, 1286878785536U, 1328255209472U, 1370962178048U,
        1415042166784U, 1460539469824U, 1507499659264U, 1555969748992U,
        1605998252032U, 1657635254272U, 1710932455424U, 1765943422976U,
        1822723272704U, 1881328365568U, 1941818208256U, 2004252577792U,
        2068694798336U, 2135208710144U, 2203861274624U, 2274721206272U,
        2347859439616U, 2423349243904U, 2501266272256U, 2581688520704U,
        2664696614912U, 2750373597184U, 2838805311488U, 2930080329728U,
        3024290091008U, 3121528877056U, 3221894033408U, 3325486600192U,
        3432409526272U, 3542770561024U, 3656679968768U, 3774251831296U,
        3895603761152U};

// 20000 Epochs worth of tabulated cache sizes (~7 Years)
// Generated with the following Mathematica Code:

// GetCacheSizes[n_]:=
// With[{ DAGSizeBytesInit=2^30U,
//        DAGSizeBytesGrowth=2^17U,
//        HashBytes=64}U,
//    Module[{j=0U,i=100}U,
//       Reap[
//          While[j<nU,
//             While[Prime[i]*HashBytes <
//                   (DAGSizeBytesInit + DAGSizeBytesGrowth * j) / 32U, i++];
//             Sow[Prime[i-1]*HashBytes];
//             j++]]]][[2]][[1]]

const uint32_t cache_sizes[] = {
        33550336, 34066432, 34598912, 35115008, 35631104, 36171776, 36663296,
        37138432, 37720064, 38268928, 38776832, 39268352, 39817216, 40349696,
        40849408, 41414656, 41873408, 42422272, 42954752, 43470848, 43986944,
        44511232, 45068288, 45592576, 46125056, 46624768, 47181824, 47648768,
        48099328, 48754688, 49197056, 49795072, 50302976, 50843648, 51367936,
        51900416, 52424704, 52932608, 53448704, 53997568, 54513664, 54972416,
        55570432, 56086528, 56553472, 57069568, 57634816, 58191872, 58683392,
        59232256, 59764736, 60280832, 60796928, 61313024, 61853696, 62369792,
        62910464, 63377408, 63926272, 64466944, 64958464, 65499136, 66056192,
        66572288, 67096576, 67555328, 68128768, 68661248, 69177344, 69718016,
        70193152, 70684672, 71274496, 71757824, 72331264, 72871936, 73363456,
        73920512, 74420224, 74960896, 75476992, 75993088, 76509184, 77017088,
        77492224, 78106624, 78573568, 79130624, 79654912, 80211968, 80728064,
        81178624, 81768448, 82284544, 82817024, 83341312, 83881984, 84373504,
        84914176, 85430272, 85946368, 86454272, 87027712, 87437312, 88076288,
        88543232, 89116672, 89624576, 90165248, 90656768, 91222016, 91738112,
        92205056, 92778496, 93319168, 93827072, 94367744, 94892032, 95408128,
        95916032, 96456704, 96980992, 97488896, 98013184, 98553856, 99045376,
        99602432, 100118528, 100642816, 101158912, 101666816, 102207488,
        102756352, 103174144, 103804928, 104329216, 104812544, 105336832,
        105877504, 106418176, 106950656, 107466752, 107958272, 108498944,
        108941312, 109514752, 110096384, 110563328, 111112192, 111652864,
        112095232, 112676864, 113242112, 113758208, 114282496, 114814976,
        115306496, 115847168, 116371456, 116903936, 117428224, 117936128,
        118484992, 118919168, 119517184, 120057856, 120573952, 121106432,
        121581568, 122138624, 122662912, 123170816, 123711488, 124203008,
        124719104, 125243392, 125800448, 126324736, 126857216, 127348736,
        127922176, 128438272, 128946176, 129462272, 130011136, 130494464,
        131035136, 131559424, 132100096, 132632576, 133148672, 133664768,
        134139904, 134705152, 135262208, 135786496, 136179712, 136818688,
        137351168, 137818112, 138407936, 138899456, 139423744, 139964416,
        140505088, 141021184, 141512704, 142077952, 142569472, 143110144,
        143642624, 144060416, 144699392, 145199104, 145707008, 146132992,
        146796544, 147304448, 147795968, 148344832, 148860928, 149417984,
        149942272, 150409216, 150966272, 151465984, 152031232, 152547328,
        153063424, 153604096, 154087424, 154611712, 155152384, 155693056,
        156135424, 156717056, 157257728, 157700096, 158322688, 158855168,
        159346688, 159838208, 160411648, 160944128, 161460224, 162000896,
        162525184, 163016704, 163549184, 164098048, 164614144, 165023744,
        165613568, 166129664, 166703104, 167235584, 167727104, 168267776,
        168808448, 169332736
};

#ifdef __cplusplus
}
#endif