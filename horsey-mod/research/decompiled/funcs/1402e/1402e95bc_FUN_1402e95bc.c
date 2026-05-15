// Address: 0x1402e95bc
// Ghidra name: FUN_1402e95bc
// ============ 0x1402e95bc FUN_1402e95bc (size=86) ============


undefined8 * FUN_1402e95bc(undefined8 *param_1)



{

  undefined8 *puVar1;

  undefined1 local_res8 [32];

  

  *param_1 = 0;

  __acrt_lock(8);

  puVar1 = (undefined8 *)FUN_1402e9630(local_res8);

  puVar1 = (undefined8 *)*puVar1;

  *param_1 = puVar1;

  if (puVar1 != (undefined8 *)0x0) {

    *(undefined4 *)(puVar1 + 2) = 0;

    puVar1[5] = 0;

    *puVar1 = 0;

    puVar1[1] = 0;

    *(undefined4 *)(puVar1 + 3) = 0xffffffff;

  }

  __acrt_unlock(8);

  return param_1;

}




