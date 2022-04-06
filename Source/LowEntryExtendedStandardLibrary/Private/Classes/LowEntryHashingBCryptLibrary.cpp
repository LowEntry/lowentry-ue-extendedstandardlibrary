// Copyright Low Entry. Apache License, Version 2.0.

#include "LowEntryHashingBCryptLibrary.h"


constexpr int32 ULowEntryHashingBCryptLibrary::P_orig[18] = {0x243f6a88, static_cast<int32>(0x85a308d3), 0x13198a2e, 0x03707344, static_cast<int32>(0xa4093822), 0x299f31d0, 0x082efa98, static_cast<int32>(0xec4e6c89), 0x452821e6, 0x38d01377, static_cast<int32>(0xbe5466cf), 0x34e90c6c, static_cast<int32>(0xc0ac29b7), static_cast<int32>(0xc97c50dd), 0x3f84d5b5, static_cast<int32>(0xb5470917), static_cast<int32>(0x9216d5d9), static_cast<int32>(0x8979fb1b)};
constexpr int32 ULowEntryHashingBCryptLibrary::S_orig[1024] = {static_cast<int32>(0xd1310ba6), static_cast<int32>(0x98dfb5ac), 0x2ffd72db, static_cast<int32>(0xd01adfb7), static_cast<int32>(0xb8e1afed), 0x6a267e96, static_cast<int32>(0xba7c9045), static_cast<int32>(0xf12c7f99), 0x24a19947, static_cast<int32>(0xb3916cf7), 0x0801f2e2, static_cast<int32>(0x858efc16), 0x636920d8, 0x71574e69, static_cast<int32>(0xa458fea3), static_cast<int32>(0xf4933d7e), 0x0d95748f, 0x728eb658, 0x718bcd58, static_cast<int32>(0x82154aee), 0x7b54a41d, static_cast<int32>(0xc25a59b5), static_cast<int32>(0x9c30d539), 0x2af26013, static_cast<int32>(0xc5d1b023), 0x286085f0, static_cast<int32>(0xca417918), static_cast<int32>(0xb8db38ef), static_cast<int32>(0x8e79dcb0), 0x603a180e, 0x6c9e0e8b, static_cast<int32>(0xb01e8a3e), static_cast<int32>(0xd71577c1), static_cast<int32>(0xbd314b27), 0x78af2fda, 0x55605c60, static_cast<int32>(0xe65525f3), static_cast<int32>(0xaa55ab94), 0x57489862, 0x63e81440, 0x55ca396a, 0x2aab10b6, static_cast<int32>(0xb4cc5c34), 0x1141e8ce, static_cast<int32>(0xa15486af), 0x7c72e993, static_cast<int32>(0xb3ee1411), 0x636fbc2a, 0x2ba9c55d, 0x741831f6, static_cast<int32>(0xce5c3e16), static_cast<int32>(0x9b87931e), static_cast<int32>(0xafd6ba33), 0x6c24cf5c, 0x7a325381, 0x28958677, 0x3b8f4898, 0x6b4bb9af, static_cast<int32>(0xc4bfe81b), 0x66282193, 0x61d809cc, static_cast<int32>(0xfb21a991), 0x487cac60, 0x5dec8032, static_cast<int32>(0xef845d5d), static_cast<int32>(0xe98575b1), static_cast<int32>(0xdc262302), static_cast<int32>(0xeb651b88), 0x23893e81, static_cast<int32>(0xd396acc5), 0x0f6d6ff3, static_cast<int32>(0x83f44239), 0x2e0b4482, static_cast<int32>(0xa4842004), 0x69c8f04a, static_cast<int32>(0x9e1f9b5e), 0x21c66842, static_cast<int32>(0xf6e96c9a), 0x670c9c61, static_cast<int32>(0xabd388f0), 0x6a51a0d2, static_cast<int32>(0xd8542f68), static_cast<int32>(0x960fa728), static_cast<int32>(0xab5133a3), 0x6eef0b6c, 0x137a3be4, static_cast<int32>(0xba3bf050), 0x7efb2a98, static_cast<int32>(0xa1f1651d), 0x39af0176, 0x66ca593e, static_cast<int32>(0x82430e88), static_cast<int32>(0x8cee8619), 0x456f9fb4, 0x7d84a5c3, 0x3b8b5ebe, static_cast<int32>(0xe06f75d8), static_cast<int32>(0x85c12073), 0x401a449f, 0x56c16aa6, 0x4ed3aa62, 0x363f7706, 0x1bfedf72, 0x429b023d, 0x37d0d724, static_cast<int32>(0xd00a1248), static_cast<int32>(0xdb0fead3), 0x49f1c09b, 0x075372c9, static_cast<int32>(0x80991b7b), 0x25d479d8, static_cast<int32>(0xf6e8def7), static_cast<int32>(0xe3fe501a), static_cast<int32>(0xb6794c3b), static_cast<int32>(0x976ce0bd), 0x04c006ba, static_cast<int32>(0xc1a94fb6), 0x409f60c4, 0x5e5c9ec2, 0x196a2463, 0x68fb6faf, 0x3e6c53b5, 0x1339b2eb, 0x3b52ec6f, 0x6dfc511f, static_cast<int32>(0x9b30952c), static_cast<int32>(0xcc814544), static_cast<int32>(0xaf5ebd09), static_cast<int32>(0xbee3d004), static_cast<int32>(0xde334afd), 0x660f2807, 0x192e4bb3, static_cast<int32>(0xc0cba857), 0x45c8740f, static_cast<int32>(0xd20b5f39), static_cast<int32>(0xb9d3fbdb), 0x5579c0bd, 0x1a60320a, static_cast<int32>(0xd6a100c6), 0x402c7279, 0x679f25fe, static_cast<int32>(0xfb1fa3cc), static_cast<int32>(0x8ea5e9f8), static_cast<int32>(0xdb3222f8), 0x3c7516df, static_cast<int32>(0xfd616b15), 0x2f501ec8, static_cast<int32>(0xad0552ab), 0x323db5fa, static_cast<int32>(0xfd238760), 0x53317b48, 0x3e00df82, static_cast<int32>(0x9e5c57bb), static_cast<int32>(0xca6f8ca0), 0x1a87562e, static_cast<int32>(0xdf1769db), static_cast<int32>(0xd542a8f6), 0x287effc3, static_cast<int32>(0xac6732c6), static_cast<int32>(0x8c4f5573), 0x695b27b0, static_cast<int32>(0xbbca58c8), static_cast<int32>(0xe1ffa35d), static_cast<int32>(0xb8f011a0), 0x10fa3d98, static_cast<int32>(0xfd2183b8), 0x4afcb56c, 0x2dd1d35b, static_cast<int32>(0x9a53e479), static_cast<int32>(0xb6f84565), static_cast<int32>(0xd28e49bc), 0x4bfb9790, static_cast<int32>(0xe1ddf2da), static_cast<int32>(0xa4cb7e33), 0x62fb1341, static_cast<int32>(0xcee4c6e8), static_cast<int32>(0xef20cada), 0x36774c01, static_cast<int32>(0xd07e9efe), 0x2bf11fb4, static_cast<int32>(0x95dbda4d), static_cast<int32>(0xae909198), static_cast<int32>(0xeaad8e71), 0x6b93d5a0, static_cast<int32>(0xd08ed1d0), static_cast<int32>(0xafc725e0), static_cast<int32>(0x8e3c5b2f), static_cast<int32>(0x8e7594b7), static_cast<int32>(0x8ff6e2fb), static_cast<int32>(0xf2122b64), static_cast<int32>(0x8888b812), static_cast<int32>(0x900df01c), 0x4fad5ea0, 0x688fc31c, static_cast<int32>(0xd1cff191), static_cast<int32>(0xb3a8c1ad), 0x2f2f2218, static_cast<int32>(0xbe0e1777), static_cast<int32>(0xea752dfe), static_cast<int32>(0x8b021fa1), static_cast<int32>(0xe5a0cc0f), static_cast<int32>(0xb56f74e8), 0x18acf3d6, static_cast<int32>(0xce89e299), static_cast<int32>(0xb4a84fe0), static_cast<int32>(0xfd13e0b7), 0x7cc43b81, static_cast<int32>(0xd2ada8d9), 0x165fa266, static_cast<int32>(0x80957705), static_cast<int32>(0x93cc7314), 0x211a1477, static_cast<int32>(0xe6ad2065), 0x77b5fa86, static_cast<int32>(0xc75442f5), static_cast<int32>(0xfb9d35cf), static_cast<int32>(0xebcdaf0c), 0x7b3e89a0, static_cast<int32>(0xd6411bd3), static_cast<int32>(0xae1e7e49), 0x00250e2d, 0x2071b35e, 0x226800bb, 0x57b8e0af, 0x2464369b, static_cast<int32>(0xf009b91e), 0x5563911d, 0x59dfa6aa, 0x78c14389, static_cast<int32>(0xd95a537f), 0x207d5ba2, 0x02e5b9c5, static_cast<int32>(0x83260376), 0x6295cfa9, 0x11c81968, 0x4e734a41, static_cast<int32>(0xb3472dca), 0x7b14a94a, 0x1b510052, static_cast<int32>(0x9a532915), static_cast<int32>(0xd60f573f), static_cast<int32>(0xbc9bc6e4), 0x2b60a476, static_cast<int32>(0x81e67400), 0x08ba6fb5, 0x571be91f, static_cast<int32>(0xf296ec6b), 0x2a0dd915, static_cast<int32>(0xb6636521), static_cast<int32>(0xe7b9f9b6), static_cast<int32>(0xff34052e), static_cast<int32>(0xc5855664), 0x53b02d5d, static_cast<int32>(0xa99f8fa1), 0x08ba4799, 0x6e85076a, 0x4b7a70e9, static_cast<int32>(0xb5b32944), static_cast<int32>(0xdb75092e), static_cast<int32>(0xc4192623), static_cast<int32>(0xad6ea6b0), 0x49a7df7d, static_cast<int32>(0x9cee60b8), static_cast<int32>(0x8fedb266), static_cast<int32>(0xecaa8c71), 0x699a17ff, 0x5664526c, static_cast<int32>(0xc2b19ee1), 0x193602a5, 0x75094c29, static_cast<int32>(0xa0591340), static_cast<int32>(0xe4183a3e), 0x3f54989a, 0x5b429d65, 0x6b8fe4d6, static_cast<int32>(0x99f73fd6), static_cast<int32>(0xa1d29c07), static_cast<int32>(0xefe830f5), 0x4d2d38e6, static_cast<int32>(0xf0255dc1), 0x4cdd2086, static_cast<int32>(0x8470eb26), 0x6382e9c6, 0x021ecc5e, 0x09686b3f, 0x3ebaefc9, 0x3c971814, 0x6b6a70a1, 0x687f3584, 0x52a0e286, static_cast<int32>(0xb79c5305), static_cast<int32>(0xaa500737), 0x3e07841c, 0x7fdeae5c, static_cast<int32>(0x8e7d44ec), 0x5716f2b8, static_cast<int32>(0xb03ada37), static_cast<int32>(0xf0500c0d), static_cast<int32>(0xf01c1f04), 0x0200b3ff, static_cast<int32>(0xae0cf51a), 0x3cb574b2, 0x25837a58, static_cast<int32>(0xdc0921bd), static_cast<int32>(0xd19113f9), 0x7ca92ff6, static_cast<int32>(0x94324773), 0x22f54701, 0x3ae5e581, 0x37c2dadc, static_cast<int32>(0xc8b57634), static_cast<int32>(0x9af3dda7), static_cast<int32>(0xa9446146), 0x0fd0030e, static_cast<int32>(0xecc8c73e), static_cast<int32>(0xa4751e41), static_cast<int32>(0xe238cd99), 0x3bea0e2f, 0x3280bba1, 0x183eb331, 0x4e548b38, 0x4f6db908, 0x6f420d03, static_cast<int32>(0xf60a04bf), 0x2cb81290, 0x24977c79, 0x5679b072, static_cast<int32>(0xbcaf89af), static_cast<int32>(0xde9a771f), static_cast<int32>(0xd9930810), static_cast<int32>(0xb38bae12), static_cast<int32>(0xdccf3f2e), 0x5512721f, 0x2e6b7124, 0x501adde6, static_cast<int32>(0x9f84cd87), 0x7a584718, 0x7408da17, static_cast<int32>(0xbc9f9abc), static_cast<int32>(0xe94b7d8c), static_cast<int32>(0xec7aec3a), static_cast<int32>(0xdb851dfa), 0x63094366, static_cast<int32>(0xc464c3d2), static_cast<int32>(0xef1c1847), 0x3215d908, static_cast<int32>(0xdd433b37), 0x24c2ba16, 0x12a14d43, 0x2a65c451, 0x50940002, 0x133ae4dd, 0x71dff89e, 0x10314e55, static_cast<int32>(0x81ac77d6), 0x5f11199b, 0x043556f1, static_cast<int32>(0xd7a3c76b), 0x3c11183b, 0x5924a509, static_cast<int32>(0xf28fe6ed), static_cast<int32>(0x97f1fbfa), static_cast<int32>(0x9ebabf2c), 0x1e153c6e, static_cast<int32>(0x86e34570), static_cast<int32>(0xeae96fb1), static_cast<int32>(0x860e5e0a), 0x5a3e2ab3, 0x771fe71c, 0x4e3d06fa, 0x2965dcb9, static_cast<int32>(0x99e71d0f), static_cast<int32>(0x803e89d6), 0x5266c825, 0x2e4cc978, static_cast<int32>(0x9c10b36a), static_cast<int32>(0xc6150eba), static_cast<int32>(0x94e2ea78), static_cast<int32>(0xa5fc3c53), 0x1e0a2df4, static_cast<int32>(0xf2f74ea7), 0x361d2b3d, 0x1939260f, 0x19c27960, 0x5223a708, static_cast<int32>(0xf71312b6), static_cast<int32>(0xebadfe6e), static_cast<int32>(0xeac31f66), static_cast<int32>(0xe3bc4595), static_cast<int32>(0xa67bc883), static_cast<int32>(0xb17f37d1), 0x018cff28, static_cast<int32>(0xc332ddef), static_cast<int32>(0xbe6c5aa5), 0x65582185, 0x68ab9802, static_cast<int32>(0xeecea50f), static_cast<int32>(0xdb2f953b), 0x2aef7dad, 0x5b6e2f84, 0x1521b628, 0x29076170, static_cast<int32>(0xecdd4775), 0x619f1510, 0x13cca830, static_cast<int32>(0xeb61bd96), 0x0334fe1e, static_cast<int32>(0xaa0363cf), static_cast<int32>(0xb5735c90), 0x4c70a239, static_cast<int32>(0xd59e9e0b), static_cast<int32>(0xcbaade14), static_cast<int32>(0xeecc86bc), 0x60622ca7, static_cast<int32>(0x9cab5cab), static_cast<int32>(0xb2f3846e), 0x648b1eaf, 0x19bdf0ca, static_cast<int32>(0xa02369b9), 0x655abb50, 0x40685a32, 0x3c2ab4b3, 0x319ee9d5, static_cast<int32>(0xc021b8f7), static_cast<int32>(0x9b540b19), static_cast<int32>(0x875fa099), static_cast<int32>(0x95f7997e), 0x623d7da8, static_cast<int32>(0xf837889a), static_cast<int32>(0x97e32d77), 0x11ed935f, 0x16681281, 0x0e358829, static_cast<int32>(0xc7e61fd6), static_cast<int32>(0x96dedfa1), 0x7858ba99, 0x57f584a5, 0x1b227263, static_cast<int32>(0x9b83c3ff), 0x1ac24696, static_cast<int32>(0xcdb30aeb), 0x532e3054, static_cast<int32>(0x8fd948e4), 0x6dbc3128, 0x58ebf2ef, 0x34c6ffea, static_cast<int32>(0xfe28ed61), static_cast<int32>(0xee7c3c73), 0x5d4a14d9, static_cast<int32>(0xe864b7e3), 0x42105d14, 0x203e13e0, 0x45eee2b6, static_cast<int32>(0xa3aaabea), static_cast<int32>(0xdb6c4f15), static_cast<int32>(0xfacb4fd0), static_cast<int32>(0xc742f442), static_cast<int32>(0xef6abbb5), 0x654f3b1d, 0x41cd2105, static_cast<int32>(0xd81e799e), static_cast<int32>(0x86854dc7), static_cast<int32>(0xe44b476a), 0x3d816250, static_cast<int32>(0xcf62a1f2), 0x5b8d2646, static_cast<int32>(0xfc8883a0), static_cast<int32>(0xc1c7b6a3), 0x7f1524c3, 0x69cb7492, 0x47848a0b, 0x5692b285, 0x095bbf00, static_cast<int32>(0xad19489d), 0x1462b174, 0x23820e00, 0x58428d2a, 0x0c55f5ea, 0x1dadf43e, 0x233f7061, 0x3372f092, static_cast<int32>(0x8d937e41), static_cast<int32>(0xd65fecf1), 0x6c223bdb, 0x7cde3759, static_cast<int32>(0xcbee7460), 0x4085f2a7, static_cast<int32>(0xce77326e), static_cast<int32>(0xa6078084), 0x19f8509e, static_cast<int32>(0xe8efd855), 0x61d99735, static_cast<int32>(0xa969a7aa), static_cast<int32>(0xc50c06c2), 0x5a04abfc, static_cast<int32>(0x800bcadc), static_cast<int32>(0x9e447a2e), static_cast<int32>(0xc3453484), static_cast<int32>(0xfdd56705), 0x0e1e9ec9, static_cast<int32>(0xdb73dbd3), 0x105588cd, 0x675fda79, static_cast<int32>(0xe3674340), static_cast<int32>(0xc5c43465), 0x713e38d8, 0x3d28f89e, static_cast<int32>(0xf16dff20), 0x153e21e7, static_cast<int32>(0x8fb03d4a), static_cast<int32>(0xe6e39f2b), static_cast<int32>(0xdb83adf7), static_cast<int32>(0xe93d5a68), static_cast<int32>(0x948140f7), static_cast<int32>(0xf64c261c), static_cast<int32>(0x94692934), 0x411520f7, 0x7602d4f7, static_cast<int32>(0xbcf46b2e), static_cast<int32>(0xd4a20068), static_cast<int32>(0xd4082471), 0x3320f46a, 0x43b7d4b7, 0x500061af, 0x1e39f62e, static_cast<int32>(0x97244546), 0x14214f74, static_cast<int32>(0xbf8b8840), 0x4d95fc1d, static_cast<int32>(0x96b591af), 0x70f4ddd3, 0x66a02f45, static_cast<int32>(0xbfbc09ec), 0x03bd9785, 0x7fac6dd0, 0x31cb8504, static_cast<int32>(0x96eb27b3), 0x55fd3941, static_cast<int32>(0xda2547e6), static_cast<int32>(0xabca0a9a), 0x28507825, 0x530429f4, 0x0a2c86da, static_cast<int32>(0xe9b66dfb), 0x68dc1462, static_cast<int32>(0xd7486900), 0x680ec0a4, 0x27a18dee, 0x4f3ffea2, static_cast<int32>(0xe887ad8c), static_cast<int32>(0xb58ce006), 0x7af4d6b6, static_cast<int32>(0xaace1e7c), static_cast<int32>(0xd3375fec), static_cast<int32>(0xce78a399), 0x406b2a42, 0x20fe9e35, static_cast<int32>(0xd9f385b9), static_cast<int32>(0xee39d7ab), 0x3b124e8b, 0x1dc9faf7, 0x4b6d1856, 0x26a36631, static_cast<int32>(0xeae397b2), 0x3a6efa74, static_cast<int32>(0xdd5b4332), 0x6841e7f7, static_cast<int32>(0xca7820fb), static_cast<int32>(0xfb0af54e), static_cast<int32>(0xd8feb397), 0x454056ac, static_cast<int32>(0xba489527), 0x55533a3a, 0x20838d87, static_cast<int32>(0xfe6ba9b7), static_cast<int32>(0xd096954b), 0x55a867bc, static_cast<int32>(0xa1159a58), static_cast<int32>(0xcca92963), static_cast<int32>(0x99e1db33), static_cast<int32>(0xa62a4a56), 0x3f3125f9, 0x5ef47e1c, static_cast<int32>(0x9029317c), static_cast<int32>(0xfdf8e802), 0x04272f70, static_cast<int32>(0x80bb155c), 0x05282ce3, static_cast<int32>(0x95c11548), static_cast<int32>(0xe4c66d22), 0x48c1133f, static_cast<int32>(0xc70f86dc), 0x07f9c9ee, 0x41041f0f, 0x404779a4, 0x5d886e17, 0x325f51eb, static_cast<int32>(0xd59bc0d1), static_cast<int32>(0xf2bcc18f), 0x41113564, 0x257b7834, 0x602a9c60, static_cast<int32>(0xdff8e8a3), 0x1f636c1b, 0x0e12b4c2, 0x02e1329e, static_cast<int32>(0xaf664fd1), static_cast<int32>(0xcad18115), 0x6b2395e0, 0x333e92e1, 0x3b240b62, static_cast<int32>(0xeebeb922), static_cast<int32>(0x85b2a20e), static_cast<int32>(0xe6ba0d99), static_cast<int32>(0xde720c8c), 0x2da2f728, static_cast<int32>(0xd0127845), static_cast<int32>(0x95b794fd), 0x647d0862, static_cast<int32>(0xe7ccf5f0), 0x5449a36f, static_cast<int32>(0x877d48fa), static_cast<int32>(0xc39dfd27), static_cast<int32>(0xf33e8d1e), 0x0a476341, static_cast<int32>(0x992eff74), 0x3a6f6eab, static_cast<int32>(0xf4f8fd37), static_cast<int32>(0xa812dc60), static_cast<int32>(0xa1ebddf8), static_cast<int32>(0x991be14c), static_cast<int32>(0xdb6e6b0d), static_cast<int32>(0xc67b5510), 0x6d672c37, 0x2765d43b, static_cast<int32>(0xdcd0e804), static_cast<int32>(0xf1290dc7), static_cast<int32>(0xcc00ffa3), static_cast<int32>(0xb5390f92), 0x690fed0b, 0x667b9ffb, static_cast<int32>(0xcedb7d9c), static_cast<int32>(0xa091cf0b), static_cast<int32>(0xd9155ea3), static_cast<int32>(0xbb132f88), 0x515bad24, 0x7b9479bf, 0x763bd6eb, 0x37392eb3, static_cast<int32>(0xcc115979), static_cast<int32>(0x8026e297), static_cast<int32>(0xf42e312d), 0x6842ada7, static_cast<int32>(0xc66a2b3b), 0x12754ccc, 0x782ef11c, 0x6a124237, static_cast<int32>(0xb79251e7), 0x06a1bbe6, 0x4bfb6350, 0x1a6b1018, 0x11caedfa, 0x3d25bdd8, static_cast<int32>(0xe2e1c3c9), 0x44421659, 0x0a121386, static_cast<int32>(0xd90cec6e), static_cast<int32>(0xd5abea2a), 0x64af674e, static_cast<int32>(0xda86a85f), static_cast<int32>(0xbebfe988), 0x64e4c3fe, static_cast<int32>(0x9dbc8057), static_cast<int32>(0xf0f7c086), 0x60787bf8, 0x6003604d, static_cast<int32>(0xd1fd8346), static_cast<int32>(0xf6381fb0), 0x7745ae04, static_cast<int32>(0xd736fccc), static_cast<int32>(0x83426b33), static_cast<int32>(0xf01eab71), static_cast<int32>(0xb0804187), 0x3c005e5f, 0x77a057be, static_cast<int32>(0xbde8ae24), 0x55464299, static_cast<int32>(0xbf582e61), 0x4e58f48f, static_cast<int32>(0xf2ddfda2), static_cast<int32>(0xf474ef38), static_cast<int32>(0x8789bdc2), 0x5366f9c3, static_cast<int32>(0xc8b38e74), static_cast<int32>(0xb475f255), 0x46fcd9b9, 0x7aeb2661, static_cast<int32>(0x8b1ddf84), static_cast<int32>(0x846a0e79), static_cast<int32>(0x915f95e2), 0x466e598e, 0x20b45770, static_cast<int32>(0x8cd55591), static_cast<int32>(0xc902de4c), static_cast<int32>(0xb90bace1), static_cast<int32>(0xbb8205d0), 0x11a86248, 0x7574a99e, static_cast<int32>(0xb77f19b6), static_cast<int32>(0xe0a9dc09), 0x662d09a1, static_cast<int32>(0xc4324633), static_cast<int32>(0xe85a1f02), 0x09f0be8c, 0x4a99a025, 0x1d6efe10, 0x1ab93d1d, 0x0ba5a4df, static_cast<int32>(0xa186f20f), 0x2868f169, static_cast<int32>(0xdcb7da83), 0x573906fe, static_cast<int32>(0xa1e2ce9b), 0x4fcd7f52, 0x50115e01, static_cast<int32>(0xa70683fa), static_cast<int32>(0xa002b5c4), 0x0de6d027, static_cast<int32>(0x9af88c27), 0x773f8641, static_cast<int32>(0xc3604c06), 0x61a806b5, static_cast<int32>(0xf0177a28), static_cast<int32>(0xc0f586e0), 0x006058aa, 0x30dc7d62, 0x11e69ed7, 0x2338ea63, 0x53c2dd94, static_cast<int32>(0xc2c21634), static_cast<int32>(0xbbcbee56), static_cast<int32>(0x90bcb6de), static_cast<int32>(0xebfc7da1), static_cast<int32>(0xce591d76), 0x6f05e409, 0x4b7c0188, 0x39720a3d, 0x7c927c24, static_cast<int32>(0x86e3725f), 0x724d9db9, 0x1ac15bb4, static_cast<int32>(0xd39eb8fc), static_cast<int32>(0xed545578), 0x08fca5b5, static_cast<int32>(0xd83d7cd3), 0x4dad0fc4, 0x1e50ef5e, static_cast<int32>(0xb161e6f8), static_cast<int32>(0xa28514d9), 0x6c51133c, 0x6fd5c7e7, 0x56e14ec4, 0x362abfce, static_cast<int32>(0xddc6c837), static_cast<int32>(0xd79a3234), static_cast<int32>(0x92638212), 0x670efa8e, 0x406000e0, 0x3a39ce37, static_cast<int32>(0xd3faf5cf), static_cast<int32>(0xabc27737), 0x5ac52d1b, 0x5cb0679e, 0x4fa33742, static_cast<int32>(0xd3822740), static_cast<int32>(0x99bc9bbe), static_cast<int32>(0xd5118e9d), static_cast<int32>(0xbf0f7315), static_cast<int32>(0xd62d1c7e), static_cast<int32>(0xc700c47b), static_cast<int32>(0xb78c1b6b), 0x21a19045, static_cast<int32>(0xb26eb1be), 0x6a366eb4, 0x5748ab2f, static_cast<int32>(0xbc946e79), static_cast<int32>(0xc6a376d2), 0x6549c2c8, 0x530ff8ee, 0x468dde7d, static_cast<int32>(0xd5730a1d), 0x4cd04dc6, 0x2939bbdb, static_cast<int32>(0xa9ba4650), static_cast<int32>(0xac9526e8), static_cast<int32>(0xbe5ee304), static_cast<int32>(0xa1fad5f0), 0x6a2d519a, 0x63ef8ce2, static_cast<int32>(0x9a86ee22), static_cast<int32>(0xc089c2b8), 0x43242ef6, static_cast<int32>(0xa51e03aa), static_cast<int32>(0x9cf2d0a4), static_cast<int32>(0x83c061ba), static_cast<int32>(0x9be96a4d), static_cast<int32>(0x8fe51550), static_cast<int32>(0xba645bd6), 0x2826a2f9, static_cast<int32>(0xa73a3ae1), 0x4ba99586, static_cast<int32>(0xef5562e9), static_cast<int32>(0xc72fefd3), static_cast<int32>(0xf752f7da), 0x3f046f69, 0x77fa0a59, static_cast<int32>(0x80e4a915), static_cast<int32>(0x87b08601), static_cast<int32>(0x9b09e6ad), 0x3b3ee593, static_cast<int32>(0xe990fd5a), static_cast<int32>(0x9e34d797), 0x2cf0b7d9, 0x022b8b51, static_cast<int32>(0x96d5ac3a), 0x017da67d, static_cast<int32>(0xd1cf3ed6), 0x7c7d2d28, 0x1f9f25cf, static_cast<int32>(0xadf2b89b), 0x5ad6b472, 0x5a88f54c, static_cast<int32>(0xe029ac71), static_cast<int32>(0xe019a5e6), 0x47b0acfd, static_cast<int32>(0xed93fa9b), static_cast<int32>(0xe8d3c48d), 0x283b57cc, static_cast<int32>(0xf8d56629), 0x79132e28, 0x785f0191, static_cast<int32>(0xed756055), static_cast<int32>(0xf7960e44), static_cast<int32>(0xe3d35e8c), 0x15056dd4, static_cast<int32>(0x88f46dba), 0x03a16125, 0x0564f0bd, static_cast<int32>(0xc3eb9e15), 0x3c9057a2, static_cast<int32>(0x97271aec), static_cast<int32>(0xa93a072a), 0x1b3f6d9b, 0x1e6321f5, static_cast<int32>(0xf59c66fb), 0x26dcf319, 0x7533d928, static_cast<int32>(0xb155fdf5), 0x03563482, static_cast<int32>(0x8aba3cbb), 0x28517711, static_cast<int32>(0xc20ad9f8), static_cast<int32>(0xabcc5167), static_cast<int32>(0xccad925f), 0x4de81751, 0x3830dc8e, 0x379d5862, static_cast<int32>(0x9320f991), static_cast<int32>(0xea7a90c2), static_cast<int32>(0xfb3e7bce), 0x5121ce64, 0x774fbe32, static_cast<int32>(0xa8b6e37e), static_cast<int32>(0xc3293d46), 0x48de5369, 0x6413e680, static_cast<int32>(0xa2ae0810), static_cast<int32>(0xdd6db224), 0x69852dfd, 0x09072166, static_cast<int32>(0xb39a460a), 0x6445c0dd, 0x586cdecf, 0x1c20c8ae, 0x5bbef7dd, 0x1b588d40, static_cast<int32>(0xccd2017f), 0x6bb4e3bb, static_cast<int32>(0xdda26a7e), 0x3a59ff45, 0x3e350a44, static_cast<int32>(0xbcb4cdd5), 0x72eacea8, static_cast<int32>(0xfa6484bb), static_cast<int32>(0x8d6612ae), static_cast<int32>(0xbf3c6f47), static_cast<int32>(0xd29be463), 0x542f5d9e, static_cast<int32>(0xaec2771b), static_cast<int32>(0xf64e6370), 0x740e0d8d, static_cast<int32>(0xe75b1357), static_cast<int32>(0xf8721671), static_cast<int32>(0xaf537d5d), 0x4040cb08, 0x4eb4e2cc, 0x34d2466a, 0x0115af84, static_cast<int32>(0xe1b00428), static_cast<int32>(0x95983a1d), 0x06b89fb4, static_cast<int32>(0xce6ea048), 0x6f3f3b82, 0x3520ab82, 0x011a1d4b, 0x277227f8, 0x611560b1, static_cast<int32>(0xe7933fdc), static_cast<int32>(0xbb3a792b), 0x344525bd, static_cast<int32>(0xa08839e1), 0x51ce794b, 0x2f32c9b7, static_cast<int32>(0xa01fbac9), static_cast<int32>(0xe01cc87e), static_cast<int32>(0xbcc7d1f6), static_cast<int32>(0xcf0111c3), static_cast<int32>(0xa1e8aac7), 0x1a908749, static_cast<int32>(0xd44fbd9a), static_cast<int32>(0xd0dadecb), static_cast<int32>(0xd50ada38), 0x0339c32a, static_cast<int32>(0xc6913667), static_cast<int32>(0x8df9317c), static_cast<int32>(0xe0b12b4f), static_cast<int32>(0xf79e59b7), 0x43f5bb3a, static_cast<int32>(0xf2d519ff), 0x27d9459c, static_cast<int32>(0xbf97222c), 0x15e6fc2a, 0x0f91fc71, static_cast<int32>(0x9b941525), static_cast<int32>(0xfae59361), static_cast<int32>(0xceb69ceb), static_cast<int32>(0xc2a86459), 0x12baa8d1, static_cast<int32>(0xb6c1075e), static_cast<int32>(0xe3056a0c), 0x10d25065, static_cast<int32>(0xcb03a442), static_cast<int32>(0xe0ec6e0e), 0x1698db3b, 0x4c98a0be, 0x3278e964, static_cast<int32>(0x9f1f9532), static_cast<int32>(0xe0d392df), static_cast<int32>(0xd3a0342b), static_cast<int32>(0x8971f21e), 0x1b0a7441, 0x4ba3348c, static_cast<int32>(0xc5be7120), static_cast<int32>(0xc37632d8), static_cast<int32>(0xdf359f8d), static_cast<int32>(0x9b992f2e), static_cast<int32>(0xe60b6f47), 0x0fe3f11d, static_cast<int32>(0xe54cda54), 0x1edad891, static_cast<int32>(0xce6279cf), static_cast<int32>(0xcd3e7e6f), 0x1618b166, static_cast<int32>(0xfd2c1d05), static_cast<int32>(0x848fd2c5), static_cast<int32>(0xf6fb2299), static_cast<int32>(0xf523f357), static_cast<int32>(0xa6327623), static_cast<int32>(0x93a83531), 0x56cccd02, static_cast<int32>(0xacf08162), 0x5a75ebb5, 0x6e163697, static_cast<int32>(0x88d273cc), static_cast<int32>(0xde966292), static_cast<int32>(0x81b949d0), 0x4c50901b, 0x71c65614, static_cast<int32>(0xe6c6c7bd), 0x327a140a, 0x45e1d006, static_cast<int32>(0xc3f27b9a), static_cast<int32>(0xc9aa53fd), 0x62a80f00, static_cast<int32>(0xbb25bfe2), 0x35bdd2f6, 0x71126905, static_cast<int32>(0xb2040222), static_cast<int32>(0xb6cbcf7c), static_cast<int32>(0xcd769c2b), 0x53113ec0, 0x1640e3d3, 0x38abbd60, 0x2547adf0, static_cast<int32>(0xba38209c), static_cast<int32>(0xf746ce76), 0x77afa1c5, 0x20756060, static_cast<int32>(0x85cbfe4e), static_cast<int32>(0x8ae88dd8), 0x7aaaf9b0, 0x4cf9aa7e, 0x1948c25c, 0x02fb8a8c, 0x01c36ae4, static_cast<int32>(0xd6ebe1f9), static_cast<int32>(0x90d4f869), static_cast<int32>(0xa65cdea0), 0x3f09252d, static_cast<int32>(0xc208e69f), static_cast<int32>(0xb74e6132), static_cast<int32>(0xce77e25b), 0x578fdfe3, 0x3ac372e6};
constexpr int32 ULowEntryHashingBCryptLibrary::bf_crypt_ciphertext[6] = {0x4f727068, 0x65616e42, 0x65686f6c, 0x64657253, 0x63727944, 0x6f756274};


