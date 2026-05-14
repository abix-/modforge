// Address: 0x1401c3090
// Ghidra name: FUN_1401c3090
// ============ 0x1401c3090 FUN_1401c3090 (size=163) ============


void FUN_1401c3090(longlong param_1,int param_2,longlong *param_3,uint param_4)



{

  longlong lVar1;

  longlong lVar2;

  uint uVar3;

  

  if (param_4 != 0) {

    uVar3 = 0;

    do {

      lVar2 = *param_3;

      lVar1 = param_1 + (ulonglong)(uVar3 + param_2) * 8;

      if (*(longlong *)(lVar1 + 0x5d0) != *(longlong *)(*(longlong *)(lVar2 + 0x10) + 0x48)) {

        FUN_1401cb5f0(param_1);

        *(undefined8 *)(lVar1 + 0x5d0) = *(undefined8 *)(*(longlong *)(lVar2 + 0x10) + 0x48);

        *(undefined1 *)(param_1 + 0x21a) = 1;

      }

      uVar3 = uVar3 + 1;

      param_3 = param_3 + 1;

    } while (uVar3 < param_4);

  }

  return;

}




