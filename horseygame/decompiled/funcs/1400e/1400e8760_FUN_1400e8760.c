// Address: 0x1400e8760
// Ghidra name: FUN_1400e8760
// ============ 0x1400e8760 FUN_1400e8760 (size=298) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



bool FUN_1400e8760(longlong *param_1,int param_2)



{

  longlong lVar1;

  char cVar2;

  int iVar3;

  

  *(undefined1 *)(param_1 + 0x6d9) = 0xff;

  cVar2 = FUN_1400e8c90();

  if (cVar2 != -0x28) {

    _DAT_1403f4c40 = "no SOI";

    return false;

  }

  if (param_2 == 1) {

    return true;

  }

  cVar2 = FUN_1400e8c90(param_1);

  do {

    if ((cVar2 == -0x40) || (cVar2 == -0x3f)) {

      iVar3 = FUN_1400ec7b0(param_1,param_2);

      return iVar3 != 0;

    }

    iVar3 = FUN_1400ecc50(param_1,cVar2);

    if (iVar3 == 0) {

      return false;

    }

    cVar2 = FUN_1400e8c90(param_1);

    while (cVar2 == -1) {

      lVar1 = *param_1;

      if (*(longlong *)(lVar1 + 0x10) == 0) {

LAB_1400e880e:

        if (*(ulonglong *)(lVar1 + 0xc0) <= *(ulonglong *)(lVar1 + 0xb8)) {

LAB_1400e885a:

          _DAT_1403f4c40 = "no SOF";

          return false;

        }

      }

      else {

        iVar3 = (**(code **)(lVar1 + 0x20))(*(undefined8 *)(lVar1 + 0x28));

        if (iVar3 != 0) {

          if (*(int *)(lVar1 + 0x30) == 0) goto LAB_1400e885a;

          goto LAB_1400e880e;

        }

      }

      cVar2 = FUN_1400e8c90(param_1);

    }

  } while( true );

}




