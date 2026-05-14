// Address: 0x140162f40
// Ghidra name: FUN_140162f40
// ============ 0x140162f40 FUN_140162f40 (size=226) ============


undefined8 FUN_140162f40(char param_1)



{

  longlong lVar1;

  char cVar2;

  int iVar3;

  longlong lVar4;

  longlong lVar5;

  

  lVar4 = FUN_1401611a0();

  lVar5 = 0;

  if (*(longlong *)(lVar4 + 0x48) != 0) {

    if ((((param_1 == '\0') && (iVar3 = FUN_14016da90(), iVar3 == 0)) &&

        ((*(char *)(lVar4 + 0xf4) != '\0' ||

         ((*(char *)(lVar4 + 0xf3) != '\0' &&

          (iVar3 = FUN_1401611b0(lVar4,0,0), lVar5 = 0, iVar3 != 0)))))) &&

       (lVar5 = 0, *(char *)(lVar4 + 0xc1) == '\0')) {

      lVar5 = *(longlong *)(lVar4 + 0x88);

    }

    lVar1 = *(longlong *)(lVar4 + 0xf8);

    if (lVar5 != lVar1) {

      if (lVar1 != 0) {

        *(ulonglong *)(lVar1 + 0x48) = *(ulonglong *)(lVar1 + 0x48) & 0xffffffffffffbfff;

      }

      if (lVar5 != 0) {

        *(ulonglong *)(lVar5 + 0x48) = *(ulonglong *)(lVar5 + 0x48) | 0x4000;

      }

      *(longlong *)(lVar4 + 0xf8) = lVar5;

      cVar2 = (**(code **)(lVar4 + 0x48))(lVar5);

      if (cVar2 == '\0') {

        if (lVar1 != 0) {

          *(ulonglong *)(lVar1 + 0x48) = *(ulonglong *)(lVar1 + 0x48) | 0x4000;

        }

        if (lVar5 != 0) {

          *(ulonglong *)(lVar5 + 0x48) = *(ulonglong *)(lVar5 + 0x48) & 0xffffffffffffbfff;

        }

        *(longlong *)(lVar4 + 0xf8) = lVar1;

        return 0;

      }

    }

  }

  return 1;

}




