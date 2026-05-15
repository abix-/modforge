// Address: 0x1401af160
// Ghidra name: FUN_1401af160
// ============ 0x1401af160 FUN_1401af160 (size=159) ============


void FUN_1401af160(longlong param_1,int param_2,undefined8 *param_3,uint param_4)



{

  longlong lVar1;

  longlong *plVar2;

  uint uVar3;

  

  if (param_4 != 0) {

    uVar3 = 0;

    do {

      plVar2 = (longlong *)*param_3;

      lVar1 = param_1 + (ulonglong)(uVar3 + param_2) * 8;

      if (*(longlong *)(lVar1 + 0x4d8) != *(longlong *)(*plVar2 + 0x10)) {

        FUN_1401bd730(param_1);

        *(undefined8 *)(lVar1 + 0x4d8) = *(undefined8 *)(*plVar2 + 0x10);

        *(undefined1 *)(param_1 + 0x248) = 1;

      }

      uVar3 = uVar3 + 1;

      param_3 = param_3 + 1;

    } while (uVar3 < param_4);

  }

  return;

}




