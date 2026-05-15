// Address: 0x14014b7f0
// Ghidra name: FUN_14014b7f0
// ============ 0x14014b7f0 FUN_14014b7f0 (size=155) ============


undefined8 FUN_14014b7f0(longlong param_1,undefined4 param_2)



{

  int iVar1;

  undefined4 uVar2;

  longlong lVar3;

  

  lVar3 = FUN_140184230(*(undefined8 *)(param_1 + 0x108),(longlong)*(int *)(param_1 + 0x110) * 4 + 8

                       );

  if (lVar3 == 0) {

    return 0;

  }

  *(undefined4 *)(lVar3 + (longlong)*(int *)(param_1 + 0x110) * 4) = param_2;

  iVar1 = *(int *)(param_1 + 0x110);

  *(int *)(param_1 + 0x110) = iVar1 + 1;

  *(undefined4 *)(lVar3 + 4 + (longlong)iVar1 * 4) = 0;

  *(longlong *)(param_1 + 0x108) = lVar3;

  uVar2 = FUN_14014f090(param_1);

  FUN_140175480(uVar2,"SDL.renderer.texture_formats",lVar3);

  return 1;

}




