// Address: 0x14014af50
// Ghidra name: FUN_14014af50
// ============ 0x14014af50 FUN_14014af50 (size=212) ============


undefined8 FUN_14014af50(longlong param_1)



{

  int iVar1;

  undefined4 extraout_var;

  undefined4 *puVar2;

  undefined8 uVar3;

  undefined8 local_18;

  undefined8 uStack_10;

  

  local_18 = *(undefined8 *)(*(longlong *)(param_1 + 0x138) + 0x18);

  uStack_10 = *(undefined8 *)(*(longlong *)(param_1 + 0x138) + 0x20);

  if (*(char *)(param_1 + 0x292) != '\0') {

    iVar1 = memcmp(&local_18,(void *)(param_1 + 0x270),0x10);

    if (iVar1 == 0) {

      return CONCAT71((int7)(CONCAT44(extraout_var,iVar1) >> 8),1);

    }

  }

  puVar2 = (undefined4 *)FUN_1401499f0(param_1);

  if (puVar2 != (undefined4 *)0x0) {

    *puVar2 = 1;

    *(undefined8 *)(puVar2 + 2) = 0;

    puVar2[4] = (undefined4)local_18;

    puVar2[5] = local_18._4_4_;

    puVar2[6] = (undefined4)uStack_10;

    puVar2[7] = uStack_10._4_4_;

    uVar3 = (**(code **)(param_1 + 0x20))(param_1,puVar2);

    if ((char)uVar3 == '\0') {

      *puVar2 = 0;

      return uVar3;

    }

    *(undefined1 *)(param_1 + 0x292) = 1;

    *(undefined8 *)(param_1 + 0x270) = local_18;

    *(undefined8 *)(param_1 + 0x278) = uStack_10;

    return uVar3;

  }

  return 0;

}




