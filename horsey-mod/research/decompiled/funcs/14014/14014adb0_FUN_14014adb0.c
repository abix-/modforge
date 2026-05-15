// Address: 0x14014adb0
// Ghidra name: FUN_14014adb0
// ============ 0x14014adb0 FUN_14014adb0 (size=165) ============


undefined8 FUN_14014adb0(longlong param_1)



{

  longlong lVar1;

  int iVar2;

  undefined4 extraout_var;

  undefined4 *puVar4;

  undefined8 local_18;

  undefined8 uStack_10;

  undefined8 uVar3;

  

  lVar1 = *(longlong *)(param_1 + 0x138);

  local_18 = *(undefined8 *)(lVar1 + 0x38);

  uStack_10 = *(undefined8 *)(lVar1 + 0x40);

  if ((*(char *)(param_1 + 0x293) != '\0') &&

     (*(char *)(lVar1 + 0x48) == *(char *)(param_1 + 0x290))) {

    iVar2 = memcmp(&local_18,(void *)(param_1 + 0x280),0x10);

    uVar3 = CONCAT44(extraout_var,iVar2);

    if (iVar2 == 0) goto LAB_14014ae3d;

  }

  puVar4 = (undefined4 *)FUN_1401499f0(param_1);

  if (puVar4 == (undefined4 *)0x0) {

    return 0;

  }

  *puVar4 = 2;

  *(undefined1 *)(puVar4 + 2) = *(undefined1 *)(lVar1 + 0x48);

  *(undefined8 *)(puVar4 + 3) = local_18;

  *(undefined8 *)(puVar4 + 5) = uStack_10;

  *(undefined8 *)(param_1 + 0x280) = local_18;

  *(undefined8 *)(param_1 + 0x288) = uStack_10;

  uVar3 = 0;

  *(undefined1 *)(param_1 + 0x290) = *(undefined1 *)(lVar1 + 0x48);

  *(undefined1 *)(param_1 + 0x293) = 1;

LAB_14014ae3d:

  return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);

}




