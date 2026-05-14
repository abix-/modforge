// Address: 0x140263e00
// Ghidra name: FUN_140263e00
// ============ 0x140263e00 FUN_140263e00 (size=1023) ============


void FUN_140263e00(undefined8 param_1,longlong param_2,undefined8 param_3,byte *param_4,char param_5

                  )



{

  undefined8 uVar1;

  longlong lVar2;

  byte bVar3;

  float fVar4;

  undefined4 uVar5;

  undefined4 uVar6;

  

  uVar1 = FUN_140149300();

  lVar2 = FUN_1401581c0(*(undefined4 *)(param_2 + 4));

  if (lVar2 != 0) {

    FUN_14015ad00(uVar1,lVar2,0,*param_4 >> 1 & 1);

    FUN_14015ad00(uVar1,lVar2,1,*param_4 >> 2 & 1);

    FUN_14015ad00(uVar1,lVar2,3,*param_4 >> 3 & 1);

    FUN_14015ad00(uVar1,lVar2,2,*param_4 & 1);

    FUN_14015ad00(uVar1,lVar2,4,param_4[1] >> 7);

    FUN_14015ad00(uVar1,lVar2,5,param_4[1] >> 5 & 1);

    FUN_14015ad00(uVar1,lVar2,6,param_4[1] >> 6 & 1);

    FUN_14015ad00(uVar1,lVar2,7,param_4[1] >> 4 & 1);

    FUN_14015ad00(uVar1,lVar2,8,param_4[1] >> 1 & 1);

    FUN_14015ad00(uVar1,lVar2,9,*param_4 >> 7);

    FUN_14015ad00(uVar1,lVar2,10,*param_4 >> 5 & 1);

    FUN_14015ad00(uVar1,lVar2,0xb,*param_4 >> 4 & 1);

    bVar3 = param_4[2];

    if (bVar3 < *(byte *)(param_2 + 0x18)) {

      *(byte *)(param_2 + 0x18) = bVar3;

    }

    if (*(byte *)(param_2 + 0x30) < bVar3) {

      *(byte *)(param_2 + 0x30) = bVar3;

    }

    uVar6 = DAT_1403053f0;

    uVar5 = DAT_1403053f0;

    fVar4 = (float)FUN_140208370();

    FUN_14015aab0(uVar1,lVar2,0,(int)fVar4,uVar5);

    bVar3 = ~param_4[3];

    if (bVar3 < *(byte *)(param_2 + 0x19)) {

      *(byte *)(param_2 + 0x19) = bVar3;

    }

    if (*(byte *)(param_2 + 0x31) < bVar3) {

      *(byte *)(param_2 + 0x31) = bVar3;

    }

    uVar5 = uVar6;

    fVar4 = (float)FUN_140208370();

    FUN_14015aab0(uVar1,lVar2,1,(int)fVar4,uVar5);

    bVar3 = ~param_4[5];

    if (param_5 == '\0') {

      bVar3 = param_4[5];

    }

    if (bVar3 < *(byte *)(param_2 + 0x1a)) {

      *(byte *)(param_2 + 0x1a) = bVar3;

    }

    if (*(byte *)(param_2 + 0x32) < bVar3) {

      *(byte *)(param_2 + 0x32) = bVar3;

    }

    uVar5 = uVar6;

    fVar4 = (float)FUN_140208370();

    FUN_14015aab0(uVar1,lVar2,2,(int)fVar4,uVar5);

    bVar3 = ~param_4[4];

    if (param_5 != '\0') {

      bVar3 = param_4[4];

    }

    if (bVar3 < *(byte *)(param_2 + 0x1b)) {

      *(byte *)(param_2 + 0x1b) = bVar3;

    }

    if (*(byte *)(param_2 + 0x33) < bVar3) {

      *(byte *)(param_2 + 0x33) = bVar3;

    }

    uVar5 = uVar6;

    fVar4 = (float)FUN_140208370();

    FUN_14015aab0(uVar1,lVar2,3,(int)fVar4,uVar5);

    bVar3 = param_4[6];

    if (bVar3 < *(byte *)(param_2 + 0x1c)) {

      *(byte *)(param_2 + 0x1c) = bVar3;

    }

    if (*(byte *)(param_2 + 0x34) < bVar3) {

      *(byte *)(param_2 + 0x34) = bVar3;

    }

    uVar5 = uVar6;

    fVar4 = (float)FUN_140208370();

    FUN_14015aab0(uVar1,lVar2,4,(int)fVar4,uVar5);

    bVar3 = param_4[7];

    if (bVar3 < *(byte *)(param_2 + 0x1d)) {

      *(byte *)(param_2 + 0x1d) = bVar3;

    }

    if (*(byte *)(param_2 + 0x35) < bVar3) {

      *(byte *)(param_2 + 0x35) = bVar3;

    }

    fVar4 = (float)FUN_140208370();

    FUN_14015aab0(uVar1,lVar2,5,(int)fVar4,uVar6);

  }

  return;

}




