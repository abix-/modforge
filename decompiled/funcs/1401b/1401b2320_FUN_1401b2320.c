// Address: 0x1401b2320
// Ghidra name: FUN_1401b2320
// ============ 0x1401b2320 FUN_1401b2320 (size=404) ============


undefined8 * FUN_1401b2320(longlong param_1)



{

  int iVar1;

  undefined8 uVar2;

  undefined8 *puVar3;

  uint uVar4;

  undefined8 local_res8;

  undefined4 local_28 [2];

  undefined8 local_20;

  undefined4 local_18;

  

  if (*(int *)(param_1 + 0x7f0) != 0) {

    FUN_140179b40(*(undefined8 *)(param_1 + 0x7e0));

    uVar4 = *(int *)(param_1 + 0x7f0) - 1;

    puVar3 = *(undefined8 **)(*(longlong *)(param_1 + 0x7e8) + (ulonglong)uVar4 * 8);

    *(uint *)(param_1 + 0x7f0) = uVar4;

    iVar1 = (**(code **)(param_1 + 0xc68))(*(undefined8 *)(param_1 + 0x570),1,puVar3);

    FUN_140179b60(*(undefined8 *)(param_1 + 0x7e0));

    if (iVar1 == 0) {

      return puVar3;

    }

    if (*(char *)(param_1 + 0x57c) != '\0') {

      uVar2 = FUN_1401c0ba0(iVar1);

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(9,"%s %s","vkResetFences",uVar2);

    }

    uVar2 = FUN_1401c0ba0(iVar1);

    FUN_14012e850("%s %s","vkResetFences",uVar2);

    return (undefined8 *)0x0;

  }

  local_28[0] = 8;

  local_20 = 0;

  local_18 = 0;

  iVar1 = (**(code **)(param_1 + 0xb10))(*(undefined8 *)(param_1 + 0x570),local_28,0,&local_res8);

  if (iVar1 == 0) {

    puVar3 = (undefined8 *)FUN_1401841f0(0x10);

    *puVar3 = local_res8;

    FUN_140139010(puVar3 + 1,0);

    return puVar3;

  }

  if (*(char *)(param_1 + 0x57c) != '\0') {

    uVar2 = FUN_1401c0ba0(iVar1);

                    /* WARNING: Subroutine does not return */

    FUN_14012e0b0(9,"%s %s","vkCreateFence",uVar2);

  }

  uVar2 = FUN_1401c0ba0(iVar1);

  FUN_14012e850("%s %s","vkCreateFence",uVar2);

  return (undefined8 *)0x0;

}




