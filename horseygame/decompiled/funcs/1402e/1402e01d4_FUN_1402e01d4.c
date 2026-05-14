// Address: 0x1402e01d4
// Ghidra name: FUN_1402e01d4
// ============ 0x1402e01d4 FUN_1402e01d4 (size=241) ============


undefined4 FUN_1402e01d4(byte *param_1)



{

  int iVar1;

  char cVar2;

  undefined4 *puVar3;

  int *piVar4;

  byte *pbVar5;

  uint uVar6;

  undefined4 uVar7;

  

  if ((*(ulonglong *)(param_1 + 0x18) == 0) ||

     (*(ulonglong *)(param_1 + 0x10) < *(ulonglong *)(param_1 + 0x18))) {

    puVar3 = (undefined4 *)FUN_1402e68b0();

    *puVar3 = 0x16;

    FUN_1402cd454();

    uVar7 = 0xffffffff;

  }

  else {

    if (*(longlong *)(param_1 + 0x28) == 0) {

      puVar3 = (undefined4 *)FUN_1402e68b0();

      uVar7 = 0xffffffff;

      *puVar3 = 0x16;

    }

    else {

      do {

        cVar2 = FUN_1402dff58(param_1 + 0x20);

        if (cVar2 == '\0') break;

        cVar2 = FUN_1402e0598(param_1);

      } while (cVar2 != '\0');

      uVar7 = *(undefined4 *)(param_1 + 0x88);

      if ((*(longlong *)(param_1 + 0x88) == 0) && (*(int *)(param_1 + 0x34) != 1)) {

        pbVar5 = *(byte **)(param_1 + 0x18);

        if (pbVar5 == *(byte **)(param_1 + 0x10)) {

          uVar6 = 0xffffffff;

          uVar7 = 0xffffffff;

        }

        else {

          uVar6 = (uint)*pbVar5;

          pbVar5 = pbVar5 + 1;

          *(byte **)(param_1 + 0x18) = pbVar5;

        }

        if ((pbVar5 != *(byte **)(param_1 + 8)) &&

           ((pbVar5 != *(byte **)(param_1 + 0x10) || (uVar6 != 0xffffffff)))) {

          *(byte **)(param_1 + 0x18) = pbVar5 + -1;

        }

      }

      if ((*param_1 & 1) == 0) {

        return uVar7;

      }

      iVar1 = *(int *)(param_1 + 0x30);

      if (iVar1 == 0) {

        return uVar7;

      }

      piVar4 = (int *)FUN_1402e68b0();

      *piVar4 = iVar1;

    }

    FUN_1402cd454();

  }

  return uVar7;

}




