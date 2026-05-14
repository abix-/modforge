// Address: 0x1402731e0
// Ghidra name: FUN_1402731e0
// ============ 0x1402731e0 FUN_1402731e0 (size=735) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1402731e0(undefined8 param_1,undefined8 param_2,longlong param_3,undefined8 *param_4,

                  undefined8 param_5)



{

  uint uVar1;

  byte bVar2;

  undefined8 uVar3;

  uint uVar4;

  byte bVar5;

  uint uVar6;

  undefined4 uVar7;

  undefined4 uVar8;

  float local_28 [8];

  

  uVar8 = DAT_14039ca44;

  if (*(char *)(param_3 + 0x24) != '\0') {

    uVar7 = DAT_14039ca44;

    if (*(char *)((longlong)param_4 + 0x1f) < '\0') {

      uVar7 = 0;

    }

    FUN_14015b110(param_5,param_1,0,0,-1 < *(char *)((longlong)param_4 + 0x1f),

                  (float)((*(byte *)((longlong)param_4 + 0x21) & 0xf) << 8 |

                         (uint)*(byte *)(param_4 + 4)) * _DAT_14037f260,

                  (float)((uint)*(byte *)((longlong)param_4 + 0x22) << 4 |

                         (uint)(*(byte *)((longlong)param_4 + 0x21) >> 4)) * _DAT_14037f320,uVar7);

    if (*(char *)((longlong)param_4 + 0x23) < '\0') {

      uVar8 = 0;

    }

    FUN_14015b110(param_5,param_1,0,1,-1 < *(char *)((longlong)param_4 + 0x23),

                  (float)((*(byte *)((longlong)param_4 + 0x25) & 0xf) << 8 |

                         (uint)*(byte *)((longlong)param_4 + 0x24)) * _DAT_14037f260,

                  (float)((uint)*(byte *)((longlong)param_4 + 0x26) << 4 |

                         (uint)(*(byte *)((longlong)param_4 + 0x25) >> 4)) * _DAT_14037f320,uVar8);

  }

  if (*(char *)(param_3 + 0x25) == '\0') goto LAB_14027339e;

  bVar5 = *(byte *)((longlong)param_4 + 0x1d) & 0xf;

  if (bVar5 == 0xc) goto LAB_14027339e;

  bVar2 = *(byte *)((longlong)param_4 + 0x1d) >> 4;

  if (bVar2 == 0) {

    uVar4 = 1;

LAB_14027337b:

    uVar1 = ((uint)bVar5 + (uint)bVar5 * 4) * 2 + 5;

    uVar6 = 100;

    if (uVar1 < 100) {

      uVar6 = uVar1;

    }

  }

  else {

    if (bVar2 == 1) {

      uVar4 = 3;

      goto LAB_14027337b;

    }

    if (bVar2 == 2) {

      uVar4 = 4;

      uVar6 = 100;

    }

    else {

      uVar4 = 0;

      uVar6 = uVar4;

    }

  }

  FUN_14015af40(param_1,uVar4,uVar6);

LAB_14027339e:

  FUN_1402734c0(param_1,param_2,param_3,param_4,param_5);

  if (*(char *)(param_3 + 0x18) != '\0') {

    FUN_14015aab0(param_5,param_1,2,(ushort)*(byte *)(param_4 + 5) * 0x101 + -0x8000);

  }

  if ((*(char *)(param_3 + 0x1a) != '\0') && (*(byte *)((longlong)param_4 + 0x27) < 5)) {

    FUN_14015aab0(param_5,param_1,3,

                  *(undefined2 *)

                   (&DAT_14037f2c0 + (ulonglong)*(byte *)((longlong)param_4 + 0x27) * 2));

  }

  if (*(char *)(param_3 + 0x19) != '\0') {

    local_28[1] = 0.0;

    local_28[2] = 0.0;

    local_28[0] = ((float)*(byte *)((longlong)param_4 + 0x29) / DAT_14030a2d0) * _DAT_1403553cc;

    FUN_14015afd0(param_5,param_1,1,param_5,local_28,3);

    FUN_14015ad00(param_5,param_1,10,0xf0 < *(byte *)((longlong)param_4 + 0x29));

  }

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




