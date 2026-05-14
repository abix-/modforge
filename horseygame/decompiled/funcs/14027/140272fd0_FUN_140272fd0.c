// Address: 0x140272fd0
// Ghidra name: FUN_140272fd0
// ============ 0x140272fd0 FUN_140272fd0 (size=524) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140272fd0(undefined8 param_1,undefined8 param_2,longlong param_3,undefined8 *param_4,

                  undefined8 param_5)



{

  uint uVar1;

  byte bVar2;

  undefined8 uVar3;

  byte bVar4;

  undefined4 uVar5;

  uint uVar6;

  undefined4 uVar7;

  undefined4 uVar8;

  

  uVar8 = DAT_14039ca44;

  uVar5 = 1;

  if (*(char *)(param_3 + 0x24) != '\0') {

    uVar7 = DAT_14039ca44;

    if (*(char *)(param_4 + 4) < '\0') {

      uVar7 = 0;

    }

    FUN_14015b110(param_5,param_1,0,0,-1 < *(char *)(param_4 + 4),

                  (float)((*(byte *)((longlong)param_4 + 0x22) & 0xf) << 8 |

                         (uint)*(byte *)((longlong)param_4 + 0x21)) * _DAT_14037f260,

                  (float)((uint)*(byte *)((longlong)param_4 + 0x23) << 4 |

                         (uint)(*(byte *)((longlong)param_4 + 0x22) >> 4)) * _DAT_14037f320,uVar7);

    if (*(char *)((longlong)param_4 + 0x24) < '\0') {

      uVar8 = 0;

    }

    FUN_14015b110(param_5,param_1,0,1,-1 < *(char *)((longlong)param_4 + 0x24),

                  (float)((*(byte *)((longlong)param_4 + 0x26) & 0xf) << 8 |

                         (uint)*(byte *)((longlong)param_4 + 0x25)) * _DAT_14037f260,

                  (float)((uint)*(byte *)((longlong)param_4 + 0x27) << 4 |

                         (uint)(*(byte *)((longlong)param_4 + 0x26) >> 4)) * _DAT_14037f320,uVar8);

  }

  if (*(char *)(param_3 + 0x25) == '\0') goto LAB_14027317f;

  bVar2 = *(byte *)((longlong)param_4 + 0x34) >> 4;

  bVar4 = *(byte *)((longlong)param_4 + 0x34) & 0xf;

  if (bVar2 == 0) {

LAB_14027315b:

    uVar1 = ((uint)bVar4 + (uint)bVar4 * 4) * 2 + 5;

    uVar6 = 100;

    if (uVar1 < 100) {

      uVar6 = uVar1;

    }

  }

  else {

    if (bVar2 == 1) {

      uVar5 = 3;

      goto LAB_14027315b;

    }

    if (bVar2 == 2) {

      uVar5 = 4;

      uVar6 = 100;

    }

    else {

      uVar5 = 0;

      uVar6 = 0;

    }

  }

  FUN_14015af40(param_1,uVar5,uVar6);

LAB_14027317f:

  FUN_1402734c0(param_1,param_2,param_3,param_4,param_5);

  uVar3 = param_4[1];

  *(undefined8 *)(param_3 + 0x84) = *param_4;

  *(undefined8 *)(param_3 + 0x8c) = uVar3;

  uVar3 = param_4[3];

  *(undefined8 *)(param_3 + 0x94) = param_4[2];

  *(undefined8 *)(param_3 + 0x9c) = uVar3;

  uVar3 = param_4[5];

  *(undefined8 *)(param_3 + 0xa4) = param_4[4];

  *(undefined8 *)(param_3 + 0xac) = uVar3;

  uVar3 = param_4[7];

  *(undefined8 *)(param_3 + 0xb4) = param_4[6];

  *(undefined8 *)(param_3 + 0xbc) = uVar3;

  return;

}