void ULowEntryHashingBCryptLibrary::encipher(int32 lr[], const int32 off)
{
	int32 i, n, l = lr[off], r = lr[off + 1];

	l ^= P[0];
	for (i = 0; i <= (BLOWFISH_NUM_ROUNDS - 2);)
	{
		n = S[(l >> 24) & 0xff];
		n += S[0x100 | ((l >> 16) & 0xff)];
		n ^= S[0x200 | ((l >> 8) & 0xff)];
		n += S[0x300 | (l & 0xff)];
		r ^= n ^ P[++i];

		n = S[(r >> 24) & 0xff];
		n += S[0x100 | ((r >> 16) & 0xff)];
		n ^= S[0x200 | ((r >> 8) & 0xff)];
		n += S[0x300 | (r & 0xff)];
		l ^= n ^ P[++i];
	}
	lr[off] = r ^ P[BLOWFISH_NUM_ROUNDS + 1];
	lr[off + 1] = l;
}

int32 ULowEntryHashingBCryptLibrary::streamtoword(const TArray<uint8>& data, int32 offp[])
{
	int32 i;
	int32 word = 0;
	int32 off = offp[0];

	for (i = 0; i < 4; i++)
	{
		word = (word << 8) | (data[off] & 0xff);
		off = (off + 1) % data.Num();
	}

	offp[0] = off;
	return word;
}

