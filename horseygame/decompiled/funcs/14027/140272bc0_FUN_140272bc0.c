// Address: 0x140272bc0
// Ghidra name: FUN_140272bc0
// ============ 0x140272bc0 FUN_140272bc0 (size=105) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_140272bc0(longlong param_1,int param_2,short param_3)



{

  float fVar1;

  undefined1 auVar2 [16];

  undefined1 auVar3 [16];

  

  if (*(char *)(param_1 + 0x26) == '\0') {

    fVar1 = (float)(int)param_3;

    auVar2 = ZEXT416((uint)fVar1);

    if (param_2 < 3) {

      auVar2 = ZEXT416((uint)(fVar1 * DAT_14030401c));

      goto LAB_140272c10;

    }

  }

  else {

    auVar2 = ZEXT416((uint)((float)((int)param_3 -

                                   (int)*(short *)(param_1 + 0x28 + (longlong)param_2 * 8)) *

                           *(float *)(param_1 + 0x2c + (longlong)param_2 * 8)));

    if (param_2 < 3) {

LAB_140272c10:

      auVar2._0_4_ = (auVar2._0_4_ * _DAT_14033a134 * DAT_14039ca50) / DAT_140304c34;

      return auVar2._0_8_;

    }

  }

  auVar3._4_12_ = auVar2._4_12_;

  auVar3._0_4_ = auVar2._0_4_ * DAT_14037f31c * _DAT_1403553cc;

  return auVar3._0_8_;

}




