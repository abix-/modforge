// Address: 0x1401aeb10
// Ghidra name: FUN_1401aeb10
// ============ 0x1401aeb10 FUN_1401aeb10 (size=217) ============


void FUN_1401aeb10(longlong param_1,int param_2,longlong *param_3,uint param_4)



{

  undefined8 uVar1;

  longlong lVar2;

  longlong lVar3;

  uint uVar4;

  uint uVar5;

  

  if (param_4 != 0) {

    uVar1 = *(undefined8 *)(param_1 + 0x110);

    uVar5 = 0;

    do {

      lVar2 = *param_3;

      uVar4 = uVar5 + param_2;

      lVar3 = *(longlong *)(param_1 + 0x818 + (ulonglong)uVar4 * 8);

      if (lVar3 != *(longlong *)(lVar2 + 0x28)) {

        if (lVar3 != 0) {

          FUN_1401bd6c0(uVar1,param_1,5);

        }

        FUN_1401bd650(uVar1,param_1,5,*(undefined8 *)(lVar2 + 0x28));

        FUN_1401bdb50(param_1,*(undefined8 *)(lVar2 + 0x28));

        *(undefined8 *)(param_1 + 0x818 + (ulonglong)uVar4 * 8) = *(undefined8 *)(lVar2 + 0x28);

        *(undefined8 *)(param_1 + 0x798 + (ulonglong)uVar4 * 8) =

             *(undefined8 *)(*(longlong *)(lVar2 + 0x28) + 0x20);

        *(undefined1 *)(param_1 + 0x24e) = 1;

      }

      uVar5 = uVar5 + 1;

      param_3 = param_3 + 1;

    } while (uVar5 < param_4);

  }

  return;

}