void ULowEntryHashingBCryptLibrary::init_key()
{
	for (int32 i = 0; i < P_len; i++)
	{
		P[i] = P_orig[i];
	}
	for (int32 i = 0; i < S_len; i++)
	{
		S[i] = S_orig[i];
	}
}

void ULowEntryHashingBCryptLibrary::key(const TArray<uint8>& key)
{
	int32 i;
	int32 koffp[] = {0};
	int32 lr[] = {0, 0};
	int32 plen = P_len, slen = S_len;

	for (i = 0; i < plen; i++)
	{
		P[i] = P[i] ^ streamtoword(key, koffp);
	}

	for (i = 0; i < plen; i += 2)
	{
		encipher(lr, 0);
		P[i] = lr[0];
		P[i + 1] = lr[1];
	}

	for (i = 0; i < slen; i += 2)
	{
		encipher(lr, 0);
		S[i] = lr[0];
		S[i + 1] = lr[1];
	}
}

void ULowEntryHashingBCryptLibrary::ekskey(const TArray<uint8>& data, const TArray<uint8>& key)
{
	int32 i;
	int32 koffp[] = {0}, doffp[] = {0};
	int32 lr[] = {0, 0};
	int32 plen = P_len, slen = S_len;

	for (i = 0; i < plen; i++)
	{
		P[i] = P[i] ^ streamtoword(key, koffp);
	}

	for (i = 0; i < plen; i += 2)
	{
		lr[0] ^= streamtoword(data, doffp);
		lr[1] ^= streamtoword(data, doffp);
		encipher(lr, 0);
		P[i] = lr[0];
		P[i + 1] = lr[1];
	}

	for (i = 0; i < slen; i += 2)
	{
		lr[0] ^= streamtoword(data, doffp);
		lr[1] ^= streamtoword(data, doffp);
		encipher(lr, 0);
		S[i] = lr[0];
		S[i + 1] = lr[1];
	}
}

