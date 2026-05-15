// Address: 0x1401c2ed0
// Ghidra name: FUN_1401c2ed0
// ============ 0x1401c2ed0 FUN_1401c2ed0 (size=211) ============


void FUN_1401c2ed0(longlong param_1,int param_2,longlong *param_3,uint param_4)



{

  longlong lVar1;

  longlong lVar2;

  uint uVar3;

  uint uVar4;

  

  if (param_4 != 0) {

    uVar4 = 0;

    do {

      lVar1 = *param_3;

      uVar3 = uVar4 + param_2;

      lVar2 = *(longlong *)(param_1 + 0x7b0 + (ulonglong)uVar3 * 8);

      if (lVar2 != *(longlong *)(lVar1 + 0x28)) {

        if (lVar2 != 0) {

          FUN_1401cb580(param_1,0x40);

        }

        FUN_1401cb510(param_1,0x40,*(undefined8 *)(lVar1 + 0x28));

        FUN_1401cb900(param_1,*(undefined8 *)(lVar1 + 0x28));

        *(undefined8 *)(param_1 + 0x7b0 + (ulonglong)uVar3 * 8) = *(undefined8 *)(lVar1 + 0x28);

        *(undefined8 *)(param_1 + 0x730 + (ulonglong)uVar3 * 8) =

             *(undefined8 *)(*(longlong *)(lVar1 + 0x28) + 0x38);

        *(undefined1 *)(param_1 + 0x220) = 1;

      }

      uVar4 = uVar4 + 1;

      param_3 = param_3 + 1;

    } while (uVar4 < param_4);

  }

  return;

}




