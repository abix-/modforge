// Address: 0x140225040
// Ghidra name: FUN_140225040
// ============ 0x140225040 FUN_140225040 (size=201) ============


void FUN_140225040(longlong param_1)



{

  UINT UVar1;

  longlong lVar2;

  undefined8 uVar3;

  HIMC pHVar4;

  CHAR local_118 [272];

  

  *(undefined8 *)(param_1 + 600) = 0;

  *(undefined8 *)(param_1 + 0x260) = 0;

  UVar1 = ImmGetIMEFileNameA(*(HKL *)(param_1 + 0x248),local_118,0x104);

  if ((UVar1 != 0) && (lVar2 = FUN_1401885b0(local_118), lVar2 != 0)) {

    uVar3 = FUN_140188550(lVar2,"GetReadingString");

    *(undefined8 *)(param_1 + 600) = uVar3;

    lVar2 = FUN_140188550(lVar2,"ShowReadingWindow");

    *(longlong *)(param_1 + 0x260) = lVar2;

    if ((lVar2 != 0) && (pHVar4 = ImmGetContext(*(HWND *)(param_1 + 0x150)), pHVar4 != (HIMC)0x0)) {

      (**(code **)(param_1 + 0x260))(pHVar4,0);

      ImmReleaseContext(*(HWND *)(param_1 + 0x150),pHVar4);

    }

  }

  return;

}




