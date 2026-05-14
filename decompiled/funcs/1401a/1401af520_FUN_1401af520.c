// Address: 0x1401af520
// Ghidra name: FUN_1401af520
// ============ 0x1401af520 FUN_1401af520 (size=205) ============


undefined8 FUN_1401af520(longlong param_1)



{

  longlong lVar1;

  int iVar2;

  undefined8 uVar3;

  

  lVar1 = *(longlong *)(param_1 + 0x110);

  iVar2 = (**(code **)(lVar1 + 0xc50))(*(undefined8 *)(param_1 + 0x118),1);

  if (iVar2 == 0) {

    *(undefined1 *)(param_1 + 0xa98) = 0;

    FUN_140179b40(*(undefined8 *)(lVar1 + 0x8d0));

    FUN_1401b55b0(lVar1,param_1,1);

    FUN_140179b60(*(undefined8 *)(lVar1 + 0x8d0));

    return 1;

  }

  if (*(char *)(lVar1 + 0x57c) != '\0') {

    uVar3 = FUN_1401c0ba0(iVar2);

                    /* WARNING: Subroutine does not return */

    FUN_14012e0b0(9,"%s %s","vkResetCommandBuffer",uVar3);

  }

  uVar3 = FUN_1401c0ba0(iVar2);

  FUN_14012e850("%s %s","vkResetCommandBuffer",uVar3);

  return 0;

}




