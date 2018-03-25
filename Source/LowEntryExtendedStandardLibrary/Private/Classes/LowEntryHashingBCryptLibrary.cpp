// Copyright Low Entry. Apache License, Version 2.0.

#include "LowEntryHashingBCryptLibrary.h"


const int32 ULowEntryHashingBCryptLibrary::P_orig[18] = {((int32) 0x243f6a88), ((int32) 0x85a308d3), ((int32) 0x13198a2e), ((int32) 0x03707344), ((int32) 0xa4093822), ((int32) 0x299f31d0), ((int32) 0x082efa98), ((int32) 0xec4e6c89), ((int32) 0x452821e6), ((int32) 0x38d01377), ((int32) 0xbe5466cf), ((int32) 0x34e90c6c), ((int32) 0xc0ac29b7), ((int32) 0xc97c50dd), ((int32) 0x3f84d5b5), ((int32) 0xb5470917), ((int32) 0x9216d5d9), ((int32) 0x8979fb1b)};
const int32 ULowEntryHashingBCryptLibrary::S_orig[1024] = {((int32) 0xd1310ba6), ((int32) 0x98dfb5ac), ((int32) 0x2ffd72db), ((int32) 0xd01adfb7), ((int32) 0xb8e1afed), ((int32) 0x6a267e96), ((int32) 0xba7c9045), ((int32) 0xf12c7f99), ((int32) 0x24a19947), ((int32) 0xb3916cf7), ((int32) 0x0801f2e2), ((int32) 0x858efc16), ((int32) 0x636920d8), ((int32) 0x71574e69), ((int32) 0xa458fea3), ((int32) 0xf4933d7e), ((int32) 0x0d95748f), ((int32) 0x728eb658), ((int32) 0x718bcd58), ((int32) 0x82154aee), ((int32) 0x7b54a41d), ((int32) 0xc25a59b5), ((int32) 0x9c30d539), ((int32) 0x2af26013), ((int32) 0xc5d1b023), ((int32) 0x286085f0), ((int32) 0xca417918), ((int32) 0xb8db38ef), ((int32) 0x8e79dcb0), ((int32) 0x603a180e), ((int32) 0x6c9e0e8b), ((int32) 0xb01e8a3e), ((int32) 0xd71577c1), ((int32) 0xbd314b27), ((int32) 0x78af2fda), ((int32) 0x55605c60), ((int32) 0xe65525f3), ((int32) 0xaa55ab94), ((int32) 0x57489862), ((int32) 0x63e81440), ((int32) 0x55ca396a), ((int32) 0x2aab10b6), ((int32) 0xb4cc5c34), ((int32) 0x1141e8ce), ((int32) 0xa15486af), ((int32) 0x7c72e993), ((int32) 0xb3ee1411), ((int32) 0x636fbc2a), ((int32) 0x2ba9c55d), ((int32) 0x741831f6), ((int32) 0xce5c3e16), ((int32) 0x9b87931e), ((int32) 0xafd6ba33), ((int32) 0x6c24cf5c), ((int32) 0x7a325381), ((int32) 0x28958677), ((int32) 0x3b8f4898), ((int32) 0x6b4bb9af), ((int32) 0xc4bfe81b), ((int32) 0x66282193), ((int32) 0x61d809cc), ((int32) 0xfb21a991), ((int32) 0x487cac60), ((int32) 0x5dec8032), ((int32) 0xef845d5d), ((int32) 0xe98575b1), ((int32) 0xdc262302), ((int32) 0xeb651b88), ((int32) 0x23893e81), ((int32) 0xd396acc5), ((int32) 0x0f6d6ff3), ((int32) 0x83f44239), ((int32) 0x2e0b4482), ((int32) 0xa4842004), ((int32) 0x69c8f04a), ((int32) 0x9e1f9b5e), ((int32) 0x21c66842), ((int32) 0xf6e96c9a), ((int32) 0x670c9c61), ((int32) 0xabd388f0), ((int32) 0x6a51a0d2), ((int32) 0xd8542f68), ((int32) 0x960fa728), ((int32) 0xab5133a3), ((int32) 0x6eef0b6c), ((int32) 0x137a3be4), ((int32) 0xba3bf050), ((int32) 0x7efb2a98), ((int32) 0xa1f1651d), ((int32) 0x39af0176), ((int32) 0x66ca593e), ((int32) 0x82430e88), ((int32) 0x8cee8619), ((int32) 0x456f9fb4), ((int32) 0x7d84a5c3), ((int32) 0x3b8b5ebe), ((int32) 0xe06f75d8), ((int32) 0x85c12073), ((int32) 0x401a449f), ((int32) 0x56c16aa6), ((int32) 0x4ed3aa62), ((int32) 0x363f7706), ((int32) 0x1bfedf72), ((int32) 0x429b023d), ((int32) 0x37d0d724), ((int32) 0xd00a1248), ((int32) 0xdb0fead3), ((int32) 0x49f1c09b), ((int32) 0x075372c9), ((int32) 0x80991b7b), ((int32) 0x25d479d8), ((int32) 0xf6e8def7), ((int32) 0xe3fe501a), ((int32) 0xb6794c3b), ((int32) 0x976ce0bd), ((int32) 0x04c006ba), ((int32) 0xc1a94fb6), ((int32) 0x409f60c4), ((int32) 0x5e5c9ec2), ((int32) 0x196a2463), ((int32) 0x68fb6faf), ((int32) 0x3e6c53b5), ((int32) 0x1339b2eb), ((int32) 0x3b52ec6f), ((int32) 0x6dfc511f), ((int32) 0x9b30952c), ((int32) 0xcc814544), ((int32) 0xaf5ebd09), ((int32) 0xbee3d004), ((int32) 0xde334afd), ((int32) 0x660f2807), ((int32) 0x192e4bb3), ((int32) 0xc0cba857), ((int32) 0x45c8740f), ((int32) 0xd20b5f39), ((int32) 0xb9d3fbdb), ((int32) 0x5579c0bd), ((int32) 0x1a60320a), ((int32) 0xd6a100c6), ((int32) 0x402c7279), ((int32) 0x679f25fe), ((int32) 0xfb1fa3cc), ((int32) 0x8ea5e9f8), ((int32) 0xdb3222f8), ((int32) 0x3c7516df), ((int32) 0xfd616b15), ((int32) 0x2f501ec8), ((int32) 0xad0552ab), ((int32) 0x323db5fa), ((int32) 0xfd238760), ((int32) 0x53317b48), ((int32) 0x3e00df82), ((int32) 0x9e5c57bb), ((int32) 0xca6f8ca0), ((int32) 0x1a87562e), ((int32) 0xdf1769db), ((int32) 0xd542a8f6), ((int32) 0x287effc3), ((int32) 0xac6732c6), ((int32) 0x8c4f5573), ((int32) 0x695b27b0), ((int32) 0xbbca58c8), ((int32) 0xe1ffa35d), ((int32) 0xb8f011a0), ((int32) 0x10fa3d98), ((int32) 0xfd2183b8), ((int32) 0x4afcb56c), ((int32) 0x2dd1d35b), ((int32) 0x9a53e479), ((int32) 0xb6f84565), ((int32) 0xd28e49bc), ((int32) 0x4bfb9790), ((int32) 0xe1ddf2da), ((int32) 0xa4cb7e33), ((int32) 0x62fb1341), ((int32) 0xcee4c6e8), ((int32) 0xef20cada), ((int32) 0x36774c01), ((int32) 0xd07e9efe), ((int32) 0x2bf11fb4), ((int32) 0x95dbda4d), ((int32) 0xae909198), ((int32) 0xeaad8e71), ((int32) 0x6b93d5a0), ((int32) 0xd08ed1d0), ((int32) 0xafc725e0), ((int32) 0x8e3c5b2f), ((int32) 0x8e7594b7), ((int32) 0x8ff6e2fb), ((int32) 0xf2122b64), ((int32) 0x8888b812), ((int32) 0x900df01c), ((int32) 0x4fad5ea0), ((int32) 0x688fc31c), ((int32) 0xd1cff191), ((int32) 0xb3a8c1ad), ((int32) 0x2f2f2218), ((int32) 0xbe0e1777), ((int32) 0xea752dfe), ((int32) 0x8b021fa1), ((int32) 0xe5a0cc0f), ((int32) 0xb56f74e8), ((int32) 0x18acf3d6), ((int32) 0xce89e299), ((int32) 0xb4a84fe0), ((int32) 0xfd13e0b7), ((int32) 0x7cc43b81), ((int32) 0xd2ada8d9), ((int32) 0x165fa266), ((int32) 0x80957705), ((int32) 0x93cc7314), ((int32) 0x211a1477), ((int32) 0xe6ad2065), ((int32) 0x77b5fa86), ((int32) 0xc75442f5), ((int32) 0xfb9d35cf), ((int32) 0xebcdaf0c), ((int32) 0x7b3e89a0), ((int32) 0xd6411bd3), ((int32) 0xae1e7e49), ((int32) 0x00250e2d), ((int32) 0x2071b35e), ((int32) 0x226800bb), ((int32) 0x57b8e0af), ((int32) 0x2464369b), ((int32) 0xf009b91e), ((int32) 0x5563911d), ((int32) 0x59dfa6aa), ((int32) 0x78c14389), ((int32) 0xd95a537f), ((int32) 0x207d5ba2), ((int32) 0x02e5b9c5), ((int32) 0x83260376), ((int32) 0x6295cfa9), ((int32) 0x11c81968), ((int32) 0x4e734a41), ((int32) 0xb3472dca), ((int32) 0x7b14a94a), ((int32) 0x1b510052), ((int32) 0x9a532915), ((int32) 0xd60f573f), ((int32) 0xbc9bc6e4), ((int32) 0x2b60a476), ((int32) 0x81e67400), ((int32) 0x08ba6fb5), ((int32) 0x571be91f), ((int32) 0xf296ec6b), ((int32) 0x2a0dd915), ((int32) 0xb6636521), ((int32) 0xe7b9f9b6), ((int32) 0xff34052e), ((int32) 0xc5855664), ((int32) 0x53b02d5d), ((int32) 0xa99f8fa1), ((int32) 0x08ba4799), ((int32) 0x6e85076a), ((int32) 0x4b7a70e9), ((int32) 0xb5b32944), ((int32) 0xdb75092e), ((int32) 0xc4192623), ((int32) 0xad6ea6b0), ((int32) 0x49a7df7d), ((int32) 0x9cee60b8), ((int32) 0x8fedb266), ((int32) 0xecaa8c71), ((int32) 0x699a17ff), ((int32) 0x5664526c), ((int32) 0xc2b19ee1), ((int32) 0x193602a5), ((int32) 0x75094c29), ((int32) 0xa0591340), ((int32) 0xe4183a3e), ((int32) 0x3f54989a), ((int32) 0x5b429d65), ((int32) 0x6b8fe4d6), ((int32) 0x99f73fd6), ((int32) 0xa1d29c07), ((int32) 0xefe830f5), ((int32) 0x4d2d38e6), ((int32) 0xf0255dc1), ((int32) 0x4cdd2086), ((int32) 0x8470eb26), ((int32) 0x6382e9c6), ((int32) 0x021ecc5e), ((int32) 0x09686b3f), ((int32) 0x3ebaefc9), ((int32) 0x3c971814), ((int32) 0x6b6a70a1), ((int32) 0x687f3584), ((int32) 0x52a0e286), ((int32) 0xb79c5305), ((int32) 0xaa500737), ((int32) 0x3e07841c), ((int32) 0x7fdeae5c), ((int32) 0x8e7d44ec), ((int32) 0x5716f2b8), ((int32) 0xb03ada37), ((int32) 0xf0500c0d), ((int32) 0xf01c1f04), ((int32) 0x0200b3ff), ((int32) 0xae0cf51a), ((int32) 0x3cb574b2), ((int32) 0x25837a58), ((int32) 0xdc0921bd), ((int32) 0xd19113f9), ((int32) 0x7ca92ff6), ((int32) 0x94324773), ((int32) 0x22f54701), ((int32) 0x3ae5e581), ((int32) 0x37c2dadc), ((int32) 0xc8b57634), ((int32) 0x9af3dda7), ((int32) 0xa9446146), ((int32) 0x0fd0030e), ((int32) 0xecc8c73e), ((int32) 0xa4751e41), ((int32) 0xe238cd99), ((int32) 0x3bea0e2f), ((int32) 0x3280bba1), ((int32) 0x183eb331), ((int32) 0x4e548b38), ((int32) 0x4f6db908), ((int32) 0x6f420d03), ((int32) 0xf60a04bf), ((int32) 0x2cb81290), ((int32) 0x24977c79), ((int32) 0x5679b072), ((int32) 0xbcaf89af), ((int32) 0xde9a771f), ((int32) 0xd9930810), ((int32) 0xb38bae12), ((int32) 0xdccf3f2e), ((int32) 0x5512721f), ((int32) 0x2e6b7124), ((int32) 0x501adde6), ((int32) 0x9f84cd87), ((int32) 0x7a584718), ((int32) 0x7408da17), ((int32) 0xbc9f9abc), ((int32) 0xe94b7d8c), ((int32) 0xec7aec3a), ((int32) 0xdb851dfa), ((int32) 0x63094366), ((int32) 0xc464c3d2), ((int32) 0xef1c1847), ((int32) 0x3215d908), ((int32) 0xdd433b37), ((int32) 0x24c2ba16), ((int32) 0x12a14d43), ((int32) 0x2a65c451), ((int32) 0x50940002), ((int32) 0x133ae4dd), ((int32) 0x71dff89e), ((int32) 0x10314e55), ((int32) 0x81ac77d6), ((int32) 0x5f11199b), ((int32) 0x043556f1), ((int32) 0xd7a3c76b), ((int32) 0x3c11183b), ((int32) 0x5924a509), ((int32) 0xf28fe6ed), ((int32) 0x97f1fbfa), ((int32) 0x9ebabf2c), ((int32) 0x1e153c6e), ((int32) 0x86e34570), ((int32) 0xeae96fb1), ((int32) 0x860e5e0a), ((int32) 0x5a3e2ab3), ((int32) 0x771fe71c), ((int32) 0x4e3d06fa), ((int32) 0x2965dcb9), ((int32) 0x99e71d0f), ((int32) 0x803e89d6), ((int32) 0x5266c825), ((int32) 0x2e4cc978), ((int32) 0x9c10b36a), ((int32) 0xc6150eba), ((int32) 0x94e2ea78), ((int32) 0xa5fc3c53), ((int32) 0x1e0a2df4), ((int32) 0xf2f74ea7), ((int32) 0x361d2b3d), ((int32) 0x1939260f), ((int32) 0x19c27960), ((int32) 0x5223a708), ((int32) 0xf71312b6), ((int32) 0xebadfe6e), ((int32) 0xeac31f66), ((int32) 0xe3bc4595), ((int32) 0xa67bc883), ((int32) 0xb17f37d1), ((int32) 0x018cff28), ((int32) 0xc332ddef), ((int32) 0xbe6c5aa5), ((int32) 0x65582185), ((int32) 0x68ab9802), ((int32) 0xeecea50f), ((int32) 0xdb2f953b), ((int32) 0x2aef7dad), ((int32) 0x5b6e2f84), ((int32) 0x1521b628), ((int32) 0x29076170), ((int32) 0xecdd4775), ((int32) 0x619f1510), ((int32) 0x13cca830), ((int32) 0xeb61bd96), ((int32) 0x0334fe1e), ((int32) 0xaa0363cf), ((int32) 0xb5735c90), ((int32) 0x4c70a239), ((int32) 0xd59e9e0b), ((int32) 0xcbaade14), ((int32) 0xeecc86bc), ((int32) 0x60622ca7), ((int32) 0x9cab5cab), ((int32) 0xb2f3846e), ((int32) 0x648b1eaf), ((int32) 0x19bdf0ca), ((int32) 0xa02369b9), ((int32) 0x655abb50), ((int32) 0x40685a32), ((int32) 0x3c2ab4b3), ((int32) 0x319ee9d5), ((int32) 0xc021b8f7), ((int32) 0x9b540b19), ((int32) 0x875fa099), ((int32) 0x95f7997e), ((int32) 0x623d7da8), ((int32) 0xf837889a), ((int32) 0x97e32d77), ((int32) 0x11ed935f), ((int32) 0x16681281), ((int32) 0x0e358829), ((int32) 0xc7e61fd6), ((int32) 0x96dedfa1), ((int32) 0x7858ba99), ((int32) 0x57f584a5), ((int32) 0x1b227263), ((int32) 0x9b83c3ff), ((int32) 0x1ac24696), ((int32) 0xcdb30aeb), ((int32) 0x532e3054), ((int32) 0x8fd948e4), ((int32) 0x6dbc3128), ((int32) 0x58ebf2ef), ((int32) 0x34c6ffea), ((int32) 0xfe28ed61), ((int32) 0xee7c3c73), ((int32) 0x5d4a14d9), ((int32) 0xe864b7e3), ((int32) 0x42105d14), ((int32) 0x203e13e0), ((int32) 0x45eee2b6), ((int32) 0xa3aaabea), ((int32) 0xdb6c4f15), ((int32) 0xfacb4fd0), ((int32) 0xc742f442), ((int32) 0xef6abbb5), ((int32) 0x654f3b1d), ((int32) 0x41cd2105), ((int32) 0xd81e799e), ((int32) 0x86854dc7), ((int32) 0xe44b476a), ((int32) 0x3d816250), ((int32) 0xcf62a1f2), ((int32) 0x5b8d2646), ((int32) 0xfc8883a0), ((int32) 0xc1c7b6a3), ((int32) 0x7f1524c3), ((int32) 0x69cb7492), ((int32) 0x47848a0b), ((int32) 0x5692b285), ((int32) 0x095bbf00), ((int32) 0xad19489d), ((int32) 0x1462b174), ((int32) 0x23820e00), ((int32) 0x58428d2a), ((int32) 0x0c55f5ea), ((int32) 0x1dadf43e), ((int32) 0x233f7061), ((int32) 0x3372f092), ((int32) 0x8d937e41), ((int32) 0xd65fecf1), ((int32) 0x6c223bdb), ((int32) 0x7cde3759), ((int32) 0xcbee7460), ((int32) 0x4085f2a7), ((int32) 0xce77326e), ((int32) 0xa6078084), ((int32) 0x19f8509e), ((int32) 0xe8efd855), ((int32) 0x61d99735), ((int32) 0xa969a7aa), ((int32) 0xc50c06c2), ((int32) 0x5a04abfc), ((int32) 0x800bcadc), ((int32) 0x9e447a2e), ((int32) 0xc3453484), ((int32) 0xfdd56705), ((int32) 0x0e1e9ec9), ((int32) 0xdb73dbd3), ((int32) 0x105588cd), ((int32) 0x675fda79), ((int32) 0xe3674340), ((int32) 0xc5c43465), ((int32) 0x713e38d8), ((int32) 0x3d28f89e), ((int32) 0xf16dff20), ((int32) 0x153e21e7), ((int32) 0x8fb03d4a), ((int32) 0xe6e39f2b), ((int32) 0xdb83adf7), ((int32) 0xe93d5a68), ((int32) 0x948140f7), ((int32) 0xf64c261c), ((int32) 0x94692934), ((int32) 0x411520f7), ((int32) 0x7602d4f7), ((int32) 0xbcf46b2e), ((int32) 0xd4a20068), ((int32) 0xd4082471), ((int32) 0x3320f46a), ((int32) 0x43b7d4b7), ((int32) 0x500061af), ((int32) 0x1e39f62e), ((int32) 0x97244546), ((int32) 0x14214f74), ((int32) 0xbf8b8840), ((int32) 0x4d95fc1d), ((int32) 0x96b591af), ((int32) 0x70f4ddd3), ((int32) 0x66a02f45), ((int32) 0xbfbc09ec), ((int32) 0x03bd9785), ((int32) 0x7fac6dd0), ((int32) 0x31cb8504), ((int32) 0x96eb27b3), ((int32) 0x55fd3941), ((int32) 0xda2547e6), ((int32) 0xabca0a9a), ((int32) 0x28507825), ((int32) 0x530429f4), ((int32) 0x0a2c86da), ((int32) 0xe9b66dfb), ((int32) 0x68dc1462), ((int32) 0xd7486900), ((int32) 0x680ec0a4), ((int32) 0x27a18dee), ((int32) 0x4f3ffea2), ((int32) 0xe887ad8c), ((int32) 0xb58ce006), ((int32) 0x7af4d6b6), ((int32) 0xaace1e7c), ((int32) 0xd3375fec), ((int32) 0xce78a399), ((int32) 0x406b2a42), ((int32) 0x20fe9e35), ((int32) 0xd9f385b9), ((int32) 0xee39d7ab), ((int32) 0x3b124e8b), ((int32) 0x1dc9faf7), ((int32) 0x4b6d1856), ((int32) 0x26a36631), ((int32) 0xeae397b2), ((int32) 0x3a6efa74), ((int32) 0xdd5b4332), ((int32) 0x6841e7f7), ((int32) 0xca7820fb), ((int32) 0xfb0af54e), ((int32) 0xd8feb397), ((int32) 0x454056ac), ((int32) 0xba489527), ((int32) 0x55533a3a), ((int32) 0x20838d87), ((int32) 0xfe6ba9b7), ((int32) 0xd096954b), ((int32) 0x55a867bc), ((int32) 0xa1159a58), ((int32) 0xcca92963), ((int32) 0x99e1db33), ((int32) 0xa62a4a56), ((int32) 0x3f3125f9), ((int32) 0x5ef47e1c), ((int32) 0x9029317c), ((int32) 0xfdf8e802), ((int32) 0x04272f70), ((int32) 0x80bb155c), ((int32) 0x05282ce3), ((int32) 0x95c11548), ((int32) 0xe4c66d22), ((int32) 0x48c1133f), ((int32) 0xc70f86dc), ((int32) 0x07f9c9ee), ((int32) 0x41041f0f), ((int32) 0x404779a4), ((int32) 0x5d886e17), ((int32) 0x325f51eb), ((int32) 0xd59bc0d1), ((int32) 0xf2bcc18f), ((int32) 0x41113564), ((int32) 0x257b7834), ((int32) 0x602a9c60), ((int32) 0xdff8e8a3), ((int32) 0x1f636c1b), ((int32) 0x0e12b4c2), ((int32) 0x02e1329e), ((int32) 0xaf664fd1), ((int32) 0xcad18115), ((int32) 0x6b2395e0), ((int32) 0x333e92e1), ((int32) 0x3b240b62), ((int32) 0xeebeb922), ((int32) 0x85b2a20e), ((int32) 0xe6ba0d99), ((int32) 0xde720c8c), ((int32) 0x2da2f728), ((int32) 0xd0127845), ((int32) 0x95b794fd), ((int32) 0x647d0862), ((int32) 0xe7ccf5f0), ((int32) 0x5449a36f), ((int32) 0x877d48fa), ((int32) 0xc39dfd27), ((int32) 0xf33e8d1e), ((int32) 0x0a476341), ((int32) 0x992eff74), ((int32) 0x3a6f6eab), ((int32) 0xf4f8fd37), ((int32) 0xa812dc60), ((int32) 0xa1ebddf8), ((int32) 0x991be14c), ((int32) 0xdb6e6b0d), ((int32) 0xc67b5510), ((int32) 0x6d672c37), ((int32) 0x2765d43b), ((int32) 0xdcd0e804), ((int32) 0xf1290dc7), ((int32) 0xcc00ffa3), ((int32) 0xb5390f92), ((int32) 0x690fed0b), ((int32) 0x667b9ffb), ((int32) 0xcedb7d9c), ((int32) 0xa091cf0b), ((int32) 0xd9155ea3), ((int32) 0xbb132f88), ((int32) 0x515bad24), ((int32) 0x7b9479bf), ((int32) 0x763bd6eb), ((int32) 0x37392eb3), ((int32) 0xcc115979), ((int32) 0x8026e297), ((int32) 0xf42e312d), ((int32) 0x6842ada7), ((int32) 0xc66a2b3b), ((int32) 0x12754ccc), ((int32) 0x782ef11c), ((int32) 0x6a124237), ((int32) 0xb79251e7), ((int32) 0x06a1bbe6), ((int32) 0x4bfb6350), ((int32) 0x1a6b1018), ((int32) 0x11caedfa), ((int32) 0x3d25bdd8), ((int32) 0xe2e1c3c9), ((int32) 0x44421659), ((int32) 0x0a121386), ((int32) 0xd90cec6e), ((int32) 0xd5abea2a), ((int32) 0x64af674e), ((int32) 0xda86a85f), ((int32) 0xbebfe988), ((int32) 0x64e4c3fe), ((int32) 0x9dbc8057), ((int32) 0xf0f7c086), ((int32) 0x60787bf8), ((int32) 0x6003604d), ((int32) 0xd1fd8346), ((int32) 0xf6381fb0), ((int32) 0x7745ae04), ((int32) 0xd736fccc), ((int32) 0x83426b33), ((int32) 0xf01eab71), ((int32) 0xb0804187), ((int32) 0x3c005e5f), ((int32) 0x77a057be), ((int32) 0xbde8ae24), ((int32) 0x55464299), ((int32) 0xbf582e61), ((int32) 0x4e58f48f), ((int32) 0xf2ddfda2), ((int32) 0xf474ef38), ((int32) 0x8789bdc2), ((int32) 0x5366f9c3), ((int32) 0xc8b38e74), ((int32) 0xb475f255), ((int32) 0x46fcd9b9), ((int32) 0x7aeb2661), ((int32) 0x8b1ddf84), ((int32) 0x846a0e79), ((int32) 0x915f95e2), ((int32) 0x466e598e), ((int32) 0x20b45770), ((int32) 0x8cd55591), ((int32) 0xc902de4c), ((int32) 0xb90bace1), ((int32) 0xbb8205d0), ((int32) 0x11a86248), ((int32) 0x7574a99e), ((int32) 0xb77f19b6), ((int32) 0xe0a9dc09), ((int32) 0x662d09a1), ((int32) 0xc4324633), ((int32) 0xe85a1f02), ((int32) 0x09f0be8c), ((int32) 0x4a99a025), ((int32) 0x1d6efe10), ((int32) 0x1ab93d1d), ((int32) 0x0ba5a4df), ((int32) 0xa186f20f), ((int32) 0x2868f169), ((int32) 0xdcb7da83), ((int32) 0x573906fe), ((int32) 0xa1e2ce9b), ((int32) 0x4fcd7f52), ((int32) 0x50115e01), ((int32) 0xa70683fa), ((int32) 0xa002b5c4), ((int32) 0x0de6d027), ((int32) 0x9af88c27), ((int32) 0x773f8641), ((int32) 0xc3604c06), ((int32) 0x61a806b5), ((int32) 0xf0177a28), ((int32) 0xc0f586e0), ((int32) 0x006058aa), ((int32) 0x30dc7d62), ((int32) 0x11e69ed7), ((int32) 0x2338ea63), ((int32) 0x53c2dd94), ((int32) 0xc2c21634), ((int32) 0xbbcbee56), ((int32) 0x90bcb6de), ((int32) 0xebfc7da1), ((int32) 0xce591d76), ((int32) 0x6f05e409), ((int32) 0x4b7c0188), ((int32) 0x39720a3d), ((int32) 0x7c927c24), ((int32) 0x86e3725f), ((int32) 0x724d9db9), ((int32) 0x1ac15bb4), ((int32) 0xd39eb8fc), ((int32) 0xed545578), ((int32) 0x08fca5b5), ((int32) 0xd83d7cd3), ((int32) 0x4dad0fc4), ((int32) 0x1e50ef5e), ((int32) 0xb161e6f8), ((int32) 0xa28514d9), ((int32) 0x6c51133c), ((int32) 0x6fd5c7e7), ((int32) 0x56e14ec4), ((int32) 0x362abfce), ((int32) 0xddc6c837), ((int32) 0xd79a3234), ((int32) 0x92638212), ((int32) 0x670efa8e), ((int32) 0x406000e0), ((int32) 0x3a39ce37), ((int32) 0xd3faf5cf), ((int32) 0xabc27737), ((int32) 0x5ac52d1b), ((int32) 0x5cb0679e), ((int32) 0x4fa33742), ((int32) 0xd3822740), ((int32) 0x99bc9bbe), ((int32) 0xd5118e9d), ((int32) 0xbf0f7315), ((int32) 0xd62d1c7e), ((int32) 0xc700c47b), ((int32) 0xb78c1b6b), ((int32) 0x21a19045), ((int32) 0xb26eb1be), ((int32) 0x6a366eb4), ((int32) 0x5748ab2f), ((int32) 0xbc946e79), ((int32) 0xc6a376d2), ((int32) 0x6549c2c8), ((int32) 0x530ff8ee), ((int32) 0x468dde7d), ((int32) 0xd5730a1d), ((int32) 0x4cd04dc6), ((int32) 0x2939bbdb), ((int32) 0xa9ba4650), ((int32) 0xac9526e8), ((int32) 0xbe5ee304), ((int32) 0xa1fad5f0), ((int32) 0x6a2d519a), ((int32) 0x63ef8ce2), ((int32) 0x9a86ee22), ((int32) 0xc089c2b8), ((int32) 0x43242ef6), ((int32) 0xa51e03aa), ((int32) 0x9cf2d0a4), ((int32) 0x83c061ba), ((int32) 0x9be96a4d), ((int32) 0x8fe51550), ((int32) 0xba645bd6), ((int32) 0x2826a2f9), ((int32) 0xa73a3ae1), ((int32) 0x4ba99586), ((int32) 0xef5562e9), ((int32) 0xc72fefd3), ((int32) 0xf752f7da), ((int32) 0x3f046f69), ((int32) 0x77fa0a59), ((int32) 0x80e4a915), ((int32) 0x87b08601), ((int32) 0x9b09e6ad), ((int32) 0x3b3ee593), ((int32) 0xe990fd5a), ((int32) 0x9e34d797), ((int32) 0x2cf0b7d9), ((int32) 0x022b8b51), ((int32) 0x96d5ac3a), ((int32) 0x017da67d), ((int32) 0xd1cf3ed6), ((int32) 0x7c7d2d28), ((int32) 0x1f9f25cf), ((int32) 0xadf2b89b), ((int32) 0x5ad6b472), ((int32) 0x5a88f54c), ((int32) 0xe029ac71), ((int32) 0xe019a5e6), ((int32) 0x47b0acfd), ((int32) 0xed93fa9b), ((int32) 0xe8d3c48d), ((int32) 0x283b57cc), ((int32) 0xf8d56629), ((int32) 0x79132e28), ((int32) 0x785f0191), ((int32) 0xed756055), ((int32) 0xf7960e44), ((int32) 0xe3d35e8c), ((int32) 0x15056dd4), ((int32) 0x88f46dba), ((int32) 0x03a16125), ((int32) 0x0564f0bd), ((int32) 0xc3eb9e15), ((int32) 0x3c9057a2), ((int32) 0x97271aec), ((int32) 0xa93a072a), ((int32) 0x1b3f6d9b), ((int32) 0x1e6321f5), ((int32) 0xf59c66fb), ((int32) 0x26dcf319), ((int32) 0x7533d928), ((int32) 0xb155fdf5), ((int32) 0x03563482), ((int32) 0x8aba3cbb), ((int32) 0x28517711), ((int32) 0xc20ad9f8), ((int32) 0xabcc5167), ((int32) 0xccad925f), ((int32) 0x4de81751), ((int32) 0x3830dc8e), ((int32) 0x379d5862), ((int32) 0x9320f991), ((int32) 0xea7a90c2), ((int32) 0xfb3e7bce), ((int32) 0x5121ce64), ((int32) 0x774fbe32), ((int32) 0xa8b6e37e), ((int32) 0xc3293d46), ((int32) 0x48de5369), ((int32) 0x6413e680), ((int32) 0xa2ae0810), ((int32) 0xdd6db224), ((int32) 0x69852dfd), ((int32) 0x09072166), ((int32) 0xb39a460a), ((int32) 0x6445c0dd), ((int32) 0x586cdecf), ((int32) 0x1c20c8ae), ((int32) 0x5bbef7dd), ((int32) 0x1b588d40), ((int32) 0xccd2017f), ((int32) 0x6bb4e3bb), ((int32) 0xdda26a7e), ((int32) 0x3a59ff45), ((int32) 0x3e350a44), ((int32) 0xbcb4cdd5), ((int32) 0x72eacea8), ((int32) 0xfa6484bb), ((int32) 0x8d6612ae), ((int32) 0xbf3c6f47), ((int32) 0xd29be463), ((int32) 0x542f5d9e), ((int32) 0xaec2771b), ((int32) 0xf64e6370), ((int32) 0x740e0d8d), ((int32) 0xe75b1357), ((int32) 0xf8721671), ((int32) 0xaf537d5d), ((int32) 0x4040cb08), ((int32) 0x4eb4e2cc), ((int32) 0x34d2466a), ((int32) 0x0115af84), ((int32) 0xe1b00428), ((int32) 0x95983a1d), ((int32) 0x06b89fb4), ((int32) 0xce6ea048), ((int32) 0x6f3f3b82), ((int32) 0x3520ab82), ((int32) 0x011a1d4b), ((int32) 0x277227f8), ((int32) 0x611560b1), ((int32) 0xe7933fdc), ((int32) 0xbb3a792b), ((int32) 0x344525bd), ((int32) 0xa08839e1), ((int32) 0x51ce794b), ((int32) 0x2f32c9b7), ((int32) 0xa01fbac9), ((int32) 0xe01cc87e), ((int32) 0xbcc7d1f6), ((int32) 0xcf0111c3), ((int32) 0xa1e8aac7), ((int32) 0x1a908749), ((int32) 0xd44fbd9a), ((int32) 0xd0dadecb), ((int32) 0xd50ada38), ((int32) 0x0339c32a), ((int32) 0xc6913667), ((int32) 0x8df9317c), ((int32) 0xe0b12b4f), ((int32) 0xf79e59b7), ((int32) 0x43f5bb3a), ((int32) 0xf2d519ff), ((int32) 0x27d9459c), ((int32) 0xbf97222c), ((int32) 0x15e6fc2a), ((int32) 0x0f91fc71), ((int32) 0x9b941525), ((int32) 0xfae59361), ((int32) 0xceb69ceb), ((int32) 0xc2a86459), ((int32) 0x12baa8d1), ((int32) 0xb6c1075e), ((int32) 0xe3056a0c), ((int32) 0x10d25065), ((int32) 0xcb03a442), ((int32) 0xe0ec6e0e), ((int32) 0x1698db3b), ((int32) 0x4c98a0be), ((int32) 0x3278e964), ((int32) 0x9f1f9532), ((int32) 0xe0d392df), ((int32) 0xd3a0342b), ((int32) 0x8971f21e), ((int32) 0x1b0a7441), ((int32) 0x4ba3348c), ((int32) 0xc5be7120), ((int32) 0xc37632d8), ((int32) 0xdf359f8d), ((int32) 0x9b992f2e), ((int32) 0xe60b6f47), ((int32) 0x0fe3f11d), ((int32) 0xe54cda54), ((int32) 0x1edad891), ((int32) 0xce6279cf), ((int32) 0xcd3e7e6f), ((int32) 0x1618b166), ((int32) 0xfd2c1d05), ((int32) 0x848fd2c5), ((int32) 0xf6fb2299), ((int32) 0xf523f357), ((int32) 0xa6327623), ((int32) 0x93a83531), ((int32) 0x56cccd02), ((int32) 0xacf08162), ((int32) 0x5a75ebb5), ((int32) 0x6e163697), ((int32) 0x88d273cc), ((int32) 0xde966292), ((int32) 0x81b949d0), ((int32) 0x4c50901b), ((int32) 0x71c65614), ((int32) 0xe6c6c7bd), ((int32) 0x327a140a), ((int32) 0x45e1d006), ((int32) 0xc3f27b9a), ((int32) 0xc9aa53fd), ((int32) 0x62a80f00), ((int32) 0xbb25bfe2), ((int32) 0x35bdd2f6), ((int32) 0x71126905), ((int32) 0xb2040222), ((int32) 0xb6cbcf7c), ((int32) 0xcd769c2b), ((int32) 0x53113ec0), ((int32) 0x1640e3d3), ((int32) 0x38abbd60), ((int32) 0x2547adf0), ((int32) 0xba38209c), ((int32) 0xf746ce76), ((int32) 0x77afa1c5), ((int32) 0x20756060), ((int32) 0x85cbfe4e), ((int32) 0x8ae88dd8), ((int32) 0x7aaaf9b0), ((int32) 0x4cf9aa7e), ((int32) 0x1948c25c), ((int32) 0x02fb8a8c), ((int32) 0x01c36ae4), ((int32) 0xd6ebe1f9), ((int32) 0x90d4f869), ((int32) 0xa65cdea0), ((int32) 0x3f09252d), ((int32) 0xc208e69f), ((int32) 0xb74e6132), ((int32) 0xce77e25b), ((int32) 0x578fdfe3), ((int32) 0x3ac372e6)};
const int32 ULowEntryHashingBCryptLibrary::bf_crypt_ciphertext[6] = {((int32) 0x4f727068), ((int32) 0x65616e42), ((int32) 0x65686f6c), ((int32) 0x64657253), ((int32) 0x63727944), ((int32) 0x6f756274)};


