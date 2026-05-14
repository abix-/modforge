// Address: 0x140289e50
// Ghidra name: FUN_140289e50
// ============ 0x140289e50 FUN_140289e50 (size=148) ============


bool FUN_140289e50(undefined8 param_1,undefined8 param_2,undefined4 *param_3,undefined8 *param_4,

                  undefined4 *param_5)



{

  undefined4 uVar1;

  longlong lVar2;

  undefined4 local_18;

  undefined4 local_14 [3];

  

  FUN_14016ebe0(param_2,local_14,&local_18);

  lVar2 = FUN_140145e60(local_14[0],local_18,0x16161804);

  if (lVar2 != 0) {

    uVar1 = FUN_14016ea50(param_2);

    FUN_1401755a0(uVar1,"SDL.internal.window.surface",lVar2);

    *param_3 = 0x16161804;

    *param_4 = *(undefined8 *)(lVar2 + 0x18);

    *param_5 = *(undefined4 *)(lVar2 + 0x10);

  }

  return lVar2 != 0;

}




