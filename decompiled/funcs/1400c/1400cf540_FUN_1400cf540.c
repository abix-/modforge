// Address: 0x1400cf540
// Ghidra name: FUN_1400cf540
// ============ 0x1400cf540 FUN_1400cf540 (size=211) ============


void FUN_1400cf540(longlong param_1,int param_2,undefined4 param_3,undefined4 param_4,

                  undefined4 param_5,undefined4 param_6)



{

  undefined8 *puVar1;

  ulonglong uVar2;

  longlong lVar3;

  ulonglong uVar4;

  ulonglong uVar5;

  undefined1 local_res10 [24];

  

  lVar3 = *(longlong *)(param_1 + 0x78);

  puVar1 = *(undefined8 **)(param_1 + 0x80);

  uVar4 = (ulonglong)param_2;

  uVar5 = (longlong)puVar1 - lVar3 >> 4;

  if (uVar5 <= uVar4) {

    uVar2 = (ulonglong)(param_2 + 1);

    if (uVar2 < uVar5) {

      *(ulonglong *)(param_1 + 0x80) = uVar2 * 0x10 + lVar3;

    }

    else if (uVar5 < uVar2) {

      if ((ulonglong)(*(longlong *)(param_1 + 0x88) - lVar3 >> 4) < uVar2) {

        FUN_1400d8290((longlong *)(param_1 + 0x78),uVar2,local_res10);

      }

      else {

        for (lVar3 = uVar2 - uVar5; lVar3 != 0; lVar3 = lVar3 + -1) {

          *puVar1 = 0;

          puVar1[1] = 0;

          puVar1 = puVar1 + 2;

        }

        *(undefined8 **)(param_1 + 0x80) = puVar1;

      }

    }

  }

  lVar3 = *(longlong *)(param_1 + 0x78);

  *(undefined4 *)(lVar3 + uVar4 * 0x10) = param_3;

  *(undefined4 *)(lVar3 + 4 + uVar4 * 0x10) = param_4;

  *(undefined4 *)(lVar3 + 8 + uVar4 * 0x10) = param_5;

  *(undefined4 *)(lVar3 + 0xc + uVar4 * 0x10) = param_6;

  return;

}




