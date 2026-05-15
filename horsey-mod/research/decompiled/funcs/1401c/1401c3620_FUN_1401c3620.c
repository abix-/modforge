// Address: 0x1401c3620
// Ghidra name: FUN_1401c3620
// ============ 0x1401c3620 FUN_1401c3620 (size=156) ============


void FUN_1401c3620(longlong param_1,int param_2,longlong *param_3,uint param_4)



{

  longlong lVar1;

  longlong lVar2;

  uint uVar3;

  

  if (param_4 != 0) {

    uVar3 = 0;

    do {

      lVar2 = *(longlong *)(*param_3 + 0x28);

      lVar1 = (ulonglong)(uVar3 + param_2) * 8;

      if (*(longlong *)(lVar1 + 0x3f0 + param_1) != *(longlong *)(lVar2 + 0x38)) {

        FUN_1401cb900(param_1,lVar2);

        *(undefined8 *)(lVar1 + 0x3f0 + param_1) = *(undefined8 *)(lVar2 + 0x38);

        *(undefined1 *)(param_1 + 0x212) = 1;

      }

      uVar3 = uVar3 + 1;

      param_3 = param_3 + 1;

    } while (uVar3 < param_4);

  }

  return;

}




