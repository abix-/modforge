// Address: 0x14008fed0
// Ghidra name: FUN_14008fed0
// ============ 0x14008fed0 FUN_14008fed0 (size=126) ============


void FUN_14008fed0(longlong param_1)



{

  longlong lVar1;

  

  lVar1 = *(longlong *)

           (*(longlong *)(DAT_1403fb0d8 + 0x438) + 8 + (longlong)*(int *)(param_1 + 8) * 8);

  *(longlong *)(param_1 + 0x278) = lVar1;

  if ((lVar1 != 0) && (*(longlong *)(lVar1 + 0x298) != *(longlong *)(lVar1 + 0x2a0))) {

    *(longlong *)(lVar1 + 0x2a0) = *(longlong *)(lVar1 + 0x298);

  }

  *(undefined4 *)(param_1 + 0x2a8) = 0xffffffff;

  *(undefined1 *)(param_1 + 0x2b0) = 0;

  *(undefined2 *)(param_1 + 600) = 1;

  *(undefined4 *)(param_1 + 0x3d0) = 0;

  *(undefined1 *)(param_1 + 0x264) = 0;

  *(undefined4 *)(param_1 + 0x230) = 0xffffffff;

  *(undefined4 *)(param_1 + 0x2f4) = 0xffffffff;

  FUN_14008ffc0();

  return;

}




