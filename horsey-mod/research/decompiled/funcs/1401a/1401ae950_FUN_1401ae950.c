// Address: 0x1401ae950
// Ghidra name: FUN_1401ae950
// ============ 0x1401ae950 FUN_1401ae950 (size=213) ============


void FUN_1401ae950(longlong param_1,int param_2,longlong *param_3,uint param_4)



{

  longlong *plVar1;

  longlong lVar2;

  uint uVar3;

  ulonglong uVar4;

  

  if (param_4 != 0) {

    uVar3 = 0;

    do {

      plVar1 = (longlong *)param_3[1];

      uVar4 = (ulonglong)(uVar3 + param_2);

      lVar2 = *param_3;

      if (*(longlong *)(param_1 + 0x718 + uVar4 * 8) != *plVar1) {

        FUN_1401bdaa0(param_1,plVar1);

        *(longlong *)(param_1 + 0x718 + uVar4 * 8) = *plVar1;

        *(undefined1 *)(param_1 + 0x24e) = 1;

      }

      if (*(longlong *)(param_1 + 0x698 + uVar4 * 8) !=

          *(longlong *)(*(longlong *)(lVar2 + 0x28) + 0x20)) {

        FUN_1401bdb50(param_1);

        *(undefined8 *)(param_1 + 0x698 + uVar4 * 8) =

             *(undefined8 *)(*(longlong *)(lVar2 + 0x28) + 0x20);

        *(undefined1 *)(param_1 + 0x24e) = 1;

      }

      uVar3 = uVar3 + 1;

      param_3 = param_3 + 2;

    } while (uVar3 < param_4);

  }

  return;

}




