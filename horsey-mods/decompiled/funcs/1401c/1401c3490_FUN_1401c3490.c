// Address: 0x1401c3490
// Ghidra name: FUN_1401c3490
// ============ 0x1401c3490 FUN_1401c3490 (size=215) ============


void FUN_1401c3490(longlong param_1,int param_2,longlong *param_3,uint param_4)



{

  longlong lVar1;

  longlong lVar2;

  uint uVar3;

  ulonglong uVar4;

  

  if (param_4 != 0) {

    uVar3 = 0;

    do {

      lVar1 = param_3[1];

      uVar4 = (ulonglong)(uVar3 + param_2);

      lVar2 = *param_3;

      if (*(longlong *)(param_1 + 0x370 + uVar4 * 8) != *(longlong *)(lVar1 + 0x48)) {

        FUN_1401cb860(param_1,lVar1);

        *(undefined8 *)(param_1 + 0x370 + uVar4 * 8) = *(undefined8 *)(lVar1 + 0x48);

        *(undefined1 *)(param_1 + 0x211) = 1;

      }

      if (*(longlong *)(param_1 + 0x2f0 + uVar4 * 8) !=

          *(longlong *)(*(longlong *)(lVar2 + 0x28) + 0x38)) {

        FUN_1401cb900(param_1);

        *(undefined8 *)(param_1 + 0x2f0 + uVar4 * 8) =

             *(undefined8 *)(*(longlong *)(lVar2 + 0x28) + 0x38);

        *(undefined1 *)(param_1 + 0x211) = 1;

      }

      uVar3 = uVar3 + 1;

      param_3 = param_3 + 2;

    } while (uVar3 < param_4);

  }

  return;

}




