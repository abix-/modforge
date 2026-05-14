// Address: 0x1401015f0
// Ghidra name: FUN_1401015f0
// ============ 0x1401015f0 FUN_1401015f0 (size=459) ============


undefined8

FUN_1401015f0(longlong param_1,int param_2,int param_3,int param_4,int param_5,uint param_6)



{

  longlong lVar1;

  int iVar2;

  longlong lVar3;

  longlong lVar4;

  undefined8 uVar5;

  

  lVar1 = *(longlong *)(param_1 + 0x270);

  lVar3 = (longlong)(*(int *)(param_1 + 0x278) * param_5 + param_4);

  lVar4 = (longlong)(param_2 + *(int *)(param_1 + 0x278) * param_3);

  if (param_2 < param_4) {

    if (*(char *)(lVar1 + 0xd + lVar3 * 0x28) != '\0') {

      if ((param_6 & 4) != 0) {

        return 1;

      }

      if ((param_6 & 8) != 0) {

        iVar2 = FUN_1400c6580(4);

        if (0 < iVar2) {

          return 1;

        }

        *(undefined1 *)(lVar1 + 0xd + lVar3 * 0x28) = 0;

LAB_1401016ce:

        FUN_140101300(param_1);

      }

    }

  }

  else if ((param_4 < param_2) && (*(char *)(lVar1 + 0xd + lVar4 * 0x28) != '\0')) {

    if ((param_6 & 4) != 0) {

      return 1;

    }

    if ((param_6 & 8) != 0) {

      iVar2 = FUN_1400c6580(4);

      if (0 < iVar2) {

        return 1;

      }

      *(undefined1 *)(lVar1 + 0xd + lVar4 * 0x28) = 0;

      goto LAB_1401016ce;

    }

  }

  if (param_3 < param_5) {

    if (*(char *)(lVar1 + 0xc + lVar3 * 0x28) == '\0') goto LAB_14010173f;

    if ((param_6 & 4) != 0) {

      return 1;

    }

    if ((param_6 & 8) == 0) goto LAB_14010173f;

    iVar2 = FUN_1400c6580(4);

    if (0 < iVar2) {

      return 1;

    }

    *(undefined1 *)(lVar1 + 0xc + lVar3 * 0x28) = 0;

  }

  else {

    if ((param_3 <= param_5) || (*(char *)(lVar1 + 0xc + lVar4 * 0x28) == '\0')) goto LAB_14010173f;

    if ((param_6 & 4) != 0) {

      return 1;

    }

    if ((param_6 & 8) == 0) goto LAB_14010173f;

    iVar2 = FUN_1400c6580(4);

    if (0 < iVar2) {

      return 1;

    }

    *(undefined1 *)(lVar1 + 0xc + lVar4 * 0x28) = 0;

  }

  FUN_140101300(param_1);

LAB_14010173f:

  if ((param_2 == param_4) && (param_3 == param_5)) {

    uVar5 = 0;

  }

  else {

    uVar5 = CONCAT71(0x1403132,

                     (*(uint *)(&DAT_1403132d4 + (longlong)*(int *)(lVar1 + lVar3 * 0x28) * 0x1c) &

                     param_6) != 0);

  }

  return uVar5;

}




