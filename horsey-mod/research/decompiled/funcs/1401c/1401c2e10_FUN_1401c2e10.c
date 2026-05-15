// Address: 0x1401c2e10
// Ghidra name: FUN_1401c2e10
// ============ 0x1401c2e10 FUN_1401c2e10 (size=192) ============


void FUN_1401c2e10(longlong param_1,int param_2,longlong *param_3,uint param_4)



{

  longlong lVar1;

  longlong lVar2;

  uint uVar3;

  uint uVar4;

  

  if (param_4 != 0) {

    uVar4 = 0;

    do {

      lVar1 = *(longlong *)(*param_3 + 0x10);

      uVar3 = uVar4 + param_2;

      lVar2 = *(longlong *)(param_1 + 0x7f0 + (ulonglong)uVar3 * 8);

      if (lVar2 != lVar1) {

        if (lVar2 != 0) {

          FUN_1401c6930(param_1,0x40);

        }

        FUN_1401c68f0(param_1,0x40,lVar1);

        FUN_1401cb5f0(param_1,lVar1);

        *(longlong *)(param_1 + 0x7f0 + (ulonglong)uVar3 * 8) = lVar1;

        *(undefined8 *)(param_1 + 0x770 + (ulonglong)uVar3 * 8) = *(undefined8 *)(lVar1 + 0x48);

        *(undefined1 *)(param_1 + 0x221) = 1;

      }

      uVar4 = uVar4 + 1;

      param_3 = param_3 + 1;

    } while (uVar4 < param_4);

  }

  return;

}