void ULowEntryHashingBCryptLibrary::encipher(int32 lr[], const int32 off)
{
	int32 i, n, l = lr[off], r = lr[off + 1];

	l ^= P[0];
	for(i = 0; i <= (BLOWFISH_NUM_ROUNDS - 2);)
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

	for(i = 0; i < 4; i++)
	{
		word = (word << 8) | (data[off] & 0xff);
		off = (off + 1) % data.Num();
	}

	offp[0] = off;
	return word;
}

void ULowEntryHashingBCryptLibrary::init_key()
{
	for(int32 i = 0; i < P_len; i++)
	{
		P[i] = P_orig[i];
	}
	for(int32 i = 0; i < S_len; i++)
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

	for(i = 0; i < plen; i++)
	{
		P[i] = P[i] ^ streamtoword(key, koffp);
	}

	for(i = 0; i < plen; i += 2)
	{
		encipher(lr, 0);
		P[i] = lr[0];
		P[i + 1] = lr[1];
	}

	for(i = 0; i < slen; i += 2)
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

	for(i = 0; i < plen; i++)
	{
		P[i] = P[i] ^ streamtoword(key, koffp);
	}

	for(i = 0; i < plen; i += 2)
	{
		lr[0] ^= streamtoword(data, doffp);
		lr[1] ^= streamtoword(data, doffp);
		encipher(lr, 0);
		P[i] = lr[0];
		P[i + 1] = lr[1];
	}

	for(i = 0; i < slen; i += 2)
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
	if((password.Num() <= 0) || (salt.Num() != BCRYPT_SALT_LEN) || (log_rounds < 4) || (log_rounds > 30))
	{
		return TArray<uint8>();
	}

	int32 rounds, i, j;
	int32 clen = bf_crypt_ciphertext_len;
	TArray<uint8> ret;

	rounds = 1 << log_rounds;

	init_key();
	ekskey(salt, password);
	for(i = 0; i != rounds; i++)
	{
		key(password);
		key(salt);
	}

	for(i = 0; i < 64; i++)
	{
		for(j = 0; j < (clen >> 1); j++)
		{
			encipher(cdata, j << 1);
		}
	}

	ret = TArray<uint8>();
	ret.SetNum(clen * 4);
	for(i = 0, j = 0; i < clen; i++)
	{
		ret[j++] = (uint8) ((cdata[i] >> 24) & 0xff);
		ret[j++] = (uint8) ((cdata[i] >> 16) & 0xff);
		ret[j++] = (uint8) ((cdata[i] >> 8) & 0xff);
		ret[j++] = (uint8) (cdata[i] & 0xff);
	}
	return ret;
}

TArray<uint8> ULowEntryHashingBCryptLibrary::crypt_raw(const TArray<uint8>& password, const TArray<uint8>& salt, const int32 log_rounds)
{
	int32 bf_crypt_ciphertext_clone[bf_crypt_ciphertext_len];
	for(int32 i = 0; i < bf_crypt_ciphertext_len; i++)
	{
		bf_crypt_ciphertext_clone[i] = bf_crypt_ciphertext[i];
	}
	return crypt_raw(password, salt, log_rounds, bf_crypt_ciphertext_clone);
}


TArray<uint8> ULowEntryHashingBCryptLibrary::Hash(const TArray<uint8>& Bytes, const TArray<uint8>& Salt, const int32 Strength)
{
	return ULowEntryHashingBCryptLibrary().crypt_raw(Bytes, Salt, Strength);
}
