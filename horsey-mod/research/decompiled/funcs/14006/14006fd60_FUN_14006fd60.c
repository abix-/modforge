// Address: 0x14006fd60
// Ghidra name: FUN_14006fd60
// ============ 0x14006fd60 FUN_14006fd60 (size=211) ============


void FUN_14006fd60(void)



{

  float fVar1;

  float fVar2;

  float fVar3;

  

  fVar1 = (float)DAT_14030b680;

  DAT_1403eda00 = 0;

  DAT_1403eda04 = 0;

  fVar3 = (float)DAT_14030b684;

  fVar2 = (float)DAT_1403d9e60 / (float)DAT_1403d9e64;

  if (fVar2 <= fVar1 / fVar3) {

    DAT_1403eda08 = (float)DAT_1403d9e60 / fVar1;

    if (fVar2 < fVar1 / fVar3) {

      DAT_1403eda04 = (int)((fVar1 / fVar2 - fVar3) * DAT_14039ca34);

    }

  }

  else {

    DAT_1403eda08 = (float)DAT_1403d9e64 / fVar3;

    DAT_1403eda00 = (int)((fVar3 * fVar2 - fVar1) * DAT_14039ca34);

  }

  DAT_1403ed994 = -DAT_1403eda00;

  DAT_1403d9e68 = DAT_1403eda00 + DAT_14030b680;

  DAT_1403ed998 = -DAT_1403eda04;

  DAT_1403d9e6c = DAT_1403eda04 + DAT_14030b684;

  return;

}




