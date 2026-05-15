// Address: 0x1401af200
// Ghidra name: FUN_1401af200
// ============ 0x1401af200 FUN_1401af200 (size=163) ============


void FUN_1401af200(longlong param_1,int param_2,longlong *param_3,uint param_4)



{

  longlong lVar1;

  longlong lVar2;

  uint uVar3;

  

  if (param_4 != 0) {

    uVar3 = 0;

    do {

      lVar2 = *param_3;

      lVar1 = param_1 + (ulonglong)(uVar3 + param_2) * 8;

      if (*(longlong *)(lVar1 + 0x498) != *(longlong *)(*(longlong *)(lVar2 + 0x28) + 0x20)) {

        FUN_1401bdb50(param_1);

        *(undefined8 *)(lVar1 + 0x498) = *(undefined8 *)(*(longlong *)(lVar2 + 0x28) + 0x20);

        *(undefined1 *)(param_1 + 0x248) = 1;

      }

      uVar3 = uVar3 + 1;

      param_3 = param_3 + 1;

    } while (uVar3 < param_4);

  }

  return;

}




