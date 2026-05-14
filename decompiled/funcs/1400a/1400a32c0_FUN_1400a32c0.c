// Address: 0x1400a32c0
// Ghidra name: FUN_1400a32c0
// ============ 0x1400a32c0 FUN_1400a32c0 (size=224) ============


void FUN_1400a32c0(longlong param_1,uint param_2)



{

  undefined1 uVar1;

  int iVar2;

  int iVar3;

  ulonglong uVar4;

  

  if (0 < (int)param_2) {

    uVar4 = (ulonglong)param_2;

    do {

      iVar2 = FUN_1400c6580(0xf0);

      iVar3 = FUN_1400c6580(2);

      if (iVar2 != 0xcf) {

        if (iVar2 == 0x1f) {

          uVar1 = FUN_1400c6580(3);

          *(undefined1 *)((longlong)iVar3 * 0xf0 + 0x1f + param_1) = uVar1;

        }

        else if (iVar2 == 0xd0) {

          uVar1 = FUN_1400c6580(3);

          *(undefined1 *)((longlong)iVar3 * 0xf0 + 0xd0 + param_1) = uVar1;

        }

        else {

          iVar3 = FUN_1400c6580(2);

          uVar1 = FUN_1400c6580(4);

          *(undefined1 *)((longlong)iVar3 * 0xf0 + (longlong)iVar2 + param_1) = uVar1;

        }

      }

      uVar4 = uVar4 - 1;

    } while (uVar4 != 0);

  }

  return;

}




