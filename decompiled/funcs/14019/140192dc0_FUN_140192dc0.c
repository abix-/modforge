// Address: 0x140192dc0
// Ghidra name: FUN_140192dc0
// ============ 0x140192dc0 FUN_140192dc0 (size=420) ============


bool FUN_140192dc0(undefined8 param_1,ushort param_2,short param_3,short param_4,short param_5,

                  char param_6)



{

  char cVar1;

  longlong lVar2;

  short sVar3;

  uint uVar4;

  bool bVar5;

  undefined1 local_28 [16];

  undefined1 local_18 [16];

  

  uVar4 = (uint)param_2;

  if (param_6 == '\0') {

    cVar1 = FUN_140192d90(param_2,param_3);

    if (cVar1 != '\0') {

      return true;

    }

  }

  else {

    if ((DAT_1403e3a5c != '\0') &&

       (uVar4 = (uint)param_2, cVar1 = FUN_140192d90(param_2,param_3), cVar1 == '\0')) {

      return true;

    }

    if (((DAT_1403e3a5d == '\0') && ((short)uVar4 == 0x57e)) && (param_3 == 0x337)) {

      return true;

    }

  }

  if ((DAT_1403fccf9 == '\0') || (param_4 == 0)) goto LAB_140192ee0;

  sVar3 = (short)uVar4;

  if (sVar3 == 0x28de) {

    if (param_4 != 1) goto LAB_140192ee0;

    bVar5 = (param_5 - 2U & 0xfffb) == 0;

  }

  else {

    if (sVar3 == 0x4b4) {

      bVar5 = param_3 == 0x2412;

LAB_140192e7d:

      if (bVar5) {

        if (param_4 != -0x60) {

          return true;

        }

        return false;

      }

    }

    else if (sVar3 == 0x37d7) {

      bVar5 = (param_3 + 0xdbffU & 0xfeff) == 0;

      goto LAB_140192e7d;

    }

    if (param_4 != 1) {

      return true;

    }

    if ((param_5 - 4U & 0xfffa) != 0) {

      return true;

    }

    bVar5 = param_5 == 9;

  }

  if (bVar5) {

    return true;

  }

LAB_140192ee0:

  if (DAT_1403fcd10 == 0) {

    return false;

  }

  FUN_14012ef10(local_28,0x10,"0x%.4x/0x0000",uVar4);

  FUN_14012ef10(local_18,0x10,"0x%.4x/0x%.4x",uVar4,param_3);

  lVar2 = FUN_14012f030(DAT_1403fcd10,local_28);

  if (lVar2 != 0) {

    return true;

  }

  lVar2 = FUN_14012f030(DAT_1403fcd10,local_18);

  return lVar2 != 0;

}