TArray<uint8> ULowEntryHashingBCryptLibrary::crypt_raw(const TArray<uint8>& password, const TArray<uint8>& salt, const int32 log_rounds, int32 cdata[])
{
	if ((password.Num() <= 0) || (salt.Num() != BCRYPT_SALT_LEN) || (log_rounds < 4) || (log_rounds > 30))
	{
		return TArray<uint8>();
	}

	int32 rounds, i, j;
	int32 clen = bf_crypt_ciphertext_len;
	TArray<uint8> ret;

	rounds = 1 << log_rounds;

	init_key();
	ekskey(salt, password);
	for (i = 0; i != rounds; i++)
	{
		key(password);
		key(salt);
	}

	for (i = 0; i < 64; i++)
	{
		for (j = 0; j < (clen >> 1); j++)
		{
			encipher(cdata, j << 1);
		}
	}

	ret = TArray<uint8>();
	ret.SetNum(clen * 4);
	for (i = 0, j = 0; i < clen; i++)
	{
		ret[j++] = static_cast<uint8>((cdata[i] >> 24) & 0xff);
		ret[j++] = static_cast<uint8>((cdata[i] >> 16) & 0xff);
		ret[j++] = static_cast<uint8>((cdata[i] >> 8) & 0xff);
		ret[j++] = static_cast<uint8>(cdata[i] & 0xff);
	}
	return ret;
}

TArray<uint8> ULowEntryHashingBCryptLibrary::crypt_raw(const TArray<uint8>& password, const TArray<uint8>& salt, const int32 log_rounds)
{
	int32 bf_crypt_ciphertext_clone[bf_crypt_ciphertext_len];
	for (int32 i = 0; i < bf_crypt_ciphertext_len; i++)
	{
		bf_crypt_ciphertext_clone[i] = bf_crypt_ciphertext[i];
	}
	return crypt_raw(password, salt, log_rounds, bf_crypt_ciphertext_clone);
}


TArray<uint8> ULowEntryHashingBCryptLibrary::Hash(const TArray<uint8>& Bytes, const TArray<uint8>& Salt, const int32 Strength)
{
	return ULowEntryHashingBCryptLibrary().crypt_raw(Bytes, Salt, Strength);
}
