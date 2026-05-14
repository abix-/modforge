// Address: 0x1401aea30
// Ghidra name: FUN_1401aea30
// ============ 0x1401aea30 FUN_1401aea30 (size=211) ============


void FUN_1401aea30(longlong param_1,int param_2,undefined8 *param_3,uint param_4)



{

  undefined8 uVar1;

  longlong *plVar2;

  longlong lVar3;

  uint uVar4;

  uint uVar5;

  

  if (param_4 != 0) {

    uVar1 = *(undefined8 *)(param_1 + 0x110);

    uVar5 = 0;

    do {

      plVar2 = (longlong *)*param_3;

      uVar4 = uVar5 + param_2;

      lVar3 = *(longlong *)(param_1 + 0x858 + (ulonglong)uVar4 * 8);

      if (lVar3 != *plVar2) {

        if (lVar3 != 0) {

          FUN_1401b50b0(uVar1,param_1,6);

        }

        FUN_1401b5050(uVar1,param_1,6,*plVar2);

        FUN_1401bd730(param_1,*plVar2);

        *(longlong *)(param_1 + 0x858 + (ulonglong)uVar4 * 8) = *plVar2;

        *(undefined8 *)(param_1 + 0x7d8 + (ulonglong)uVar4 * 8) = *(undefined8 *)(*plVar2 + 0x10);

        *(undefined1 *)(param_1 + 0x24e) = 1;

      }

      uVar5 = uVar5 + 1;

      param_3 = param_3 + 1;

    } while (uVar5 < param_4);

  }

  return;

}




