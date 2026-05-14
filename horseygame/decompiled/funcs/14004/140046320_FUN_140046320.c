// Address: 0x140046320
// Ghidra name: FUN_140046320
// ============ 0x140046320 FUN_140046320 (size=174) ============


void FUN_140046320(undefined8 param_1,undefined1 param_2)



{

  longlong lVar1;

  longlong *plVar2;

  

  if ((DAT_1403ea292 == '\0') && (DAT_1403ea293 != '\0')) {

    plVar2 = (longlong *)FUN_140047560(&DAT_1403ea2c0,param_1);

    if (((longlong *)*plVar2 != (longlong *)plVar2[1]) && (lVar1 = *(longlong *)*plVar2, lVar1 != 0)

       ) {

      FUN_140044ff0(lVar1,0);

      FUN_140045310(*(undefined4 *)(*plVar2 + 0x28));

      *(undefined1 *)(DAT_1403ea2a8 + 0x39) = param_2;

      if (*(longlong *)(DAT_1403ea2a8 + 0x58) != 0) {

        *(undefined1 *)(*(longlong *)(DAT_1403ea2a8 + 0x58) + 0xb) = param_2;

      }

      if (*(longlong *)(DAT_1403ea2a8 + 0x60) != 0) {

        *(undefined1 *)(*(longlong *)(DAT_1403ea2a8 + 0x60) + 0xb) = param_2;

      }

    }

  }

  FUN_140027900(param_1);

  return;

}




