// Address: 0x140146ca0
// Ghidra name: FUN_140146ca0
// ============ 0x140146ca0 FUN_140146ca0 (size=426) ============


undefined8

FUN_140146ca0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,

             int param_5,int param_6,undefined8 param_7,undefined4 param_8,char param_9)



{

  char cVar1;

  undefined4 uVar2;

  uint uVar3;

  uint uVar4;

  longlong lVar5;

  

  param_1[5] = 0;

  *(undefined8 *)(param_1 + 8) = 0;

  FUN_1402f94c0(param_1 + 0xc,0,0xf8);

  *(undefined8 *)(param_1 + 6) = param_7;

  param_1[4] = param_8;

  *(undefined **)(param_1 + 10) = &DAT_1403fbf44;

  *param_1 = 1;

  param_1[1] = param_4;

  param_1[2] = param_2;

  param_1[3] = param_3;

  if (param_9 != '\0') {

    param_1[0xc] = param_1[0xc] | 2;

  }

  lVar5 = FUN_14017a950(param_4);

  *(longlong *)(param_1 + 0xe) = lVar5;

  if (lVar5 == 0) {

LAB_140146e2b:

    FUN_140146010(param_1);

    return 0;

  }

  param_1[0x1b] = param_2;

  param_1[0x1c] = param_3;

  param_1[0x44] = 0xffffffff;

  if (param_5 == 0) {

    param_5 = FUN_14017a4b0(param_4);

  }

  param_1[0x10] = param_5;

  if (param_6 != 0) {

    uVar2 = FUN_140146bc0(param_1);

    cVar1 = FUN_1401745f0(param_6,uVar2);

    if (cVar1 == '\0') goto LAB_140146e2b;

  }

  uVar4 = param_1[1];

  if (uVar4 == 0) {

LAB_140146d8f:

    if (((uVar4 & 0xf000000) + 0xfb000000 & 0xfeffffff) != 0) {

LAB_140146dbe:

      if (uVar4 != 0) goto LAB_140146dc2;

      goto LAB_140146dd0;

    }

LAB_140146d9b:

    uVar3 = uVar4 & 0xf00000;

    if ((((uVar3 != 0x300000) && (uVar3 != 0x400000)) && (uVar3 != 0x700000)) && (uVar3 != 0x800000)

       ) goto LAB_140146dbe;

  }

  else {

    if ((uVar4 & 0xf0000000) == 0x10000000) {

      if ((uVar4 & 0xf000000) != 0x4000000) goto LAB_140146d8f;

      goto LAB_140146d9b;

    }

LAB_140146dc2:

    if ((uVar4 & 0xf0000000) != 0x10000000) goto LAB_140146e20;

LAB_140146dd0:

    uVar4 = param_1[1] & 0xf000000;

    if (((uVar4 != 0x7000000) && ((uVar4 + 0xf8000000 & 0xfcffffff) != 0)) ||

       (((uVar4 = param_1[1] & 0xf00000, uVar4 != 0x300000 &&

         ((uVar4 != 0x200000 && (uVar4 != 0x600000)))) && (uVar4 != 0x500000)))) goto LAB_140146e20;

  }

  FUN_140148450(param_1,1);

LAB_140146e20:

  param_1[8] = 1;

  return 1;

}




